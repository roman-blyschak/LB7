#include "Plane.h"
#ifndef Fighter
#define Fighter
class CFighter :
	virtual public CPlane
{
protected:
	char* m_pszGunModel;
public:
	CFighter();
	CFighter(const char* model, const char* gunModel);
	CFighter(const CFighter& obj);
	virtual ~CFighter();
	void ShowArmament();
	virtual void ShowFunctionality();
	virtual void ShowFullInformation();
	CFighter& operator=(CFighter&);

};
#endif
