#pragma once
#ifndef CMODELX_H
#define CMODELX_H
#include <vector>    //Vector�N���X�̃C���N���[�h(���I�z��)
#include"CMatrix.h"  //�}�g���b�N�X�N���X�̃C���N���[�h
class CModelX;       //CModelX�N���X�̐錾
class CModelXFrame;     //CModelXFrame�N���X�̐錾
class CMesh;
#define MODEL_FILE "res\\sample.blend.x"

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a){if(a) delete[] a;a = nullptr;}

/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
*/

class CModelX
{
	friend CModelXFrame;
public:
	char* Token();

	~CModelX();

	//�m�[�h�̓ǂݔ�΂�
	void SkipNode();

	//�P��̎��o��
	char* GetToken();

	CModelX();

	//�t�@�C���ǂݍ���
	void Load(char* file);

private:
	std::vector<CModelXFrame*> mFrame;  //�t���[���̔z��

	//c����؂蕶���Ȃ�true��Ԃ�
	bool IsDelimiter(char c);

	char* mpPointer;     //�ǂݍ��݈ʒu
	char mToken[1024];   //���o�����P��̗̈�
};

#endif // !CMODELX_H

//CModelXFrame�N���X�̒�`
class CModelXFrame
{
	friend CModelX;
public:
	//�R���X�g���N�^
	CModelXFrame(CModelX* model);

	//�f�X�g���N�^
	~CModelXFrame();

private:
	CMesh* mpMesh;
	std::vector<CModelXFrame*> mChild;  //�q�t���[���̔z��
	CMatrix mTransformMatrix;           //�ϊ��s��
	char* mpName;                       //�t���[����
	int mIndex;                         //�t���[���ԍ�

};



class CMesh
{
public:
	//�R���X�g���N�^
	CMesh();

	//�f�X�g���N�^
	~CMesh();

	//�ǂݍ��ݏ���
	void Init(CModelX* model);

private:
	int mNormalNum;
	CVector* mpNormal;
	int mFaceNum;
	int* mpVertexIndex;
	int mVertexNum;
	CVector* mpVertex;
	
};
