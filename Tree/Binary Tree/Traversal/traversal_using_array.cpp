#include<bits/stdc++.h>
using namespace std;
void inorder_traversal(vector<int>& v,int i,int n,vector<int>& result){
    if(i>=n) return;
    inorder_traversal(v,2*i+1,n,result);
    result.push_back(v[i]);
    inorder_traversal(v,2*i+2,n,result);
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> result;
    inorder_traversal(v,0,n,result);
    for(int x:result){
        cout << x << " ";
    }
    cout << endl;
}
