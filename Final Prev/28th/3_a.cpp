#include <bits/stdc++.h>
using namespace std;

/*
Design a linked list with the following properties:
    (a) Insertion of an item in the first or last position has the 
        complexity of O(1)
    (b) Deletion of an item from the middle position hax the complexity 
        of O(1)
*/
struct ll {
    struct node {
        int val;
        node* next;
        node* prev;
    };

    node* head = NULL;
    node* tail = NULL;

    // Insertion at the last position (O(1))
    void insert_last(int x) {
        node* a = (node*)malloc(sizeof(node));
        a->next = NULL;
        a->prev = tail;
        a->val = x;

        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = tail = a;
        }
    }

    // Insertion at the front (O(1))
    void insert_first(int x) {
        node* a = (node*)malloc(sizeof(node));
        a->next = head;
        a->prev = NULL;
        a->val = x;

        if (head) {
            head->prev = a;
            head = a;
        } else {
            head = tail = a;
        }
    }

    // Deletion from a given node (O(1))
    void delete_node(node* nodeToDelete) {
        if (nodeToDelete == NULL) return;

        if (nodeToDelete == head) {
            head = nodeToDelete->next;
            if (head) {
                head->prev = NULL;
            }
        } else if (nodeToDelete == tail) {
            tail = nodeToDelete->prev;
            if (tail) {
                tail->next = NULL;
            }
        } else {
            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        free(nodeToDelete);
    }

    // Utility function to delete first occurrence of x (in the middle)
    void delete_first_x(int x) {
        node* p = head;
        while (p) {
            if (p->val == x) {
                delete_node(p);
                return;
            }
            p = p->next;
        }
    }

    // Printing the list
    void print() {
        node* p = head;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    ll my_list;
    int n;
    cin >> n;

    // Insert elements in the list
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        my_list.insert_last(x);  // Inserting at the end
    }

    int v;
    cin >> v;

    // Deleting the first occurrence of v from the list
    my_list.delete_first_x(v);

    // Printing the list after deletion
    my_list.print();

    return 0;
}
