#include "CharaBase.h"


CharaBase::CharaBase(T_Location locaion, float radius, T_Location speed)
	: SphereCollider(locaion, radius), speed(speed),image(nullptr),bullets(nullptr)//コンストラクタ
{

}

BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}