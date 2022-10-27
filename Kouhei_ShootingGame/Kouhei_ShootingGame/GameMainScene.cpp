#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,400 };//�����ʒu�����߂�ꏊ
	player = new Player(location);

	enemy = new Enemy* [10];//�G�l�~�[�̔z����쐬
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;//�z��̒���nullptr������
	}
	//enemy[0]�Ԗڂɓ���Ă���
	enemy[0] = new Enemy(T_Location{ 200,0 });//�����ʒu�����߂�ꏊ
}


//�`��ȊO�̍X�V���������� 
void GameMainScene::Update()
{
	player->Update();
	
	int enemyCount;
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;//enemy[enemyCount]��nullptr�Ȃ�break�Ŕ����鏈��
		}
		enemy[enemyCount]->Update();//nullptr�Ȃ�Update�������Ăяo������
	}
}

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	player->Draw();

	
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;//enemy[enemyCount]��nullptr�Ȃ�break�Ŕ����鏈��
		}
		enemy[enemyCount]->Draw();//nullptr�Ȃ�Draw�������Ăяo������
	}
}

//�V�[���̕ύX����
AbstractScene* GameMainScene::ChangeScene()
{
	return this;
}