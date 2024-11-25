#include<bits/stdc++.h>
using namespace std;
vector<int> countSort(vector<int>& inputArray){
    int n=inputArray.size();
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,inputArray[i]);
    }
    vector<int> countArray(mx+1,0);
    for(int i=0;i<n;i++){
        countArray[inputArray[i]]++;
    }
    for(int i=1;i<=mx;i++){
        countArray[i]+=countArray[i-1];
    }
    vector<int> outputArray(n);
    for(int i=n-1;i>=0;i--){
        outputArray[countArray[inputArray[i]]-1]=inputArray[i];
        countArray[inputArray[i]]--;
    }
    return outputArray;
}
int main(){
    vector<int> inputArray={4,3,12,1,5,5,3,9};
    vector<int> outputArray=countSort(inputArray);
    for(int i=0;i<inputArray.size();i++)
        cout << outputArray[i] << " ";
    return 0;
}
