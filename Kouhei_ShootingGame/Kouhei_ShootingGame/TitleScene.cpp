#include "TitleScene.h"
#include"KeyManager.h"
#include"GameMainScene.h"
#include"DxLib.h"

TitleScene::TitleScene()//�R���X�g���N�^
{

}

void TitleScene::Update()//�A�b�v�f�[�g����(�}�C�t���[�����Ă���)
{
	KeyManager::Update();//�}�C�t���[������������
}

void TitleScene::Draw() const //�`�揈��
{
	
	DrawFormatString(500, 200, 0xffffff, "ShootingGame");
	DrawFormatString(500, 500, 0xffffff, "Q�L�[������Start");
}

AbstractScene* TitleScene::ChangeScene()//�V�[���̕ύX����
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Q))//�L�[�{�[�h�p���}�E�X�p�������ƌ���
	{
		return new GameMainScene();
	}

	return this;//�ǂ̏ꏊ�ɂ��K�v
}