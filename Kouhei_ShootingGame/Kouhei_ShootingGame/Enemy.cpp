#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"

Enemy::Enemy(T_Location location)
	: CharaBase(location, 20.f, T_Location{ 0,0.5 })
	, hp(10), point(10)
{
	bullets = new BulletsBase * [30];//������30���o����悤�ɂȂ�
	for (int i = 0; i < 30; i++)//���g��nullptr�����Ă���
	{
		bullets[i] = nullptr;
	}
}


void Enemy::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);


	//�G�l�~�[�̒e�̏���

	int bulletCount;

	for (bulletCount = 0; bulletCount < 30; bulletCount++)//30��񂵂�nullptr�Ȃ�break
	{
		if (bulletCount == 30)
		{
			break;
		}

		if (bullets[bulletCount] == nullptr)
		{
			break;
		}

		bullets[bulletCount]->Update();

		//��ʊO�ɍs������e������
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);//�e���������߂̊֐�
			bulletCount--;//�e���o�Ȃ��Ȃ邱�Ƃ��Ȃ�������

		}

	}

	if (bulletCount < 30 && bullets[bulletCount] == nullptr)
	{
		bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,-2 });
	}

	
}

void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	//�G�l�~�[�̒e�̕`��

	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}

}

void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0;
		}
	}
}

bool Enemy::HpCheck()//�q�b�g�|�C���g���`�F�b�N����֐�
{
	bool ret = (hp <= 0);
	return ret;
}

int Enemy::GetPoint()//�|�C���g�����炤�֐�
{
	return point;
}
