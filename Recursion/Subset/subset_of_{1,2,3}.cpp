#include<bits/stdc++.h>
using namespace std;
void func(vector<int>& set,vector<int>& subset,int i){
    if(i==set.size()){
        cout << "{";
        for(int x:subset){
            cout << x << " ";
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
    vector<int> set={1,2,3};
    vector<int> subset;
    func(set,subset,0);
}
