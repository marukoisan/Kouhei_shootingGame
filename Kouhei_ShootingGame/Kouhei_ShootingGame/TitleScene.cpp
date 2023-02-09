#include "TitleScene.h"
#include"KeyManager.h"
#include"GameMainScene.h"
#include"DxLib.h"

TitleScene::TitleScene()//コンストラクタ
{

}

void TitleScene::Update()//アップデート処理(マイフレーム見ている)
{
	KeyManager::Update();//マイフレーム見たいから
}

void TitleScene::Draw() const //描画処理
{
	
	DrawFormatString(500, 200, 0xffffff, "ShootingGame");
	DrawFormatString(500, 500, 0xffffff, "Qキー押してStart");
}

AbstractScene* TitleScene::ChangeScene()//シーンの変更処理
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Q))//キーボード用かマウス用かちゃんと見る
	{
		return new GameMainScene();
	}

	return this;//どの場所にも必要
}