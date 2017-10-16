#include "stdafx.h"
#include "cItem.h"


cItem::cItem()
{ 
	m_pImage = new cImage;
	m_pImage->Setup("images/RunGame.bmp", 960, 960, 12, 12, true, RGB(255, 0, 255));
}


cItem::~cItem()
{
	delete m_pImage;
}

void cItem::Setup()
{
	srand(time(NULL));
	m_pImage = 0;
}

void cItem::Update()
{
	//if (m_nDelay < GEN_DELAY)
	//{
	//	++m_pImage;
	//}
	//else
	//{
	//	m_pImage = 0;
	//}
	//
	//for (m_vecIter = m_vecItem.begin(); m_vecIter != m_vecItem.end(); m_vecIter++)
	//{
	//
	//}
}

void cItem::Render()
{
	POINT ptImgPos;
	for (m_vecIter = m_vecItem.begin(); m_vecIter != m_vecItem.end(); m_vecIter++)
	{
		ptImgPos.y = 11;

		switch(m_vecIter->type)
		{
		case ET_COIN:
			ptImgPos.x = 4;
			break;
		case ET_SPEED:
			ptImgPos.x = 2;
			break;
		}
		m_pImage->FrameRender(g_hDC, m_vecIter->PosX, m_vecIter->PosY, ptImgPos.x, ptImgPos.y);
	}

	string str("Delay : ");
	char szStr[128];
	str += itoa(m_nDelay, szStr, 10); // itoa => 인트형을 문자열로 변환 (변환 소스, 임시 저장소, 숫자의 진수)
	TextOutA(g_hDC, 25, 75, str.c_str(), str.length());
}

void cItem::CreateItem()
{
	tagItem stItem;

	stItem.type = (E_TYPE)GetRandom(ET_MAX);
	stItem.PosX = WINSIZEX + m_pImage->GetFrameWidth();
	stItem.PosY = WINSIZEY - m_pImage->GetFrameHeight();

	switch (stItem.type)
	{
	case ET_COIN:
		break;
	case ET_SPEED:
		break;
	}

	m_vecItem.push_back(stItem);
}
