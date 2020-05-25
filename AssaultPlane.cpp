#include "AssaultPlane.h"

CAssaultPlane::CAssaultPlane() :
	CPlane(), CFighter(), CBomber()
{
	cout << "CAssaultPlane Default Constructor" << endl;
}

CAssaultPlane::CAssaultPlane(const char* model, const char* gunModel, const char* bombModel) :
	CPlane(model), CFighter(model, gunModel), CBomber(model, bombModel)
{
	cout << "CAssaultPlane Constructor" << endl;
}

CAssaultPlane::CAssaultPlane(const CAssaultPlane& obj) :
	CPlane(obj), CFighter(obj), CBomber(obj)
{
	cout << "CAssaultPlane Copy Constructor" << endl;
}

CAssaultPlane::~CAssaultPlane()
{
	cout << "CAssaultPlane Destructor" << endl;
}

void CAssaultPlane::ShowArmament()
{
	CFighter::ShowArmament();
	CBomber::ShowArmament();
}

void CAssaultPlane::ShowFunctionality()
{
	CFighter::ShowFunctionality();
	CBomber::ShowFunctionality();
}

void CAssaultPlane::ShowFullInformation()
{
	cout << "Model: " << m_pszModel << endl
		<< "Airage: " << m_dblAirage << " hours" << endl;
	cout << "Armament: " << endl;
	ShowArmament();
	cout << "Functionality: " << endl;
	ShowFunctionality();
	cout << "-------------------------" << endl;
}

CAssaultPlane& CAssaultPlane::operator=(CAssaultPlane& obj)
{
	if (this != &obj)
	{
		cout << "CAssaultPlane operator=" << endl;
		CFighter::operator=(obj);
		CBomber::operator=(obj);
	}
	return *this;
}
