#include "stdafx.h"
#include "cMainGame.h"



cMainGame::cMainGame()
	: m_isPlaying(false)
{
	m_pMap = new cMap;
	m_pPlayer = new cPlayer;
	m_pObject = new cObject;
	m_pItem = new cItem;
}

cMainGame::~cMainGame()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pObject;
	delete m_pItem;
}

void cMainGame::Setup()
{
	m_pMap->Setup();
	m_pPlayer->Setup();
	m_pObject->Setup();
	m_pItem->Setup();

	m_nHP = m_pPlayer->GetPlayerHP();
	m_nGold = m_pPlayer->GetPlayerGold();
}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pMap->Update();
		m_pPlayer->Update();
		m_pObject->Update();	
		m_pItem->Update();

		m_isSliding = m_pPlayer->GetSliding();

			// 슬라이딩이 아닐 때 충돌 처리
			if (!m_isSliding)
			{ 
				RECT rt;
				if ( IntersectRect(&rt, &m_pPlayer->GetCollisionNomal(), &m_pObject->GetObstacleCollision()))
				{					
					if (m_nHP <= 0)
					{
						//PostQuitMessage(0);
					}
					if (m_nHP > 0 && !m_isCollosion)
					{
						m_isCollosion = true;
						m_nHP -= 10;    
					}				
				}

				else 
				{
					m_isCollosion = false;
				}
			}

			// 슬라이딩 일 때 충돌 처리
			else
			{
				RECT rt1;
				if ( IntersectRect(&rt1, &m_pPlayer->GetCollisionSliding(), &m_pObject->GetObstacleCollision()))
				{
			
					if (m_nHP <= 0)
					{
					//  	PostQuitMessage(0);
					}
					if (m_nHP > 0 && !m_isCollosion)
					{
						m_isCollosion = true;
						m_nHP += 10; // collision  확인 용으로 사용
					}
				}
				else
				{
					m_isCollosion = false;
				}
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
		m_pItem->Render();

//		RectangleMake(g_hDC, m_pObject->GetObstacle());

		string str("HP : ");
		char szStr[128];
		str += itoa(m_nHP, szStr, 10); // itoa => 인트형을 문자열로 변환 (변환 소스, 임시 저장소, 숫자의 진수)
		TextOutA(g_hDC, 25, 50, str.c_str(), str.length());
	}
	else
	{
		TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	}
}