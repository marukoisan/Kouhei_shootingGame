#pragma once
#include "CharaBase.h"
class Player : public CharaBase
{
private:
	int score;
	int life;

public:
	Player(T_Location location);//�R���X�g���N�^

public:
	void Update() override;
	void Draw() override;
	void Hit(int damage) override;
	bool LifeCheck();//���C�t���`�F�b�N����֐�
	int GetScore();//�X�R�A��Ԃ��֐�
	

};

