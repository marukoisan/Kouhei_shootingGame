#pragma once
#include "ItemBase.h"
class Recovery : public ItemBase
{
private:
	int volume;//回復

public:
	//コンストラクタ
	Recovery(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	int GetVolume();//volumeの値を取得する
};

