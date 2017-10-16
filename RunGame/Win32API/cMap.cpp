#include "stdafx.h"
#include "cMap.h"


cMap::cMap()
{
	m_pBgImage = new cImage;
	m_pBgImage->Setup("images/bg.bmp", 6600, 675);
}

cMap::~cMap()
{
	delete m_pBgImage;
}

void cMap::Setup()
{
	m_SlowDelay = 0;
	m_nSourX = 0;
	m_nMoveSpeed = 5;
}

void cMap::Update()
{
	if (m_SlowDelay > 0)
	{
		--m_SlowDelay;
		m_nSourX += m_nMoveSpeed / 2;
	}
	else
	{
		m_nSourX += m_nMoveSpeed;
	}

	if (m_nSourX >= 5400)
		m_nSourX = 0;
}

void cMap::Render()
{
	m_pBgImage->Render(g_hDC, 0, 0, m_nSourX, 0, WINSIZEX, WINSIZEY);
}