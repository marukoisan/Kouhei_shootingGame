#include"DxLib.h"
#include "StraightBullets.h"


StraightBullets::StraightBullets(T_Location location) 
	: BulletsBase(location,5.f,1,T_Location{0,2})
{

}


void StraightBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y -= speed.y;
	SetLocation(newLocation);
}

void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 255));
}

bool StraightBullets::isScreenOut()
{
	//画面外に弾が出ると消える処理、GetRadiusをたしているのは弾の中心座標の分から足している
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	return ret;
}