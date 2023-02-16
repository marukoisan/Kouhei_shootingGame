#include "RingBullets.h"
#include"DxLib.h"
#include"coomon.h"

#define _USE_MATH_DEFINES
#include<math.h>

RingBullets::RingBullets(T_Location location, float speed, int degAngle)
    :BulletsBase(location, 5.f, 1, T_Location{ 0,0 })
{
    //角度の計算
    //int deg = degAngle % 360;//一周分の360度の意味

    //円１周分の360度をまず10で割り、その値にpi/180の値をかけてやることで、円の10分の１のラジアンを取得することができます
    float rad = degAngle * (M_PI / 180);

	float x = cos(rad);
		//(abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);//(条件式) ? TRUE : FALSE
    //それぞれの角度が90の時と270の時はそのまま0を代入している 横軸はcos
	float y = sin(rad) ;//縦軸はsin

	this->speed = T_Location{ (speed * x), (speed * y) };

}


void RingBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x += speed.x;
	SetLocation(newLocation);
}

void RingBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255,255));
}

bool RingBullets::isScreenOut()
{
	//画面外に弾が出ると消える処理、GetRadiusをたしているのは弾の中心座標の分から足している
	/*bool ret = ((GetLocation().y + GetRadius()) <= 0 || (GetLocation().y + GetRadius()) >= SCREEN_HEIGHT);
	return ret;*/

	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}

	ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
	if (ret)
	{
		return ret;
	}

	ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}

	ret = (SCREEN_WIDTH <= (GetLocation().x - GetRadius()));
	return ret;

	/*ret = ((GetLocation().y + GetRadius()) >= SCREEN_HEIGHT);
	return ret;*/
}