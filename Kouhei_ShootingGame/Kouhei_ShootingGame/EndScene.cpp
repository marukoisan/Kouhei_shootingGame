#include "EndScene.h"
#include"DxLib.h"
#include"KeyManager.h"

EndScene::EndScene()//コンストラクタ
{

}

void EndScene::Update()//アップデート処理(マイフレーム見ている)
{
	WaitTimer++;//マイフレーム値をプラスする
	if (WaitTimer >= 180)//WaitTimerが180以上になったら
	{
		DxLib_End();//ゲームを終了する
	}
}

void EndScene::Draw() const//描画処理
{
	SetFontSize(30);
	DrawFormatString(580, 270, 0xffffff, "GameEnd");
}

AbstractScene* EndScene::ChangeScene()
{

	return this;//どの場所にも必要
}