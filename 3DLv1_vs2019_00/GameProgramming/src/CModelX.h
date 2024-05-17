#pragma once
#ifndef CMODELX_H
#define CMODELX_H
#include <vector>    //Vectorクラスのインクルード(動的配列)
#include"CMatrix.h"  //マトリックスクラスのインクルード
class CModelX;       //CModelXクラスの宣言
class CModelXFrame;     //CModelXFrameクラスの宣言
class CMesh;
class CMaterial;
#define MODEL_FILE "res\\sample.blend.x"

//領域開放をマクロ化
#define SAFE_DELETE_ARRAY(a){if(a) delete[] a;a = nullptr;}

/*
CModelX
Xファイル形式の3Dモデルデータをプログラムで認識する
*/

class CModelX
{
	friend CModelXFrame;
public:

	bool EOT();
	void Render();
	char* Token();

	~CModelX();

	//ノードの読み飛ばし
	void SkipNode();

	//単語の取り出し
	char* GetToken();

	CModelX();

	//ファイル読み込み
	void Load(char* file);

private:
	std::vector<CModelXFrame*> mFrame;  //フレームの配列

	//cが区切り文字ならtrueを返す
	bool IsDelimiter(char c);

	char* mpPointer;     //読み込み位置
	char mToken[1024];   //取り出した単語の領域
};

#endif // !CMODELX_H

//CModelXFrameクラスの定義
class CModelXFrame
{
	friend CModelX;
public:
	void Render();
	//コンストラクタ
	CModelXFrame(CModelX* model);

	//デストラクタ
	~CModelXFrame();

private:
	CMesh* mpMesh;
	std::vector<CModelXFrame*> mChild;  //子フレームの配列
	CMatrix mTransformMatrix;           //変換行列
	char* mpName;                       //フレーム名
	int mIndex;                         //フレーム番号

};



class CMesh
{
public:
	void Render();

	//コンストラクタ
	CMesh();

	//デストラクタ
	~CMesh();

	//読み込み処理
	void Init(CModelX* model);

private:
	int mMaterialNum;
	int mMaterialIndexNum;
	int* mpMaterialIndex;
	std::vector<CMaterial*> mMaterial;

	int mNormalNum;
	CVector* mpNormal;
	int mFaceNum;
	int* mpVertexIndex;
	int mVertexNum;
	CVector* mpVertex;
	
};
