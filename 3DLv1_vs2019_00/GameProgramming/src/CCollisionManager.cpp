#include "CCollisionManager.h"
#include "CCollider.h"

//�}�l�[�W���̃C���X�^���X
CCollisionManager* CCollisionManager::mpInstance = nullptr;

void CCollisionManager::Collision(CCollider* c, int range)
{
	CCollider* task = (CCollider*)mHead.mpNext;

	while (task->mpNext)
	{
		if (task->mPriority <= c->mPriority + range)
		{
			break;
		}
		task = (CCollider*)task->mpNext;
	}
	while (task->mpNext)
	{
		if (task->mPriority <= c->mPriority - range)
		{
			break;
		}

		if (c->mpParent && c != task)c->mpParent->Collision(c, task);
		task = (CCollider*)task->mpNext;
	}
}

//�C���X�^���X�̎擾
CCollisionManager* CCollisionManager::Instance()
{
	if (mpInstance == nullptr)
	{
		mpInstance = new CCollisionManager();
	}
	return mpInstance;
}
