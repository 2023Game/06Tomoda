#pragma once
#ifndef CCOLLIDERTRIANGLE
#define CCOLLIDERTRIANGLE
#include "CCollider.h"

/*
三角コライダの定義
*/

class CColliderTriangle :public CCollider
{
public:
	void ChangePriority();
	CColliderTriangle() {};

	//コンストラクタ(三角コライダ)
	//CColliderTriangle(親,親行列,頂点1,頂点2,頂点3)
	CColliderTriangle(CCharacter3* parent, CMatrix* matrix,
		const CVector& v0, const CVector& v1, const CVector& v2);

	//三角コライダの設定
	//Set(親,親行列,頂点1,頂点2,頂点3)
	void Set(CCharacter3* parent, CMatrix* matrix,
		const CVector& v0, const CVector& v1, const CVector& v2);

	//描画
	void Render();
};

#endif // !CCOLLIDERTRIANGLE
