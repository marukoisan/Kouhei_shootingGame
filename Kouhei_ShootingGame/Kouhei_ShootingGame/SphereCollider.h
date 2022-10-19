#pragma once
#include"coomon.h"

class SphereCollider
{
private:
	T_Location location;  //中心座標
	float radius;        //半径

public:
	SphereCollider(T_Location locaion, float radius);//コンストラクタ

public:

	bool HitSphere(SphereCollider* collider)  const;
	void SetLocation(T_Location location);//中心座標の設定
	T_Location GetLocation() const;//中心座標の取得
	float GetRadius() const;//半径の取得
};

