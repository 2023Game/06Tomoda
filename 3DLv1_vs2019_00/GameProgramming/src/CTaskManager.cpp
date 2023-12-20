#include "CTaskManager.h"

//デフォルトコンストラクタ
CTaskManager::CTaskManager()
{
	mHead.mpNext = &mTail;
	mTail.mpPrev = &mHead;
}

CTaskManager::~CTaskManager(){}

//リストに追加
//Add(タスクのポインタ)
void CTaskManager::Add(CTask * addTask)
{
	CTask* task = mHead.mpNext;

	while (addTask->mPriority < task->mPriority)
	{
		task = task->mpNext;
	}


	//addTaskの次をtask
	addTask->mpNext = task;

	//addタスクの前をtaskの前に
	addTask->mpPrev = task->mpPrev;

	//addTaskの前の次をaddTaskに
	addTask->mpPrev->mpNext = addTask;
	
	//taskの前をaddTaskに
	task->mpPrev = addTask;
}

//更新
void CTaskManager::Update()
{
//先頭から最後まで繰り返し
	CTask* task = mHead.mpNext;
	while (task->mpNext)
	{
		//更新処理を呼ぶ
		task->Update();

		//次へ
		task = task->mpNext;
	}
}

//描画
void CTaskManager::Render()
{

	CTask* task = mTail.mpPrev;
	while (task->mpPrev)
	{
		//描画処理を呼ぶ
		task->Render();

		//次へ
		task = task->mpPrev;

	}
}

void CTaskManager::Remove(CTask* task)
{
	//タスクの前の次を、タスクの次にする
	task->mpPrev->mpNext = task->mpNext;

	//タスクの次の前を、タスクの前にする
	task->mpNext->mpPrev = task->mpPrev;
}

void CTaskManager::Delete()
{
	//先頭から最後まで繰り返し
	CTask* task = mHead.mpNext;
	while (task->mpNext)
	{
		CTask* del = task;

		//次へ
		task = task->mpNext;

		//mEnabledがfalseなら削除
		if (del->mEnabled == false)
		{
			delete del;
		}
	}
}

//タスクマネージャのインスタンス
CTaskManager* CTaskManager::mpInstance = nullptr;

//インスタンスの取得
CTaskManager* CTaskManager::Instance()
{
	//インスタンスがなければ
	if (mpInstance == nullptr)
	{
		//インスタンスを生成する
		mpInstance = new CTaskManager();
	}
	return mpInstance;
}