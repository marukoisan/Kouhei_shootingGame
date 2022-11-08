#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,400 };//初期位置を決める場所
	player = new Player(location);

	enemy = new Enemy* [10];//エネミーの配列を作成
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;//配列の中にnullptrを入れる
	}
	//enemy[0]番目に入れている
	enemy[0] = new Enemy(T_Location{ 200,0 });//初期位置を決める場所
}


//描画以外の更新を実装する 
void GameMainScene::Update()
{
	player->Update();
	
	int enemyCount;
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;//enemy[enemyCount]がnullptrならbreakで抜ける処理
		}
		enemy[enemyCount]->Update();//nullptrならUpdate処理を呼び出す処理
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
				//エネミーにプレイヤーの弾がヒット
				// 
				// 
				// エネミーにダメージを与えます
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

				//弾を削除します
				player->DeleteBullet(bulletCount);
				bulletCount--;

				// 
				//エネミーのhpが0以下
				if (enemy[enemyCount]->HpCheck())
				{

					//スコアの加算
					player->AddScore(enemy[enemyCount]->GetPoint());

					//エネミーの削除
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;//不特定な値を見ないようにするためにnullptrを代入する
					
					//配列を前に詰める処理
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

//描画に関することを実装する
void GameMainScene::Draw() const
{
	player->Draw();

	
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;//enemy[enemyCount]がnullptrならbreakで抜ける処理
		}
		enemy[enemyCount]->Draw();//nullptrならDraw処理を呼び出す処理
	}
}

//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene()
{
	return this;
}