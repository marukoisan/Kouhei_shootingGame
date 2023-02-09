#include "GameClearScene.h"
#include"TitleScene.h"
#include"DxLib.h"
#include"KeyManager.h"

GameClearScene::GameClearScene()//�R���X�g���N�^
{

}

void GameClearScene::Update()//�A�b�v�f�[�g����(�}�C�t���[�����Ă���)
{
	KeyManager::Update();//�}�C�t���[������������
}

void GameClearScene::Draw() const//�`�揈��
{
	DrawFormatString(500, 500, 0xffffff, "GameClear");
	DrawFormatString(500, 700, 0xffffff, "Z�L�[�������Ă�");
}

AbstractScene* GameClearScene::ChangeScene()
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Z))//�L�[�{�[�h�p���}�E�X�p�������ƌ���
	{
		return new TitleScene();//�s�������ꏊ
	}

	return this;//�ǂ̏ꏊ�ɂ��K�v
}