#pragma once
#include "ItemBase.h"
class Recovery : public ItemBase
{
private:
	int volume;//‰ñ•œ

public:
	virtual void Update() override;
	virtual void Draw() override;
	int GetVolume();//volume‚Ì’l‚ðŽæ“¾‚·‚é
};

