#pragma once
#include "BulletsBase.h"
class RingBullets : public BulletsBase
{
public:
	RingBullets(T_Location location, float speed, int degAngle);//�p�x�p�̕ϐ�speed��float�ɕύX

public:
	virtual void Update()override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;//�e���O�ɏo�����ǂ���������Ƃ�֐�
};

