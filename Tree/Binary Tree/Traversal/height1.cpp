#include<bits/stdc++.h>
using namespace std;
struct tree{
    struct node{
        int val;
        node* left;
        node* right;
        node* parent;
    };
    node* root=NULL;
    void insertion(int x){
        node* a=new node();
        a->val=x;
        a->left=NULL;
        a->right=NULL;
        a->parent=NULL;

        if(!root){
            root=a;
            return;
        }

        queue<node*> q;
        q.push(root);

        while(!q.empty()){
            node* curr=q.front();
            q.pop();

            if(!curr->left){
                curr->left=a;
                a->parent=curr;
                return;
            }
            else{
                q.push(curr->left);
            }

            if(!curr->right){
                curr->right=a;
                a->parent=curr;
                return;
            }
            else{
                q.push(curr->right);
            }
        }
    }
    int get_height(node* p){
        if(!p) return -1;
        int left_height=get_height(p->left);
        int right_height=get_height(p->right);
        return 1+max(left_height,right_height);
    }
};
int main(){
    tree my_tree;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        my_tree.insertion(x);
    }
    cout << "height: ";
    cout << my_tree.get_height(my_tree.root) << endl;
}
