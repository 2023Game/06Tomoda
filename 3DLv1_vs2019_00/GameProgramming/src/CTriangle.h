#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
/*
�O�p�`�N���X
*/
class CTriangle {
public:

	//�}�e���A���ԍ��̎擾
	int MaterialIdx();

	//�}�e���A���ԍ��̐ݒ�
	//Material(�}�e���A���ԍ��̐ݒ�
	void MaterialIdx(int idx);

	//���_���W�ݒ�
	//Vertex(���_1,���_2,���_3)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//�@���ݒ�
	//Normal(�@���x�N�g��)
	void Normal(const CVector& n);
	//�`��
	void Render();
	//Normal(�@���x�N�g��1,�@���x�N�g��2,�@���x�N�g��3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
	int mMaterialIdx; //�}�e���A���ԍ�
	CVector mV[3];//���_���W
	CVector mN[3];//�@��
};
#endif // CTRIANGLE_H
