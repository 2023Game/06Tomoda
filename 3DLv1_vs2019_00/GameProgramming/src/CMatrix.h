#pragma once
#ifndef CMATRIX_H
#define CMATRIX_X
/*
マトリクスクラス
4桁4列の行列データを扱います
*/

class CMatrix
{
public:
	//回転（X）軸の作成
	//RotateX
	CMatrix RotateX(float degree);

	//回転（Z）軸の作成
	//RotateZ
	CMatrix RotateZ(float degree);

	//回転（Y）軸の作成
	//RotateY
	CMatrix RotateY(float degree);

	//行列値の取得
	//M(行,列）
	//mM[行][列]を取得
	float M(int r, int c) const;

	//拡大縮小行列の作成
	//Scale(倍率X,倍率Y,倍率Z）
	CMatrix Scale(float sx, float sy, float sz);
 
	//表示確認用
	//4×4の行列を画面出力
	void Print();

	//デフォルトコンストラクタ
	CMatrix();

	//単位行列の作成
	CMatrix Identity();
private:
	//4×4の行列データを設定
	float mM[4][4];
};
#endif