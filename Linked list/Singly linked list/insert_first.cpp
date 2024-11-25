#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct node{
        int val;
        node* next;
    };
    node* head=NULL;
    node* tail=NULL;
    void insert_first(int x){
        node* a=(node*)malloc(sizeof(node));
        a->next=NULL;
        a->val=x;
        if(head==NULL){
            head=a;
            tail=a;
        }
        else{
            a->next=head;
            head=a;
        }
    }
    void print(){
        node* p=head;
        while(p){
            cout << p->val << " ";
            p=p->next;
        }
        cout << endl;
    }
};
int main(){
    ll my_list;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        my_list.insert_first(x);
    }
    my_list.print();
}
