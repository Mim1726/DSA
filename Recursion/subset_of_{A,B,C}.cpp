#include<bits/stdc++.h>
using namespace std;
void func(vector<char>& set,vector<char>& subset,int i){
    if(i==set.size()){
        cout << "{";
        for(char c:subset){
            cout << c << " ";
        }
        cout << "}" << endl;
        return;
    }
    func(set,subset,i+1);
    subset.push_back(set[i]);
    func(set,subset,i+1);
    subset.pop_back();
}
int main(){
    vector<char> set={'A','B','C'};
    vector<char> subset;
    func(set,subset,0);
    return 0;
}
