#pragma once
#include"coomon.h"

class SphereCollider
{
private:
	T_locaion location;  //���S���W
	float radius;        //���a

public:
	SphereCollider(T_locaion locaion, float radius);//�R���X�g���N�^

public:

	bool HitSphere(SphereCollider* collider)  const;
	void SetLocation(T_locaion location);//���S���W�̐ݒ�
	T_locaion GetLocation() const;//���S���W�̎擾
	float GetRadius() const;//���a�̎擾
};;

