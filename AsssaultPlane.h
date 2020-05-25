#include "Fighter.h"
#include "Bomber.h"
#ifndef AssaultPlane
#define AssaultPlane
class CAssaultPlane :
	public CFighter, public CBomber
{
public:
	CAssaultPlane();
	CAssaultPlane(const char* model, const char* gunModel, const char* bombModel);
	CAssaultPlane(const CAssaultPlane& obj);
	virtual ~CAssaultPlane();
	void ShowArmament();
	virtual void ShowFunctionality();
	virtual void ShowFullInformation();
	CAssaultPlane& operator=(CAssaultPlane&);
};
#endif
#pragma once
