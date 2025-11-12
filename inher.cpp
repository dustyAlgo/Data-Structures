#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    int rollNo;
};
class Teacher{
public:
    int empID;
    string subject;
};
class TA:public Student, public Teacher{
public:
    string subject;
};

int main(){
    int x=4, y=5;
    TA t1;
    t1.Teacher::subject = "Physics";
    t1.TA::subject = "English";
    cout<<"TA subject: "<<t1.TA::subject<<endl;;
    cout<<"Teacher subject: "<<t1.Teacher::subject;
    return 0;

}