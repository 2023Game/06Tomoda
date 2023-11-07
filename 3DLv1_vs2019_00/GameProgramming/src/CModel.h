#pragma once
//vectorのインクルード
#include <vector>
#include "CVector.h"
#include "CTriangle.h"
#include "CMaterial.h"
#include "CVertex.h"
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
	//Render(行列)
	void Render(const CMatrix& m);
	void Render();
	~CModel();
	
	//モデルファイルの入力
	//Load(モデルファイル名,マテリアルファイル名)
	void Load(char* obj, char* mtl);
private:
	//頂点の配列
	CVertex* mpVertexes;
	void CreateVertexBuffer();

	    //マテリアルポインタの可変長配列
	std::vector<CMaterial*> mpMaterials;

		//三角形の可変長配列
		std::vector<CTriangle> mTriangles;
};

#endif // !CMODEL_H


