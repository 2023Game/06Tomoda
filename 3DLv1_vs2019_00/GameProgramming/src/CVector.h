#pragma once
#include "CMatrix.h"
#ifndef CVECTOR_H
#define CVECTOR_H
/*
�x�N�g���N���X
�x�N�g���f�[�^�������܂�
*/

class CVector 
{
public:
	//CVector * CMaterial�̌��ʂ�CVector�ŕԂ�
	CVector operator*(const CMatrix& m);

	//-���Z�q�̃I�[�o�[���[�h
	//CVector - CVector�@�̉��Z���ʂ�Ԃ�
	CVector operator-(const CVector &v) const;

	//+���Z�q�̃I�[�o�[���[�h
	//CVector + CVector �̉��Z���ʂ�Ԃ�
	CVector operator+(const CVector& v) const;

	//�f�t�H���g�R���X�g���N�^
	CVector();

	//�R���X�g���N�^
	//CVector(X���W,Y���W,Z���W)
	CVector(float x, float y, float z);

	//�e���ł̒l�̐ݒ�
	//Set(X���W,Y���W,Z���W)
	void Set(float x, float y, float z);

	//X�̒l�𓾂�
	float X() const;

	//Y�̒l�𓾂�
	float Y() const;

	//Z�̒l�𓾂�
	float Z() const;
private:
	//3D�e���ł̒l��ݒ�
	float mX, mY, mZ;
};
#endif // !CVECTOR_H

