#pragma once
#ifndef CMATRIX_H
#define CMATRIX_X

/*
�}�g���N�X�N���X
4��4��̍s��f�[�^�������܂�
*/
class CVector;
class CMatrix
{
public:
	CVector VectorZ() const;
	CVector VectorX() const;
	CVector VectorY() const;

	//�t�s��擾
	CMatrix Transpose() const;

	//�s��̎擾
	float* M() const;

	//*���Z�̃I�[�o�[���[�h
	//CMatrix * CMatrix�̉��Z���ʂ�Ԃ�
	const CMatrix operator* (const CMatrix& m) const;

	//�s��l�̑��
	//M(�s��,��,�l)
	void M(int row, int col, float value);

	//�ړ��s��̍쐬
	//Translate(�ړ���X,�ړ���Y,�ړ���Z)
	CMatrix Translate(float mx, float my, float mz);

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