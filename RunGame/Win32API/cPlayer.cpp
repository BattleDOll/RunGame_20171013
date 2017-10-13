#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pPlayerImage = new cImage;
	m_pPlayerImage->Setup("images/ch.bmp", 960, 960, 12, 12, 200, MAP1_Y, true, RGB(255, 0, 255));
}


cPlayer::~cPlayer()
{
}

void cPlayer::Setup()
{
	m_nMapYPos = MAP1_Y;
	m_fJumpPower = 15.0f;

	SetLanding();
}

void cPlayer::Update()
{
	if(g_pKeyManager->isOnceKeyDown(VK_SPACE)) // 변수로 처리 하자 ->> 카운트(점프 가능 횟수--)하고 렌딩시 카운트 초기화(맥스값으로)//
	{	
		if (!m_isJumpping && !m_isDobleJumpping)
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
		m_pPlayerImage->SetPosY(m_pPlayerImage->GetPosY() - m_fJumpPower + m_fGravity);
		m_fGravity += GRAVITY;

		if (m_fGravity > m_fJumpPower &&
			m_pPlayerImage->GetPosY() > m_nMapYPos - m_pPlayerImage->GetFrameHeight() / 2)	
		{
			SetLanding();
		}
	}
}

void cPlayer::Render()
{
	if(!m_isJumpping)
	{ 
	m_pPlayerImage->FrameRender(g_hDC,
	(int)(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
	(int)(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
	1, 0, 8, 0, 3);
	}
	if(m_isJumpping)
	{ 
		m_pPlayerImage->FrameRender(g_hDC,
		(int)(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
		(int)(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
		4, 8, 4, 8, 5);
	}

	//	RectangleMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5));

	HPEN hPen = (HPEN)CreatePen(0, 2, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).top,
		m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).top);
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).top,
		m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom);
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).right,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom,
		m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom);
	LineMake(g_hDC, m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).bottom,
		m_pPlayerImage->GetBoundingBox(20, 5).left,
		m_pPlayerImage->GetBoundingBox(20, 5).top);

	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}

void cPlayer::SetLanding()
{
	m_pPlayerImage->SetCenterY(m_nMapYPos);
	m_fGravity = 0.0f;
	m_isJumpping = false;
	m_isDobleJumpping = false;
}