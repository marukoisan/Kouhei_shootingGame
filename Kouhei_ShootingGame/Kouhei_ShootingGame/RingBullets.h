#pragma once
#include "BulletsBase.h"
class RingBullets : public BulletsBase
{
public:
	RingBullets(T_Location location, float speed, int degAngle);//角度用の変数speedをfloatに変更

public:
	virtual void Update()override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;//弾が外に出たかどうか判定をとる関数
};

