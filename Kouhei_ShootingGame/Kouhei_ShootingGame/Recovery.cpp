#include "Recovery.h"
#include"DxLib.h"

Recovery::Recovery(T_Location location)
	: ItemBase(location, 5.f, E_ITEM_TYPE::Heal, T_Location{ 0,0.5 }), volume(2)
{

}

void Recovery::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}
void Recovery::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 150, 200));
}

int Recovery::GetVolume()//Volume‚Ì’l‚ðŽæ“¾‚·‚é
{
	return volume;
}