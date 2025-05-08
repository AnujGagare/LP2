#include <iostream>
using namespace std;

class Employee
{
    private :
    string name;
    int employee_id;
    string punctuality;
    string task_completion;
    string teamwork;
    string initiative;
    string problem_solving;
    public :
    Employee()
    {
        cout<<"Enter Employee Name : ";
        cin>>name;

        cout << "Enter Employee ID : ";
        cin>>  employee_id;

        cout<< "How would you rate his punctuality (Excellent / Good / Average / Poor)?";
        cin>> punctuality;

        cout<< "How would you rate his task completion (Excellent / Good / Average / Poor)?";
        cin>> task_completion;

        cout<< "How would you rate his teamwork (Excellent / Good / Average / Poor)?";
        cin>> teamwork;

        cout<< "How would you rate his initiatives (Excellent / Good / Average / Poor)?";
        cin>> initiative;

        cout<< "How would you rate his problem solving skills (Excellent / Good / Average / Poor)?";
        cin>> problem_solving;

        total_score();
    }

    int getscore(string rating)
    {
        if(rating == "Excellent")
        {
            return 4;
        }
        else if(rating == "Good")
        {
            return 3;
        }
        else if(rating == "Average")
        {
            return 2;
        }
        else if(rating == "Poor")
        {
            return 1;
        }
    }

    void total_score()
    {
        int total_score = getscore(punctuality) + getscore(task_completion) + getscore(teamwork) + getscore(initiative) + getscore(problem_solving);
        decision(total_score);
    }

    void decision(int total_score)
    {
        if(total_score >= 19)
        {
            cout<<"Promotion recommended";
        }
        else if(total_score >= 16 && total_score < 19)
        {
            cout<<"Should get a bonus";
        }

        else if(total_score >= 13 && total_score < 16)
        {
            cout<<"Satisfactory performance";
        }
        else if(total_score >=10 && total_score < 13)
        {
            cout<<"Needs improvement";
        }
        else if(total_score >=6 && total_score < 10)
        {
            cout<<"Put under review";
        }
        else if(total_score == 5)
        {
            cout<<"Termination suggested";
        }
    }
};



int main()
{
    Employee e;
    return 0;
}