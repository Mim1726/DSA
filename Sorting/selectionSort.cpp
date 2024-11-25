#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int mn=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mn]){
                mn=j;
            }
        }
        swap(arr[i],arr[mn]);
    }
}
void printArray(vector<int> &arr){
    for(int &x:arr){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    vector<int> arr={64,25,12,22,11};
    cout << "Original array: ";
    printArray(arr);
    selectionSort(arr);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
