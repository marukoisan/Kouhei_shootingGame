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
	void Hit(class ItemBase* item);//�A�C�e���Ɋւ���֐�
	bool LifeCheck();//���C�t���`�F�b�N����֐�
	int GetScore();//�X�R�A��Ԃ��֐�
	void AddScore(int score);//���݂̃X�R�A

};

