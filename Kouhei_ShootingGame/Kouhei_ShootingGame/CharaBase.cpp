#include "CharaBase.h"


CharaBase::CharaBase(T_Location locaion, float radius, T_Location speed)
	: SphereCollider(locaion, radius), speed(speed),image(nullptr),bullets(nullptr)//�R���X�g���N�^
{

}

BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}