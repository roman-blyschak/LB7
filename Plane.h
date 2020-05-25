#include <iostream>
#include <cstring>
using namespace std;
#ifndef Plane
#define Plane
class CPlane
{
protected:
	char* m_pszModel;
	double m_dblAirage;
public:
	CPlane();
	CPlane(const char* model);
	CPlane(const CPlane& obj);
	virtual ~CPlane();
	void SetAirage(double);
	double GetAirage();
	void ShowArmament();
	virtual void ShowFunctionality() = 0;
	virtual void ShowFullInformation() = 0;
	CPlane& operator=(const CPlane&);
};
#endif
#pragma once
