#include "stdafx.h"
#include "cMainGame.h"
#include "cMap.h"
#include "cPlayer.h"
#include "cObject.h"


cMainGame::cMainGame()
	: m_isPlaying(false)
{
	m_pMap = new cMap;
	m_pPlayer = new cPlayer;
	m_pObject = new cObject;
}

cMainGame::~cMainGame()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pObject;
}

void cMainGame::Setup()
{
	m_pMap->Setup();
	m_pPlayer->Setup();
	m_pObject->Setup();
	
}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pMap->Update();
		m_pPlayer->Update();
		m_pObject->Update();

		

			RECT rt;
			if (IntersectRect(&rt, &m_pPlayer->GetPlayer(), &m_pObject->GetObstacle()))
			{
			//	PostQuitMessage(0);
			}


		
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		Setup();
		m_isPlaying = true;
	}
}

void cMainGame::Render()
{
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (m_isPlaying)
	{
		m_pMap->Render();
		m_pPlayer->Render();
		m_pObject->Render();
	}
	else
	{
		TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	}
}