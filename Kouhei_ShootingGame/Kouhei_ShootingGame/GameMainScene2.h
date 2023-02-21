#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy2.h"
#include"ItemBase.h"

class GameMainScene2 : public AbstractScene
{
private:
	Player* player;
	Enemy2** enemy2;
	ItemBase** items;

protected:
	//������̂̃G�l�~�[��������瓯�������ɂ��Ăǂ���Ƃ�TURE��������݂����Ȕ�������
	int enemyDown = 0;//�G�l�~�[���|���ꂽ��|���ꂽ�����J�E���g����
	int enemyVolume = 1;//�X�e�[�W�ɏo�����̃G�l�~�[���̐���ݒ肵�Ă���


public:
	GameMainScene2();//�R���X�g���N�^
	virtual ~GameMainScene2() {};//�f�X�g���N�^

public:
	//�p����̃f�[�^��override������
	virtual void Update()override;//�`��ȊO�̍X�V���������� 
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������

	int EnemyDown();//�J�E���g���ꂽ������Ⴄ
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX����


};

