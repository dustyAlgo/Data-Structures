#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> fl;

    fl.push_front(3);  // [3]
    fl.push_front(2);  // [2, 3]
    fl.push_front(1);  // [1, 2, 3]

    cout << "Forward list: ";
    for(int x : fl) cout << x << " ";

    // Insert after first element
    auto it = fl.begin();
    advance(it, 2);
    fl.insert_after(it, 10);   // [1, 10, 2, 3]

    cout << "\nAfter insert: ";
    for(int x : fl) cout << x << " ";
}
