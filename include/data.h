#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
    string name;
    string cnic;    
public:
    Person(string _name = "unamed", string _cnic = "not given"): name(_name), cnic(_cnic){}

    string GetName(){return name;}
    void SetName(string _name){name = _name;}

    string GetCnic(){return cnic;}
    void SetCnic(string _cnic){cnic = _cnic;}

    virtual ~Person()=0;};
    Person::~Person(){}

class Staff: public Person{
protected:
    string staffno;
    string password;
    int workhours;
public:
    Staff(string _staffno = "", string _password = "", int _workhours=0)
    : staffno(_staffno), password(_password), workhours(_workhours){}

    string GetStaffno(){return staffno;}
    void SetStaffno(string _staffno){staffno = _staffno;}

    string GetPassword(){return password;}
    void SetPassword(string _password){password = _password;}  

    int GetWorkhours(){return workhours;}
    void SetWorkhours(int _workhours){workhours = _workhours;}

    virtual ~Staff()=0;};
    Staff::~Staff(){}

class Principle: public Staff{
private:
    string budget;
public:
    Principle(string _name = "unamed", string _cnic = "not given", string _staffno = "", 
    string _password = "", int _workhours=0, string _budget = ""): 
    budget(_budget){
        name = _name;
        cnic = _cnic;
        staffno = _staffno;
        password = _password;
        workhours = _workhours;
    }

    string GetBudget(){return budget;}
    void SetBudget(string _budget){budget = _budget;} 

    void Display(){
    cout<<"Designation: Principal"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"CNIC: "<<cnic<<endl;
    cout<<"Staffno: "<<staffno<<endl;
    cout<<"password: "<<password<<endl;
    cout<<"Workhours: "<<workhours<<endl;
    cout<<"Budget: Rs "<<budget<<endl;
    cout<<"\n"<<endl;
    }
};

class Teacher: public Staff{
private:;
    string subject;
public:
    Teacher(string _name = "unamed", string _cnic = "not given", string _staffno = "", 
    string _password = "", int _workhours=0, string _subject=""): subject(_subject){
        name = _name;
        cnic = _cnic;
        staffno = _staffno;
        password = _password;
        workhours = _workhours;
    }

    string GetSubject(){return subject;}
    void SetSubject(string _subject){subject = _subject;}  

    void Display(){
    cout<<"Designation: Teacher"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"CNIC: "<<cnic<<endl;
    cout<<"Staffno: "<<staffno<<endl;
    cout<<"password: "<<password<<endl;
    cout<<"Workhours: "<<workhours<<endl;
    cout<<"Subject: "<<subject<<endl;  
    cout<<"\n"<<endl;
    }

    };

class Janitorial: public Staff{
private:
    string schedule;
public:
    Janitorial(string _name = "unamed", string _cnic = "not given", string _staffno = "", 
    string _password = "", int _workhours=0, string _schedule = ""): schedule(_schedule){
        name = _name;
        cnic = _cnic;
        staffno = _staffno;
        password = _password;
        workhours = _workhours;
    }

    string GetSchedule(){return schedule;}
    void SetSchedule(string _schedule){schedule = _schedule;}  

    void DisplaySchedule(){
        cout<<"Hi "<<name<<"your shedule for today is to clean up the "<<schedule<<endl;
    }


    void Display(){
    cout<<"Designation: Janitor"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"CNIC: "<<cnic<<endl;
    cout<<"Staffno: "<<staffno<<endl;
    cout<<"password: "<<password<<endl;
    cout<<"Workhours: "<<workhours<<endl;
    cout<<"Schedule: "<<schedule<<endl;  
    cout<<"\n"<<endl;
    }
};

class Students: public Person{
private:
    string password;
    int phy_marks;
    int math_marks;
    int chem_marks;
public:
    Students(string _name, string _cnic, string _password, int _phy_marks=0, int _math_marks=0, int _chem_marks=0)
    : password(_password), phy_marks(_phy_marks), math_marks(_math_marks), chem_marks(_chem_marks){
        name = _name;
        cnic = _cnic;
    }

    int GetPhyMarks(){return phy_marks;}
    void SetPhyMarks(int _phy_marks){phy_marks = _phy_marks;}
    int GetMathMarks(){return math_marks;}
    void SetMathMarks(int _math_marks){math_marks = _math_marks;}
    int GetChemMarks(){return chem_marks;}
    void SetChemMarks(int _chem_marks){chem_marks = _chem_marks;}
    string GetPassword(){return password;}
    void SetPassword(string _password){password = _password;}  
    
    void DisplayMarks(){
        cout<<"Hi "<<name<<"your marks are as follows "<<endl;
        cout<<"Physics: "<<phy_marks<<endl;
        cout<<"Math: "<<math_marks<<endl;
        cout<<"Chemistry: "<<chem_marks<<endl;
    }


    void Display(){
    cout<<"Designation: Student"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"CNIC: "<<cnic<<endl;
    cout<<"Physics: "<<phy_marks<<"/100"<<endl;
    cout<<"Maths: "<<math_marks<<"/100"<<endl;
    cout<<"Chemistry: "<<chem_marks<<"/100"<<endl;
    cout<<"\n"<<endl; 
    }
};

// Principle P("Dr Ali","37405", "000", "qwerty123", 40, "100000");

// Teacher T1("Azhar", "45641", "154", "patanahi");
// Teacher T2("Shafqat", "78325", "785", "ferrofluid", 40, "Physics");
// Teacher T3("Asad", "74325", "963", "potatiumnitrate", 40, "Chemistry");

// Janitorial J1("Saad", "45687", "124", "123", 40, "Gym");
// Janitorial J2("Hassan", "45632", "124", "asd", 40, "Bathrooms");
// Janitorial J3("Afsand", "95136", "124", "542as", 40, "Hallway");