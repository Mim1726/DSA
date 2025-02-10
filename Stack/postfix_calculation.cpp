#include<bits/stdc++.h>
using namespace std;
int solve(string postfix){
    stack<int> st;
    for(char c:postfix){
        if(isdigit(c)){
            st.push(c-'0');
        }
        else{
            if(c=='#'){
                int right=st.top();
                st.pop();
                st.push(right+1);
            }
            else if(c=='$'){
                int right=st.top();
                st.pop();
                st.push(right-1);
            }
            else{
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                if(c=='+')st.push(left+right);
                if(c=='-')st.push(left-right);
                if(c=='*')st.push(left*right);
                if(c=='/'){
                    if(right==0) right+=2;
                    st.push(left/right);
                }
            }

        }
    }
    return st.top();
}
int main(){
    string postfix;
    cin >> postfix;
    int ans=solve(postfix);
    cout << ans << endl;
}
