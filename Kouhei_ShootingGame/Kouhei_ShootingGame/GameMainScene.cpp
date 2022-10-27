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