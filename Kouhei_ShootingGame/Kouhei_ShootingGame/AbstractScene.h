#pragma once

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class AbstractScene
{
public:
	//�f�X�g���N�^
	virtual ~AbstractScene() {};

	//���ƂȂ�p����̃f�[�^�� = 0�ɂ���
	// �֐��̒�`������K�v���Ȃ��̂ƌp����Ŋ֐����`�����邱�ƓO�ꂳ���邽��

	//�`��ȊO�̍X�V���������� 
	virtual void Update() = 0;

	//�`��Ɋւ��邱�Ƃ��������� 
	virtual void Draw() const = 0;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() = 0;
};