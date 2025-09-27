#include <iostream>
using namespace std;

// Deklarasi struktur node
struct node{
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;


// Insert Didepan
void insertFirst(int n){
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head==NULL){
        head = newNode;
        tail = head;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
}

// Insert Dibelakang
void insertLast(int n){
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head==NULL){
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

// insert after
void insertAfter(int n, int check){
    if (head == NULL){
        cout<<"List Kosong, Insert di depan dulu";
    }
    // else if (tail == NULL){
    //     cout<<"List Kosong, Insert di belakang dulu";
    // }

    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;
    node *p = head;

    while (p != NULL && p -> value != check){
        p = p -> next;
    }

    if (p == NULL) {
        cout<<"Node dengan nilai "<< check << "tidak ditemukan\n";
        delete newNode;
    }
    else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail){
            tail = newNode;
        }
    }
}

void printList(){
    node *temp = head;
    cout<< "isi linkedlist : ";
    while (temp != NULL){
        cout<<temp -> value << " -> ";
        temp = temp -> next;
    }
    cout<< "NULL\n";
}

int main(){
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    // insertAfter(25, 20);
    printList();
    return 0;
}