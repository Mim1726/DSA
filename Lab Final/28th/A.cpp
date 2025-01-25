#include<bits/stdc++.h>
using namespace std;
/*
You will be given a list of numbers and a list of queries. You have to find the frequency
of the queries in the list.
Input:
First line: n, a number. (1<=n<=10^5)
Next n lines: an integer v (-2147483648<=v <=2147483647), the numbers in the list
Next line: m, a number (1<=m<=10^5), the number of keys.
Next m lines: an integer q (-2147483648<= q <=2147483647), the queries.
Output:
m lines, each containing the frequencies of the queries.
Sample Case:
Input:          output: 
3               1
1               2
1               0
2                 
3
2
1
3
*/

int main(){
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        freq[v]++;
    }

    int m;
    cin >> m;

    for(int i=0;i<m;i++){
        int q;
        cin >> q;
        cout << freq[q] << endl;
    }
}
