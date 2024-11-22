#include<bits/stdc++.h>
using namespace std;
void f(int i,vector<char>& a){
    if(i==3){
        for(char c:a){
            cout << c;
        }
        cout << endl;
        return;
    }
    for(char c:{'a','b','c'}){
        a[i]=c;
        f(i+1,a);
    }
}
int main(){
    vector<char> a(3);
    f(0,a);
    return 0;
}
/*pseudo code(python):
def f(i):
    if i == 3:  # Base case: when index reaches 3, print the current configuration
        print("".join(a))
        return
    for c in ['a', 'b', 'c']:  # Iterate over 'a', 'b', 'c'
        a[i] = c  # Assign the character to the current position
        f(i + 1)  # Recurse to the next index

# Initialize the array and start the recursion
a = [''] * 3  # Create an array of size 3 to hold the characters
f(0)  # Start the recursion from index 0
*/
