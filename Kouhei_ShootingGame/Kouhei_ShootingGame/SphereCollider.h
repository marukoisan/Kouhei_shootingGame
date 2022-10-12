#pragma once
#include"coomon.h"

class SphereCollider
{
private:
	T_locaion location;  //中心座標
	float radius;        //半径

public:
	SphereCollider(T_locaion locaion, float radius);//コンストラクタ

public:

	bool HitSphere(SphereCollider* collider)  const;
	void SetLocation(T_locaion location);//中心座標の設定
	T_locaion GetLocation() const;//中心座標の取得
	float GetRadius() const;//半径の取得
};;

