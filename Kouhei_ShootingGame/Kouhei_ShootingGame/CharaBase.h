#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"
class CharaBase : public SphereCollider
{

protected:
	T_Location speed;//	�X�s�[�h�����邽�߂̕ϐ�
	BulletsBase** bullets; //(�|�C���^�z��)
	int* image;//�z����������悤�Ƀ|�C���^��

public:
	CharaBase(T_Location locaion, float radius, T_Location speed);//�R���X�g���N�^
public:

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;

	BulletsBase** GetBullets();//Bullets���󂯎��֐�


};

