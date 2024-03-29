#pragma once
#include"AbstractScene.h"
class EndScene : public AbstractScene
{
private:
	int WaitTimer = 0;//初期値ゼロ

public:
	EndScene();//コンストラクタ
	virtual ~EndScene() {};//デストラクタ

	virtual void Update()override;//描画以外の更新を実装する 
	virtual void Draw() const override;//描画に関することを実装する
	virtual AbstractScene* ChangeScene() override;//シーンの変更処理
};

