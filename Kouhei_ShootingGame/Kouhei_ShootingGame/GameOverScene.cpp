#include "GameOverScene.h"
#include"KeyManager.h"
#include"TitleScene.h"
#include"DxLib.h"

GameOverScene::GameOverScene()//�R���X�g���N�^
{

}

void GameOverScene::Update()//�A�b�v�f�[�g����(�}�C�t���[�����Ă���)
{
	KeyManager::Update();//�}�C�t���[������������
}

void GameOverScene::Draw() const
{
	DrawFormatString(500, 500, 0xffffff, "GameOver");
	DrawFormatString(500, 700, 0xffffff, "Z�L�[�������Ă�");
}

AbstractScene* GameOverScene::ChangeScene()//���ɍs�������ꏊ�̃V�[����ݒ肷��
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Z))//�L�[�{�[�h�p���}�E�X�p�������ƌ���
	{
		return new TitleScene();//�s�������ꏊ
	}

	return this;//�ǂ̏ꏊ�ɂ��K�v
}