#include <iostream>
#include <algorithm>
using namespace std;
 int main(){
    int arr[5] = {12, 3, 4, 7, 10};
    int minimum = *min_element(arr, arr+5);
    cout<<minimum;
    return 0;
 }