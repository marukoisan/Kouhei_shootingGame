#include "DxLib.h"
#include "Player.h"
#include"StraightBullets.h"
#include"KeyManager.h"

Player::Player(T_Location location):
	CharaBase(location, 10.f, T_Location{2,2}), score(0),life(2)
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

		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		//画面外に行ったら弾を消す
		if (bullets[bulletCount]->isScreenOut())
		{
			delete bullets[bulletCount];
			bullets[bulletCount] = nullptr;//不特定な値を見ないようにするためにnullptrを代入する

			//配列を前に詰める処理
			/*if (bullets[bulletCount] == nullptr)
			{
				w = bullets[bulletCount + 1]途中並び替えはしなくて大丈夫

			}*/
		}
	}

	if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT))//球の発射管理をしている左クリックで球を発射
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

void Player::Hit()
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