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

	//更新処理
	void Update();

	CInput mInput;

	CXPlayer();

private:
	//コライダの宣言
	CCollider mColSphereBody;  //体
	CCollider mColSphereHead;  //頭
	CCollider mColSphereSword; //剣

};

#endif // !CXPLAYER_H
