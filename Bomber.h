#include "Plane.h"
#ifndef Bomber
#define Bomber
class CBomber :
	virtual public CPlane
{
protected:
	char* m_pszBombModel;
public:
	CBomber();
	CBomber(const char* model, const char* bombModel);
	CBomber(const CBomber& obj);
	virtual ~CBomber();
	void ShowArmament();
	virtual void ShowFunctionality();
	virtual void ShowFullInformation();
	CBomber& operator=(CBomber&);
};
#endif
#pragma once
