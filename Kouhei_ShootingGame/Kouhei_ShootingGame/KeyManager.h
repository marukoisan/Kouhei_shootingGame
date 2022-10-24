#pragma once
class KeyManager
{
private:
	static char oldKey[256];//�L�[�{�[�h�p��static char
	static char nowKey[256];//static�ō�邱�Ƃő��̏ꏊ�ł��g����

	static int oldMouse;//�}�E�X�̓��͒l�̕ϐ�
	static int nowMouse;
private:
	KeyManager() = default;

public:
	static void Update();
	static bool OnKeyClicked(int key);//�������u�Ԃ̊֐�
	static bool OnKeyReleased(int key);//���������̂̊֐�
	static bool OnKeyPressed(int key);//�����ꂽ���̊֐�


	static bool OnMouseClicked(int key);//�������u�Ԃ̊֐�
	static bool OnMouseReleased(int key);//���������̂̊֐�
	static bool OnMousePressed(int key);//�����ꂽ���̊֐�
};

