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
    void delete_first_x(int x){
        if(head==NULL)
            return;
        if(head->val==x){
            node* tmp=head;
            head=head->next;
            if(head==NULL)
                tail=NULL;
            free(tmp);
            return;
        }
        node* p=head;
        while(p->next){
            if(p->next->val==x){
                node* tmp=p->next;
                p->next=p->next->next;
                if(p->next==NULL){
                    tail=p;
                }
                free(tmp);
                return;
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
    int v;
    cin >> v;
    my_list.delete_first_x(v);
    my_list.print();
}
