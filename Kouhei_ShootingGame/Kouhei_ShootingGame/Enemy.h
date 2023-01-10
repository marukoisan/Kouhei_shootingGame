#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;//�ǂꂾ���e���o�������̕ϐ�

protected:
	int k = 0;//�Y�����p�̕ϐ�

public:
	Enemy(T_Location location , float speed);//�R���X�g���N�^

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	

	bool HpCheck();//�q�b�g�|�C���g���`�F�b�N����֐�
	int GetPoint();//�|�C���g�����炤�֐�
	void Move();//�G�̈ړ�����
};

