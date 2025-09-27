#include <iostream>
#include <stack>
using namespace std;

struct node{
    int value;
    node *next;
};

node *top = NULL;

void push(int n){
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = top;
    top = newNode;
    cout << n << " di push ke stack.\n";
}

void pop(){
    if (top == NULL){
        cout<<"Stack kosong. gak bisa di apus. \n";
        return;
    }
    node *temp = top;
    top = top -> next;
    cout <<temp -> value << " di apus dari stack.\n";
    delete temp;
}

int peak(){
    if (top == NULL){
        cout<<"Stack kosong. \n";
        return 1;
    }
    cout<<"Puncak nya: "<<top->value<<" \n";
    return top->value;
}

bool isEmpty(){
    return top == NULL;
}

void display(){
    if (top == NULL){
        cout<<"Stack kosong.\n";
        return;
    }
    node *temp = top;
    cout<<"Isi stack: ";
    while (temp != NULL){
        cout<<temp->value <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    for (int i = 11; i<30; i+=7){
        push(i);
        display();
    }
    pop();
}