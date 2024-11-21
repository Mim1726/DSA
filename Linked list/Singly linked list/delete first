#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct node{
        int val;
        node* next;
    };
    node* head=NULL;
    node* tail=NULL;
    void insertion(int x){
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
    int delete_first(){
        if(head==NULL)
            return -1;
        if(head==tail){
            int x=head->val;
            free(head);
            head=NULL;
            tail=NULL;
            return x;
        }
        else{
            int x=head->val;
            node* tmp=head;
            head=head->next;
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
    ll my_list;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        my_list.insertion(x);
    }
    int p=my_list.delete_first();
    cout << p << endl;
    my_list.print();
}
