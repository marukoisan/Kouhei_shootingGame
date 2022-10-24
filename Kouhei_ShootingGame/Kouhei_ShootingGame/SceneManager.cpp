#include"SceneManager.h"
#include"KeyManager.h"

//メンバ変数の値を書き換えるのがアップデート関数
void SceneManager::Update()
{
	//現在のシーンのアップデートを実行
	KeyManager::Update();//Keymanagerのアップデート
    mScene->Update();
}

//描画処理のみを行う関数
void SceneManager::Draw() const
{
	mScene->Draw();//現在シーンの描画関数を実行
}

//シーンの変更処理
AbstractScene* SceneManager::ChangeScene()
{
	//シーンの変更処理呼び出し
	AbstractScene* nextScene = mScene->ChangeScene();

	//次のシーンが現在のシーンと別なら変更
	if (nextScene != mScene)
	{
		delete mScene;
		mScene = nextScene;
	}

	return nextScene;
}
