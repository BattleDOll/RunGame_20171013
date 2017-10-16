#include "stdafx.h"
#include "cObject.h"


cObject::cObject()	
{
	m_pObstacle = new cImage;
	m_pObstacle->Setup("images/object01.bmp", 75, 75, 1, 1, WINSIZEX, WINSIZEY - 130, true, RGB(255, 0, 255));
}

cObject::~cObject()
{
	delete m_pObstacle;
}

void cObject::Setup()
{
	srand(time(NULL));
	m_fMoveSpeed = 10.0f;
}

void cObject::Update()
{
	m_pObstacle->SetPosX(m_pObstacle->GetPosX() - m_fMoveSpeed);
	if (m_pObstacle->GetPosX() < 0)
	{
		m_nRandPosX = GetRandom(1500, 2000);
		m_pObstacle->SetPosX(m_nRandPosX);
	}	
}

void cObject::Render()
{	
	m_pObstacle->Render(g_hDC,
		m_pObstacle->GetPosX() - m_pObstacle->GetFrameWidth() / 2, 
		m_pObstacle->GetPosY() - m_pObstacle->GetFrameHeight() / 2);

//	RectangleMake(g_hDC, m_pObstacle->GetBoundingBox());
//
//	HPEN hPen = (HPEN)CreatePen(0, 2, RGB(255, 0, 0));
//	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);
//
//	BoundingLineMake(g_hDC,
//		m_pObstacle->GetPosX() - m_pObstacle->GetFrameWidth() / 2,
//		m_pObstacle->GetPosY() - m_pObstacle->GetFrameHeight() / 2,
//		m_pObstacle->GetPosX() + m_pObstacle->GetFrameWidth() / 2,
//		m_pObstacle->GetPosY() + m_pObstacle->GetFrameHeight() / 2);
//
//	DeleteObject(hSelectPen);
//	DeleteObject(hPen);

	string str("좌표 : ");
	char szStr[128];
	str += itoa(m_nRandPosX, szStr, 10); // itoa => 인트형을 문자열로 변환 (변환 소스, 임시 저장소, 숫자의 진수)
	TextOutA(g_hDC, 25, 25, str.c_str(), str.length());
}
