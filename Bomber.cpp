#include "Bomber.h"

CBomber::CBomber() :
	CPlane(), m_pszBombModel(new char[8])
{
	cout << "CBomber Default Constructor" << endl;
	strcpy(m_pszBombModel, "No bomb");
}

CBomber::CBomber(const char* model, const char* bombModel) :
	CPlane(model), m_pszBombModel(new char[strlen(bombModel) + 1])
{
	cout << "CBomber Constructor" << endl;
	strcpy(m_pszBombModel, bombModel);
}

CBomber::CBomber(const CBomber& obj) :
	CPlane(obj), m_pszBombModel(new char[strlen(obj.m_pszBombModel) + 1])
{
	cout << "CBomber Copy Constructor" << endl;
	strcpy(m_pszBombModel, obj.m_pszBombModel);
}

CBomber::~CBomber()
{
	cout << "CBomber Destructor" << endl;
	delete[] m_pszBombModel;
}

void CBomber::ShowArmament()
{
	cout << "Bomb model: " << m_pszBombModel << endl;
}

void CBomber::ShowFunctionality()
{
	cout << "Bombarding" << endl;
}

void CBomber::ShowFullInformation()
{
	cout << "Model: " << m_pszModel << endl
		<< "Airage: " << m_dblAirage << " hours" << endl;
	cout << "Armament: " << endl;
	ShowArmament();
	cout << "Functionality: " << endl;
	ShowFunctionality();
	cout << "-------------------------" << endl;
}
CBomber& CBomber::operator=(CBomber& obj)
{
	if (this != &obj)
	{
		cout << "CBomber operator=" << endl;
		delete[] m_pszBombModel;
		m_pszBombModel = new char[strlen(obj.m_pszBombModel) + 1];
		strcpy(m_pszBombModel, obj.m_pszBombModel);
		CPlane::operator=(obj);
	}
	return *this;
}
