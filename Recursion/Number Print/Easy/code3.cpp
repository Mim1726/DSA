#include<bits/stdc++.h>
using namespace std;
void func(int x,int n){
    if(x==n+1)
        return;
    cout << x << endl;
    func(x+1,n);
}
int main(){
    int x,n;
    cin >> x >> n;
    func(x,n);
    /* f(1) to print n number line by line
    */
    return 0;
}
