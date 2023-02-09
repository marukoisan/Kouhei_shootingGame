#pragma once

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装すると楽
class AbstractScene
{
public:
	//デストラクタ
	virtual ~AbstractScene() {};

	//元となる継承先のデータは = 0にする
	// 関数の定義をする必要がないのと継承先で関数を定義させること徹底させるため

	//描画以外の更新を実装する 
	virtual void Update() = 0;

	//描画に関することを実装する 
	virtual void Draw() const = 0;

	//シーンの変更処理
	virtual AbstractScene* ChangeScene() = 0;
};