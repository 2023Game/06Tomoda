#pragma once
//vector�̃C���N���[�h
#include <vector>
#include "CVector.h"
#include "CTriangle.h"
#include "CMaterial.h"
#ifndef CMODEL_H
#define CMODEL_H
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel
{
public:
	//�`��
	//Render(�s��)
	void Render(const CMatrix& m);

	~CModel();
	//�`��
	void Render();
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����,�}�e���A���t�@�C����)
	void Load(char* obj, char* mtl);
private:
	    //�}�e���A���|�C���^�̉ϒ��z��
	std::vector<CMaterial*> mpMaterials;

		//�O�p�`�̉ϒ��z��
		std::vector<CTriangle> mTriangles;
};

#endif // !CMODEL_H


