#include "EndScene.h"
#include"DxLib.h"
#include"KeyManager.h"

EndScene::EndScene()//�R���X�g���N�^
{

}

void EndScene::Update()//�A�b�v�f�[�g����(�}�C�t���[�����Ă���)
{
	WaitTimer++;//�}�C�t���[���l���v���X����
	if (WaitTimer >= 180)//WaitTimer��180�ȏ�ɂȂ�����
	{
		DxLib_End();//�Q�[�����I������
	}
}

void EndScene::Draw() const//�`�揈��
{
	SetFontSize(30);
	DrawFormatString(580, 270, 0xffffff, "GameEnd");
}

AbstractScene* EndScene::ChangeScene()
{

	return this;//�ǂ̏ꏊ�ɂ��K�v
}