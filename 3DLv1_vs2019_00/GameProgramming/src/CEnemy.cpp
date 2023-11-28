#include "CEnemy.h"

//移動速度
#define VELOCITY CVector(0.0f,0.0f,0.09f)

//コンストラクタ
//CEnemy(モデル,位置,回転,拡縮)

CEnemy::CEnemy(CModel* model, const CVector& position, const CVector& rotation, const CVector& scale)
	:mCollider1(this,&mMatrix,CVector(0.0f,5.0f,0.0f),0.8f)
	, mCollider2(this, &mMatrix, CVector(0.0f, 5.0f, 20.0f), 0.8f)
	, mCollider3(this, &mMatrix, CVector(0.0f, 5.0f, -20.0f), 0.8f)
	
{
	//モデル、位置、回転、拡縮を設定する
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}

//更新処理
void CEnemy::Update()
{
	//行列を更新
	CTransform::Update();
		//位置を移動
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}

//衝突処理
//Collider(コライダ1,コライダ2)
void CEnemy::Collision(CCollider* m, CCollider* o)
{
	//コライダのmとoが衝突しているか判定
	if (CCollider::Collision(m, o))
	{
		//衝突しているときは無効にする
		mEnabled = false;
	}
}