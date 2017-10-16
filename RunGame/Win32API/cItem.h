#pragma once
#include "cImage.h"

class cMap;
class cPlayer;

#define GEN_DELAY 30
#define OBJECT_SPEED 10

enum E_TYPE { ET_COIN, ET_SPEED, ET_MAX };

struct tagItem
{
	E_TYPE		type;
	float		PosX;			// x��ǥ
	float		PosY;			// y��ǥ
	int			Score;			// �̵� �ӵ�
};

class cItem
{
private:
	vector<tagItem>				m_vecItem;			//������Ʈ ����
	vector<tagItem>::iterator	m_vecIter;			//������Ʈ ���� �ݺ���

	cImage*		m_pImage;

	int			m_nDelay;					// ������Ʈ ���� ������ ����.

	cMap*		m_pMap;
	cPlayer*	m_pPlayer;
public:
	cItem();
	~cItem();

	void Setup();
	void Update();
	void Render();

	void CreateItem();
	void SetMap(cMap* map) { m_pMap = map; }
};

