#include "Plane.h"

CPlane::CPlane() :
	m_pszModel(new char[9]), m_dblAirage(0.0)
{
	cout << "CPlane Default Constructor" << endl;
	strcpy(m_pszModel, "No model");
}

CPlane::CPlane(const char* model) :
	m_pszModel(new char[strlen(model) + 1]), m_dblAirage(0.0)
{
	cout << "CPlane Constructor" << endl;
	strcpy(this->m_pszModel, model);

}

CPlane::CPlane(const CPlane& obj) :
	m_dblAirage(obj.m_dblAirage), m_pszModel(new char[strlen(obj.m_pszModel) + 1])
{
	cout << "CPlane Copy Constructor" << endl;
	strcpy(m_pszModel, obj.m_pszModel);
}

CPlane::~CPlane()
{
	cout << "CPlane Destructor" << endl;
	delete[] m_pszModel;
}

void CPlane::SetAirage(double airage)
{
	m_dblAirage = airage;
}

double CPlane::GetAirage()
{
	return m_dblAirage;
}

void CPlane::ShowArmament()
{
	cout << "Armament: nothing" << endl;
	cout << "-------------------------" << endl;
}

CPlane& CPlane::operator=(const CPlane& obj)
{
	if (this != &obj)
	{
		cout << "CPlane operator=" << endl;
		delete[] m_pszModel;
		m_pszModel = new char[strlen(obj.m_pszModel) + 1];
		strcpy(m_pszModel, obj.m_pszModel);
		m_dblAirage = obj.m_dblAirage;
	}
	return *this;
}

