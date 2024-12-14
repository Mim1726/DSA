#include<bits/stdc++.h>
using namespace std;
void func(int x){
    if(x==10)
        return;
    func(x+1);
    cout << x << endl;
}
int main(){
    int x;
    cin >> x;
    func(x);
    // 4
    // f(5)
    // f(6)
    // f(7)
    // f(8)
    // f(9)
    // f(10) return to f(9)
    // print 9
    // return to f(8)
    // print 8 
    // continue like this
    /* ans:
    9
    8
    7
    6
    5
    4 */
    return 0;
}
