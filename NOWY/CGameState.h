#pragma once
class CGameState
{
public:
	CGameState();
	virtual void input() =0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual ~CGameState() = 0;
};

