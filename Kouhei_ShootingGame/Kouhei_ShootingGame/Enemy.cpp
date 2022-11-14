#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"

Enemy::Enemy(T_Location location)
	: CharaBase(location, 20.f, T_Location{ 0,0.5 })
	, hp(10), point(10)
{
	bullets = new BulletsBase * [30];//同時に30発出せるようになる
	for (int i = 0; i < 30; i++)//中身をnullptrを入れている
	{
		bullets[i] = nullptr;
	}
}


void Enemy::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);


	//エネミーの弾の処理

	int bulletCount;

	for (bulletCount = 0; bulletCount < 30; bulletCount++)//30回回してnullptrならbreak
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

		//画面外に行ったら弾を消す
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);//弾を消すための関数
			bulletCount--;//弾が出なくなることをなくす処理

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

	//エネミーの弾の描画

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

bool Enemy::HpCheck()//ヒットポイントをチェックする関数
{
	bool ret = (hp <= 0);
	return ret;
}

int Enemy::GetPoint()//ポイントをもらう関数
{
	return point;
}
