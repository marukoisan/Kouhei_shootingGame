#include"DxLib.h"
#include "StraightBullets.h"
#include"coomon.h"
#include<math.h>


StraightBullets::StraightBullets(T_Location location, T_Location speed)
	: BulletsBase(location,5.f,1,speed)//speed�ϐ��������
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
	//��ʊO�ɒe���o��Ə����鏈���AGetRadius�������Ă���̂͒e�̒��S���W�̕����瑫���Ă���
	bool ret = ((GetLocation().y + GetRadius()) <= 0 || (GetLocation().y + GetRadius()) >= SCREEN_HEIGHT);
	return ret;

	/*ret = ((GetLocation().y + GetRadius()) >= SCREEN_HEIGHT);
	return ret;*/
}