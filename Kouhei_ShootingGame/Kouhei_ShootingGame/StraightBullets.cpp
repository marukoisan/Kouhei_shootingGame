#include"DxLib.h"
#include "StraightBullets.h"
#include"coomon.h"
#include<math.h>


StraightBullets::StraightBullets(T_Location location, T_Location speed)
	: BulletsBase(location,5.f,1,speed)//speed変数を作った
{

}


void StraightBullets::Update()
{
	T_Location newLocation = GetLocation();
	//newLocation.x += speed.x;
	newLocation.y += speed.y;
	SetLocation(newLocation);
}

void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 255));
}

bool StraightBullets::isScreenOut()
{
	//画面外に弾が出ると消える処理、GetRadiusをたしているのは弾の中心座標の分から足している
	bool ret = ((GetLocation().y + GetRadius()) <= 0 || (GetLocation().y + GetRadius()) >= SCREEN_HEIGHT);
	return ret;

	/*ret = ((GetLocation().y + GetRadius()) >= SCREEN_HEIGHT);
	return ret;*/
}