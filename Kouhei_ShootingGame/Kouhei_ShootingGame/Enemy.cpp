#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"
#include"RotationBullets.h"

//移動する順番(座標)の配列
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
	bullets = new BulletsBase * [30];//同時に30発出せるようになる
	for (int i = 0; i < 30; i++)//中身をnullptrを入れている
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
		//回転する弾
		bullets[bulletCount] = new RotationBullets(GetLocation(),2.f,(20 * shotNum));
		shotNum++;

		//T_Locationで弾の方向とスピードを決めている
		//bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
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
