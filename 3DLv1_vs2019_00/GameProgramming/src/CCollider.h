#pragma once
#ifndef CCOLLIDER_H
#define CCOLLIDER_H

//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"

/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollisionManager;

class CCollider : public CTransform,public CTask
{
	friend CCollisionManager;
public:
	//�R���C�_�^�C�v
	enum class EType
	{
		ESPHERE, //���R���C�_
		ETRIANGLE, //�O�p�R���C�_
	};

	//�f�t�H���g�R���X�g���N�^
	CCollider();

	//�Փ˔���
	//Collision(�R���C�_1,�R���C�_2)
	//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider* m, CCollider* o);

	~CCollider();

	//�R���X�g���N�^
	//CCollider(�e,�e�s��,�ʒu,���a)
	CCollider(CCharacter3* parent, CMatrix* matrix,
		const CVector& position, float radius);

	//�e�|�C���^�̎擾
	CCharacter3* Parent();

	//�`��
	void Render();

protected:
	EType mType; //�R���C�_�^�C�v

	//���_
	CVector mV[3];

	CCharacter3* mpParent; //�e
	CMatrix* mpMatrix;     //�e�s��
	float mRadius;         //���a
};
#endif // !CCOLLIDER_H