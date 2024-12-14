#include<bits/stdc++.h>
using namespace std;
void func(int x){
    if(x>=10)
        return;
    func(x+1);
    cout << x-1 << endl;
    func(x+2);
    cout << x << endl;
}
int main(){
    int x;
    cin >> x;
    func(x);
    /* input: f(6)
    f(7)
    f(8)
    f(9)
    f(10)->
    f(9)------    print 8
    f(11)-> f(9)  print 9
    f(8) ----     print 7
    f(10)->f(8)   print 8
    f(7) -----    print 6
    f(9) f(10)->
    f(9)          print 8
    f(11)->f(9)   print 9
    f(7)          print 7
    f(6)-----     print 5
    f(8) f(9) f(10)->
    f(9)          print 8
    f(11)->f(9)   print 9
    f(8)          print 7
    f(10)->f(8)   print 8
    f(6)          print 6
    */
    return 0;
}
