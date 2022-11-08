#include "DxLib.h"
#include "Player.h"
#include"StraightBullets.h"
#include"KeyManager.h"

Player::Player(T_Location location):
	CharaBase(location, 10.f, T_Location{2,2}), score(0),life(2)
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
			bullets[bulletCount] = new StraightBullets(GetLocation());
			
		}
		
	}
}

void Player::Draw()
{
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