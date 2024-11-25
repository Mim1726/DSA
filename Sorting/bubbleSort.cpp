#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr){
    int n=arr.size();
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}
void printVector(vector<int>& arr){
    for(int &x:arr){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    vector<int>arr={64,34,25,12,22,11};
    bubbleSort(arr);
    cout << "Sorted array: " << endl;
    printVector(arr);
    return 0;
}
