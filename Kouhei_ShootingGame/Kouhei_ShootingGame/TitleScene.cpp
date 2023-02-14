#include "TitleScene.h"
#include"KeyManager.h"
#include"GameMainScene.h"
#include"EndScene.h"
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
	
	DrawFormatString(200, 200, 0xffffff, "ShootingGame");
	DrawFormatString(800, 200, 0xffffff, "GameEnd");
	DrawFormatString(200, 500, 0xffffff, "Qキー押してStart");
	DrawFormatString(800, 500, 0xffffff, "Xキー押してEnd");
}

AbstractScene* TitleScene::ChangeScene()//シーンの変更処理
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Q))//キーボード用かマウス用かちゃんと見る
	{
		return new GameMainScene();//ゲームメインへ遷移
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_X))//キーボード用かマウス用かちゃんと見る
	{
		return new EndScene();//ゲームエンドへ遷移
	}

	return this;//どの場所にも必要
}