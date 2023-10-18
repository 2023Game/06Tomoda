#pragma once
#ifndef CMATRIX_H
#define CMATRIX_X
/*
�}�g���N�X�N���X
4��4��̍s��f�[�^�������܂�
*/

class CMatrix
{
public:
	//��]�iX�j���̍쐬
	//RotateX
	CMatrix RotateX(float degree);

	//��]�iZ�j���̍쐬
	//RotateZ
	CMatrix RotateZ(float degree);

	//��]�iY�j���̍쐬
	//RotateY
	CMatrix RotateY(float degree);

	//�s��l�̎擾
	//M(�s,��j
	//mM[�s][��]���擾
	float M(int r, int c) const;

	//�g��k���s��̍쐬
	//Scale(�{��X,�{��Y,�{��Z�j
	CMatrix Scale(float sx, float sy, float sz);
 
	//�\���m�F�p
	//4�~4�̍s�����ʏo��
	void Print();

	//�f�t�H���g�R���X�g���N�^
	CMatrix();

	//�P�ʍs��̍쐬
	CMatrix Identity();
private:
	//4�~4�̍s��f�[�^��ݒ�
	float mM[4][4];
};
#endif