#pragma once
#ifndef CMODELX_H
#define CMODELX_H
#include <vector>    //Vector�N���X�̃C���N���[�h(���I�z��)
#include"CMatrix.h"  //�}�g���b�N�X�N���X�̃C���N���[�h
class CModelX;       //CModelX�N���X�̐錾
class CModelXFrame;     //CModelXFrame�N���X�̐錾
class CMesh;
class CMaterial;
class CSkinWeights;
class CAnimationSet;
class CAnimation;
class CAnimationKey;

#define MODEL_FILE "res\\sample.blend.x"

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a){if(a) delete[] a;a = nullptr;}

//�z��̃T�C�Y�擾���}�N����
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
*/

class CModelX
{
	friend CAnimation;
	friend CAnimationSet;
	friend CModelXFrame;
public:
	void AnimationFrame();

	//�t���[�����ɊY������t���[���̃A�h���X��Ԃ�
	CModelXFrame* FindFrame(char* name);

	std::vector<CAnimationSet*>& AnimationSet();

	bool EOT();
	void Render();
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
	std::vector<CAnimationSet*> Animation;

	//�A�j���[�V�����Z�b�g�̔z��
	std::vector<CAnimationSet*> mAnimationSet;

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
	friend CAnimationSet;
	friend CAnimation;
	friend CModelX;
public:
	
	void Render();
	//�R���X�g���N�^
	CModelXFrame(CModelX* model);

	//�f�X�g���N�^
	~CModelXFrame();
	int Index();
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
	void Render();

	//�R���X�g���N�^
	CMesh();

	//�f�X�g���N�^
	~CMesh();

	//�ǂݍ��ݏ���
	void Init(CModelX* model);

private:
	std::vector<CSkinWeights*> mSkinWeights;
	int mMaterialNum;
	int mMaterialIndexNum;
	int* mpMaterialIndex;
	std::vector<CMaterial*> mMaterial;

	int mNormalNum;
	CVector* mpNormal;
	int mFaceNum;
	int* mpVertexIndex;
	int mVertexNum;
	CVector* mpVertex;
	
};

/*
CSkinWeights
�X�L���E�F�C�g�N���X
*/
class CSkinWeights
{
	friend CModelX;
	friend CMesh;
public:
	CSkinWeights(CModelX* model);
	~CSkinWeights();
	const int& FrameIndex();
	const CMatrix& offset();

private:
	char* mpFrameName;
	int mFrameIndex;
	int mIndexNum;
	int* mpIndex;
	float* mpWeight;
	CMatrix mOffset;
};

/*
CAnimationSet
�A�j���[�V�����Z�b�g
*/
class CAnimationSet
{
	friend CModelX;
public:
	void AnimateMatrix(CModelX* model);
	std::vector<CAnimation*>& Animation();
	void Time(float time);
	void Weight(float weight);
	CAnimationSet(CModelX* model);
	~CAnimationSet();
private:

	float mTime;
	float mWeight;
	float mMaxTime;

	//�A�j���[�V�����Z�b�g��
	char* mpName;

	//�A�j���[�V����
	std::vector<CAnimation*> mAnimation;
};

/*
CAnimation
�A�j���[�V�����N���X
*/
class CAnimation
{
	friend CModelX;
	friend CAnimationSet;
public:
	CAnimation(CModelX* model);
	~CAnimation();
private:
	int mKeyNum;
	CAnimationKey* mpKey;
	char* mpFrameName;
	int mFrameIndex;
};

/*
CAnimationKey
�A�j���[�V�����L�[�N���X
*/
class CAnimationKey
{
	friend CAnimation;
	friend CAnimationSet;
private:
	//����
	float mTime;

	//�s��
	CMatrix mMatrix;
};