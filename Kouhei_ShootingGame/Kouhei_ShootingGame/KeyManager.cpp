#include"DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];//	2�Ƃ�����������
char KeyManager::nowKey[256];
int KeyManager::oldMouse;//�}�E�X�̓��͒l�̕ϐ�
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
	nowMouse = GetMouseInput();//�}�E�X�̓��͏���
}

bool KeyManager::OnKeyClicked(int key)//������Ă���u��
{
	bool ret = ((nowKey[key] == 1) && (oldKey[key] != 1));
	return ret;
}

bool KeyManager::OnKeyReleased(int key)//�������u��
{
	bool ret = ((nowKey[key] == 0) && (oldKey[key] == 1));//!=1�ł�==0�ł����v
	return ret;
}

bool KeyManager::OnKeyPressed(int key)//�����ꂽ��
{
	bool ret = (nowKey[key] == 1);
	return ret;
}



bool KeyManager::OnMouseClicked(int key)//������Ă���u��
{
	bool ret = ((nowMouse & key) && (~oldMouse & key));
	return ret;
}

bool KeyManager::OnMouseReleased(int key)//�������u��
{
	bool ret = ((~nowMouse & key) && (oldMouse & key));
	return ret;
}

bool KeyManager::OnMousePressed(int key)//�����ꂽ��
{
	bool ret = (nowMouse & key);
	return ret;
}