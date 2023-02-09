#pragma once
#include"AbstractScene.h"

class TitleScene : public AbstractScene //継承の形に注意
{
private:


public:
	TitleScene();//コンストラクタ
	virtual ~TitleScene() {};//デストラクタ

	virtual void Update()override;//描画以外の更新を実装する 
	virtual void Draw() const override;//描画に関することを実装する
	virtual AbstractScene* ChangeScene() override;//シーンの変更処理
};

