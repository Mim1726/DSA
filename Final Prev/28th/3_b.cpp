#include<bits/stdc++.h>
using namespace std;

//write down a code to find whether a linked list is circular or not
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
    void make_circular(){
        if(tail){
            tail->next=head;
        }
    }
    bool is_circular(){
        if(!head) return false;

        node* l=head;
        node* r=head;

        while(r && r->next){
            l=l->next;
            r=r->next->next;
            if(l==r) return true;
        }
        return false;
    }
    void print(){
        node* p=head;
        unordered_set<node*> visited;
        while(p){
            if(visited.find(p) != visited.end()) break;
            visited.insert(p);
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
    //my_list.print();
    cout << (my_list.is_circular() ? "Yes" : "No") << endl;
    my_list.make_circular();
    //my_list.print();
    cout << (my_list.is_circular() ? "Yes" : "No") << endl;
}
