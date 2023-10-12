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