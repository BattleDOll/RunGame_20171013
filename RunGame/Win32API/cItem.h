#pragma once
#include "cImage.h"
struct tagGold
{

	float		m_fPosX;			// x��ǥ
	float		m_fPosY;			// y��ǥ
	float		m_fMoveSpeed;		// �̵� �ӵ�
};

class cItem
{
private:
	cImage*				m_pGoldImage;

	tagGold				m_stGold;
	vector<tagGold>		m_vecGold;

	int					m_nGoldDelay;

	int					m_nRandPosX;		//���� ���� ��ǥ
	int					m_nRandPosY;		//���� ���� ��ǥ

public:
	cItem();
	~cItem();

	void Setup();
	void Update();
	void Render();

	vector<tagGold>& GetGold() { return m_vecGold; }
};

