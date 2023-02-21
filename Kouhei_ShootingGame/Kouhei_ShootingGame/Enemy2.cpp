#include "Enemy2.h"
#include"DxLib.h"
#include"BulletsBase.h"
#include"StraightBullets.h"
#include"RingBullets.h"



void Enemy2::inputCSV()
{
	FILE* fp; //FILE�^�\����
	errno_t error; // fopen_s�̃G���[�m�F

	error = fopen_s(&fp, "EnemyData/EnemyMove2.csv", "r");//�f�[�^��u�����ꏊ����������Ǝw�肷��
	//CSV�t�@�C�������B�W���A���X�^�W�I�ɓǂݍ��܂���Ƃ��̓X�y�[�X�Ȃǂ͎g��Ȃ��悤�ɂ���

	if (error != 0)//�[������Ȃ���
	{
		//�G���[����
		return;
	}
	else
	{
		//�t�@�C�����J����
		char line[100];//��s
		//while (fgets(line, 100, fp) != NULL)
		for (int i = 0; fgets(line, 100, fp) != NULL; i++)//100�̏��͈�s��100������������Ƃ����Ӗ�
		{
			sscanf_s(line, "%d, %f, %f, %d, %d, %d",//line����s������ : %�̏��͐������������Ƃ��Ă������ : �Ō�͍\���̂ɓ��Ă͂߂�
				&moveInfo[i].pattern,
				&moveInfo[i].targetLocation.x,
				&moveInfo[i].targetLocation.y,
				&moveInfo[i].nextArrayNum,
				&moveInfo[i].waitTimeFlame,
				&moveInfo[i].attackType
			);
		}

		return;
	}



	fclose(fp); //�t�@�C�������
}

Enemy2::Enemy2(T_Location location, float speed)
	: CharaBase(location, 20.f, T_Location{ 0,0 })
	, hp(10), point(10), shotNum(0)
{
	bullets = new BulletsBase * [30];//������30���o����悤�ɂȂ�
	for (int i = 0; i < 30; i++)//���g��nullptr�����Ă���
	{
		bullets[i] = nullptr;
	}

	inputCSV();//CSV�t�@�C���̏�����

	float x = 1;
	float y = 1;

	this->speed = T_Location{ (speed * x), (speed * y) };

}


void Enemy2::Update()
{
	switch (moveInfo[current].pattern)//current���z��̔ԍ��A�p�^�[�����s���̃p�^�[���B���ɍs������E�ɍs������
	{
	case 0:
		Move();//�ړ�����
		break;

	case 1:
		waitCount++;//waitCount�������Ă���

		if (moveInfo[current].waitTimeFlame <= waitCount)//�ݒ肳�ꂽwaitTimeFlame�Ƒ�����Ă���waitCount���ׂ�
		{
			waitCount = 0;//�[����������
			current = moveInfo[current].nextArrayNum;//���ݎQ�Ƃ��Ă�����̂�nextArrayNum���Q�Ƃ���current�ɑ������
		}
		break;

	default:
		break;
	}


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

	if (moveInfo[current].attackType != 0)//attackType���[������Ȃ���
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			////��]����e
			//bullets[bulletCount] = new RotationBullets(GetLocation(), 2.f, (20 * shotNum));
			//shotNum++;
			////T_Location�Œe�̕����ƃX�s�[�h�����߂Ă���
			////bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });

			if (moveInfo[current].attackType == 1)//1��������
			{
				//1��������܂�������Ԓe
				bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
			}
			else if (moveInfo[current].attackType == 3)
			{
				//�g�U����e
				shotNum = 1;
				BulletsNum += 10;
				bullets[bulletCount] = new RingBullets(GetLocation(), 3.f, BulletsNum * (10 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 3.f, BulletsNum * (50 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 3.f, BulletsNum * (90 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 3.f, BulletsNum * (140 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 3.f, BulletsNum * (190 * shotNum));
				bullets[++bulletCount] = new RingBullets(GetLocation(), 3.f, BulletsNum * (240 * shotNum));
			}
		}
	}




}

void Enemy2::Draw()
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

void Enemy2::Hit(int damage)
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

bool Enemy2::HpCheck()//�q�b�g�|�C���g���`�F�b�N����֐�
{
	bool ret = (hp <= 0);
	return ret;

}

int Enemy2::GetPoint()//�|�C���g�����炤�֐�
{
	return point;
}

void Enemy2::Move()
{
	//��������W���ꎞ�I�ɕۑ����Ă���
	T_Location nextLocation = GetLocation();

	//�s�������ꏊ�̏�����(x.y�������ꏊ�ɓ��B���Ă�����)
	if ((nextLocation.y == moveInfo[current].targetLocation.y) &&
		(nextLocation.x == moveInfo[current].targetLocation.x))
	{
		current = moveInfo[current].nextArrayNum;//���̍��W�����鏈��
		return;
	}
	else//�ړI�n�ɓ��B���Ă��Ȃ���(y�o�[�W����)
	{
		//��������W�ƖړI�̍��W�ɂ��Ȃ�������
		if (nextLocation.y != moveInfo[current].targetLocation.y)
		{
			//��������W�ƖړI�̍��W���ׂč�������W��������������
			if (nextLocation.y < moveInfo[current].targetLocation.y)
			{
				////�v���X���Ă���(���Ɉړ�����)
				nextLocation.y += speed.y;

				//���݂̍��W���s���������W�𒴂��Ă��܂�����
				if ((GetLocation().y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y <= nextLocation.y))
				{
					//�V�������W�ɍs���������W��������
					nextLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
		else//��������W�ƖړI�̍��W���ׂč�������W���傫��������
		{
			//�}�C�i�X���Ă���(��Ɉړ�����)
			nextLocation.y -= speed.y;

			//���݂̍��W���s���������W�𒴂��Ă��܂�����
			if ((nextLocation.y <= moveInfo[current].targetLocation.y) &&
				(moveInfo[current].targetLocation.y <= GetLocation().y))
			{
				//�V�������W�ɍs���������W��������
				nextLocation.y = moveInfo[current].targetLocation.y;
			}
		}



		//��������W�ƖړI�̍��W�ɂ��Ȃ�������
		if (nextLocation.x != moveInfo[current].targetLocation.x)
		{
			//��������W�ƍs���������W���ׂď�����������
			if (nextLocation.x < moveInfo[current].targetLocation.x)
			{
				//�v���X���Ă���(�E�Ɉړ�����)
				nextLocation.x += speed.x;

				//���݂̍��W���s���������W�𒴂��Ă��܂�����
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= nextLocation.x))
				{
					//�V�������W�ɍs���������W��������
					nextLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			else//��������W�ƍs���������W���ׂđ傫��������
			{
				//�}�C�i�X���Ă���(���Ɉړ�����)
				nextLocation.x -= speed.x;

				//���݂̍��W���s���������W�𒴂��Ă��܂�����
				if ((nextLocation.x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= GetLocation().x))
				{
					//�V�������W�ɍs���������W��������
					nextLocation.x = moveInfo[current].targetLocation.x;
				}
			}

		}

	}

	//���W���X�V���Ă���
	SetLocation(nextLocation);
}