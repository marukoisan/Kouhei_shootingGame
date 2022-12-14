#pragma once
#include"SphereCollider.h"
class BulletsBase :  public SphereCollider
{
private:
	int damage;

protected:
	T_Location speed;

public:
	BulletsBase(T_Location location, float radius, int damage, T_Location speed);

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool isScreenOut() = 0;//弾が外に出たかどうか判定をとる関数
	int GetDamage();

};

