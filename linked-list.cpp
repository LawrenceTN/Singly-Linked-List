#include <iostream>

struct Node {
    int data;
    Node * next;
};

// This funciton will be used to print the contents of our Linked List
void printList(Node * head){ 
    while(head != NULL){
        std::cout << "[" << head->data << "] -> ";
        head = head->next;
    }
    std::cout << "[NULL]";
    return;
}

int main(){
    std::cout << "Welcome! In this project, I will be showing and explaining how to create a singly Linked List\n";
    std::cout << "Here we have 3 nodes all connected together\n";

    // Allocate 3 nodes in the heap, the first node of a linked list is called the head
    Node * head = new Node();
    Node * second = new Node();
    Node * third = new Node();

    // Now we're going to fill in the contents of these nodes with data (int type) and what the node is connected to (Node *).
    head->data = 16;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = NULL;

    // Now we can print it out to show what our list is comprised of thus far..
    printList(head);
    return 0;
}