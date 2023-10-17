#include "CMatrix.h"
//•W€“üo—ÍŠÖ”‚ÌƒCƒ“ƒNƒ‹[ƒh
#include <stdio.h>

void CMatrix::Print()
{
	printf("%10f %10f %10f %10f\n",
		mM[0][0], mM[0][1], mM[0][2], mM[0][3]);
	printf("%10f %10f %10f %10f\n",
		mM[1][0], mM[1][1], mM[1][2], mM[1][3]);
	printf("%10f %10f %10f %10f\n",
		mM[2][0], mM[2][1], mM[2][2], mM[2][3]);
	printf("%10f %10f %10f %10f\n",
		mM[3][0], mM[3][1], mM[3][2], mM[3][3]);

}

CMatrix::CMatrix()
{
	Identity();
}

CMatrix CMatrix::Identity()
{
	mM[0][0] = 1, mM[0][1] = 0, mM[0][2] = 0, mM[0][3] = 0;
	mM[1][0] = 0, mM[1][1] = 1, mM[1][2] = 0, mM[1][3] = 0;
	mM[2][0] = 0, mM[2][1] = 0, mM[2][2] = 1, mM[2][3] = 0;
	mM[3][0] = 0, mM[3][1] = 0, mM[3][2] = 0, mM[3][3] = 1;
	
	return *this;
}

float CMatrix::M(int r, int c) const
{
	return mM[r][c];
}

//Šg‘åk¬s—ñ‚Ìì¬
//Scale(”{—¦X,”{—¦Y,”{—¦Z)
CMatrix CMatrix::Scale(float sx, float sy ,float sz)
{
	mM[0][0] = sx, mM[0][1] = 0, mM[0][2] = 0, mM[0][3] = 0;
	mM[1][0] = 0, mM[1][1] = sy, mM[1][2] = 0, mM[1][3] = 0;
	mM[2][0] = 0, mM[2][1] = 0, mM[2][2] = sz, mM[2][3] = 0;
	mM[3][0] = 0, mM[3][1] = 0, mM[3][2] = 0, mM[3][3] = 1;

	//‚±‚Ìs—ñ‚ğ•Ô‚·
	return *this;

}