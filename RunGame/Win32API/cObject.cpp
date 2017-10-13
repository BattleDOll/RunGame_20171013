#include "stdafx.h"
#include "cObject.h"


cObject::cObject()
{
	m_pObstacle = new cImage;
	m_pObstacle->Setup("images/object01.bmp", 75, 75, 1, 1, WINSIZEX, WINSIZEY - 120, true, RGB(255, 0, 255));
}

cObject::~cObject()
{
	delete m_pObstacle;
}

void cObject::Setup()
{
	m_fMoveSpeed = 10.0f;
}

void cObject::Update()
{
	m_pObstacle->SetPosX(m_pObstacle->GetPosX() - m_fMoveSpeed);
	if (m_pObstacle->GetPosX() < 0) m_pObstacle->SetPosX(1100);
}

void cObject::Render()
{	
	m_pObstacle->Render(g_hDC,
		m_pObstacle->GetPosX() - m_pObstacle->GetFrameWidth() / 2, 
		m_pObstacle->GetPosY() - m_pObstacle->GetFrameHeight() / 2);

//	RectangleMake(g_hDC, m_pObstacle->GetBoundingBox());

	HPEN hPen = (HPEN)CreatePen(0, 2, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	LineMake(g_hDC, m_pObstacle->GetBoundingBox().left,
		m_pObstacle->GetBoundingBox().top,
		m_pObstacle->GetBoundingBox().right,
		m_pObstacle->GetBoundingBox().top);
	LineMake(g_hDC, m_pObstacle->GetBoundingBox(20, 5).right,
		m_pObstacle->GetBoundingBox().top,
		m_pObstacle->GetBoundingBox().right,
		m_pObstacle->GetBoundingBox().bottom);
	LineMake(g_hDC, m_pObstacle->GetBoundingBox(20, 5).right,
		m_pObstacle->GetBoundingBox().bottom,
		m_pObstacle->GetBoundingBox().left,
		m_pObstacle->GetBoundingBox().bottom);
	LineMake(g_hDC, m_pObstacle->GetBoundingBox(20, 5).left,
		m_pObstacle->GetBoundingBox().bottom,
		m_pObstacle->GetBoundingBox().left,
		m_pObstacle->GetBoundingBox().top);

	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}
