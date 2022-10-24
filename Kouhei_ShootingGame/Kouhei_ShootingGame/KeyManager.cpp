#include"DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];//	2つとも初期化処理
char KeyManager::nowKey[256];
int KeyManager::oldMouse;//マウスの入力値の変数
int KeyManager::nowMouse;

void KeyManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldKey[i] = nowKey[i];
	}

	if (GetHitKeyStateAll(nowKey) == -1)
	{
		throw - 1;
	}

	oldMouse = nowMouse;
	nowMouse = GetMouseInput();//マウスの入力処理
}

bool KeyManager::OnKeyClicked(int key)//押されている瞬間
{
	bool ret = ((nowKey[key] == 1) && (oldKey[key] != 1));
	return ret;
}

bool KeyManager::OnKeyReleased(int key)//離した瞬間
{
	bool ret = ((nowKey[key] == 0) && (oldKey[key] == 1));//!=1でも==0でも大丈夫
	return ret;
}

bool KeyManager::OnKeyPressed(int key)//押された間
{
	bool ret = (nowKey[key] == 1);
	return ret;
}



bool KeyManager::OnMouseClicked(int key)//押されている瞬間
{
	bool ret = ((nowMouse & key) && (~oldMouse & key));
	return ret;
}

bool KeyManager::OnMouseReleased(int key)//離した瞬間
{
	bool ret = ((~nowMouse & key) && (oldMouse & key));
	return ret;
}

bool KeyManager::OnMousePressed(int key)//押された間
{
	bool ret = (nowMouse & key);
	return ret;
}