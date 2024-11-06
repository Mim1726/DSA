#include<bits/stdc++.h>
using namespace std;
struct dll{
    struct node{
        int val;
        node* next;
        node* prev;
    };
    node* head=NULL;
    node* tail=NULL;
    void insert_last(int x){
        node* a=(node*)malloc(sizeof(node));
        a->next=NULL;
        a->prev=NULL;
        a->val=x;
        if(head==NULL){
            head=a;
            tail=a;
        }
        else{
            tail->next=a;
            a->prev=tail;
            tail=tail->next;
        }
    }
    int delete_first(){
        if(head==NULL)
            return -1;
        if(head->next==NULL){
            int x=head->val;
            free(head);
            head=NULL;
            tail=NULL;
            return x;
        }
        else{
            node* tmp=head;
            int x=head->val;
            head=head->next;
            head->prev=NULL;
            free(tmp);
            return x;
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
    dll my_list;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        my_list.insert_last(x);
    }
    int p=my_list.delete_first();
    cout << p << endl;
    my_list.print();
}
