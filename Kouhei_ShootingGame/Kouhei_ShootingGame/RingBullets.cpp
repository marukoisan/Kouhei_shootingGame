#include "RingBullets.h"
#include"DxLib.h"
#include"coomon.h"

#define _USE_MATH_DEFINES
#include<math.h>

RingBullets::RingBullets(T_Location location, float speed, int degAngle)
    :BulletsBase(location, 5.f, 1, T_Location{ 0,0 })
{
    //�p�x�̌v�Z
    //int deg = degAngle % 360;//�������360�x�̈Ӗ�

    //�~�P������360�x���܂�10�Ŋ���A���̒l��pi/180�̒l�������Ă�邱�ƂŁA�~��10���̂P�̃��W�A�����擾���邱�Ƃ��ł��܂�
    float rad = degAngle * (M_PI / 180);

	float x = cos(rad);
		//(abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);//(������) ? TRUE : FALSE
    //���ꂼ��̊p�x��90�̎���270�̎��͂��̂܂�0�������Ă��� ������cos
	float y = sin(rad) ;//�c����sin

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
	//��ʊO�ɒe���o��Ə����鏈���AGetRadius�������Ă���̂͒e�̒��S���W�̕����瑫���Ă���
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