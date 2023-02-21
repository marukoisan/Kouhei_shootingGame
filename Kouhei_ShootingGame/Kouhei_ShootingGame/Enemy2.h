#pragma once
#include "CharaBase.h"


//データベースからデータを引っ張ってくるような感じ
struct T_MoveInformation2
{
	int pattern;                //行動パターン
	T_Location targetLocation;  //座標
	int nextArrayNum;           //次の配列番号
	int waitTimeFlame;          //時間
	int attackType;             //攻撃の手段
};



class Enemy2 : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;//どれだけ弾を出したかの変数
	int BulletsNum;//弾の数

	//敵エネミーの動きのパターンを作成する
	//上で作成したstructの中身の数字をこの中で決めている
	T_MoveInformation2 moveInfo[5];



protected:
	int k = 0;//添え字用の変数
	int current = 0; //添え字用の変数
	int waitCount = 0; //時間用変数


public:
	Enemy2(T_Location location, float speed);//コンストラクタ

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;


	bool HpCheck();//ヒットポイントをチェックする関数
	int GetPoint();//ポイントをもらう関数
	void Move();//敵の移動処理
	void inputCSV();//CSVファイルの読込み
};