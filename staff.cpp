#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

class STAFF{
protected:
	string mName;
	__int16 mYear;
public:
	STAFF();	// constructor
	~STAFF();	// destructor
	virtual void Input();
	virtual void Output();
};
void delete_cache(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize> :: max(), '\n');
}
STAFF :: STAFF(){
	mName = "";
	mYear = 0;
}
STAFF :: ~STAFF(){
	mName = "";
	mYear = 0;
}
void STAFF :: Input(){
	cout << "\tEnter the name: ";
	delete_cache();
	getline(cin, mName);
	cout << "\tYear: ";
	cin >> mYear;
}
void STAFF :: Output(){
	cout << "\tName: " << mName << endl;
	cout << "\tYear: " << mYear << endl;
}
//class PRODUCTION STAFF
class PRODUCTION_STAFF : public STAFF{
private:
	__int16 number_production;
public:
	PRODUCTION_STAFF(){
		number_production = 0;
	}

	void Input();
	void Output();
	__int32 Salary();
};
void PRODUCTION_STAFF :: Input(){
	STAFF :: Input();
	cout << "\tNumber of production: ";
	cin >> number_production;
}
void PRODUCTION_STAFF :: Output(){
	STAFF :: Output();
	cout << "\tNumber of production: " << number_production << endl;
	cout << "\tSalary: " << Salary();
}
__int32 PRODUCTION_STAFF :: Salary(){
	return number_production * 10000 + 100000 + (2020 - mYear) * 20000; 
}
// class OFFICER STAFF
class OFFICER_STAFF : public STAFF{
private:
	__int16 mWage;	// muc luong 
	__int16 mDayOff;	// ngay nghi
public:
	OFFICER_STAFF(){
		mWage = mDayOff = 0;
	}
	void Input();
	void Output();
	__int32 Salary();
};
void OFFICER_STAFF :: Input(){
	STAFF :: Input();
	cout << "\tWage: ";
	cin >> mWage;
	cout << "\tDay off: ";
	cin >> mDayOff;
}
void OFFICER_STAFF :: Output(){
	STAFF :: Output();
	cout << "\tWage: " << mWage << endl;
	cout << "\tDay off: " << mDayOff << endl;
	cout << "\tSalary: " << Salary();
}
__int32 OFFICER_STAFF :: Salary(){
	return mWage - mDayOff * 10000 + 100000 + (2020 - mYear) * 20000;
}
//clas management staff
class MANAGEMENT_STAFF{
public:
	vector <STAFF*> MANA_STAFF;
public:
	void enter_data();
	void display_data();
	void sort_data(vector <STAFF*>*);
};
//enter data
void MANAGEMENT_STAFF :: enter_data(){
	__int16 selection;
	STAFF *staff;
	cout << "\t1. Production staff." << endl;
	cout << "\t2. Officer staff." << endl;
	cout << "\n\t\tYour selection: " ;
	cin >> selection;
	switch(selection){
		case 1:
			staff = new PRODUCTION_STAFF();
			staff -> Input();
			MANA_STAFF.push_back(staff);
			break;
		case 2:
			staff = new OFFICER_STAFF();
			staff -> Input();
			MANA_STAFF.push_back(staff);
			break;

			default:
				break;
		}
}
// display data
void MANAGEMENT_STAFF :: display_data(){
	//for(vector<STAFF*> :: iterator it = MANA_STAFF.begin(); it != MANA_STAFF.end(); it++)
		// it -> Output();
	for(int i = 0; i < MANA_STAFF.size(); i++){
		MANA_STAFF[i] -> Output();
		cout << "\n\t======================\n";
	}
}

void MANAGEMENT_STAFF :: sort_data( vector<STAFF*> *MANA_STAFF){
	sort(MANA_STAFF -> begin(), MANA_STAFF -> end());
}
int main()
{
  	MANAGEMENT_STAFF MN_staff;
  	__int16 select;
  	do{
  		system("cls");
  	cout << "STAFF MANAGEMENT PROGRAM" << endl;
  	cout << "------------------------" << endl << endl;
  	cout << "1.Enter data." << endl;
  	cout << "2.Display data." << endl;
  	cout << "3.Sort data." << endl;
  	cout << "4.Exit" << endl;
  	cout << "\n\t\t Your select: ";
  	cin >> select;
  	switch(select){
  		case 1: 
  			MN_staff.enter_data();
  			break;
  		case 2:
  			MN_staff.display_data();
  			system("pause");
  			break;
  		case 3:
  			MN_staff.sort_data(&MN_staff.MANA_STAFF);
  			break;
  		case 4:
  			exit(1);
  			break;
  	}
  }while(select != 4);
    return 0;
}
