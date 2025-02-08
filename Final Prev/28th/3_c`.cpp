#include <iostream>
using namespace std;

struct ll {
    struct node {
        int val;
        node* next;
    };
    
    node* head = NULL;
    node* tail = NULL;

    void insert_last(int x) {
        node* a = new node;
        a->next = NULL;
        a->val = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }

    // Function to find the middle of the linked list
    node* getMiddle(node* head) {
        if (!head || !head->next) return head;
        node* slow = head;
        node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted lists
    node* mergeSortedLists(node* l1, node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeSortedLists(l1, l2->next);
            return l2;
        }
    }

    // Merge Sort function for Linked List
    node* mergeSort(node* head) {
        if (!head || !head->next) return head;

        node* mid = getMiddle(head);
        node* rightHalf = mid->next;
        mid->next = nullptr;

        node* leftSorted = mergeSort(head);
        node* rightSorted = mergeSort(rightHalf);

        return mergeSortedLists(leftSorted, rightSorted);
    }

    // Sort function (calls merge sort)
    void sort() {
        head = mergeSort(head);
        // Update tail after sorting
        tail = head;
        while (tail && tail->next) {
            tail = tail->next;
        }
    }

    void print() {
        node* p = head;
        while (p) {
            cout << p->val << endl;
            p = p->next;
        }
    }
};

int main() {
    ll my_list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        my_list.insert_last(v);
    }
    my_list.sort();
    my_list.print();
    return 0;
}
