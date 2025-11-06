#include <iostream>
#include <string>
using namespace std;

class teacher{
    private:
    double salary;

    public:

    teacher(){
        dept = "\nPsychology";
    }
    string name;
    string dept;

    void setSalary(double s){
        salary = s; //as salary is private so the same class can access it
    }
    double getSalary(){
        return salary;
    }
};

int main(){
    teacher t1;
    t1.setSalary(2300.0);
    cout<<t1.getSalary();
    cout<<t1.dept;
    return 0;

}