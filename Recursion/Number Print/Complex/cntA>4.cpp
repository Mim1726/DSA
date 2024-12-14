#include<bits/stdc++.h>
using namespace std;

/*Write down a C++ code for printing all the words:
(i) consisting of letters {A, B, C}, (ii) of length
K where K>5, (iii) having more than four “A”.*/

void func(string s,int k,int cnt){
    if(s.size()==k){
        if(cnt>4){
            cout << s << endl;
        }
        return;
    }
    func(s+'A',k,cnt+1);
    func(s+'B',k,cnt);
    func(s+'C',k,cnt);
}
int main(){
    int k;
    cin >> k;
    string s;
    func(s,k,0);
    return 0;
}
