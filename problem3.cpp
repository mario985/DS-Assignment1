#include <iostream>
#include <fstream>
#include <sstream>
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
int main(void) 
{
    ifstream file("Testcases/testcases_problem3.txt");
    if (!file) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }
    string line;
    int testCaseNumber = 1;
    while (getline(file, line)) {
        if (line.empty()) continue; 

        SortedLinkedList fileList;
        istringstream ss(line);
        int value;

        while (ss >> value) {
            fileList.insert(value);
        }

        cout << "Test Case " << testCaseNumber++ << ":\n";
        cout << "Initial List: " << fileList << endl;

        while (getline(file, line) && !line.empty()) {
            istringstream commandStream(line);
            string command;
            commandStream >> command;

            if (command == "insert") {
                int val;
                if (commandStream >> val) {
                    fileList.insert(val);
                    cout << "Inserted " << val << "\n";
                    cout<<fileList<<endl;
                }
            } else if (command == "remove") {
                int index;
                if (commandStream >> index) {
                    fileList.remove(index);
                    cout << "Removed at index " << index << "\n";
                    cout<<fileList<<endl;
                }
            } else if (command == "print") {
                cout << "List: " << fileList << endl;
            } else if (command == "access") {
                int index;
                if (commandStream >> index) {
                    try {
                        fileList[index];
                        cout << "Element at index " << index << " : " << fileList[index] << "\n";
                    } catch (const out_of_range& e) {
                        cerr << e.what() << "\n";
                    }
                }
            }
        }
        cout << "Final List: " << fileList << "\n\n";
    }

    file.close();
  cout << "\nEEEEE  X   X  III  TTTTT   TTTTT  III  N   N   GGG  " << endl;
    cout << "E      X   X   I     T       T     I   NN  N  G     " << endl;
    cout << "EEE     X X    I     T       T     I   N N N  G  GG " << endl;
    cout << "E        X     I     T       T     I   N  NN  G   G " << endl;
    cout << "EEEEE   X  X  III    T       T    III  N   N   GGG  " << endl;
    }
Node::Node(int val) {
    data = val;
    next = NULL;
}
SortedLinkedList::SortedLinkedList() {
    head = NULL;
    count = 0;
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
    count++;
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
    else if(index>count){
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

    if (head == nullptr) {
        throw out_of_range("List is empty.");
    }
    if (index >= count || index < 0) {
        throw out_of_range("Index out of range.");
    }
    Node*current = head;
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









