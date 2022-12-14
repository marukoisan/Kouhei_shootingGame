#pragma once
#include "CharaBase.h"
class Player : public CharaBase
{
private:
	int score;
	int life;

public:
	Player(T_Location location);//コンストラクタ

public:
	void Update() override;
	void Draw() override;
	void Hit(int damage) override;
	void Hit(class ItemBase* item);//アイテムに関する関数
	bool LifeCheck();//ライフをチェックする関数
	int GetScore();//スコアを返す関数
	void AddScore(int score);//現在のスコア

};

