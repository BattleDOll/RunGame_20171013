#pragma once
#include "cImage.h"

#define MAP1_Y (WINSIZEY - 110)

class cPlayer
{
private:
	cImage*	m_pPlayer;

	float	m_fGravity;
	float	m_fJumpPower;

	int		m_nMapYPos;
	int		m_nPlayerHP;
	int		m_nJumpCount;		// 점프 횟수 지정 3>2>1>0....
	int		m_nGold;

	bool	m_isJumpping;
	bool	m_isDobleJumpping;
	bool	m_isSliding;
	bool	m_isRun;

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void SetLanding();

	RECT GetCollisionNomal() { return m_pPlayer->GetBoundingBox(); }
	RECT GetCollisionSliding() { return m_pPlayer->GetBoundingBox(0, -10, 20, 40); }

	int GetPlayerHP() { return m_nPlayerHP; }
	int GetPlayerGold() { return m_nGold; }

	bool GetSliding() { return m_isSliding; }
};

