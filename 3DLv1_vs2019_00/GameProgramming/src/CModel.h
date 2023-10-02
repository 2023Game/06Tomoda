#pragma once
//vectorのインクルード
#include <vector>
#include "CVector.h"
#include "CTriangle.h"
#ifndef CMODEL_H
#define CMODEL_H
/*
モデルクラス
モデルデータの入力や表示
*/
class CModel
{
public:
	//描画
	void Render();

	//モデルファイルの入力
	//Load(モデルファイル名,マテリアルファイル名)
	void Load(char* obj, char* mtl);
private:
		//三角形の可変長配列
		std::vector<CTriangle> mTriangles;
};

#endif // !CMODEL_H


