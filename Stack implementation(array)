#include<bits/stdc++.h>
using namespace std;
class Stack{
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size){
        arr=new int[size];
        capacity=size;
        top=-1;
    }
    ~Stack(){
        delete[] arr;
    }
    void push(int x){
        if(isFull()){
            cout << "Stack overflow\n";
            return;
        }
        arr[++top]=x;
        cout << "Inserted " << x << endl;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==capacity-1;
    }
};
int main(){
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    cout << "Top element is " << stack.peek() << endl;
    cout << "Stack size is " << stack.size() << endl;
    cout << "Popped element is " << stack.pop() << endl;
    cout << "Popped element is " << stack.pop() << endl;
    if(stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
}
