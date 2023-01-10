#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"
#include"RotationBullets.h"

//移動する順番(座標)の配列
//T_Location locations[4] = {
//
//	{640,0},
//	{640,100},
//	{1100,100},
//	{100,100}
//};

//データベースからデータを引っ張ってくるような感じ
struct MoveInformation
{
	T_Location targetLocation;//座標
	int pattern;//パターン
	int next;//次のもの
	int waitTimeFlame;//時間
	int attackPattern;//攻撃の手段
};

//敵エネミーの動きのパターンを作成する
MoveInformation moveInfo[10] = {
	{   640, 150, 0, 1,   0, 0},
	{1200.4, 150, 0, 2,   0, 0},
	{     0,   0, 1, 3, 180, 1},
	{  80.2, 150, 0, 4,   0, 2},
	{     0,   0, 1, 5, 180, 1},
	{1200.4, 150, 0, 2,   0, 1},
}

//移動する順番(座標)の配列
T_Location locations[3] = {

	{   640,150},
	{1200.4,150},
	{  80.2,150},
};

//場所をループさせるための配列
int next[3] = {
	1,
	2,
	1
};

int current = 0;

Enemy::Enemy(T_Location location, float speed)
	: CharaBase(location, 20.f, T_Location{ 0,0 })
	, hp(10), point(10), shotNum(0)
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
	Move();

	////新しい座標に今いる座標を代入する
	//T_Location newLocation = GetLocation();

	//if (k < 4)//4以下の時に下の処理に入る
	//{   //今いる座標xyと、行きたい座標xyが一緒かどうか判定している
	//	if (GetLocation().x == locations[k].x && GetLocation().y == locations[k].y)
	//	{
	//		k++;//一緒だったらプラスする
	//	}
	//	else//違ったら目的の場所に移動する
	//	{   
	//		//今いる座標xと行きたい座標xが違うとき
	//		if (GetLocation().x != locations[k].x)
	//		{   
	//			//今いる座標と行きたい座標を比べて小さかったら
	//			if (GetLocation().x < locations[k].x)
	//			{
	//				//プラスしていく(右に移動する)
	//				newLocation.x += speed.x;
	//				SetLocation(newLocation);
	//			}
	//			//今いる座標と行きたい座標を比べて大きかったら
	//			else if (GetLocation().x > locations[k].x) {
	//				//マイナスして行く(左に移動する)
	//				newLocation.x -= speed.x;
	//				SetLocation(newLocation);
	//			}

	//		}

	//		//今いる座標yと行きたい座標yが違うとき
	//		if (GetLocation().y != locations[k].y)
	//		{
	//			//今いる座標と行きたい座標を比べて小さかったら
	//			if (GetLocation().y < locations[k].y)
	//			{
	//				//プラスしていく(下に移動する)
	//				newLocation.y += speed.y;
	//				SetLocation(newLocation);
	//			}
	//			//今いる座標と行きたい座標を比べて大きかったら
	//			else if (GetLocation().y > locations[k].y) {
	//				//マイナスして行く(上に移動する)
	//				newLocation.y -= speed.y;
	//				SetLocation(newLocation);
	//			}


	//		}

	//		//現在の座標が行きたい座標を超えてしまったら
	//		if (GetLocation().x > locations[k].x)
	//		{
	//			//新しい座標に行きたい座標を代入する
	//			newLocation.x = locations[k].x;
	//		}
	//		if (GetLocation().y > locations[k].y)
	//		{
	//			newLocation.y = locations[k].y;
	//		}
	//	}
	//}
	//else
	//{
	//	//配列2番を見たいため2を代入する
	//	k = 2;
	//}


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
		bullets[bulletCount] = new RotationBullets(GetLocation(), 2.f, (20 * shotNum));
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


void Enemy::Move()
{
	//今いる座標を一時的に保存している
	T_Location nextLocation = GetLocation();

	//行きたい場所の条件式(x.yが同じ場所に到達していたら)
	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		current = next[current];//次の座標を入れる処理
	}
	else//目的地に到達していない時(yバージョン)
	{
		//今いる座標と目的の座標にいなかったら
		if (nextLocation.y != locations[current].y)
		{
			//今いる座標と目的の座標を比べて今いる座標が小さかったら
			if (nextLocation.y < locations[current].y)
			{
				////プラスしていく(下に移動する)
				nextLocation.y += speed.y;

				//現在の座標が行きたい座標を超えてしまったら
				if ((GetLocation().y <= locations[current].y) &&
					(locations[current].y <= nextLocation.y))
				{
					//新しい座標に行きたい座標を代入する
					nextLocation.y = locations[current].y;
				}
			}
		}
		else//今いる座標と目的の座標を比べて今いる座標が大きかったら
		{
			//マイナスしていく(上に移動する)
			nextLocation.y -= speed.y;

			//現在の座標が行きたい座標を超えてしまったら
			if ((nextLocation.y <= locations[current].y) &&
				(locations[current].y <= GetLocation().y))
			{
				//新しい座標に行きたい座標を代入する
				nextLocation.y = locations[current].y;
			}
		}



		//今いる座標と目的の座標にいなかったら
		if (nextLocation.x != locations[current].x)
		{
			//今いる座標と行きたい座標を比べて小さかったら
			if (nextLocation.x < locations[current].x)
			{
				//プラスしていく(右に移動する)
				nextLocation.x += speed.x;

				//現在の座標が行きたい座標を超えてしまったら
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					//新しい座標に行きたい座標を代入する
					nextLocation.x = locations[current].x;
				}
			}
			else//今いる座標と行きたい座標を比べて大きかったら
			{
				//マイナスしていく(左に移動する)
				nextLocation.x -= speed.x;

				//現在の座標が行きたい座標を超えてしまったら
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					//新しい座標に行きたい座標を代入する
					nextLocation.x = locations[current].x;
				}
			}

		}

	}

	//座標を更新している
	SetLocation(nextLocation);
}