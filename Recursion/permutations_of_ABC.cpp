#include<bits/stdc++.h>
using namespace std;
void func(string s,int i){
    if(i==s.size()){
        cout << s << endl;
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        func(s,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string s="ABC";
    func(s,0);
    return 0;
}
