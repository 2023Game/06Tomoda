#pragma once
#ifndef CMODELX_H
#define CMODELX_H
#include <vector>    //Vectorクラスのインクルード(動的配列)
#include"CMatrix.h"  //マトリックスクラスのインクルード
#include "CMyShader.h" //シェーダーのインクルード

class CModelX;       //CModelXクラスの宣言
class CModelXFrame;     //CModelXFrameクラスの宣言
class CMesh;
class CMaterial;
class CSkinWeights;
class CAnimationSet;
class CAnimation;
class CAnimationKey;

#define MODEL_FILE "res\\ラグナ.x"

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
	friend CMyShader;
	friend CAnimation;
	friend CAnimationSet;
	friend CModelXFrame;
public:
	//シェーダーを使った描画
	void RenderShader(CMatrix* m);

	//アニメーションセットの追加
	void AddAnimationSet(const char* file);

	bool IsLoaded();

	/*
	アニメーションを抜き出す
	idx:分割したいアニメーションセット
	start:分割したいアニメーションの開始時間
	end:分割したいアニメーションの終了時間
	name:追加するアニメーションセットの名前
	*/
	void CModelX::SeparateAnimationSet(int idx, int start, int end, char* name);

	void AnimateVertex(CMatrix*);

	//マテリアル配列の取得
	std::vector<CMaterial*>& Material();

	//マテリアルの検索
	CMaterial* FindMaterial(char* name);

	//頂点にアニメーションを適用
	void AnimateVertex();
	//スキンウェイトのフレーム番号設定
	void SetSkinWeightFrameIndex();

	std::vector<CModelXFrame*>& Frames();

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
	//シェーダー用スキンマトリックス
	CMatrix* mpSkinningMatrix;
	CMyShader mShader; //シェーダーのインスタンス

	bool mLoaded;

	std::vector<CMaterial*> mMaterial; //マテリアル配列

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
	friend CMyShader;
	friend CAnimationSet;
	friend CAnimation;
	friend CModelX;
public:
	CModelXFrame();

	const CMatrix& CombinedMatrix();

	//合成行列の作成
	void AnimateCombined(CMatrix* parent);

	void Render();
	//コンストラクタ
	CModelXFrame(CModelX* model);

	//デストラクタ
	~CModelXFrame();
	int Index();
private:
	CMatrix mCombinedMatrix;

	CMesh* mpMesh;
	std::vector<CModelXFrame*> mChild;  //子フレームの配列
	CMatrix mTransformMatrix;           //変換行列
	char* mpName;                       //フレーム名
	int mIndex;                         //フレーム番号
	
};



class CMesh
{
	friend CMyShader;
public:
	//頂点バッファの作成
	void CreateVertexBuffer();

	void AnimateVertex(CMatrix*);
	//頂点にアニメーション適用
	void AnimateVertex(CModelX* model);

	//スキンウェイトにフレーム番号を設定する
	void SetSkinWeighFrameIndex(CModelX* model);

	void Render();

	//コンストラクタ
	CMesh();

	//デストラクタ
	~CMesh();

	//読み込み処理
	void Init(CModelX* model);

private:
	//マテエリアル毎の面数
	std::vector<int> mMaterialVertexCount;

	//頂点バッファ識別子
	GLuint mMyVertexBufferId;

	//テクスチャ座標データ
	float* mpTextureCoords;

	CVector* mpAnimationVertex; //アニメーション用頂点
	CVector* mpAnimationNormal; //アニメーション用法線

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
	friend CMyShader;
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
	CAnimationSet();
	void AnimateMatrix(CModelX* model);
	std::vector<CAnimation*>& Animation();
	float Time();
	float MaxTime();
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
	CAnimation();
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
	friend CModelX;
	friend CAnimation;
	friend CAnimationSet;
private:
	//時間
	float mTime;

	//行列
	CMatrix mMatrix;
};