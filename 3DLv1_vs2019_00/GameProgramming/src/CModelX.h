#pragma once
#ifndef CMODELX_H
#define CMODELX_H
#include <vector>    //Vectorクラスのインクルード(動的配列)
#include"CMatrix.h"  //マトリックスクラスのインクルード
class CModelX;       //CModelXクラスの宣言
class CModelXFrame;     //CModelXFrameクラスの宣言
class CMesh;
class CMaterial;
class CSkinWeights;
class CAnimationSet;
class CAnimation;
class CAnimationKey;

#define MODEL_FILE "res\\sample.blend.x"

//領域開放をマクロ化
#define SAFE_DELETE_ARRAY(a){if(a) delete[] a;a = nullptr;}

//配列のサイズ取得をマクロ化
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

/*
CModelX
Xファイル形式の3Dモデルデータをプログラムで認識する
*/

class CModelX
{
	friend CAnimation;
	friend CAnimationSet;
	friend CModelXFrame;
public:
	void AnimationFrame();

	//フレーム名に該当するフレームのアドレスを返す
	CModelXFrame* FindFrame(char* name);

	std::vector<CAnimationSet*>& AnimationSet();

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
	std::vector<CAnimationSet*> Animation;

	//アニメーションセットの配列
	std::vector<CAnimationSet*> mAnimationSet;

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
	friend CAnimationSet;
	friend CAnimation;
	friend CModelX;
public:
	
	void Render();
	//コンストラクタ
	CModelXFrame(CModelX* model);

	//デストラクタ
	~CModelXFrame();
	int Index();
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
	std::vector<CSkinWeights*> mSkinWeights;
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

/*
CSkinWeights
スキンウェイトクラス
*/
class CSkinWeights
{
	friend CModelX;
	friend CMesh;
public:
	CSkinWeights(CModelX* model);
	~CSkinWeights();
	const int& FrameIndex();
	const CMatrix& offset();

private:
	char* mpFrameName;
	int mFrameIndex;
	int mIndexNum;
	int* mpIndex;
	float* mpWeight;
	CMatrix mOffset;
};

/*
CAnimationSet
アニメーションセット
*/
class CAnimationSet
{
	friend CModelX;
public:
	void AnimateMatrix(CModelX* model);
	std::vector<CAnimation*>& Animation();
	void Time(float time);
	void Weight(float weight);
	CAnimationSet(CModelX* model);
	~CAnimationSet();
private:

	float mTime;
	float mWeight;
	float mMaxTime;

	//アニメーションセット名
	char* mpName;

	//アニメーション
	std::vector<CAnimation*> mAnimation;
};

/*
CAnimation
アニメーションクラス
*/
class CAnimation
{
	friend CModelX;
	friend CAnimationSet;
public:
	CAnimation(CModelX* model);
	~CAnimation();
private:
	int mKeyNum;
	CAnimationKey* mpKey;
	char* mpFrameName;
	int mFrameIndex;
};

/*
CAnimationKey
アニメーションキークラス
*/
class CAnimationKey
{
	friend CAnimation;
	friend CAnimationSet;
private:
	//時間
	float mTime;

	//行列
	CMatrix mMatrix;
};