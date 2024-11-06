#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct node{
        int val;
        node* next;
    };
    node* head=NULL;
    node* tail=NULL;
    void insert_last(int x){
        node* a=(node*)malloc(sizeof(node));
        a->next=NULL;
        a->val=x;
        if(tail){
            tail->next=a;
            tail=a;
        }
        else{
            head=a;
            tail=a;
        }
    }
    int delete_last(){
        if(head==NULL)
            return -1;
        if(head==tail){
            int x=head->val;
            free(head);
            head=NULL;
            tail=NULL;
            return x;
        }
        node* p=head;
        while(p->next!=tail){
            p=p->next;
        }
        int x=tail->val;
        node* tmp=tail;
        tail=p;
        tail->next=NULL;
        free(tmp);
        return x;
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
        my_list.insert_last(x);
    }
    int p=my_list.delete_last();
    cout << p << endl;
    my_list.print();
}
