#include "GameMainScene.h"
#include"GameClearScene.h"
#include"GameOverScene.h"
#include"KeyManager.h"
#include"DxLib.h"
#include"Recovery.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,400 };//初期位置を決める場所
	player = new Player(location);

	enemy = new Enemy* [10];//エネミーの配列を作成、初期化処理
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;//配列の中にnullptrを入れる
	}
	//enemy[0]番目に入れている
	//enemy[0] = new Enemy(T_Location{ 200,0 });//初期位置を決める場所
	enemy[0] = new Enemy(T_Location{ 640,0},1);//初期位置を決める場所
	items = new ItemBase* [10];//アイテムの初期化処理
	for (int i = 0; i < 10; i++)
	{
		items[i] = nullptr;//配列の中にnullptrを入れる
	}

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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;//items[i]がnullptrならbreakで抜ける処理
		}
		items[i]->Update();//nullptrならUpdate処理を呼び出す処理
	}

	
	BulletsBase** bullet = player->GetBullets();
	//エネミーにダメージを与えるfor文
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
					EnemyDown();//関数の呼び出し

					//アイテムの処理

					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new Recovery(enemy[enemyCount]->GetLocation());//敵が死んだ座標にアイテムを出現させる
							break;//breakで抜ける
						}

					}

					//スコアの加算
					player->AddScore(enemy[enemyCount]->GetPoint());

					//エネミーの削除
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;//不特定な値を見ないようにするためにnullptrを代入する
					
					//配列を前に詰める処理
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

	//プレイヤーにダメージを与えるfor文
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}

		BulletsBase** bullet = enemy[enemyCount]->GetBullets();//エネミーが配列なのでエネミー一つ一つのデータを持ってくるため

		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}

			if (player->HitSphere(bullet[i]))
			{
				//エネミーにプレイヤーの弾がヒット
				// 
				// 
				// プレイヤーにダメージを与えます
				player->Hit(bullet[i]->GetDamage());

				//弾を削除します
				enemy[enemyCount]->DeleteBullet(i);
				i--;


				// 
				//プレイヤーのLifeが0以下
				if (player->LifeCheck())
				{
					//アイテムの処理

					//for (int i = 0; i < 10; i++)
					//{
					//	if (items[i] == nullptr)
					//	{
					//		items[i] = new Recovery(enemy[enemyCount]->GetLocation());//敵が死んだ座標にアイテムを出現させる
					//		break;//breakで抜ける
					//	}

					//}

					////スコアの加算
					//player->AddScore(enemy[enemyCount]->GetPoint());

					//エネミーの削除
					/*delete player;
					player = nullptr*/;//不特定な値を見ないようにするためにnullptrを代入する

					//配列を前に詰める処理
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

	//アイテムの取得削除
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		
		if (items[itemCount] == nullptr)
		{
			break;//nullptrなら処理を抜ける
		}

		if (items[itemCount]->HitSphere(player) == true)//アイテムとプレイヤーがぶつかったか? 
		{

			//回復処理
			player->Hit(items[itemCount]);//この処理の中でアイテムの中の機能が発揮される

			delete items[itemCount];
			items[itemCount];
			
			//配列を前に詰める
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

	KeyManager::Update();//GOTO
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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;//items[i]がnullptrならbreakで抜ける処理
		}
		items[i]->Draw();//nullptrならDraw処理を呼び出す処理
	}

}

int GameMainScene::EnemyDown()//カウントされた数字をもらう
{
	enemyDown++;
	return enemyDown;//プラス1された状態のはず…
}

//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene()
{
	
	if (enemyDown == enemyVolume)//倒した数と設定した数が一緒になるか
	{
		return new GameClearScene();//行きたい場所
	}

	if (player->LifeCheck())//プレイヤーの体力が0以下になったら
	{
		return new GameOverScene();//行きたい場所
	}

	return this;
}

