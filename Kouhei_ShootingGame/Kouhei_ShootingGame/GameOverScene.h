#pragma once
#include"AbstractScene.h"

class GameOverScene :  public AbstractScene
{

public:
	GameOverScene();//�R���X�g���N�^
	virtual ~GameOverScene() {};//�f�X�g���N�^

	virtual void Update()override;//�`��ȊO�̍X�V���������� 
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX����
};

