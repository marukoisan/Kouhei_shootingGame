#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
public:
	StraightBullets(T_Location location);

public:
	virtual void Update()override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;//弾が外に出たかどうか判定をとる関数
};

