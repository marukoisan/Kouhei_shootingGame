#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"ItemBase.h"

class GameMainScene : public AbstractScene
{
private:
	Player* player;
	Enemy** enemy;
	ItemBase** items;
	int WaitTimer = 0;//初期値ゼロ

protected:
	//もう一体のエネミーを作ったら同じ感じにしてどちらともTUREだったらみたいな判定を作る
	int enemyDown = 0;//エネミーが倒されたら倒された分をカウントする
	int enemyVolume = 1;//ステージに出す分のエネミー分の数を設定しておく


public:
	GameMainScene();//コンストラクタ
	virtual ~GameMainScene() {};//デストラクタ

public:
	//継承先のデータはoverrideをする
	virtual void Update()override;//描画以外の更新を実装する 
	virtual void Draw() const override;//描画に関することを実装する

	int EnemyDown();//カウントされた数字を貰う
	int CountDown();//カウントされた数字をもらう
	virtual AbstractScene* ChangeScene() override;//シーンの変更処理


};

