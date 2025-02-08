#include<bits/stdc++.h>
using namespace std;
/*
Design an approach to sort the nodes of a linked list containing
integer values without using any external array.
*/
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
    void sort(){
        if(head==NULL)
            return;

        node* p=head;
        while(p){
            node* tmp1=p;
            node* tmp2=p->next;
            while(tmp2){
                if(tmp1->val > tmp2->val){
                    tmp1=tmp2;
                }
                tmp2=tmp2->next;
            }
            if(tmp1 != p){
                int tmp=p->val;
                p->val=tmp1->val;
                tmp1->val=tmp;
            }
            p=p->next;
        }
    }
    void print(){
        node* p=head;
        while(p){
            cout << p->val << " ";
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
    my_list.sort();
    my_list.print();
}
