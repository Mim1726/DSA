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
            a->prev=tail;
            tail->next=a;
            tail=tail->next;
        }
    }
    int delete_last(){
        if(head==NULL)
            return -1;
        else if(head->next==NULL){
            int x=head->val;
            free(head);
            head=NULL;
            tail=NULL;
            return x;
        }
        else{
            int x=tail->val;
            node* tmp=tail;
            tail=tail->prev;
            tail->next=NULL;
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
    int p=my_list.delete_last();
    cout << p << endl;
    my_list.print();
}
