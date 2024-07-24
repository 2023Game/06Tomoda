#pragma once
#ifndef CCOLLIDER_H
#define CCOLLIDER_H

//キャラクタクラスのインクルード
#include "CCharacter3.h"

/*
コライダクラス
衝突判定データ
*/
class CCollisionManager;

class CCollider : public CTransform,public CTask
{
	friend CCollisionManager;
public:
	enum class ETag
	{
		EBODY,   //体
		ESWORD,  //剣
	};
	ETag Tag(); //タグの取得

	void Matrix(CMatrix* m);
	//半径
	virtual void ChangePriority();

	void ChangePriority(int priority);
	
	//ColliderTriangleSphere(三角コライダ,球コライダ,調節値)
	//return:true(衝突してる)false(衝突していない)
	//調節値:衝突しない位置まで戻す値
	static bool ColliderTriangleSphere(CCollider* triangle, CCollider* sphere, CVector* adjust);

	//CollisionTriangleLine(三角コライダ,線分コライダ,調整値)
	//return:true(衝突している)false(衝突していない)
	//調節値:衝突しない位置まで戻す値
	static bool CollisionTriangleLine(CCollider* triangle, CCollider* line, CVector* adjust);

	//コライダタイプ
	enum class EType
	{
		ESPHERE, //球コライダ
		ETRIANGLE, //三角コライダ
		ELINE, //線分コライダ
	};

	//デフォルトコンストラクタ
	CCollider();

	//衝突判定
	//Collision(コライダ1,コライダ2)
	//return:true(衝突している)false(衝突していない)
	static bool Collision(CCollider* m, CCollider* o);

	~CCollider();

	//コンストラクタ
	//CCollider(親,親行列,位置,半径)
	CCollider(CCharacter3* parent, CMatrix* matrix,
		const CVector& position, float radius,ETag tag = ETag::EBODY);

	//親ポインタの取得
	CCharacter3* Parent();

	//描画
	void Render();

	EType Type();
protected:
	ETag mTag;  //タグ

	EType mType; //コライダタイプ

	//頂点
	CVector mV[3];

	CCharacter3* mpParent; //親
	CMatrix* mpMatrix;     //親行列
	float mRadius;
	
};
#endif // !CCOLLIDER_H
