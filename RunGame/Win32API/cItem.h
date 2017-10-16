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
	float		PosX;			// x좌표
	float		PosY;			// y좌표
	int			Score;			// 이동 속도
};

class cItem
{
private:
	vector<tagItem>				m_vecItem;			//오브젝트 벡터
	vector<tagItem>::iterator	m_vecIter;			//오브젝트 벡터 반복자

	cImage*		m_pImage;

	int			m_nDelay;					// 오브젝트 생성 딜레이 계산용.

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

