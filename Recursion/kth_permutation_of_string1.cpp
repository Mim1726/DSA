#include<bits/stdc++.h>
using namespace std;
//kth lexicographically lowest permutation of a string
void func(string s,int i,set<string>& st){
    if(i==s.size()){
        st.insert(s);
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        func(s,i+1,st);
        swap(s[i],s[j]);
    }
}
int main(){
    string s;
    int k;
    cin >> s >> k;
    set<string> st;
    func(s,0,st);
    vector<string> v(st.begin(),st.end());
    cout << v[k-1] << endl;
}
