#include <iostream>
using namespace std;

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=NULL;
    node *tail=NULL;

    void insert_last(int x)
    {
        //insert x at last
        //Your code starts here #001
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
        //Your code ends here #001
    }

    void sort(){
        //Sorts the linked list

        //Your code starts here #002
        if(head==NULL)
            return;
        node* p=head;
        while(p){
            node* tmp1=p;
            node* tmp2=p->next;
            while(tmp2){
                if((tmp1->val)>(tmp2->val)){
                    tmp1=tmp2;
                }
                tmp2=tmp2->next;
            }
            if(tmp1!=p){
                int tmp=p->val;
                p->val=tmp1->val;
                tmp1->val=tmp;
            }
            p=p->next;
        }
        //Your code ends here #002
    }

    void print()
    {
        //prints elements from head to tail
        //Your code starts here #003
        node* p=head;
        while(p){
            cout << p->val << endl;
            p=p->next;
        }

        //Your code ends here #003
    }
};


int main()
{

    //Your code starts here #004
    ll my_list;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        my_list.insert_last(v);
    }
    my_list.sort();
    my_list.print();
    //Your code ends here #004
    return 0;


}
