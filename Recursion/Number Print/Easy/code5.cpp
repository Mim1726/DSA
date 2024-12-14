#include<bits/stdc++.h>
using namespace std;
void func(int x){
    if(x<=0)
        return;
    func(x-1);
    func(x-2);
    cout << x << endl;
}
int main(){
    int x;
    cin >> x;
    func(x);
    /* input : 4
    f(4)
    f(3)
    f(2)
    f(1)
    f(0) return to f(1) THEN f(1-2) f(-1) return to f(1) print 1
    then go to f(2) then f(2-2=0) return to f(2) then print    2
    then go to f(3) then f(3-2=1) print f(1)(f(0) & f(-1))     1
    return to f(3)                                             3
    then  f(4) to f(2) then f(1) (f(0) & f(-1))                1
                then f(2)                                      2
                retrun to f(4)                                 4
                */
    return 0;
}
