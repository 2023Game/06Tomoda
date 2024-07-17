#pragma once

#ifndef CXPLAYER_H
#define CXPLAYER_H
#include <vector>
#include "CXCharacter.h""
#include "CInput.h"
class CXCharacter;
class CXPlayer:public CXCharacter
{
	friend CXCharacter;
public:
	//XVˆ—
	void Update();

	CInput mInput;
};

#endif // !CXPLAYER_H
