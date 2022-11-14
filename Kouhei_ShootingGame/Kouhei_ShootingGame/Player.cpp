#include "DxLib.h"
#include "Player.h"
#include"StraightBullets.h"
#include"KeyManager.h"
#include"Recovery.h"

Player::Player(T_Location location):
	CharaBase(location, 10.f, T_Location{2,2}), score(0),life(10)
{
	bullets = new BulletsBase*[30];//同時に30発出せるようになる
	for (int i = 0; i < 30; i++)//中身をnullptrを入れている
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	T_Location newLocation = GetLocation();
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))//キーボード用かマウス用かちゃんと見る
	{
		newLocation.y -= speed.y;//上
	}
	
	if (KeyManager::OnKeyPressed(KEY_INPUT_A))//左
	{
		newLocation.x -= speed.x;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_S))//下
	{
		newLocation.y += speed.y;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_D))//右
	{
		newLocation.x += speed.x;
	}


	SetLocation(newLocation);

	int bulletCount;

	for (bulletCount = 0; bulletCount < 30; bulletCount++)//30回回してnullptrならbreak
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

		//画面外に行ったら弾を消す
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);//弾を消すための関数
			bulletCount--;//弾が出なくなることをなくす処理
			
		}
	
	}

	if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT))//球の発射管理をしている左クリックで球を発射
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{0,2});
			
		}
		
	}
}

void Player::Draw()
{
#define _DEBUG_MODE_//名前を変えるとき_DEBUG_MODE_PLEYRなど　_MODE_の後ろを変更する

#ifdef _DEBUG_MODE_//デバッグモードこの処理があればこの中の処理に通る
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

void Player::Hit(ItemBase* item)//重なったらアイテムに関する情報をもらう
{
	switch (item->GetType())
	{
		case E_ITEM_TYPE::Heal:
		{


			Recovery* recovery = dynamic_cast<Recovery*>(item);//キャストすることで値を代入している
			life += recovery->GetVolume();//回復処理
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
	if (0 <= score)//0以上の数値を加算する
	{
		this->score += score;
	}
}