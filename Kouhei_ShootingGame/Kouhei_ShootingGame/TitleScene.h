#pragma once
#include"AbstractScene.h"

class TitleScene : public AbstractScene //�p���̌`�ɒ���
{
private:


public:
	TitleScene();//�R���X�g���N�^
	virtual ~TitleScene() {};//�f�X�g���N�^

	virtual void Update()override;//�`��ȊO�̍X�V���������� 
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX����
};

