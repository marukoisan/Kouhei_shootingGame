#pragma once
#include"coomon.h"

class SphereCollider
{
private:
	T_Location location;  //���S���W
	float radius;        //���a

public:
	SphereCollider(T_Location locaion, float radius);//�R���X�g���N�^

public:

	bool HitSphere(SphereCollider* collider)  const;
	void SetLocation(T_Location location);//���S���W�̐ݒ�
	T_Location GetLocation() const;//���S���W�̎擾
	float GetRadius() const;//���a�̎擾
};

