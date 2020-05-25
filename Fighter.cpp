#include "Fighter.h"

CFighter::CFighter() :
	CPlane(), m_pszGunModel(new char[7])
{
	cout << "CFighter Default Constructor" << endl;
	strcpy(m_pszGunModel, "No gun");
}

CFighter::CFighter(const char* model, const char* gunModel) :
	CPlane(model), m_pszGunModel(new char[strlen(gunModel) + 1])
{
	cout << "CFighter Constructor" << endl;
	strcpy(m_pszGunModel, gunModel);
}

CFighter::CFighter(const CFighter& obj) :
	CPlane(obj), m_pszGunModel(new char[strlen(obj.m_pszGunModel) + 1])
{
	cout << "CFighter Copy Constructor" << endl;
	strcpy(m_pszGunModel, obj.m_pszGunModel);
}

CFighter::~CFighter()
{
	cout << "CFighter Destructor" << endl;
	delete[] m_pszGunModel;
}

void CFighter::ShowArmament()
{
	cout << "Gun model: " << m_pszGunModel << endl;
}

void CFighter::ShowFunctionality()
{
	cout << "Shooting" << endl;
}

void CFighter::ShowFullInformation()
{
	cout << "Model: " << m_pszModel << endl
		<< "Airage: " << m_dblAirage << " hours" << endl;
	cout << "Armament: " << endl;
	ShowArmament();
	cout << "Functionality: " << endl;
	ShowFunctionality();
	cout << "-------------------------" << endl;
}
CFighter& CFighter::operator=(CFighter& obj)
{
	if (this != &obj)
	{
		cout << "CFighter operator=" << endl;
		delete[] m_pszGunModel;
		m_pszGunModel = new char[strlen(obj.m_pszGunModel) + 1];
		strcpy(m_pszGunModel, obj.m_pszGunModel);
		CPlane::operator=(obj);
	}
	return *this;
}


