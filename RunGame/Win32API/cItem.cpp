#include "stdafx.h"
#include "cItem.h"


cItem::cItem()
{ 
	m_pGoldImage = new cImage;
	m_pGoldImage->Setup("images/object.bmp", 256, 256, 4, 4, WINSIZEX, WINSIZEY - 200, true, RGB(255, 0, 255));
}


cItem::~cItem()
{
	delete m_pGoldImage;
}

void cItem::Setup()
{
	srand(time(NULL));
	m_stGold.m_fMoveSpeed = 10.0f;
	m_nGoldDelay = 0;
	m_nRandPosY = GetRandom(300, WINSIZEY - 200);
	m_nRandPosX = WINSIZEX + 50;
}

void cItem::Update()
{
	if (m_nGoldDelay <= 0)
	{
		m_nGoldDelay = 100;
		m_pGoldImage->GetPosX();
		m_pGoldImage->GetPosY();
		
		m_vecGold.push_back(m_stGold);
	}
	else
	{
		m_nGoldDelay--;
	}

	m_pGoldImage->SetPosX(m_pGoldImage->GetPosX() - m_stGold.m_fMoveSpeed);
}

void cItem::Render()
{

	m_pGoldImage->FrameRender(g_hDC,
		(int)(m_pGoldImage->GetPosX() - m_pGoldImage->GetFrameWidth() / 2),
		(int)(m_pGoldImage->GetPosY() - m_pGoldImage->GetFrameHeight() / 2),
		0, 0, 0, 0, 10);

	string str("Delay : ");
	char szStr[128];
	str += itoa(m_nGoldDelay, szStr, 10); // itoa => 인트형을 문자열로 변환 (변환 소스, 임시 저장소, 숫자의 진수)
	TextOutA(g_hDC, 25, 75, str.c_str(), str.length());
}
