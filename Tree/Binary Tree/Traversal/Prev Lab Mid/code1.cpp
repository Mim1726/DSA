#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* left;
    node* mid;
    node* right;

    node(int x):value(x),left(nullptr),mid(nullptr),right(nullptr) {}
};
void traversal(node* p,vector<int>& result){
    if(!p) return;

    traversal(p->left,result);

    traversal(p->mid,result);

    result.push_back(p->value);

    traversal(p->right,result);
}
int main(){
    int r;
    cin >> r;

    node* root=new node(r);

    unordered_map<int,node*> nodeMap;
    nodeMap[r]=root;

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int op,key,val;
        cin >> op >> key >> val;

        if(nodeMap.find(key)!=nodeMap.end()){
            node* parent=nodeMap[key];

            node* child=new node(val);
            nodeMap[val]=child;

            if(op==0){
                parent->left=child;
            }
            else if(op==1){
                parent->mid=child;
            }
            else if(op==2){
                parent->right=child;
            }
        }
    }
    vector<int> result;
    traversal(root,result);

    for(int x:result){
        cout << x << endl;
    }
    return 0;
}
/*
Problem B
In this problem, you will have a ternary tree of integers where each node has up to three
children: left child, mid-child, and right child. You will have to print the tree in a new
order that prints the tree in the following order: left sub-tree, mid sub-tree, node value,
and finally the right sub-tree.
Input:
First line: r, the value of root. (-2147483648<=r<=2147483647)
Next line: n, the number of operations. (1<=n<=10000)
Next n lines: op key val, three integers (0<=op<=2, -2147483648<=key,
val<=2147483647). If op = 0, set the left child of the node with the value key to val. If op
= 1, set the mid child of the node with the value key to val. If op = 2, set the right child of
the node with the value key to val. If the key is not found, ignore the command.
Output:
Each line contains the values in the tree according to the new order.
Sample Case:
input: 
5
5
0 5 6
1 5 7
2 5 8
0 7 9
2 7 10 
output:
6
9
7
10
5
8
*/
