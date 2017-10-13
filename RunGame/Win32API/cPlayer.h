#pragma once
#include "cImage.h"

#define MAP1_Y (WINSIZEY - 110)

class cPlayer
{
private:
	cImage*			m_pPlayerImage;
	float			m_fGravity;
	float			m_fJumpPower;
	bool			m_isJumpping;
	bool			m_isDobleJumpping;

	int				m_nMapYPos;

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void SetLanding();

	RECT GetPlayer() {return m_pPlayerImage->GetBoundingBox();}
};

