#pragma once
#include "cImage.h"
struct tagGold
{

	float		m_fPosX;			// xÁÂÇ¥
	float		m_fPosY;			// yÁÂÇ¥
	float		m_fMoveSpeed;		// ÀÌµ¿ ¼Óµµ
};

class cItem
{
private:
	cImage*				m_pGoldImage;

	tagGold				m_stGold;
	vector<tagGold>		m_vecGold;

	int					m_nGoldDelay;

	int					m_nRandPosX;		//·»´ý »ý¼º ÁÂÇ¥
	int					m_nRandPosY;		//·»´ý »ý¼º ÁÂÇ¥

public:
	cItem();
	~cItem();

	void Setup();
	void Update();
	void Render();

	vector<tagGold>& GetGold() { return m_vecGold; }
};

