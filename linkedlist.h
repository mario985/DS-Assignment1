#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include <iostream>
#include <fstream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    int count;
    Node(int val);
};
class SortedLinkedList {
private:
    Node* head;
    int count;
public:
    SortedLinkedList();
    void insert(int value);
    void remove(int index);

    friend ostream& operator<<(ostream& os, const SortedLinkedList& list);
    int operator[](int index);

    ~SortedLinkedList();
};
#endif
