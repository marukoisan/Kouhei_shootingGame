#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"
#include"RotationBullets.h"
#include"RingBullets.h"

//移動する順番(座標)の配列
//T_Location locations[4] = {
//
//	{640,0},
//	{640,100},
//	{1100,100},
//	{100,100}
//};



//移動する順番(座標)の配列
//T_Location locations[3] = {
//
//	{   640,150},
//	{1000.4,150},
//	{  180.2,150},
//};

//場所をループさせるための配列
//int next[3] = {
//	1,
//	2,
//	1
//};

void Enemy::inputCSV()
{
	FILE* fp; //FILE型構造体
	errno_t error; // fopen_sのエラー確認

	error = fopen_s(&fp, "EnemyData/EnemyMove1.csv", "r");//データを置いた場所をしっかりと指定する
	//CSVファイルをヴィジュアルスタジオに読み込ませるときはスペースなどは使わないようにする

	if (error != 0)//ゼロじゃない時
	{
		//エラー発生
		return;
	}
	else
	{
		//ファイルを開いた
		char line[100];//一行
		//while (fgets(line, 100, fp) != NULL)
		for (int i = 0; fgets(line, 100, fp) != NULL; i++)//100の所は一行に100文字分を見るという意味
		{
			sscanf_s(line, "%d, %f, %f, %d, %d, %d",//lineが一行を見る : %の所は整数か少数をとってくるもの : 最後は構造体に当てはめる
				&moveInfo[i].pattern,
				&moveInfo[i].targetLocation.x,
				&moveInfo[i].targetLocation.y,
				&moveInfo[i].nextArrayNum,
				&moveInfo[i].waitTimeFlame,
				&moveInfo[i].attackType
			);
		}

		return;
	}



	fclose(fp); //ファイルを閉じる
}

Enemy::Enemy(T_Location location, float speed)
	: CharaBase(location, 20.f, T_Location{ 0,0 })
	, hp(10), point(10), shotNum(0)
{
	bullets = new BulletsBase * [30];//同時に30発出せるようになる
	for (int i = 0; i < 30; i++)//中身をnullptrを入れている
	{
		bullets[i] = nullptr;
	}

	inputCSV();//CSVファイルの初期化

	float x = 1;
	float y = 1;

	this->speed = T_Location{ (speed * x), (speed * y) };

}


void Enemy::Update()
{
	switch (moveInfo[current].pattern)//currentが配列の番号、パターンが行動のパターン。左に行ったり右に行ったり
	{
		case 0:
			Move();//移動処理
			break;

		case 1:
			waitCount++;//waitCountをたしていく

			if (moveInfo[current].waitTimeFlame <= waitCount)//設定されたwaitTimeFlameと足されていくwaitCountを比べる
			{
				waitCount = 0;//ゼロを代入する
				current = moveInfo[current].nextArrayNum;//現在参照しているもののnextArrayNumを参照してcurrentに代入する
			}
			break;

		default:
			break;
	}
	

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

	if (moveInfo[current].attackType != 0)//attackTypeがゼロじゃない時
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			////回転する弾
			//bullets[bulletCount] = new RotationBullets(GetLocation(), 2.f, (20 * shotNum));
			//shotNum++;
			////T_Locationで弾の方向とスピードを決めている
			////bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });

			if (moveInfo[current].attackType == 1)//1だったら
			{
				//1だったらまっすぐ飛ぶ弾
				bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
			}
			//else if (moveInfo[current].attackType == 2)//2だったら
			//{
			//	//回転する弾 2だったら回転して飛ぶ弾
			//	shotNum++;
			//	bullets[bulletCount] = new RotationBullets(GetLocation(), 2.f, (20 * shotNum));
			//
			//}
			else if (moveInfo[current].attackType == 2)
			{				
				shotNum = 1;
				BulletsNum++;
				bullets[bulletCount] = new RingBullets(GetLocation(), 2.f,BulletsNum * (10 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, BulletsNum * (50 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, BulletsNum * (90 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, BulletsNum * (140 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, BulletsNum * (190 * shotNum));



			  /*bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, (60 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, (70 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, (80 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, (90 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 2.f, (100 * shotNum));*/
					

			}
		}
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
	if ((nextLocation.y == moveInfo[current].targetLocation.y) &&
		(nextLocation.x == moveInfo[current].targetLocation.x))
	{
		current = moveInfo[current].nextArrayNum;//次の座標を入れる処理
		return;
	}
	else//目的地に到達していない時(yバージョン)
	{
		//今いる座標と目的の座標にいなかったら
		if (nextLocation.y != moveInfo[current].targetLocation.y)
		{
			//今いる座標と目的の座標を比べて今いる座標が小さかったら
			if (nextLocation.y < moveInfo[current].targetLocation.y)
			{
				////プラスしていく(下に移動する)
				nextLocation.y += speed.y;

				//現在の座標が行きたい座標を超えてしまったら
				if ((GetLocation().y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y <= nextLocation.y))
				{
					//新しい座標に行きたい座標を代入する
					nextLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
		else//今いる座標と目的の座標を比べて今いる座標が大きかったら
		{
			//マイナスしていく(上に移動する)
			nextLocation.y -= speed.y;

			//現在の座標が行きたい座標を超えてしまったら
			if ((nextLocation.y <= moveInfo[current].targetLocation.y) &&
				(moveInfo[current].targetLocation.y <= GetLocation().y))
			{
				//新しい座標に行きたい座標を代入する
				nextLocation.y = moveInfo[current].targetLocation.y;
			}
		}



		//今いる座標と目的の座標にいなかったら
		if (nextLocation.x != moveInfo[current].targetLocation.x)
		{
			//今いる座標と行きたい座標を比べて小さかったら
			if (nextLocation.x < moveInfo[current].targetLocation.x)
			{
				//プラスしていく(右に移動する)
				nextLocation.x += speed.x;

				//現在の座標が行きたい座標を超えてしまったら
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= nextLocation.x))
				{
					//新しい座標に行きたい座標を代入する
					nextLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			else//今いる座標と行きたい座標を比べて大きかったら
			{
				//マイナスしていく(左に移動する)
				nextLocation.x -= speed.x;

				//現在の座標が行きたい座標を超えてしまったら
				if ((nextLocation.x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= GetLocation().x))
				{
					//新しい座標に行きたい座標を代入する
					nextLocation.x = moveInfo[current].targetLocation.x;
				}
			}

		}

	}

	//座標を更新している
	SetLocation(nextLocation);
}