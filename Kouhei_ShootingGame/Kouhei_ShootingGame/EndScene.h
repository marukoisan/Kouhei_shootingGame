#pragma once
#include"AbstractScene.h"
class EndScene : public AbstractScene
{
private:
	int WaitTimer = 0;//�����l�[��

public:
	EndScene();//�R���X�g���N�^
	virtual ~EndScene() {};//�f�X�g���N�^

	virtual void Update()override;//�`��ȊO�̍X�V���������� 
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX����
};

