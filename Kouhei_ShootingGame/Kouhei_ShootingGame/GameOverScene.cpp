#include "GameOverScene.h"
#include"KeyManager.h"
#include"TitleScene.h"
#include"DxLib.h"

GameOverScene::GameOverScene()//コンストラクタ
{

}

void GameOverScene::Update()//アップデート処理(マイフレーム見ている)
{
	KeyManager::Update();//マイフレーム見たいから
}

void GameOverScene::Draw() const
{
	DrawFormatString(500, 500, 0xffffff, "GameOver");
	DrawFormatString(500, 700, 0xffffff, "Zキーを押してね");
}

AbstractScene* GameOverScene::ChangeScene()//次に行きたい場所のシーンを設定する
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Z))//キーボード用かマウス用かちゃんと見る
	{
		return new TitleScene();//行きたい場所
	}

	return this;//どの場所にも必要
}