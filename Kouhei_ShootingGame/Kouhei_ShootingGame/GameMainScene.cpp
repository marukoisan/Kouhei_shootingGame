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

	
	BulletsBase** bullet = player->GetBullets();

	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}

			if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
			{
				//�G�l�~�[�Ƀv���C���[�̒e���q�b�g
				// 
				// 
				// �G�l�~�[�Ƀ_���[�W��^���܂�
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

				//�e���폜���܂�
				player->DeleteBullet(bulletCount);
				bulletCount--;

				// 
				//�G�l�~�[��hp��0�ȉ�
				if (enemy[enemyCount]->HpCheck())
				{

					//�X�R�A�̉��Z
					player->AddScore(enemy[enemyCount]->GetPoint());

					//�G�l�~�[�̍폜
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;//�s����Ȓl�����Ȃ��悤�ɂ��邽�߂�nullptr��������
					
					//�z���O�ɋl�߂鏈��
					for (int i = enemyCount + 1; i < 10; i++)
					{
						if (enemy[i + 1] == nullptr)
						{
							break;
						}
						enemy[i] = enemy[i + 1];
						enemy[i + 1] = nullptr;
					}
					enemyCount--;
					break;
				}
			}
		}
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