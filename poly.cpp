#include <iostream>
#include <string>
using namespace std;

class Parent{
public:
    virtual void hello(){
        cout<<"hello from parent";
    }
};
class Child : public Parent{
public:
    void hello(){
        cout<<"hello form child";
    }
};
int main(){
    Child c1;
    c1.hello();
    Parent p1;
    p1.hello();

}