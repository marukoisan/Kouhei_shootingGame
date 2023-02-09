#include "GameClearScene.h"
#include"TitleScene.h"
#include"DxLib.h"
#include"KeyManager.h"

GameClearScene::GameClearScene()//コンストラクタ
{

}

void GameClearScene::Update()//アップデート処理(マイフレーム見ている)
{
	KeyManager::Update();//マイフレーム見たいから
}

void GameClearScene::Draw() const//描画処理
{
	DrawFormatString(500, 500, 0xffffff, "GameClear");
	DrawFormatString(500, 700, 0xffffff, "Zキーを押してね");
}

AbstractScene* GameClearScene::ChangeScene()
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Z))//キーボード用かマウス用かちゃんと見る
	{
		return new TitleScene();//行きたい場所
	}

	return this;//どの場所にも必要
}