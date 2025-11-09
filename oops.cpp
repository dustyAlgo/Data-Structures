#include <iostream>
#include <string>
using namespace std;

class teacher{
    private:
    double salary;

    public:

    teacher(string name, string dept, double ID){
        this->name = name;
        this->dept = dept;
        IDptr = new double;
        *IDptr = ID;
    }
    teacher(teacher &obj){
        this->name = obj.name;
        this->dept = obj.dept;
        IDptr = new double;
        *IDptr = *(obj.IDptr);
    }
        
    string name;
    string dept;
    double* IDptr;

    void getInfo(){
       cout<<"name: "<<name<<endl;
       cout<<"dept: "<<dept<<endl;
       cout<<"id: "<<*IDptr<<endl;
    }
};

int main(){
    teacher t1("rahul", "CSE", 0.1);
    teacher t2(t1);
    t2.name = "Ram";
    t1.getInfo();
    *(t2.IDptr) = 0.2;
    t2.getInfo();
    t1.getInfo();
    return 0;

}