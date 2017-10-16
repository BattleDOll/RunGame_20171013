#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pPlayer = new cImage;
	m_pPlayer->Setup("images/RunGame.bmp", 960, 960, 12, 12, 200, MAP1_Y, true, RGB(255, 0, 255));
}


cPlayer::~cPlayer()
{
	delete m_pPlayer;
}

void cPlayer::Setup()
{
	m_nMapYPos = MAP1_Y;
	m_fJumpPower = 15.0f;
	m_nPlayerHP = 100;

	m_isSliding = false;

	SetLanding();
}

void cPlayer::Update()
{
	if (g_pKeyManager->isStayKeyDown(VK_SHIFT) && !m_isJumpping)
	{	
		m_isSliding = true;
		m_isRun = false;
	}
	else
	{
		m_isSliding = false;
		m_isRun = true;
	}

	if(g_pKeyManager->isOnceKeyDown(VK_SPACE)) // 변수로 처리 하자 ->> 카운트(점프 가능 횟수--)하고 렌딩시 카운트 초기화(맥스값으로)//
	{	
		if (!m_isJumpping && !m_isDobleJumpping && !m_isSliding)
		{
			m_isJumpping = true;
		}
		else if (m_isJumpping  && !m_isDobleJumpping)
		{
			m_isDobleJumpping = true;
			m_fGravity = 0;
		} 
	}

	if (m_isJumpping)
	{
		m_pPlayer->SetPosY(m_pPlayer->GetPosY() - m_fJumpPower + m_fGravity);
		m_fGravity += GRAVITY;

		if (m_fGravity > m_fJumpPower &&
			m_pPlayer->GetPosY() > m_nMapYPos - m_pPlayer->GetFrameHeight() / 2)	
		{
			SetLanding();
		}
	}


}

void cPlayer::Render()
{
	
	HPEN hPen = (HPEN)CreatePen(0, 2, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	if(m_isRun && !m_isJumpping)
	{ 
		m_pPlayer->FrameRender(g_hDC,
			m_pPlayer->GetPosX() - m_pPlayer->GetFrameWidth() / 2,
			m_pPlayer->GetPosY() - m_pPlayer->GetFrameHeight() / 2,
			1, 0, 8, 0, 3);

		BoudingLineMake(g_hDC,
			m_pPlayer->GetBoundingBox().left,
			m_pPlayer->GetBoundingBox().top,
			m_pPlayer->GetFrameWidth(),
			m_pPlayer->GetFrameHeight());
	}

	if (m_isSliding)
	{
		m_pPlayer->FrameRender(g_hDC,
			m_pPlayer->GetPosX() - m_pPlayer->GetFrameWidth() / 2,
			m_pPlayer->GetPosY() - m_pPlayer->GetFrameHeight() / 2,
			5, 1, 11, 1, 3);

		BoudingLineMake(g_hDC,
			m_pPlayer->GetBoundingBox(0, -10, 20, 40).left,
			m_pPlayer->GetBoundingBox(0, -10, 20, 40).top,
			m_pPlayer->GetFrameWidth() -20,
			m_pPlayer->GetFrameHeight() -40);
	}

	if(  m_isJumpping && m_fJumpPower > m_fGravity)
	{ 
		m_pPlayer->FrameRender(g_hDC, 
			m_pPlayer->GetPosX() - m_pPlayer->GetFrameWidth() / 2, 
			m_pPlayer->GetPosY() - m_pPlayer->GetFrameHeight() / 2,
			0, 
			2);

		BoudingLineMake(g_hDC,
			m_pPlayer->GetBoundingBox().left,
			m_pPlayer->GetBoundingBox().top,
			m_pPlayer->GetFrameWidth(),
			m_pPlayer->GetFrameHeight());
	}

	if (  m_isJumpping && m_fJumpPower < m_fGravity)
	{
		m_pPlayer->FrameRender(g_hDC, 
			m_pPlayer->GetPosX() - m_pPlayer->GetFrameWidth() / 2, 
			m_pPlayer->GetPosY() - m_pPlayer->GetFrameHeight() / 2, 
			5, 
			9);

		BoudingLineMake(g_hDC,
			m_pPlayer->GetBoundingBox().left,
			m_pPlayer->GetBoundingBox().top,
			m_pPlayer->GetFrameWidth(),
			m_pPlayer->GetFrameHeight());
	}
	
	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}

void cPlayer::SetLanding()
{
	m_pPlayer->SetCenterY(m_nMapYPos);
	m_fGravity = 0.0f;
	m_isJumpping = false;
	m_isDobleJumpping = false;
}