#include "CMatrix.h"
//�W�����o�͊֐��̃C���N���[�h
#include <stdio.h>

//�~����M_PI��L���ɂ���
#define _USE_MATH_DEFINES
//�����֐��̃C���N���[�h
#include <math.h>


void CMatrix::Print()
{
	printf("%10f %10f %10f %10f\n",
		mM[0][0], mM[0][1], mM[0][2], mM[0][3]);
	printf("%10f %10f %10f %10f\n",
		mM[1][0], mM[1][1], mM[1][2], mM[1][3]);
	printf("%10f %10f %10f %10f\n",
		mM[2][0], mM[2][1], mM[2][2], mM[2][3]);
	printf("%10f %10f %10f %10f\n",
		mM[3][0], mM[3][1], mM[3][2], mM[3][3]);

}

CMatrix::CMatrix()
{
	Identity();
}

CMatrix CMatrix::Identity()
{
	mM[0][0] = 1, mM[0][1] = 0, mM[0][2] = 0, mM[0][3] = 0;
	mM[1][0] = 0, mM[1][1] = 1, mM[1][2] = 0, mM[1][3] = 0;
	mM[2][0] = 0, mM[2][1] = 0, mM[2][2] = 1, mM[2][3] = 0;
	mM[3][0] = 0, mM[3][1] = 0, mM[3][2] = 0, mM[3][3] = 1;
	
	return *this;
}

float CMatrix::M(int r, int c) const
{
	return mM[r][c];
}

//�g��k���s��̍쐬
//Scale(�{��X,�{��Y,�{��Z)
CMatrix CMatrix::Scale(float sx, float sy ,float sz)
{
	mM[0][0] = sx, mM[0][1] = 0, mM[0][2] = 0, mM[0][3] = 0;
	mM[1][0] = 0, mM[1][1] = sy, mM[1][2] = 0, mM[1][3] = 0;
	mM[2][0] = 0, mM[2][1] = 0, mM[2][2] = sz, mM[2][3] = 0;
	mM[3][0] = 0, mM[3][1] = 0, mM[3][2] = 0, mM[3][3] = 1;

	//���̍s���Ԃ�
	return *this;
}

//��]�s��iY���j�̍쐬
//RotateY(�p�x)
CMatrix CMatrix::RotateY(float degree)
{
	//�p�x���烉�W�A�������߂�
	float rad = degree / 180.0f * M_PI;

	//�P�ʍs��ɂ���
	Identity();

	//Y���ŉ�]����s��̐ݒ�
	mM[0][0] = mM[2][2] = cosf(rad);
	mM[0][2] = sinf(rad);
	mM[2][0] = -mM[0][2];

	//�s���Ԃ�
	return *this;
}

//��]�s��iZ���j�̍쐬
//RotateZ(�p�x)
CMatrix CMatrix::RotateZ(float degree)
{
	//�p�x���烉�W�A�������߂�
	float rad = degree / 180.0f * M_PI;

	//�P�ʍs��ɂ���
	Identity();

	//Z���ŉ�]����s��̐ݒ�
	mM[0][0] = mM[1][1] = cosf(rad);
	mM[0][1] = sinf(rad);
	mM[1][0] = -mM[0][1];

	//�s���Ԃ�
	return *this;
}

//��]�s��iX���j�̍쐬
//RotateX(�p�x)
CMatrix CMatrix::RotateX(float degree)
{
	//�p�x���烉�W�A�������߂�
	float rad = degree / 180.0f * M_PI;

	//�P�ʍs��ɂ���
	Identity();

	//X���ŉ�]����s��̐ݒ�
	mM[1][1] = mM[2][2] = cosf(rad);
	mM[1][2] = sinf(rad);
	mM[2][1] = -mM[1][2];

	//�s���Ԃ�
	return *this;
}

//�ړ��s��̍쐬
//Translate(�ړ���X,�ړ���Y,�ړ���Z)
CMatrix CMatrix::Translate(float mx, float my, float mz)
{
	mM[3][0] = mx;
    mM[3][1] = my;
	mM[3][2] = mz;
	//���̍s���Ԃ�
	return *this;
}

void CMatrix::M(int row, int col, float value)
{
	mM[row][col] = value;
}