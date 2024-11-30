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
    void print(){
        node* p=head;
        while(p){
            cout << p->val << " ";
            p=p->next;
        }
    }
};
ll merge_sort(ll& list1,ll& list2){
    ll result;
    ll::node* p1=list1.head;
    ll::node* p2=list2.head;
    while(p1!=NULL && p2!=NULL){
        if(p1->val <= p2->val){
            result.insert_last(p1->val);
            p1=p1->next;
        }
        else{
            result.insert_last(p2->val);
            p2=p2->next;
        }
    }
    while(p1!=NULL){
        result.insert_last(p1->val);
        p1=p1->next;
    }
    while(p2!=NULL){
        result.insert_last(p2->val);
        p2=p2->next;
    }
    return result;
}
int main(){
    ll list1,list2;
    int n1;
    cin >> n1;
    for(int i=0;i<n1;i++){
        int x;
        cin >> x;
        list1.insert_last(x);
    }
    int n2;
    cin >> n2;
    for(int i=0;i<n2;i++){
        int x;
        cin >> x;
        list2.insert_last(x);
    }
    ll merged_list=merge_sort(list1,list2);
    merged_list.print();
}
