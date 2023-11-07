#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
/*
三角形クラス
*/
class CTriangle {
public:
	//頂点座標を得る
	const CVector& V0() const;
	const CVector& V1() const;
	const CVector& V2() const;

	//法線を得る
	const CVector& N0() const;
	const CVector& N1() const;
	const CVector& N2() const;

	//UVを得る
	const CVector& U0() const;
	const CVector& U1() const;
	const CVector& U2() const;

	//描画
	//Render(行列）
	void Render(const CMatrix& m);

	//UV設定
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);

	//マテリアル番号の取得
	int MaterialIdx();

	//マテリアル番号の設定
	//Material(マテリアル番号の設定
	void MaterialIdx(int idx);

	//頂点座標設定
	//Vertex(頂点1,頂点2,頂点3)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//法線設定
	//Normal(法線ベクトル)
	void Normal(const CVector& n);
	//描画
	void Render();
	//Normal(法線ベクトル1,法線ベクトル2,法線ベクトル3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
	CVector mUv[3]; //テクスチャマッピング
	int mMaterialIdx; //マテリアル番号
	CVector mV[3];//頂点座標
	CVector mN[3];//法線
};
#endif // CTRIANGLE_H

