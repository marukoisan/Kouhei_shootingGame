#pragma once
#include "ItemBase.h"
class Recovery : public ItemBase
{
private:
	int volume;//��

public:
	//�R���X�g���N�^
	Recovery(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	int GetVolume();//volume�̒l���擾����
};

