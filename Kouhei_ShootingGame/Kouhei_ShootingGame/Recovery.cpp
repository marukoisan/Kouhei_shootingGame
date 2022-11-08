#include "Recovery.h"
#include"DxLib.h"

//コンストラクタを作成する

void Recovery::Update()
{

}
void Recovery::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));
}

int Recovery::GetVolume()//Volumeの値を取得する
{
	return volume;
}