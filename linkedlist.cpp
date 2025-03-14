#include "linkedlist.h"
Node::Node(int val) {
    data = val;
    next = NULL;
}
SortedLinkedList::SortedLinkedList() {
    head =nullptr;
}

void SortedLinkedList::insert(int value) {
    Node*newnode = new Node(value);
    if (!head) {
        head = newnode;
    }
    else if (head->data >=newnode->data) {
        newnode->next = head;
        head = newnode;

    }
    else {
        Node *current = head;
        Node*next = head->next;
        while (next && newnode->data >=next->data) {
            current = next;
            next = current->next;
        }
        current->next = newnode;
        newnode->next = next;
    }
}
void SortedLinkedList::remove(int index) {
   if (head==NULL) {
       return;
   }
    Node*previous = head;
    Node*current = head->next;
    if (index == 0) {
        delete head;
        head = current;
        return;
    }
    else {
        while ( index>1 && current) {
           previous = previous->next;
            current = current->next;
            index--;
        }
        if (current) {
            previous->next = current->next;
            delete current;
        }
    }
}
int SortedLinkedList::operator[](int index) {
    Node*current = head;
    if (head==NULL) {
        return 0;
    }
    while (index>=1 && current) {
        current = current->next;
        index--;
    }
    if (current) {
        return current->data;
    }
    return 0;

}
 ostream& operator<<(ostream& os, const SortedLinkedList& list) {
    Node*current = list.head;
    os<<"[";
    while (current) {
        os<<current->data;
        if (current->next) {
            os<<", ";
        }
        current = current->next;
    }
    os<<"]"<<endl;
    return os;
}
SortedLinkedList::~SortedLinkedList() {
    Node*current = head;
    while (current) {
        Node*temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;

}







