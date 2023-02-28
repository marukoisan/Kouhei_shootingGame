#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"ItemBase.h"

class GameMainScene : public AbstractScene
{
private:
	Player* player;
	Enemy** enemy;
	ItemBase** items;
	int WaitTimer = 0;//�����l�[��

protected:
	//������̂̃G�l�~�[��������瓯�������ɂ��Ăǂ���Ƃ�TURE��������݂����Ȕ�������
	int enemyDown = 0;//�G�l�~�[���|���ꂽ��|���ꂽ�����J�E���g����
	int enemyVolume = 1;//�X�e�[�W�ɏo�����̃G�l�~�[���̐���ݒ肵�Ă���


public:
	GameMainScene();//�R���X�g���N�^
	virtual ~GameMainScene() {};//�f�X�g���N�^

public:
	//�p����̃f�[�^��override������
	virtual void Update()override;//�`��ȊO�̍X�V���������� 
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������

	int EnemyDown();//�J�E���g���ꂽ������Ⴄ
	int CountDown();//�J�E���g���ꂽ���������炤
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX����


};

