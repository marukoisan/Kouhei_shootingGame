#include "GameMainScene.h"
#include"Recovery.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,400 };//�����ʒu�����߂�ꏊ
	player = new Player(location);

	enemy = new Enemy* [10];//�G�l�~�[�̔z����쐬�A����������
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;//�z��̒���nullptr������
	}
	//enemy[0]�Ԗڂɓ���Ă���
	//enemy[0] = new Enemy(T_Location{ 200,0 });//�����ʒu�����߂�ꏊ
	enemy[0] = new Enemy(T_Location{ 640,0},1);//�����ʒu�����߂�ꏊ
	items = new ItemBase* [10];//�A�C�e���̏���������
	for (int i = 0; i < 10; i++)
	{
		items[i] = nullptr;//�z��̒���nullptr������
	}

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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;//items[i]��nullptr�Ȃ�break�Ŕ����鏈��
		}
		items[i]->Update();//nullptr�Ȃ�Update�������Ăяo������
	}

	
	BulletsBase** bullet = player->GetBullets();
	//�G�l�~�[�Ƀ_���[�W��^����for��
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
					//�A�C�e���̏���

					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new Recovery(enemy[enemyCount]->GetLocation());//�G�����񂾍��W�ɃA�C�e�����o��������
							break;//break�Ŕ�����
						}

					}

					//�X�R�A�̉��Z
					player->AddScore(enemy[enemyCount]->GetPoint());

					//�G�l�~�[�̍폜
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;//�s����Ȓl�����Ȃ��悤�ɂ��邽�߂�nullptr��������
					
					//�z���O�ɋl�߂鏈��
					for (int i = enemyCount; i < 10 - 1; i++)
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

	//�v���C���[�Ƀ_���[�W��^����for��
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}

		BulletsBase** bullet = enemy[enemyCount]->GetBullets();//�G�l�~�[���z��Ȃ̂ŃG�l�~�[���̃f�[�^�������Ă��邽��

		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}

			if (player->HitSphere(bullet[i]))
			{
				//�G�l�~�[�Ƀv���C���[�̒e���q�b�g
				// 
				// 
				// �v���C���[�Ƀ_���[�W��^���܂�
				player->Hit(bullet[i]->GetDamage());

				//�e���폜���܂�
				enemy[enemyCount]->DeleteBullet(i);
				i--;


				// 
				//�v���C���[��Life��0�ȉ�
				if (player->LifeCheck())
				{
					//�A�C�e���̏���

					//for (int i = 0; i < 10; i++)
					//{
					//	if (items[i] == nullptr)
					//	{
					//		items[i] = new Recovery(enemy[enemyCount]->GetLocation());//�G�����񂾍��W�ɃA�C�e�����o��������
					//		break;//break�Ŕ�����
					//	}

					//}

					////�X�R�A�̉��Z
					//player->AddScore(enemy[enemyCount]->GetPoint());

					//�G�l�~�[�̍폜
					/*delete player;
					player = nullptr*/;//�s����Ȓl�����Ȃ��悤�ɂ��邽�߂�nullptr��������

					//�z���O�ɋl�߂鏈��
					/*for (int i = enemyCount; i < 10 - 1; i++)
					{
						if (enemy[i + 1] == nullptr)
						{
							break;
						}
						enemy[i] = enemy[i + 1];
						enemy[i + 1] = nullptr;
					}*/
					/*enemyCount--;
					break;*/
				}
			}
		}
	}

	//�A�C�e���̎擾�폜
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		
		if (items[itemCount] == nullptr)
		{
			break;//nullptr�Ȃ珈���𔲂���
		}

		if (items[itemCount]->HitSphere(player) == true)//�A�C�e���ƃv���C���[���Ԃ�������? 
		{

			//�񕜏���
			player->Hit(items[itemCount]);//���̏����̒��ŃA�C�e���̒��̋@�\�����������

			delete items[itemCount];
			items[itemCount];
			
			//�z���O�ɋl�߂�
			for (int i = itemCount; i < 10 - 1; i++)
			{
				if (items[i] == nullptr)
				{
					break;
				}
				items[i] = items[i + 1];
				items[i + 1] = nullptr;
			}
			itemCount--;
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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;//items[i]��nullptr�Ȃ�break�Ŕ����鏈��
		}
		items[i]->Draw();//nullptr�Ȃ�Draw�������Ăяo������
	}

}

//�V�[���̕ύX����
AbstractScene* GameMainScene::ChangeScene()
{
	return this;
}