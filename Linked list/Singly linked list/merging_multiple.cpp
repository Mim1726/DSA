#include <bits/stdc++.h>
using namespace std;

struct ll {
    struct node {
        int val;
        node* next;
    };
    node* head = NULL;
    node* tail = NULL;

    void insert_last(int x) {
        node* a = (node*)malloc(sizeof(node));
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

    void print() {
        node* p = head;
        while (p) {
            cout << p->val << endl;
            p = p->next;
        }
    }
};

ll merge_sorted_lists(vector<ll>& lists) {
    ll result;
    vector<ll::node*> pointers;  // Pointers to the current head of each list

    // Initialize pointers for all linked lists
    for (int i = 0; i < lists.size(); i++) {
        pointers.push_back(lists[i].head);
    }

    while (true) {
        int min_index = -1;
        int min_value = INT_MAX;

        // Find the smallest value among the current nodes of all lists
        for (int i = 0; i < pointers.size(); i++) {
            if (pointers[i] != NULL && pointers[i]->val < min_value) {
                min_value = pointers[i]->val;
                min_index = i;
            }
        }

        // If all pointers are NULL, we are done
        if (min_index == -1) break;

        // Add the smallest value to the result list
        result.insert_last(min_value);

        // Move the pointer of the list that contributed the smallest value
        pointers[min_index] = pointers[min_index]->next;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<ll> lists(n);

    for (int i = 0; i < n; i++) {
        int mi;
        cin >> mi;
        for (int j = 0; j < mi; j++) {
            int x;
            cin >> x;
            lists[i].insert_last(x);
        }
    }

    ll merged_list = merge_sorted_lists(lists);
    merged_list.print();

    return 0;
}
