#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;//どれだけ弾を出したかの変数

protected:

public:
	Enemy(T_Location location , float speed);//コンストラクタ

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	

	bool HpCheck();//ヒットポイントをチェックする関数
	int GetPoint();//ポイントをもらう関数
};

