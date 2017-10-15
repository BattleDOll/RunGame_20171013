#pragma once
#include "cImage.h"

class cObject
{
private:
	cImage*	m_pObstacle;		// 장애물 이미지

	float	m_fObsPosX;			// 장애물 x좌표
	float	m_fObsPosY;			// 장애물 y좌표
	float	m_fMoveSpeed;		// 장애물 이동 속도

	int		m_nRandPosX;

public:
	cObject();
	~cObject();

	void Setup();
	void Update();
	void Render();

	RECT GetObstacleCollision() { return m_pObstacle->GetBoundingBox(); }
};

