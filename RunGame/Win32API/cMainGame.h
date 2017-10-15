#pragma once
#include "cGameNode.h"

#include "cMap.h"
#include "cPlayer.h"
#include "cObject.h"
#include "cItem.h"

class cMap;
class cPlayer;
class cObject;
class cItem;

class cMainGame : public cGameNode
{
private:
	cMap*			m_pMap;
	cPlayer*		m_pPlayer;
	cObject*		m_pObject;
	cItem*			m_pItem;

	bool			m_isPlaying;
	bool			m_isCollosion;

	int				m_nHP;
	int				m_nGold;
	bool			m_isSliding;

public:
	cMainGame();
	~cMainGame();

	void Setup();

	virtual void Update() override;
	virtual void Render() override;
};