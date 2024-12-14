#include<bits/stdc++.h>
using namespace std;
void func(int x){
    if(x<=0)
        return;
    func(x-1);
    cout << x << endl;
    func(x-2);
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
    f(0) return to f(1) THEN print 1
    f(-1)
    f(1)
    f(2)                     print 2
    f(0) then f(2)
    f(3)                     print 3
    f(1) f(0) f(1)           print 1
    f(-1) f(1) f(3) f(4)     print 4
    f(2) f(1) f(0) f(1)      print 1
    f(-1) f(1) f(2)          print 2
    return to f(4)
    done
                */
    return 0;
}
