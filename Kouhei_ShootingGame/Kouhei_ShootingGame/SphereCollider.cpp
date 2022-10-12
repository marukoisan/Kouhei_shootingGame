#include "SphereCollider.h"
#include<math.h>

//コンストラクタ
SphereCollider::SphereCollider(T_locaion locaion, float radius)
{
	this->location.x = locaion.x;
	this->location.y = locaion.y;
	this->radius = radius;

}


//SphereCollider型同士の当たり判定
bool SphereCollider::HitSphere(SphereCollider* collider)  const
{
	//自分から、相手へのベクトルを計算する
	//計算で出したベクトルの大きさと
	//自分と相手の半径の合計より
	//ベクトルの大きさが小さければ、当たっている

	//自分と相手との間のベクトルを計算する
	//fabsfで符号関係なしに計算結果が出てくる
	float vectorX = fabsf(this->location.x - collider->GetLocation().x);
	float vectorX = fabsf(this->location.y - collider->GetLocation().y);

	//ベクトルの大きさを計算
}

	//中心座標の設定
void SphereCollider::SetLocation(T_locaion location)
{
	this->location.x = location.x;
	this->location.y = location.y;
	
}

	//中心座標の取得
T_locaion SphereCollider::GetLocation() const
{
	return location;
}

	//半径の取得
float SphereCollider::GetRadius() const
{
		return radius;
}