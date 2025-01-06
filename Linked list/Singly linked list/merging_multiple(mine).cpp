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
ll merge_sorted_lists(vector<ll>& lists){
    ll result;
    vector<ll::node*> v;

    for(int i=0;i<lists.size();i++){
        v.push_back(lists[i].head);
    }

    while(true){
        int min_index=-1;
        int min_val=INT_MAX;

        for(int i=0;i<v.size();i++){
            if(v[i]!=NULL && v[i]->val < min_val){
                min_val=v[i]->val;
                min_index=i;
            }
        }
        if(min_index==-1) break;
        result.insert_last(min_val);
        v[min_index]=v[min_index]->next;
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    vector<ll> lists(n);
    for(int i=0;i<n;i++){
        int mi;
        cin >> mi;
        for(int j=0;j<mi;j++){
            int x;
            cin >> x;
            lists[i].insert_last(x);
        }
    }
    ll merged_list=merge_sorted_lists(lists);
    merged_list.print();
}
