#pragma once

#ifndef CXPLAYER_H
#define CXPLAYER_H
#include <vector>
#include "CXCharacter.h""
#include "CInput.h"
#include "CCollider.h"
class CXPlayer:public CXCharacter
{
public:
	void Init(CModelX* model);

	//�X�V����
	void Update();

	CInput mInput;

	CXPlayer();

private:
	//�R���C�_�̐錾
	CCollider mColSphereBody;  //��
	CCollider mColSphereHead;  //��
	CCollider mColSphereSword; //��

};

#endif // !CXPLAYER_H
