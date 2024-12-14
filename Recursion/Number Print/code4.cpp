#include<bits/stdc++.h>
using namespace std;
void func(int x){
    if(x==0)
        return;
    func(x-1);
    cout << x << endl;
}
int main(){
    int x;
    cin >> x;
    func(x);
    /*input: 5
    output:1
           2
           3
           4
           5 */
    return 0;
}
