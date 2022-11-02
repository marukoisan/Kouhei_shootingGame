#include "CharaBase.h"


CharaBase::CharaBase(T_Location locaion, float radius, T_Location speed)
	: SphereCollider(locaion, radius), speed(speed),image(nullptr),bullets(nullptr)//コンストラクタ
{

}

BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}

void CharaBase::DeleteBullet(int bulletNum)
{
	delete bullets[bulletNum];
	bullets[bulletNum] = nullptr;//不特定な値を見ないようにするためにnullptrを代入する

	//配列を前に詰める処理

	for (int i = bulletNum; i < (30 - 1); i++)
	{
		if (bullets[i + 1] == nullptr)
		{
			break;
		}
		bullets[i] = bullets[i + 1];
		bullets[i + 1] = nullptr;
	}

	//配列を手前から奥に詰める処理
	/*for (int i = bulletNum + 1; i < 30; i++)
	{
		if (bulletNum[i] == nullptr)
		{
			break;
		}
		bulletNum[i - 1] = bulletNum[i];
		bulletNum[i] = nullptr;
	}*/
}