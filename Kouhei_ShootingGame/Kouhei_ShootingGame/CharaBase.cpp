#include "CharaBase.h"


CharaBase::CharaBase(T_Location locaion, float radius, T_Location speed)
	: SphereCollider(locaion, radius), speed(speed),image(nullptr),bullets(nullptr)//�R���X�g���N�^
{

}

BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}

void CharaBase::DeleteBullet(int bulletNum)
{
	delete bullets[bulletNum];
	bullets[bulletNum] = nullptr;//�s����Ȓl�����Ȃ��悤�ɂ��邽�߂�nullptr��������

	//�z���O�ɋl�߂鏈��

	for (int i = bulletNum; i < (30 - 1); i++)
	{
		if (bullets[i + 1] == nullptr)
		{
			break;
		}
		bullets[i] = bullets[i + 1];
		bullets[i + 1] = nullptr;
	}

	//�z�����O���牜�ɋl�߂鏈��
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