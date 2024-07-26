#pragma once
#include "CTexture.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CInput.h"
#include "CFont.h"
#include <vector>
#include "CSound.h"
#include "CModel.h"
#include "CCharacter3.h"
#include "CTaskManager.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"
#include "CUi.h"
#include "CModelX.h"
#include "CMatrix.h"
#include "CXCharacter.h"
#include "CXPlayer.h"
#include "CXEnemy.h"

class CApplication
{
private:
	CModelX mKnight;

	//敵のインスタンス
	CXEnemy mXEnemy;

	//キャラクタのインスタンス
	CXPlayer mXPlayer;

	CMatrix mMatrix;

	CModelX mModelX;

	static CUi* spUi;

	CColliderMesh mColliderMesh;

	//三角コライダの作成
	//CColliderTriangle mCColliderTriangle;
	//CColliderTriangle mCColliderTriangle2;

	//モデルビューの逆行列
	static CMatrix mModelViewInverse;

	//C5モデル
	CModel mModelC5;
	static CTaskManager mTaskManager;
	CModel mBackGround; //背景モデル
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//ゲームオーバー

	enum class EState
	{
		ESTART,	//ゲーム開始
		EPLAY,	//ゲーム中
		ECLEAR,	//ゲームクリア
		EOVER,	//ゲームオーバー
	};
	EState mState;
//	CCharacter mRectangle;
	CPlayer* mpPlayer;
	static CTexture mTexture;
	CEnemy* mpEnemy;
//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	
	//CCharacter3 mCharacter;
	CPlayer mPlayer;
	
	//モデルクラスのインスタンス作成
	CModel mModel;
	//CCharacterのポインタの可変長配列
//	std::vector<CCharacter*> mCharacters;
public:
	
	~CApplication();

	static CUi* Ui();

	//モデルビュー行列の取得
	static const CMatrix& ModelViewInverse();

//	static CTaskManager* TaskManager();
	static CTexture* Texture();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};