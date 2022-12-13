#include"DxLib.h"
#include "RotationBullets.h"
#include"coomon.h"

#define _USE_MATH_DEFINES
#include<math.h>

RotationBullets::RotationBullets(T_Location location, float speed,int degAngle)
	: BulletsBase(location, 5.f, 1, T_Location{0,0})//float�^�ɕύX�������ߏ������̎d����ς���
{
	//�p�x�̌v�Z
	int deg = degAngle % 360;//�������360�x�̈Ӗ�
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg)== 270) ? 0: cos(rad);//(������) ? TRUE : FALSE
	//���ꂼ��̊p�x��90�̎���270�̎��͂��̂܂�0�������Ă��� ������cos
	float y = sin(rad);//�c����sin

	this->speed = T_Location{ (speed * x), (speed * y) };
}


void RotationBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x += speed.x;
	SetLocation(newLocation);
}

void RotationBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));
}

bool RotationBullets::isScreenOut()
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