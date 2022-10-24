#pragma once
class KeyManager
{
private:
	static char oldKey[256];//キーボード用のstatic char
	static char nowKey[256];//staticで作ることで他の場所でも使える

	static int oldMouse;//マウスの入力値の変数
	static int nowMouse;
private:
	KeyManager() = default;

public:
	static void Update();
	static bool OnKeyClicked(int key);//押した瞬間の関数
	static bool OnKeyReleased(int key);//離した時のの関数
	static bool OnKeyPressed(int key);//押された時の関数


	static bool OnMouseClicked(int key);//押した瞬間の関数
	static bool OnMouseReleased(int key);//離した時のの関数
	static bool OnMousePressed(int key);//押された時の関数
};

