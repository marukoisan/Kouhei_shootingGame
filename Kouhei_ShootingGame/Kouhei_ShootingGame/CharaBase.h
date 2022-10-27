#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"
class CharaBase : public SphereCollider
{

protected:
	T_Location speed;//	スピードを見るための変数
	BulletsBase** bullets; //(ポインタ配列)
	int* image;//配列も入れられるようにポインタ化

public:
	CharaBase(T_Location locaion, float radius, T_Location speed);//コンストラクタ
public:

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;

	BulletsBase** GetBullets();//Bulletsを受け取る関数


};

