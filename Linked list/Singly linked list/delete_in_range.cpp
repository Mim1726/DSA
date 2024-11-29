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
        a->val=x;
        a->next=NULL;
        if(tail){
            tail->next=a;
            tail=a;
        }
        else{
            head=a;
            tail=a;
        }
    }
    void delete_in_range(int l,int u){
        while(head!=NULL && head->val>=l && head->val<=u){
            node* tmp=head;
            head=head->next;
            free(tmp);
        }
        node* p=head;
        while(p!=NULL && p->next!=NULL){
            if(p->next->val>=l && p->next->val<=u){
                node* tmp=p->next;
                p->next=p->next->next;
                free(tmp);
            }
            else{
                p=p->next;
            }
        }
    }
    void print(){
        node* p=head;
        while(p){
            cout << p->val << endl;
            p=p->next;
        }
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
    int l,u;
    cin >> l >> u;
    my_list.delete_in_range(l,u);
    my_list.print();
}
