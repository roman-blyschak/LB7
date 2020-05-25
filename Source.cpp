#include "AssaultPlane.h"

using namespace std;

int main()
{
	cout << "----- Creating objects -----" << endl;
	CFighter f1("MIG-1", "Minigun");
	f1.SetAirage(20.1);
	f1.ShowFullInformation();

	CBomber b1("WG-5", "FN-12");
	b1.SetAirage(10.0);
	b1.ShowFullInformation();

	CAssaultPlane a1("IL-2", "Minigun-2", "FN-14");
	a1.SetAirage(0.9);
	a1.ShowFullInformation();

	CAssaultPlane a2 = a1;
	a2.ShowFullInformation();

	CAssaultPlane a3(a2);
	a3.ShowFullInformation();

	f1 = a3;
	f1.ShowFullInformation();

	{
		CAssaultPlane a4(a2);
		a4.ShowFullInformation();
	}

	//------------------------------------------------------------------
	cout << "----- Creating reference -----" << endl;

	cout << "----- CPlane &ref1 = f1; -----" << endl;
	CPlane& ref1 = f1;
	ref1.ShowFullInformation();

	cout << "----- ref1 = b1; -----" << endl;
	ref1 = b1;
	ref1.ShowFullInformation();

	cout << "----- CPlane &ref2 = b1; -----" << endl;
	CPlane& ref2 = b1;
	ref2.ShowFullInformation();

	cout << "----- CPlane &ref3 = a1; -----" << endl;
	CPlane& ref3 = a1;
	ref3.ShowFullInformation();

	cout << "----- Creating dynamic objects -----" << endl;

	cout << "----- CPlane* ptr1 = new CFighter(\"F-2\", \"F-Gun\") -----" << endl;
	CPlane* ptr1 = new CFighter("F-2", "F-Gun");
	ptr1->SetAirage(1.2);
	ptr1->ShowArmament();
	ptr1->ShowFunctionality();
	ptr1->ShowFullInformation();

	cout << "----- CPlane* ptr2 = new CBomber(\"B-2\", \"Bomb-2\"); -----" << endl;
	CPlane* ptr2 = new CBomber("B-2", "Bomb-2");
	ptr2->SetAirage(0.2);
	ptr2->ShowArmament();
	ptr2->ShowFunctionality();
	ptr2->ShowFullInformation();

	cout << "----- CPlane* ptr3 = new CAssaultPlane(\"A-2\", \"F-Gun\", \"Bomb-2\"); -----" << endl;
	CPlane* ptr3 = new CAssaultPlane("A-2", "F-Gun", "Bomb-2");
	ptr3->SetAirage(4.2);
	ptr3->ShowArmament();
	ptr3->ShowFunctionality();
	ptr3->ShowFullInformation();

	//------------------------------------------------------------------
	cout << "delete ptr1 " << endl;
	delete ptr1;
	cout << "-------------------------" << endl << "delete ptr2 " << endl;
	delete ptr2;
	cout << "-------------------------" << endl << "delete ptr3 " << endl;
	delete ptr3;
	cout << "-------------------------" << endl;

	return 0;
}

