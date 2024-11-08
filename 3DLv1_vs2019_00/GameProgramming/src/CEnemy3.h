#pragma once
#ifndef CENEMY3_H
#define CENEMY3_H

//キャラクタークラスのインクルード
#include "CCharacter3.h"

//コライダクラスのインクルード
#include "CCollider.h"

/*
エネミークラス
キャラクタクラスを継承
*/
class CEnemy3 :public CCharacter3
{
public:
	//コンストラクタ
	CEnemy3();

	//CEnemy3(位置,回転,拡縮)
	CEnemy3(const CVector& position, const CVector& rotation,
		const CVector& scale);

	//更新処理
	void Update();

	//衝突処理
	//Collision(コライダ１,コライダ２)
	void Collision(CCollider* m, CCollider* o);
	void Collision();

private:
	CVector mPoint;

	int mHp;

	//モデルデータ
	static CModel sModel;

	//コライダ
	CCollider mCollider;
};

#endif // !CENEMY3_H
