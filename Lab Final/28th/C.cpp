#include<bits/stdc++.h>
using namespace std;
/*
You will be given a list of integers in sorted order and a list of queries. You have to find
the number of integers in the list less than or equal to the query. You may assume that
the query exists in the list of integers.
Input:
First line: n, a number. (1<=n<=10^6)
Next n lines: an integer v (-2147483648<=v <=2147483647), the numbers in the list
Next line: m, a number (1<=m<=10^5), the number of keys.
Next m lines: an integer q (-2147483648<= q <=2147483647), the queries.
Output:
m lines, each containing the number of integers in the list less than or equal to the
query.
Sample Case:
Input:       Output:
7            5
1            6
1
1
2
2
3
4
2
2
3
*/

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    int m;
    cin >> m;

    vector<int> queries(m);

    for(int i=0;i<m;i++){
        cin >> queries[i];
    }

    for(int i=0;i<m;i++){
        int q=queries[i];
        int cnt=upper_bound(v.begin(),v.end(),q)-v.begin();
        cout << cnt << endl;
    }
    return 0;
}
