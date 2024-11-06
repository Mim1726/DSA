#include<bits/stdc++.h>
using namespace std;
bool is_operator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}
string postfix_to_infix(string postfix){
    stack<string> st;
    for(char c:postfix){
        if(is_operator(c)){
            string right=st.top();
            st.pop();
            string left=st.top();
            st.pop();
            string infix="("+left+c+right+")";
            st.push(infix);
        }
        else{
            st.push(string(1,c));
        }
    }
    return st.top();
}
int main(){
    string postfix;
    cin >> postfix;
    string infix=postfix_to_infix(postfix);
    cout << infix << endl;
}
