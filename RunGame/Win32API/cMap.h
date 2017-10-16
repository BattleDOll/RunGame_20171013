#pragma once
#include "cImage.h"

class cMap
{
private:
	cImage*	m_pBgImage;
	int		m_nSourX;
	int		m_nMoveSpeed;
	int		m_SlowDelay;

public:
	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();

	int GetSlow() { return m_SlowDelay; }
	void SetSlow(int delay) { m_SlowDelay = delay; }
};

