#include <iostream>
#include <string>
using namespace std;

class Guest {
public:
    string name;
    string contact;
    string iftar_date;

    Guest(string n, string c, string d)  {
        name = n;
        contact = c; 
        iftar_date = d;
    
    }

    void display_guest() {
        cout << "Guest name : " << name << ", Contact: " << contact << ", Iftar Date: " << iftar_date << endl;
    }

    void update_invitation(string new_date) {
        iftar_date = new_date;
    }
};

class IftarManager {
private:
    Guest** guest_list;  
    int capacity;
    int no_guests;

public:
    IftarManager(int size) : capacity(size), no_guests(0) {
        guest_list = new Guest * [capacity];  
    }

    ~IftarManager() {
        for (int i = 0; i < no_guests; i++) {
            delete guest_list[i];  
        }
        delete[] guest_list;  
    }

    void add_guest(Guest* guest) {
        if (no_guests < capacity) {
            guest_list[no_guests++] = guest;
        }
        else {
            cout << "Guest list is completed" << endl;
        }
    }

    void display_all_guests() {
        for (int i = 0; i < no_guests; i++) {
            guest_list[i]->display_guest();
        }
    }

    void update_guest_invitation(string name, string new_date) {
        for (int i = 0; i < no_guests; i++) {
            if (guest_list[i]->name == name) {
                guest_list[i]->update_invitation(new_date);
                cout << "new invitation for " << name  << endl;
                return;
            }
        }
        cout << "Guest not found" << endl;
    }

    void remove_guest(string name) {
        for (int i = 0; i < no_guests; i++) {
            if (guest_list[i]->name == name) {
                delete guest_list[i]; 

                for (int j = i; j < no_guests - 1; j++) {
                    guest_list[j] = guest_list[j + 1]; 
                }

                no_guests--;
                cout << "Guest " << name << " removed from guest list" << endl;
                return;
            }
        }
        cout << "Guest not found!" << endl;
    }

    void send_reminder(string date) {
        
        for (int i = 0; i < no_guests; i++) {
            if (guest_list[i]->iftar_date == date) {
                cout << "Reminder sent to " << guest_list[i]->name
                    << ": Your Iftar invitation is on " << date <<  endl;
            }
        }
    }

    
    void Insertionsort_guest_list() {
        for (int i = 1; i < no_guests; i++) {
            Guest* key = guest_list[i]; 
            int j = i - 1;

            while (j >= 0 && guest_list[j]->iftar_date > key->iftar_date) {
                guest_list[j + 1] = guest_list[j];
                j--;
            }
            guest_list[j + 1] = key;
        }
        cout << "Guests sorted   by Iftar date" << endl;
    }
};

int main() {
    IftarManager manager(5);

    Guest* guest1 = new Guest("ahmed", "ahmed@example.com", "2025-03-15");
    Guest* guest2 = new Guest("ali", "ali@example.com", "2025-03-18");
    Guest* guest3 = new Guest("fares", "fares@example.com", "2025-03-12");
    Guest* guest4 = new Guest("shika", "shika@example.com", "2025-03-20");

    manager.add_guest(guest1);
    manager.add_guest(guest2);
    manager.add_guest(guest3);
    manager.add_guest(guest4);

    cout << " guest list Before Sorting: " << endl;
    manager.display_all_guests();

    manager.Insertionsort_guest_list();

    cout << " guest list After Sorting: " << endl;
    manager.display_all_guests();

    cout << " Sending Reminder  "<<endl;
    manager.send_reminder("2025-03-15");

    cout << " Updating  invitation "<<endl;
    manager.update_guest_invitation("ali", "2025-03-22");

    cout << " Updated Guest List: " << endl;;
    manager.display_all_guests();

    cout << " Removing guest "<<endl;
    manager.remove_guest("ahmed");

    cout << " Guest List After Remove: "<<endl;
    manager.display_all_guests();

    return 0;
}
