#pragma once
#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy :public CXCharacter
{
public:
    void Collision(CCollider* m, CCollider* o);

    void Init(CModelX* model);
    CXEnemy();
private:
    //ƒRƒ‰ƒCƒ_‚ÌéŒ¾
    CCollider mColSphereBody;    //‘Ì
    CCollider mColSphereHead;    //“ª
    CCollider mColSphereSword;    //Œ•
};