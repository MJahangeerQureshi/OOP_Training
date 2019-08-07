//login
//principle :-> set budget, set workhours, set schedule
//teacher :-> set student marks
//janitor :-> show schedule
//students :-> show marks
#include <iostream>
#include <string>
#include <fstream>
#include "include/data.h"

using namespace std;

void PrincipleConsole(Principle P, Teacher T[3], Janitorial J[3])
{
    string input_principle_choice;
    string input_teacher_or_janitor;
    string input_budget;
    int input_workhours;
    string input_schedule;
    cout<<"To edit the budget press 1, to set workhours press 2, to set schedules for the janitorial staff press 3"<<endl;
    cin>>input_principle_choice;
    if(!input_principle_choice.compare("1"))
    {
        cout<<"Please type the value of the desired budget"<<endl;
        cin>>input_budget;
        P.SetBudget(input_budget);
        cout<<"The budget is now Rs"<<P.GetBudget()<<endl;

    }
    else if(!input_principle_choice.compare("2"))
    {
        cout<<"Please type 1 for teachers and 2 for the janitorial staff."<<endl;
        for (;;)
        {
            cin>>input_teacher_or_janitor;
            if (input_teacher_or_janitor.compare("1") or input_teacher_or_janitor.compare("2"))
            {
                cout<<"Invalid entry please enter 1 or 2"<<endl;
            }
            else
            {
                if(input_teacher_or_janitor=="1")
                {   
                    cout<<"Please enter the workhours"<<endl;
                    cin>>input_workhours;
                    for (int i=0;i<3;i++)
                    {
                        T[i].SetWorkhours(input_workhours);
                    }
                    cout<<"The workhours for the teachers have been set to "<<input_workhours<<endl;
                }
                else
                {   
                    cout<<"Please enter the workhours"<<endl;
                    cin>>input_workhours;
                    for (int i=0;i<3;i++)
                    {
                        J[i].SetWorkhours(input_workhours);
                    }
                    cout<<"The workhours for the janitors have been set to "<<input_workhours<<endl;
                }
            }
        }
        
    }
    else if(!input_principle_choice.compare("3"))
    {   
        cout<<"Please enter the schedule for the janitors"<<endl;
        cin>>input_workhours;
        for (int i=0;i<3;i++)
        {
            J[i].SetSchedule(input_schedule);
        }
        cout<<"The schedule for the janitorial staff has been set to "<<input_schedule<<endl;
    }
    else
    {
        cout<<"You seemed to have entered an invalid value, please select values from 1-3 or to terminate the session type close."<<endl;
    }
}

void TeacherConsole(Teacher T, Students S[3])
{
    string teacher_student_cnic;
    int teacher_student_marks;
    string teachers_subject;
    
    teachers_subject = T.GetSubject();
    
    cout<<"Please enter the cnic of the student to enter their marks"<<endl;
    cin>>teacher_student_cnic;
    
    for (int i=0; i<3; i++)
    {
        if(!S[i].GetCnic().compare(teacher_student_cnic))
        {
           cout<<"Please enter the appropriate marks for "<<S[i].GetName()<<" (CNIC: "<<teacher_student_cnic<<") for the subject of "<<T.GetSubject()<<endl;
           cin>>teacher_student_marks;
           if(T.GetSubject().compare("Math"))
           {
               S[i].SetMathMarks(teacher_student_marks);
               
           }
           else if(T.GetSubject().compare("Physics"))
           {
               S[i].SetPhyMarks(teacher_student_marks);
           }
           else if(T.GetSubject().compare("Chemistry"))
           {
               S[i].SetChemMarks(teacher_student_marks);
           }
           else
           {
               cout<<"This student doesnt seem to be in your class."<<endl;
           }
        cout<<"The student named "<<S[i].GetName()<<" (CNIC: "<<teacher_student_cnic<<") marks have been set to "<<teacher_student_marks<<endl;   
        }
    }
    

}

void JanitorConsole(Janitorial J)
{
    cout<<"Your Schedule for today is to clean the "<<J.GetSchedule()<<endl;
}

void StudentConsole(Students S)
{
    cout<<"Your marks are as follows"<<endl;
    cout<<"Physics: "<<S.GetPhyMarks()<<"/100"<<endl;
    cout<<"Maths: "<<S.GetMathMarks()<<"/100"<<endl;
    cout<<"Chemistry: "<<S.GetChemMarks()<<"/100"<<endl;
    cout<<"\n"<<endl; 
}

int main(){
    //*************************Data Declaration********************************
    Principle P("Dr Ali","37405", "000", "qwerty123", 40, "100000");//P.Display();
    
    Teacher T1("Rashid", "78965", "159", "euclid", 40, "Math");//T1.Display();
    Teacher T2("Shafqat", "78325", "785", "ferrofluid", 40, "Physics");//T2.Display();
    Teacher T3("Asad", "74325", "963", "potatiumnitrate", 40, "Chemistry");//T3.Display();
    
    Janitorial J1("Saad", "45687", "124", "123", 40, "Bathrooms");//J1.Display();
    Janitorial J2("Hassan", "45632", "124", "asd", 40, "Bathrooms");//J2.Display();
    Janitorial J3("Afsand", "95136", "124", "542as", 40, "Bathrooms");//J3.Display();
    
    Students S1("Saad", "43544", "patanahi", 54, 74, 23);//S1.Display();
    Students S2("Sameer", "46824", "kyamatlab",45, 23, 78);//S2.Display();
    Students S3("Usama", "32145", "kyabola",97, 87, 98);//S3.Display();

    int loopcnt=0;
    string input;
    string passwords[10]={
        P.GetPassword(),
        T1.GetPassword(),
        T2.GetPassword(),
        T3.GetPassword(),
        J1.GetPassword(),
        J2.GetPassword(),
        J3.GetPassword(),
        S1.GetPassword(),
        S2.GetPassword(),
        S3.GetPassword()};
    cout<<"Welcome to the School Managment System, To start please enter your passcode to end please type close."<<endl;
    
    for (;;)
    {
        if(loopcnt<1)
        {
            cout<<"Password: ";
            cin>>input;
        }
        else
        {
            loopcnt+=1;
        }
        
        
        if (!input.compare("close")){cout<<"Terminating Session"<<endl;break;}
        else
        {
            for (int i=0;i<10;i++)
            {
                if(!input.compare(passwords[i]))
                {   
                    if (i == 0)
                    {
                        cout<<"Welcome "<<P.GetName()<<endl;
                        Teacher T[3] = {T1, T2, T3};
                        Janitorial J[3] = {J1, J2, J3};
                        PrincipleConsole(P, T, J);
                    }
                    else if(i==1)
                    {
                        cout<<"Welcome "<<T1.GetName()<<endl;
                        Students S[3] = {S1, S2, S3};
                        TeacherConsole(T1, S);
                    }
                    else if(i==2)
                    {
                        cout<<"Welcome "<<T2.GetName()<<endl;
                        Students S[3] = {S1, S2, S3};
                        TeacherConsole(T2, S);
                    }
                    else if(i==3)
                    {
                        cout<<"Welcome "<<T3.GetName()<<endl;
                        Students S[3] = {S1, S2, S3};
                        TeacherConsole(T3, S);
                    }
                    else if(i==4)
                    {
                        cout<<"Welcome "<<J1.GetName()<<endl;
                        JanitorConsole(J1);
                    }
                    else if(i==5)
                    {
                        cout<<"Welcome "<<J2.GetName()<<endl;
                        JanitorConsole(J1);
                    }
                    else if(i==6)
                    {
                        cout<<"Welcome "<<J3.GetName()<<endl;
                        JanitorConsole(J1);
                    }
                    else if(i==7)
                    {
                        cout<<"Welcome "<<S1.GetName()<<endl;
                        StudentConsole(S1);
                    }
                    else if(i==8)
                    {
                        cout<<"Welcome "<<S2.GetName()<<endl;
                        StudentConsole(S2);
                    }
                    else if(i==9)
                    {
                        cout<<"Welcome "<<S3.GetName()<<endl;
                        StudentConsole(S3);
                    }
                    else if(i==10)
                    {
                        S3.Display();
                    }
                }
                
            }
        }
    
    }
    return 0;
}