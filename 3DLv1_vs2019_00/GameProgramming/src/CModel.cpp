#include "CModel.h"
//�W�����͂̃C���N���[�h
#include <stdio.h>

//���f���t�@�C���̓���
//Load(���f���t�@�C����,�}�e���A���t�@�C����)
void CModel::Load(char* obj, char* mtl)
{
	//�t�@�C���|�C���^�ϐ��̍쐬
	FILE* fp, * fp2;

	//�t�@�C������f�[�^�����
	//���̓G���A���쐬����
	char buf[256];

	//�t�@�C���̃I�[�v��
	//fopen(�t�@�C����,���[�h)
	//�I�[�v���ł��Ȃ��Ƃ���NULL��Ԃ�
	fp = fopen(mtl, "r");
	fp2 = fopen(obj, "r");
	//�t�@�C���I�[�v���G���[�̐ݒ�
	//fp��NULL�̏ꍇ�̓G���[
	if (fp == NULL)
	{
		//�R���\�[���ɃG���[���o�͂��Ė߂�
		printf("%s file open error\n", mtl);
		return;
	}
	if (fp2 == NULL)
	{
		printf("%s file open error\n", obj);
		return;
	}

	//�t�@�C������1������
	//fgets(���̓G���A,�G���A�T�C�Y,�t�@�C���|�C���^)
	//�t�@�C���̍Ō�ɂȂ��NULL��Ԃ�
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		//���͂����l���R���\�[���ɏo�͂���
		printf("%s", buf);
	
	}
	
	while (fgets(buf, sizeof(buf), fp2) != NULL)
	{
		//���͂����l���R���\�[���ɏo�͂���
		printf("%s", buf);
	}

	//�t�@�C���̃N���[�Y
	fclose(fp);
	fclose(fp2);
}
