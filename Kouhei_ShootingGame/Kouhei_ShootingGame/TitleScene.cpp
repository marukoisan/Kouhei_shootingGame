#include "TitleScene.h"
#include"KeyManager.h"
#include"GameMainScene.h"
#include"EndScene.h"
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
	
	DrawFormatString(200, 200, 0xffffff, "ShootingGame");
	DrawFormatString(800, 200, 0xffffff, "GameEnd");
	DrawFormatString(200, 500, 0xffffff, "Q�L�[������Start");
	DrawFormatString(800, 500, 0xffffff, "X�L�[������End");
}

AbstractScene* TitleScene::ChangeScene()//�V�[���̕ύX����
{
	if (KeyManager::OnKeyPressed(KEY_INPUT_Q))//�L�[�{�[�h�p���}�E�X�p�������ƌ���
	{
		return new GameMainScene();//�Q�[�����C���֑J��
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_X))//�L�[�{�[�h�p���}�E�X�p�������ƌ���
	{
		return new EndScene();//�Q�[���G���h�֑J��
	}

	return this;//�ǂ̏ꏊ�ɂ��K�v
}