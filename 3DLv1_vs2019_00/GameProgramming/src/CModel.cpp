#include "CModel.h"
//標準入力のインクルード
#include <stdio.h>

//モデルファイルの入力
//Load(モデルファイル名,マテリアルファイル名)
void CModel::Load(char* obj, char* mtl)
{
	//ファイルポインタ変数の作成
	FILE* fp;

	//ファイルからデータを入力
	//入力エリアを作成する
	char buf[256];

	//ファイルのオープン
	//fopen(ファイル名,モード)
	//オープンできないときはNULLを返す
	fp = fopen(mtl, "r");
	
	//ファイルオープンエラーの設定
	//fpがNULLの場合はエラー
	if (fp == NULL)
	{
		//コンソールにエラーを出力して戻る
		printf("%s file open error\n", mtl);
		return;
	}
	
	//ファイルから1桁入力
	//fgets(入力エリア,エリアサイズ,ファイルポインタ)
	//ファイルの最後になるとNULLを返す
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		//入力した値をコンソールに出力する
		printf("%s", buf);
	
	}
	
	//ファイルのクローズ
	fclose(fp);
	fp = fopen(obj, "r");

	if (fp == NULL)
	{
		printf("%s file open error\n", obj);
	}

	while (fgets(buf,sizeof(buf),fp) != NULL) 
	{
		printf("%s", buf);
	}

	fclose(fp);
}
