#include "SphereCollider.h"
#include<math.h>

//�R���X�g���N�^
SphereCollider::SphereCollider(T_locaion locaion, float radius)
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
	float vectorX = fabsf(this->location.y - collider->GetLocation().y);

	//�x�N�g���̑傫�����v�Z
}

	//���S���W�̐ݒ�
void SphereCollider::SetLocation(T_locaion location)
{
	this->location.x = location.x;
	this->location.y = location.y;
	
}

	//���S���W�̎擾
T_locaion SphereCollider::GetLocation() const
{
	return location;
}

	//���a�̎擾
float SphereCollider::GetRadius() const
{
		return radius;
}