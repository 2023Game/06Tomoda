#include "CModel.h"
//�W�����͂̃C���N���[�h
#include <stdio.h>
//CVector�̃C���N���[�h
#include "CVector.h"

//������s1�ƕ�����s2�̔�r
//s1��s2�����������0��
//�������Ȃ����0�ȊO��Ԃ�
int strcmp(const char* s1, const char* s2)
{
	int i = 0;

	//�����������͌J��Ԃ�
	//�ǂ��炩�̕����I���ɂȂ�ƃ��[�v�̏I���
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}

	//�����Ȃ������0
	return s1[i] - s2[i];
}

//���f���t�@�C���̓���
//Load(���f���t�@�C����,�}�e���A���t�@�C����)
void CModel::Load(char* obj, char* mtl)
{

	//���_�f�[�^�̕ۑ�(CVector�^)
	std::vector<CVector> vertex;

	std::vector<CVector> normal;

	//�t�@�C���|�C���^�ϐ��̍쐬
	FILE* fp;

	//�t�@�C������f�[�^�����
	//���̓G���A���쐬����
	char buf[256];

	//�t�@�C���̃I�[�v��
	//fopen(�t�@�C����,���[�h)
	//�I�[�v���ł��Ȃ��Ƃ���NULL��Ԃ�
	fp = fopen(mtl, "r");
	
	//�t�@�C���I�[�v���G���[�̐ݒ�
	//fp��NULL�̏ꍇ�̓G���[
	if (fp == NULL)
	{
		//�R���\�[���ɃG���[���o�͂��Ė߂�
		printf("%s file open error\n", mtl);
		return;
	}
	//�}�e���A���C���f�b�N�X
	int idx = 0;

	//�t�@�C������1������
	//fgets(���̓G���A,�G���A�T�C�Y,�t�@�C���|�C���^)
	//�t�@�C���̍Ō�ɂȂ��NULL��Ԃ�
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		//�f�[�^�𕪊�����
		char str[4][64] = { "","","","" };

		//�����񂩂�f�[�^���S�ϐ��֑������
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);
		
		//�擪��newmtl�̎��A�}�e���A����ǉ�����
		if (strcmp(str[0], "newmtl") == 0)
		{
			CMaterial* pm = new CMaterial();

			//�}�e���A�����̐ݒ�
			pm->Name(str[1]);

			//�}�e���A���̉ϒ��z��ɒǉ�
			mpMaterials.push_back(pm);

			//�z��̒������擾
			idx = mpMaterials.size() - 1;
		}

		//�擪��Kd�̎��ADiffuse��ݒ肷��
		else if (strcmp(str[0], "Kd") == 0)
		{
			mpMaterials[idx]->Diffuse()[0] = atof(str[1]);
			mpMaterials[idx]->Diffuse()[1] = atof(str[2]);
			mpMaterials[idx]->Diffuse()[2] = atof(str[3]);
		}

		//�擪��d�̎��Aa�l��ݒ肷��
		else if (strcmp(str[0], "d") == 0)
		{
			mpMaterials[idx]->Diffuse()[3] = atof(str[1]);
		}
	}
	
	//�t�@�C���̃N���[�Y
	fclose(fp);

	fp = fopen(obj, "r");

	if (fp == NULL)
	{
		printf("%s file open error\n", obj);
		return;
	}
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		//�f�[�^�𕪊�����
		char str[4][64] = { "","","","" };

		//�����񂩂�f�[�^��4�ϐ��֑������
		//sscanf(������,�ϊ��w��q,�ϐ�)
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);

		//������̔�r
		//strcmp(������1,������2)
		//������1�ƕ�����2��������0�A�قȂ�Ƃ�0�ȊO��Ԃ�
		//����Ƃ���v�̎��A���_��vertex�ɒǉ�����
		if (strcmp(str[0], "v") == 0)
		{
			//�ϒ��z��vertex�ɒǉ�
			//atof(������)�@�����񂩂�float�^�̒l��Ԃ�
			vertex.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));

		}
		else if (strcmp(str[0], "vn") == 0)
		{
			normal.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}
		//�擪��f�̎��A�O�p�`���쐬���Ēǉ�����
		else if (strcmp(str[0],"f") == 0)
		{
			//���_�Ɩ@���̔ԍ��쐬
			int v[3], n[3];
			
			//���_�Ɩ@���̔ԍ��擾
			sscanf(str[1], "%d//%d", &v[0], &n[0]);
			sscanf(str[2], "%d//%d", &v[1], &n[1]);
			sscanf(str[3], "%d//%d", &v[2], &n[2]);

			//�O�p�`�쐬
			CTriangle t;
			t.Vertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);

			t.Normal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);

			//�}�e���A���ԍ��̐ݒ�
			t.MaterialIdx(idx);

			//�ϒ��z��mTriangles�ɎO�p�`��ǉ�
			mTriangles.push_back(t);

		}


		//�擪��usemtl�̎��A�}�e���A���C���f�N�X���擾����
		else if (strcmp(str[0], "usemtl") == 0)
		{
			//�ϒ��z������Ƃ����r
			for (idx = mpMaterials.size() - 1; idx > 0; idx--)
			{
				//�������O�̃}�e���A��������΃��[�v�I��
				if (strcmp(mpMaterials[idx]->Name(), str[1]) == 0)
				{
					break;//���[�v����o��
				}
			}
		}
	}
    fclose(fp);
	
}

//�`��
void CModel::Render()
{
	for (int i = 0; i < mTriangles.size(); i++)
	{
		//�}�e���A���̓K�p
		mpMaterials[mTriangles[i].MaterialIdx()]->Enabled();

		//�ϒ��z��ɓY�����ŃA�N�Z�X����
		mTriangles[i].Render();
	}
}

CModel::~CModel()
{
	for (int i = 0; i < mpMaterials.size(); i++)
	{
		delete mpMaterials[i];
	}
}