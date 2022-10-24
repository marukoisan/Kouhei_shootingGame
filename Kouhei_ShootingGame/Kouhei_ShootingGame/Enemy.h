#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit() override;
	bool HpCheck();//ヒットポイントをチェックする関数
	int GetPoint();//ポイントをもらう関数
};

