#pragma once
#ifndef CCOLLIDERLINE
#define CCOLLIDERLINE
#include "CCollider.h"

/*
�����R���C�_�̒�`
*/

class CColliderLine :public CCollider
{
public:
	void ChangePriority();
	CColliderLine() {}
	
	//�R���X�g���N�^(�����R���C�_)
	//CColliderLine(�e,�e�s��,���_1,���_�Q)
	CColliderLine(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1);

	//�����R���C�_�̐ݒ�
	//Set(�e,�e�s��,���_1,���_�Q)
	void Set(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1);

	//�`��
	void Render();
};

#endif // !CCOLLIDERLINE
