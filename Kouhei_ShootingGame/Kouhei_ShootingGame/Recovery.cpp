#include "Recovery.h"
#include"DxLib.h"

//�R���X�g���N�^���쐬����

void Recovery::Update()
{

}
void Recovery::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));
}

int Recovery::GetVolume()//Volume�̒l���擾����
{
	return volume;
}