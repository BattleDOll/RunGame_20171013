#pragma once
#include "cGameNode.h"

class cMap;
class cPlayer;
class cObject;

class cMainGame : public cGameNode
{
private:
	bool			m_isPlaying;

	cMap*			m_pMap;
	cPlayer*		m_pPlayer;
	cObject*		m_pObject;

public:
	cMainGame();
	~cMainGame();

	void Setup();

	virtual void Update() override;
	virtual void Render() override;
};