#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->val > b->val; // Min-Heap
    }
};

Node* merge_sorted_lists(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Push heads of all lists into the priority queue
    for (auto list : lists) {
        if (list) pq.push(list);
    }

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (!pq.empty()) {
        Node* smallest = pq.top();
        pq.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next) pq.push(smallest->next);
    }

    return dummy->next;
}
