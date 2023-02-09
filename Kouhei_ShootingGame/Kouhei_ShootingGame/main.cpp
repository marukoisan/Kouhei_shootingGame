#include"DxLib.h"
#include"SceneManager.h"
#include"GameMainScene.h"
#include"TitleScene.h"
#include"coomon.h"


/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�V���[�e�B���O�Q�[��");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);


	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	//�V�[���}�l�[�W���[�I�u�W�F�N�g�̍쐬
	//�V�[���}�l�[�W���[�̍ŏ��̎n�܂�����߂�ꏊ
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));

	// �Q�[�����[�v
	while (ProcessMessage() == 0) 
	{
		ClearDrawScreen();		// ��ʂ̏�����

		sceneMng.Update();  //�V�[���̍X�V����
		sceneMng.Draw();    //�V�[���̕`�揈��

		if (sceneMng.ChangeScene() == nullptr)//�V�[���̕ύX����
		{
			DxLib_End();	// DX���C�u�����g�p�̏I������

			return 0;	// �\�t�g�̏I��
		}


		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}
	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��

}