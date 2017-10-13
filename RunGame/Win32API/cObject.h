#pragma once
#include "cImage.h"

class cObject
{
private:
	cImage*			m_pObstacle;		// ��ֹ� �̹���
	float			m_fObsPosX;			// ��ֹ� x��ǥ
	float			m_fObsPosY;			// ��ֹ� y��ǥ
	float			m_fMoveSpeed;		// ��ֹ� �̵� �ӵ�

public:
	cObject();
	~cObject();

	void Setup();
	void Update();
	void Render();
};
