#include "SphereCollider.h"
#include<math.h>

//�R���X�g���N�^
SphereCollider::SphereCollider(T_Location locaion, float radius)
{
	this->location.x = locaion.x;
	this->location.y = locaion.y;
	this->radius = radius;

}


//SphereCollider�^���m�̓����蔻��
bool SphereCollider::HitSphere(SphereCollider* collider)  const
{
	//��������A����ւ̃x�N�g�����v�Z����
	//�v�Z�ŏo�����x�N�g���̑傫����
	//�����Ƒ���̔��a�̍��v���
	//�x�N�g���̑傫������������΁A�������Ă���

	//�����Ƒ���Ƃ̊Ԃ̃x�N�g�����v�Z����
	//fabsf�ŕ����֌W�Ȃ��Ɍv�Z���ʂ��o�Ă���
	float vectorX = fabsf(this->location.x - collider->GetLocation().x);
	float vectorY = fabsf(this->location.y - collider->GetLocation().y);

	//�x�N�g���̑傫�����v�Z
	float vectorLength = (vectorX * vectorX) + (vectorY * vectorY);
	vectorLength = sqrtf(vectorLength);

	//�����Ƒ���̔��a�̍��v�l���v�Z
	float sumRadius = radius + collider->GetRadius();

	//�����蔻��̌��ʂ��i�[
	bool ret = (vectorLength < sumRadius);

	return ret;
}

	//���S���W�̐ݒ�
void SphereCollider::SetLocation(T_Location location)
{
	this->location.x = location.x;
	this->location.y = location.y;
	
}

	//���S���W�̎擾
T_Location SphereCollider::GetLocation() const
{
	return location;
}

	//���a�̎擾
float SphereCollider::GetRadius() const
{
		return radius;
}