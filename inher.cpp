#include <iostream>
#include <string>
using namespace std;

class person{
    private:
    double salary;

    public:
    string name;
    int age;
};
class employe:public person{
      
    public:
    int empID;
    void setSalary(double s){
        salary = s;
    }
    void getInfo(){
        cout<<"name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"EmpID: "<<empID<<endl;
        cout<<"salary: "<<salary<<endl;
    }
};

int main(){
    employe e1;
    e1.name = "Ram";
    e1.age = 23;
    e1.empID = 0102;
    e1.getInfo();
    return 0;

}