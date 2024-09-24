#include "CActionCamera.h"
#include "glut.h"
#include "CXCharacter.h"

#define TURN_V 1.0f  //��]���x

CActionCamera* CActionCamera::spInstance = nullptr;

CActionCamera::CActionCamera()
{
	spInstance = this;
}

CActionCamera* CActionCamera::Instance()
{
	return spInstance;
}

void CActionCamera::Set(float distance, float xaxis, float yaxis)
{
	Rotation(CVector(xaxis, yaxis, 0.0f));
	Scale(CVector(0.0f, 0.0f, distance));
	mUp = CVector(0.0f, 1.0f, 0.0f);
	spInstance = this;
}

void CActionCamera::Update()
{
	//�J�����̑O��
	CVector cameraZ = CActionCamera::Instance()->VectorZ();
	//�J�����̍�����
	CVector cameraX = CActionCamera::Instance()->VectorX();
	//�L�����N�^�̑O��
	CVector charZ = mMatrixRotate.VectorZ();
	//XZ���ʂɂ��Đ��K��
	cameraZ.Y(0.0f); cameraZ = cameraZ.Normalize();
	cameraX.Y(0.0f); cameraX = cameraX.Normalize();
	charZ.Y(0.0f); charZ = charZ.Normalize();
	//�ړ������̐ݒ�
	CVector move;
	if (mInput.Key('A')) {
		move = move + cameraX;
	}
	if (mInput.Key('D')) {
		move = move - cameraX;
	}
	if (mInput.Key('W')) {
		move = move + cameraZ;
	}
	if (mInput.Key('S')) {
		move = move - cameraZ;
	}

	//�ړ�����
	if (move.Length() > 0.0f)
	{
		//�V��
		const float MARGIN = 0.06f;
		//���K��
		move = move.Normalize();
		//�����̌����ƌ��������������ŊO��
		float cross = charZ.Cross(move).Y();
		//�����̌����ƌ��������������œ���
		float dot = charZ.Dot(move);
		//�O�ς��v���X�͍���]
		if (cross > MARGIN) {
			mRotation.Y(mRotation.Y() + 5.0f);
		}
		//�O�ς��}�C�i�X�͉E��]
		else if (cross < -MARGIN) {
			mRotation.Y(mRotation.Y() - 5.0f);
		}
		//�O��̌����������Ƃ����ς�1.0
		else if (dot < 1.0f - MARGIN) {
			mRotation.Y(mRotation.Y() - 5.0f);
		}
		//�ړ������ֈړ�
		mPosition = mPosition + move * 0.1f;
	}

	if (mInput.Key('J'))
	{
		mRotation = mRotation + CVector(0.0f, TURN_V, 0.0f);
	}

	if (mInput.Key('L'))
	{
		mRotation = mRotation - CVector(0.0f, TURN_V, 0.0f);
	}

	if (mInput.Key('I'))
	{
		mRotation = mRotation - CVector(TURN_V, 0.0f, 0.0f);

		if (mRotation.X() < -80.0f)
		{
			mRotation.X(-80.0f);
		}
	}

	if (mInput.Key('K'))
	{
		mRotation = mRotation + CVector(TURN_V, 0.0f, 0.0f);

		if (mRotation.X() > 80.0f)
		{
			mRotation.X(80.0f);
		}
	}


	CTransform::Update();
	mCenter = mPosition;
	mEye = mPosition + mMatrixRotate.VectorZ() * mScale.Z();

}

void CActionCamera::Render()
{
	gluLookAt(mEye.X(), mEye.Y(), mEye.Z(), mCenter.X(), mCenter.Y(), mCenter.Z(), mUp.X(), mUp.Y(), mUp.Z());
	//���f���r���[�s��̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelView.M());

}

CVector CActionCamera::VectorX()
{
	return CVector(-mModelView.M(0, 0), -mModelView.M(1, 0), -mModelView.M(2, 0));
}

CVector CActionCamera::VectorZ()
{
	return CVector(-mModelView.M(0, 2), -mModelView.M(1, 2), -mModelView.M(2, 2));
}