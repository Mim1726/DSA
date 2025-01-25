#include<bits/stdc++.h>
using namespace std;
/*
You will be given the marks of students in a particular course. Output the id of the
students according to the ascending order of their marks. In case of same marks, the
smaller id value will be printed.
Input:
First line: n, a number. (1<=n<=10^5)
Next n lines: two integers id mark (0<=id, mark <=2147483647), the id and mark of a
student.
Output:
n lines, each containing the id of a student according to the order defined above.
Sample Case:
Input:     Output:
3          2
1 5        3
2 3        1
3 4
*/

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> students;

    for(int i=0;i<n;i++){
        int id,mark;
        cin >> id >> mark;
        students.push_back({mark,id});
    }

    sort(students.begin(),students.end());

    for(auto x: students){
        cout << x.second << endl;
    }
    return 0;
}
