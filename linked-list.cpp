#include <iostream>

struct Node {
    int data;
    Node * next;
};

// This funciton will be used to print the contents of our Linked List starting with the head of the list
void printList(Node * head){ 
    std::cout << "Printing the list:\n\t";
    while(head != NULL){
        std::cout << "[" << head->data << "] -> ";
        head = head->next;
    }
    std::cout << "[NULL]\n";
    return;
}

// This function will add a node to the linked list at the beginning and set it as the new node using a double ptr.
void newHead(Node ** head, int data){
    std::cout << "Adding a new head node with data: " << data << std::endl;
    Node * newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;        
}

// The append node will add a node at the end of the list
void appendNode(Node * head, int data){
    std::cout << "Appending a node at the end with data: " << data << std::endl;
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
    std::cout << "Adding a node with data '" << data << "' at position [" << placement << "]\n";
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
    
    // Create a node ptr and set it to the next node after the head. Delete the old head, then use the double ptr head to label the new head of the linked list 
    std::cout << "Removing the head node\n";
    Node * curr = *head;
    Node * newHead = NULL;
    
    newHead = curr->next;
    delete curr;
    *head = newHead;

    return;
}

// Remove the last node (popping the linked list)
void popNode(Node * head){
    std::cout << "Removing the last node in the list\n";
    Node * prev = NULL;
    Node * curr = head;
    
    // Keep iterating and jumping along the list until you reach the end, then set the prev node to NULL before deleting the last node.
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
    return;
}

void removeNode(Node * head, int placement){
    std::cout << "Removing the node at position [" << placement <<  "]\n";
    Node * curr = head;
    Node * prev = NULL;
    
    // Humans naturally see the list and think the first entry is '1', therefore we use "placement-1"
    // Make sure you connect the prev node and the next node of the chosen deleted node before deleeting.
    for(int i = 0; i < placement-1; i++){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
    return;
}

void reverseList(Node ** head){
    std::cout << "Reversing the contents of the linked list\n";
    Node * curr = *head;
    Node * prev = NULL;
    Node * next = NULL;
    
    // Really think about each step in this while-loop and draw it out. The pointers are used as signs/labels and '->next' is flipping the direction of our linked list.
    while(curr != NULL){ 
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // At the end, we have a new head, so using the double ptr head in the parameter you can set the new head to be prev.
    *head = prev;
    return;
}

void editHead(Node * head, int newData){
    head->data = newData;
    return;
}


void editNode(Node * head, int newData, int placement){ // If the user enters a number larger than the length of the list, it will automatically edit the last node's data.
    bool validPlacement = false;
    
    while(!validPlacement){
        if(placement < 1){
            std::cout << "Invalid placement in the Linked List. Exiting...\n";
            return;
        }
        else{
            validPlacement = true;
        }
    }
    
        Node * curr = head;
        for(int i = 0; i < placement-1; i++){ // If 1, it changes the head
            curr = curr->next;
            if(curr->next == NULL){
                break;
            }
        }
        curr->data = newData;
        return;
}


void editEnd(Node * head, int newData){
    while(head->next != NULL){
        head = head->next;
    }
    head->data = newData;
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
    
    removeNode(head, 3);
    
    printList(head);
    
    reverseList(&head);
    
    printList(head);
    
    editHead(head, 10);
    
    printList(head);
    
    editEnd(head, 34);
    
    printList(head);
    
    editNode(head, 24, 5);
    
    printList(head);

    editNode(head, 5, 0); // Result in an exit because there is no node before the head... (I'm explicitly labeling the first node 1st in the list and not 0th (like an array..))
    
    printList(head);
    
    return 0;
}
