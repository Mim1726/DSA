#include <bits/stdc++.h>
using namespace std;

struct ll {
    struct node {
        int val;
        node* next;
    };
    
    node* head = NULL;
    node* tail = NULL;

    // Stack class within ll struct
    class Stack {
        node* top;  // Pointer to the top node of the stack

    public:
        Stack() : top(NULL) {}  // Initialize the top pointer to NULL

        ~Stack() {
            // Destructor to free memory
            while (!isEmpty()) {
                pop();
            }
        }

        void push(int x) {
            node* a = new node();  // Allocate memory for a new node
            a->val = x;            // Set node value
            a->next = top;         // Link new node to the current top
            top = a;               // Update top to the new node
            cout << "Pushed " << x << " onto stack" << endl;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow" << endl;
                return -1;
            }
            int tmp = top->val;    // Store the data of the top node
            node* p = top;         // Store the current top node in a temporary variable
            top = top->next;       // Move top to the next node
            delete p;              // Delete the old top node
            return tmp;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->val;  // Return the data of the top node
        }

        bool isEmpty() {
            return top == NULL;
        }
    };
};

int main() {
    ll::Stack stack;  // Create an instance of Stack from the ll struct

    // Test stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is " << stack.peek() << endl;

    cout << "Popped element is " << stack.pop() << endl;
    cout << "Popped element is " << stack.pop() << endl;

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}
