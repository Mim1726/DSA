#include<bits/stdc++.h>
using namespace std;
/*Input: First line n, a number n (1<=n<=10)
    Output: Each line contains a list of space-separated
    digits while the list contains n digits. The digits
    in the list are 0 to 4( inclusive). The odd-indexed
    digit in the list is an odd digit. The even-indexed
    digit in the list is an even digit. The list will be
    printed in sorted order Example 010 before 012 */
void func(int cur[],int l,int n){
    if(l==n){
        for(int i=0;i<n;i++){
            if(i) cout << " ";
            cout << cur[i];
        }
        cout << endl;
        return;
    }
    for(int i=0;i<5;i++){
        if(l%2!=i%2)
            continue;
        cur[l]=i;
        func(cur,l+1,n);
    }
}
int main(){
    int n;
    cin >> n;
    int cur[n];
    func(cur,0,n);
}