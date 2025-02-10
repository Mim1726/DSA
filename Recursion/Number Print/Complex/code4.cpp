#include<bits/stdc++.h>
using namespace std;

void func(int cur[],int l,int k,int n,int start){
    if(l==k){
        for(int i=0;i<k;i++){
            if(i) cout << " ";
            cout << cur[i];
        }
        cout << endl;
        return;
    }
    for(int i=start;i>=0;i--){
        cur[l]=i;
        func(cur,l+1,k,n,i-1);
    }
}
int main(){
    int n;
    int k;
    cin >> n >> k;
    int cur[k];
    func(cur,0,k,n,n-1);
    return 0;
}
