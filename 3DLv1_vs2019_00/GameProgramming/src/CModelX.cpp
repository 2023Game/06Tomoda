#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"

CModelX::CModelX()
	:mpPointer(nullptr)
{
	//mToken��������
	memset(mToken, 0, sizeof(mToken));
}

void CModelX::Load(char* file)
{
	//�t�@�C���T�C�Y���擾����

	FILE* fp;                 //�t�@�C���|�C���^�[�ϐ��̍쐬
	fp = fopen(file, "rb");   //�t�@�C�����I�[�v������

    //�G���[�`�F�b�N
	if (fp == NULL)
	{
		printf("fopen error:%s\n", file);
		return;
	}
	
	//�t�@�C���̍Ō�ֈړ�
	fseek(fp, 0L, SEEK_END);

	//�t�@�C���T�C�Y�̎擾
	int size = ftell(fp);

	//�t�@�C���T�C�Y�{1�o�C�g���̗̈���m��
	char* buf = mpPointer = new char[size + 1];

	//�t�@�C������3D���f���̃f�[�^��ǂݍ���
	//�t�@�C���̐擪�ֈړ�
	fseek(fp, 0L, SEEK_SET);

	//�m�ۂ����̈�Ƀt�@�C���T�C�Y���f�[�^��ǂݍ���
	fread(buf, size, 1, fp);

	//�Ō��\0��ݒ肷��i������̏I�[�j
	buf[size] = '\0';

	//������̍Ō�܂ŌJ��Ԃ�
	while (*mpPointer != '\0')
	{
		GetToken();   //�P��̎擾
		//�P�ꂪFrame�̏ꍇ
		if (strcmp(mToken, "Frame") == 0)
		{
			//�t���[�����쐬����
			new CModelXFrame(this);
		}

		if (strcmp(mToken, "AnimationSet") == 0)
		{
			printf("%s ", mToken);  
			GetToken();            
			printf("%s\n", mToken);
		}
	}

	fclose(fp);          //�t�@�C�����N���[�Y����

	SAFE_DELETE_ARRAY(buf);  //�m�ۂ����̈���J������

}

char* CModelX::GetToken()
{
	char* p = mpPointer;
	char* q = mToken;

	//�^�u(\t)��()���s(\r)(\n),;�h�̋�؂蕶���ȊO�ɂȂ�܂œǂݔ�΂�
	while (*p != '\0' && IsDelimiter(*p)) p++;
	if (*p == '{' || *p == '}')
	{
		//{�܂���}�Ȃ�mToken�ɑ�������̕�����
		*q++ = *p++;
	}
	else {
		//�^�u(\t)��()���s(\r)(\n),;"�̋�؂蕶���A
		//�܂��́A}�̕����ɂȂ�܂�mToken�ɑ������
		while (*p != '\0' && !IsDelimiter(*p) && *p != '}')
			*q++ = *p++;
	}

	*q = '\0';      //mToken�̍Ō��\0����
	mpPointer = p;  //���̓ǂݍ��ރ|�C���g���X�V����

	//����mToken��//�̏ꍇ�́A�R�����g�Ȃ̂ŉ��s�܂œǂݔ�΂�
	/*
	strcmp(������1,������2)
	������1�ƕ�����2���������ꍇ�A0��Ԃ�
	������1�ƕ�����2���������Ȃ��ꍇ�A0�ȊO��Ԃ�
	*/

	if (!strcmp("//", mToken))
	{
		//���s�܂œǂݔ�΂�
		while (*p != '\0' && !strchr("\r\n", * p)) p++;

		//�ǂݍ��݈ʒu�̍X�V
		mpPointer = p;

		//�P����擾����(�ċN�Ăяo��)
		return GetToken();
	}
	return mToken;
}

#include <ctype.h>
#include "CEffect.h"
/*
*IsDelimiter(c)
*c��\t\r\n�X�y�[�X�Ȃǂ̋󔒕���
*�܂���,;"�Ȃǂ̕����ł����
*��؂蕶���Ƃ���true��Ԃ�
*/

bool CModelX::IsDelimiter(char c)
{
	//isspace(c)
	//c���󔒕����Ȃ�0�ȊO��Ԃ�
	if (isspace(c) != 0)
		return true;

	/*
	strchr(������,����)
	������ɕ������܂܂�Ă���΁A
	�������������ւ̃|�C���^��Ԃ�
	������Ȃ�������NULL��Ԃ�
	*/
	if (strchr(",;\"", c) != NULL)
		return true;

	//��؂蕶���ł͂Ȃ�
	return false;
}

CModelXFrame::~CModelXFrame()
{
	if (mpMesh != nullptr)
	{
		delete mpMesh;
	}

	//�q�t���[�������ׂĉ������
	std::vector<CModelXFrame*>::iterator itr;
	for (itr = mChild.begin();itr != mChild.end();itr++)
	{
		delete* itr;
	}

	//���O�̃G���A���������
	SAFE_DELETE_ARRAY(mpName);

}

CModelX::~CModelX()
{
	if (mFrame.size() > 0)
	{
		delete mFrame[0];
	}
}

/*
SkipNode
�m�[�h��ǂݔ�΂�
*/
void CModelX::SkipNode()
{
	//�������I�������I��
	while (*mpPointer != '\0')
	{
		//���̒P��擾
		GetToken();
		//�o�����������烋�[�v�I��
		if (strchr(mToken, '{'))break;
	}
	int count = 1;

	//�������I��邩�A�J�E���g��0�ɂȂ�����I��
	while (*mpPointer != '\0'&& count > 0)
	{
		//���̒P��擾
		GetToken();

		//�o��������ƃJ�E���g�A�b�v
		if (strchr(mToken, '{')) count++;

		//�p��������ƃJ�E���g�_�E��
		else if (strchr(mToken, '}')) count--;
	}
}

/*
CModelXFrame
model:CModelX�C���X�^���X�ւ̃|�C���^
�t���[�����쐬����
�ǂݍ��ݒ���Frame��������΁A�t���[�����쐬���A
�q�t���[���ɒǉ�����
*/
CModelXFrame::CModelXFrame(CModelX* model)
	:mpName(nullptr)
	, mIndex(0)
	,mpMesh(nullptr)
{

	//���݂̃t���[���z��̗v�f�����擾���ݒ肷��
	mIndex = model->mFrame.size();

	//CModelX�̃t���[���z��ɒǉ�����
	model->mFrame.push_back(this);

	//�ϊ��s���P�ʍs��ɂ���
	mTransformMatrix.Identity();

	//���̒P��(�t���[�����̗\��)���擾����
	model->GetToken();  //frame name

	//�t���[�������G���A���m�ۂ���
	mpName = new char[strlen(model->mToken) + 1];

	//�t���[�������R�s�[����
	strcpy(mpName, model->mToken);

	//���̒P��(�o�̗\��)���擾����
	model->GetToken();

	//�������Ȃ��Ȃ�����I���
	while (*model->mpPointer != '\0')
	{
		//���̒P��擾
		model->GetToken();

		//{�������̏ꍇ�͏I��
		if (strchr(model->mToken, '}')) break;

		//�V���ȃt���[���̏ꍇ�́A�q�t���[���ɒǉ�
		if (strcmp(model->mToken,"Frame") == 0)
		{
			//�t���[�����쐬���A�q�t���[���̔z��ɒǉ�
			mChild.push_back(new CModelXFrame(model));
		}
		else if (strcmp(model->mToken, "FrameTransformMatrix") == 0)
		{
			model->GetToken(); //{
			for (int i = 0;i < mTransformMatrix.Size();i++)
			{
				mTransformMatrix.M()[i] = atof(model->GetToken());
			}
			model->GetToken();
		}
		else if (strcmp(model->mToken, "Mesh") == 0)
		{
			mpMesh = new CMesh();
			mpMesh->Init(model);
		}
		else
		{
			//��L�ȊO�̗v�f�͓ǂݔ�΂�
			model->SkipNode();
		}
	}
	//�f�o�b�N�o�[�W�����̂ݗL��
#ifdef _DEBUG
	printf("%s\n", mpName);
	mTransformMatrix.Print();
#endif // _DEBUG

}

char* CModelX::Token()
{
	return mToken;
}

//�R���X�g���N�^
CMesh::CMesh()
	:mVertexNum(0)
	, mpVertex(nullptr)
{}

//�f�X�g���N�^
CMesh::~CMesh()
{
	SAFE_DELETE_ARRAY(mpVertex);
}

/*
Init
Mush�̃f�[�^����荞��
*/
void CMesh::Init(CModelX* model)
{
	model->GetToken();

	if (!strchr(model->Token(), '{'))
	{
		//���O�̏ꍇ�A�����o
		model->GetToken();
	}

	//���_���̎擾
	mVertexNum = atoi(model->GetToken());

	//���_�����G���A�m��
	mpVertex = new CVector[mVertexNum];

	//���_�����f�[�^����荞��
	for (int i = 0;i < mVertexNum;i++)
	{
		mpVertex[i].X(atof(model->GetToken()));
		mpVertex[i].Y(atof(model->GetToken()));
		mpVertex[i].Z(atof(model->GetToken()));
	}

#ifdef _DEBUG
	printf("VertexNum:%d\n", mVertexNum);
	for (int i = 0;i < mVertexNum;i++)
	{
		printf("%10f %10f %10f\n", mpVertex[i].X(), mpVertex[i].Y(), mpVertex[i].Z());
	}

#endif // _DEBUG
}