#pragma once
#include "CharaBase.h"


//�f�[�^�x�[�X����f�[�^�����������Ă���悤�Ȋ���
struct T_MoveInformation2
{
	int pattern;                //�s���p�^�[��
	T_Location targetLocation;  //���W
	int nextArrayNum;           //���̔z��ԍ�
	int waitTimeFlame;          //����
	int attackType;             //�U���̎�i
};



class Enemy2 : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;//�ǂꂾ���e���o�������̕ϐ�
	int BulletsNum;//�e�̐�

	//�G�G�l�~�[�̓����̃p�^�[�����쐬����
	//��ō쐬����struct�̒��g�̐��������̒��Ō��߂Ă���
	T_MoveInformation2 moveInfo[5];



protected:
	int k = 0;//�Y�����p�̕ϐ�
	int current = 0; //�Y�����p�̕ϐ�
	int waitCount = 0; //���ԗp�ϐ�


public:
	Enemy2(T_Location location, float speed);//�R���X�g���N�^

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;


	bool HpCheck();//�q�b�g�|�C���g���`�F�b�N����֐�
	int GetPoint();//�|�C���g�����炤�֐�
	void Move();//�G�̈ړ�����
	void inputCSV();//CSV�t�@�C���̓Ǎ���
};