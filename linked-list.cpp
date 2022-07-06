#include <iostream>

struct Node {
    int data;
    Node * next;
};

// This funciton will be used to print the contents of our Linked List starting with the head of the list
void printList(Node * head){ 
    while(head != NULL){
        std::cout << "[" << head->data << "] -> ";
        head = head->next;
    }
    std::cout << "[NULL]\n";
    return;
}

// This function will add a node to the linked list at the beginning and set it as the new node using a double ptr.
void newHead(Node ** head, int data){
    Node * newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;        
}

// The append node will add a node at the end of the list
void appendNode(Node * head, int data){
    Node * newNode = new Node();
    newNode->data = data;
    
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
    return;
}

// This function will add a node at a specifc placement at the user's request (1 = first node, 2 = 2nd node, etc...)
void addNode(Node * head, int data, int placement){
    Node * newNode = new Node();
    newNode->data = data;

    Node * curr = head;
    Node * prev = NULL;

    for(int i = 0; i < placement-1; i++){
        prev = curr;
        curr = curr->next;
        if(curr->next == NULL){
            break;
        }
    }

    prev->next = newNode;
    newNode->next = curr;
}

// Remove's the first node (head) and assigns the next node as the new head.
void removeHead(Node ** head){
    Node * curr = *head;
    Node * newHead = NULL;
    
    newHead = curr->next;
    delete curr;
    *head = newHead;

    return;
}

// Remove the last node (popping the linked list)
void popNode(Node * head){
    Node * prev = NULL;
    Node * curr = head;

    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
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

    // Now we can print it out to show what our list is comprised of thus far.
    printList(head);

    // We will now add a new node to the beginning (making it the new head) and we will assign it with data to hold as well.
    newHead(&head, 4);

    printList(head);

    // Now we will append a Node to the list (place at the back).
    appendNode(head, 10);

    printList(head);

    // Let's add a node at specific position, the 3rd parameter in this function call will be where the new node will be placed.
    addNode(head, 12, 2);

    printList(head);

    // Removing the head and making the second node the new head
    removeHead(&head);

    printList(head);

    // Remove the last node 
    popNode(head);

    printList(head);

    return 0;
}