#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"
#include"RotationBullets.h"

//�ړ����鏇��(���W)�̔z��
T_Location locations[4] = {

	{640,-40},
	{640,100},
	{1100,100},
	{100,100}
};

Enemy::Enemy(T_Location location, float speed)
	: CharaBase(location, 20.f, T_Location{ 0,0 })
	, hp(10), point(10),shotNum(0)
{
	bullets = new BulletsBase * [30];//������30���o����悤�ɂȂ�
	for (int i = 0; i < 30; i++)//���g��nullptr�����Ă���
	{
		bullets[i] = nullptr;
	}

	float x = 1;
	float y = 1;

	this->speed = T_Location{ (speed * x), (speed * y) };

}


void Enemy::Update()
{
	/*T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);*/

	T_Location newLocation = locations[0];
	newLocation.y += speed.y;
	SetLocation(newLocation);
	
	T_Location  locations[1];
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
		//��]����e
		bullets[bulletCount] = new RotationBullets(GetLocation(),2.f,(20 * shotNum));
		shotNum++;

		//T_Location�Œe�̕����ƃX�s�[�h�����߂Ă���
		//bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
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
