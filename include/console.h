#include <iostream>
#include <string>
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
    for(;;)
    {   
        cin>>input_principle_choice;
        if (!input_principle_choice.compare("close")){cout<<"Terminating Session"<<endl;break;}
        else if(!input_principle_choice.compare("1"))
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
            cout<<"You seemed to have entered an invalid, value please select values from 1-3, or to terminate the session type close."<<endl;
        }
    }
}


Principle ModifyBudget(string budget,Principle P){
    P.SetBudget(budget);
    return P;
}

Principle ModifyWorkhoursPrinciple(int workshours, Principle P){
    P.SetWorkhours(workshours);
    return P;
}

Teacher ModifyWorkhoursTeacher(int workshours, Teacher T){
    T.SetWorkhours(workshours);
    return T;
}

Janitorial ModifyWorkhoursTeacher(int workshours, Janitorial J){
    J.SetWorkhours(workshours);
    return J;
}

Janitorial ModifySchedule(string schedule, Janitorial J){
    J.SetSchedule(schedule);
}

Students ModifyMarks(int phy_marks, int math_marks, int chem_marks, Students S){
    S.SetPhyMarks(phy_marks);
    S.SetMathMarks(math_marks);
    S.SetChemMarks(chem_marks);
}


    //****************************Console Login********************************
    // cout<<"Welcome to the School Managment System, please enter your passcode :"<<endl;
    // for (;;)
    // {
    //     cin>>input;  
    //     cout<<input<<endl;
    //     if (input=="close")
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         for (int i; i=7; i++)
    //         {
    //             if (input.compare(Password[i]))
    //             {
    //                 cout<<i<<endl;
    //                 break;
    //             }
    //         }
    //     cout<<"The entered text is Invalid"<<endl;
    //     }
    // }