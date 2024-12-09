#include<bits/stdc++.h>
using namespace std;
//kth lowest lexicographically permutation of a string
void func(string s,int k){
    sort(s.begin(),s.end());
    int cnt=1;
    while(1){
        if(cnt==k){
            cout << s << endl;
            return;
        }
        cnt++;
        if(!next_permutation(s.begin(),s.end())){
            break;
        }
    }
}
int main(){
    string s;
    int k;
    cin >> s >> k;
    func(s,k);
}
