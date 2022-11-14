#include "DxLib.h"
#include "Player.h"
#include"StraightBullets.h"
#include"KeyManager.h"
#include"Recovery.h"

Player::Player(T_Location location):
	CharaBase(location, 10.f, T_Location{2,2}), score(0),life(10)
{
	bullets = new BulletsBase*[30];//������30���o����悤�ɂȂ�
	for (int i = 0; i < 30; i++)//���g��nullptr�����Ă���
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	T_Location newLocation = GetLocation();
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))//�L�[�{�[�h�p���}�E�X�p�������ƌ���
	{
		newLocation.y -= speed.y;//��
	}
	
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))//��
	{
		newLocation.x -= speed.x;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_S))//��
	{
		newLocation.y += speed.y;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_D))//�E
	{
		newLocation.x += speed.x;
	}


	SetLocation(newLocation);

	int bulletCount;

	for (bulletCount = 0; bulletCount < 30; bulletCount++)//30��񂵂�nullptr�Ȃ�break
	{
		if (bulletCount == 30)
		{
			break;
		}

		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		//��ʊO�ɍs������e������
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);//�e���������߂̊֐�
			bulletCount--;//�e���o�Ȃ��Ȃ邱�Ƃ��Ȃ�������
			
		}
	
	}

	if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT))//���̔��ˊǗ������Ă��鍶�N���b�N�ŋ��𔭎�
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{0,2});
			
		}
		
	}
}

void Player::Draw()
{
#define _DEBUG_MODE_//���O��ς���Ƃ�_DEBUG_MODE_PLEYR�Ȃǁ@_MODE_�̌���ύX����

#ifdef _DEBUG_MODE_//�f�o�b�O���[�h���̏���������΂��̒��̏����ɒʂ�
	DrawFormatString(10, 10, GetColor(255, 255, 255), "life = %d", life);
#endif

	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}

void Player::Hit(int damage)
{

}

void Player::Hit(ItemBase* item)//�d�Ȃ�����A�C�e���Ɋւ���������炤
{
	switch (item->GetType())
	{
		case E_ITEM_TYPE::Heal:
		{


			Recovery* recovery = dynamic_cast<Recovery*>(item);//�L���X�g���邱�ƂŒl�������Ă���
			life += recovery->GetVolume();//�񕜏���
			break;
		}
		default:
			break;
	}
}

bool Player::LifeCheck()
{
	bool ret = (life <= 0);
	return ret;
}

int Player::GetScore()
{
	return score;
}

void Player::AddScore(int score)
{
	if (0 <= score)//0�ȏ�̐��l�����Z����
	{
		this->score += score;
	}
}