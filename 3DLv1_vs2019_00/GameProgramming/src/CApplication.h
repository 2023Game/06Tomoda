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

	//�G�̃C���X�^���X
	CXEnemy mXEnemy;

	//�L�����N�^�̃C���X�^���X
	CXPlayer mXPlayer;

	CMatrix mMatrix;

	CModelX mModelX;

	static CUi* spUi;

	CColliderMesh mColliderMesh;

	//�O�p�R���C�_�̍쐬
	//CColliderTriangle mCColliderTriangle;
	//CColliderTriangle mCColliderTriangle2;

	//���f���r���[�̋t�s��
	static CMatrix mModelViewInverse;

	//C5���f��
	CModel mModelC5;
	static CTaskManager mTaskManager;
	CModel mBackGround; //�w�i���f��
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//�Q�[���I�[�o�[

	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
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
	
	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;
	//CCharacter�̃|�C���^�̉ϒ��z��
//	std::vector<CCharacter*> mCharacters;
public:
	
	~CApplication();

	static CUi* Ui();

	//���f���r���[�s��̎擾
	static const CMatrix& ModelViewInverse();

//	static CTaskManager* TaskManager();
	static CTexture* Texture();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};