#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"StraightBullets.h"
#include"RotationBullets.h"

//�ړ����鏇��(���W)�̔z��
//T_Location locations[4] = {
//
//	{640,0},
//	{640,100},
//	{1100,100},
//	{100,100}
//};

//�f�[�^�x�[�X����f�[�^�����������Ă���悤�Ȋ���
struct MoveInformation
{
	T_Location targetLocation;//���W
	int pattern;//�p�^�[��
	int next;//���̂���
	int waitTimeFlame;//����
	int attackPattern;//�U���̎�i
};

//�G�G�l�~�[�̓����̃p�^�[�����쐬����
MoveInformation moveInfo[10] = {
	{   640, 150, 0, 1,   0, 0},
	{1200.4, 150, 0, 2,   0, 0},
	{     0,   0, 1, 3, 180, 1},
	{  80.2, 150, 0, 4,   0, 2},
	{     0,   0, 1, 5, 180, 1},
	{1200.4, 150, 0, 2,   0, 1},
}

//�ړ����鏇��(���W)�̔z��
T_Location locations[3] = {

	{   640,150},
	{1200.4,150},
	{  80.2,150},
};

//�ꏊ�����[�v�����邽�߂̔z��
int next[3] = {
	1,
	2,
	1
};

int current = 0;

Enemy::Enemy(T_Location location, float speed)
	: CharaBase(location, 20.f, T_Location{ 0,0 })
	, hp(10), point(10), shotNum(0)
{
	bullets = new BulletsBase * [30];//������30���o����悤�ɂȂ�
	for (int i = 0; i < 30; i++)//���g��nullptr�����Ă���
	{
		bullets[i] = nullptr;
	}

	float x = 1;
	float y = 1;

	this->speed = T_Location{ (speed * x), (speed * y) };
}


void Enemy::Update()
{
	Move();

	////�V�������W�ɍ�������W��������
	//T_Location newLocation = GetLocation();

	//if (k < 4)//4�ȉ��̎��ɉ��̏����ɓ���
	//{   //��������Wxy�ƁA�s���������Wxy���ꏏ���ǂ������肵�Ă���
	//	if (GetLocation().x == locations[k].x && GetLocation().y == locations[k].y)
	//	{
	//		k++;//�ꏏ��������v���X����
	//	}
	//	else//�������ړI�̏ꏊ�Ɉړ�����
	//	{   
	//		//��������Wx�ƍs���������Wx���Ⴄ�Ƃ�
	//		if (GetLocation().x != locations[k].x)
	//		{   
	//			//��������W�ƍs���������W���ׂď�����������
	//			if (GetLocation().x < locations[k].x)
	//			{
	//				//�v���X���Ă���(�E�Ɉړ�����)
	//				newLocation.x += speed.x;
	//				SetLocation(newLocation);
	//			}
	//			//��������W�ƍs���������W���ׂđ傫��������
	//			else if (GetLocation().x > locations[k].x) {
	//				//�}�C�i�X���čs��(���Ɉړ�����)
	//				newLocation.x -= speed.x;
	//				SetLocation(newLocation);
	//			}

	//		}

	//		//��������Wy�ƍs���������Wy���Ⴄ�Ƃ�
	//		if (GetLocation().y != locations[k].y)
	//		{
	//			//��������W�ƍs���������W���ׂď�����������
	//			if (GetLocation().y < locations[k].y)
	//			{
	//				//�v���X���Ă���(���Ɉړ�����)
	//				newLocation.y += speed.y;
	//				SetLocation(newLocation);
	//			}
	//			//��������W�ƍs���������W���ׂđ傫��������
	//			else if (GetLocation().y > locations[k].y) {
	//				//�}�C�i�X���čs��(��Ɉړ�����)
	//				newLocation.y -= speed.y;
	//				SetLocation(newLocation);
	//			}


	//		}

	//		//���݂̍��W���s���������W�𒴂��Ă��܂�����
	//		if (GetLocation().x > locations[k].x)
	//		{
	//			//�V�������W�ɍs���������W��������
	//			newLocation.x = locations[k].x;
	//		}
	//		if (GetLocation().y > locations[k].y)
	//		{
	//			newLocation.y = locations[k].y;
	//		}
	//	}
	//}
	//else
	//{
	//	//�z��2�Ԃ�����������2��������
	//	k = 2;
	//}


	//�G�l�~�[�̒e�̏���

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

	if (bulletCount < 30 && bullets[bulletCount] == nullptr)
	{
		//��]����e
		bullets[bulletCount] = new RotationBullets(GetLocation(), 2.f, (20 * shotNum));
		shotNum++;

		//T_Location�Œe�̕����ƃX�s�[�h�����߂Ă���
		//bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
	}


}

void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	//�G�l�~�[�̒e�̕`��

	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}

}

void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0;
		}
	}
}

bool Enemy::HpCheck()//�q�b�g�|�C���g���`�F�b�N����֐�
{
	bool ret = (hp <= 0);
	return ret;
}

int Enemy::GetPoint()//�|�C���g�����炤�֐�
{
	return point;
}


void Enemy::Move()
{
	//��������W���ꎞ�I�ɕۑ����Ă���
	T_Location nextLocation = GetLocation();

	//�s�������ꏊ�̏�����(x.y�������ꏊ�ɓ��B���Ă�����)
	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		current = next[current];//���̍��W�����鏈��
	}
	else//�ړI�n�ɓ��B���Ă��Ȃ���(y�o�[�W����)
	{
		//��������W�ƖړI�̍��W�ɂ��Ȃ�������
		if (nextLocation.y != locations[current].y)
		{
			//��������W�ƖړI�̍��W���ׂč�������W��������������
			if (nextLocation.y < locations[current].y)
			{
				////�v���X���Ă���(���Ɉړ�����)
				nextLocation.y += speed.y;

				//���݂̍��W���s���������W�𒴂��Ă��܂�����
				if ((GetLocation().y <= locations[current].y) &&
					(locations[current].y <= nextLocation.y))
				{
					//�V�������W�ɍs���������W��������
					nextLocation.y = locations[current].y;
				}
			}
		}
		else//��������W�ƖړI�̍��W���ׂč�������W���傫��������
		{
			//�}�C�i�X���Ă���(��Ɉړ�����)
			nextLocation.y -= speed.y;

			//���݂̍��W���s���������W�𒴂��Ă��܂�����
			if ((nextLocation.y <= locations[current].y) &&
				(locations[current].y <= GetLocation().y))
			{
				//�V�������W�ɍs���������W��������
				nextLocation.y = locations[current].y;
			}
		}



		//��������W�ƖړI�̍��W�ɂ��Ȃ�������
		if (nextLocation.x != locations[current].x)
		{
			//��������W�ƍs���������W���ׂď�����������
			if (nextLocation.x < locations[current].x)
			{
				//�v���X���Ă���(�E�Ɉړ�����)
				nextLocation.x += speed.x;

				//���݂̍��W���s���������W�𒴂��Ă��܂�����
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					//�V�������W�ɍs���������W��������
					nextLocation.x = locations[current].x;
				}
			}
			else//��������W�ƍs���������W���ׂđ傫��������
			{
				//�}�C�i�X���Ă���(���Ɉړ�����)
				nextLocation.x -= speed.x;

				//���݂̍��W���s���������W�𒴂��Ă��܂�����
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					//�V�������W�ɍs���������W��������
					nextLocation.x = locations[current].x;
				}
			}

		}

	}

	//���W���X�V���Ă���
	SetLocation(nextLocation);
}