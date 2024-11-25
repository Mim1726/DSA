#include<bits/stdc++.h>
using namespace std;
int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    return 0;
}
bool is_operator(char c){
    return c=='+' || c=='-' || c=='*' || c=='/';
}
string infix_to_postfix(const string& infix){
    stack<char> st;
    string postfix;

    for (char c:infix){
        if(isalnum(c)){
            postfix += c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top() != '('){
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if(is_operator(c)){
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix+=st.top();
        st.pop();
    }

    return postfix;
}
int main(){
    string infix;
    cin >> infix;
    string postfix = infix_to_postfix(infix);
    cout << postfix << endl;
    return 0;
}
