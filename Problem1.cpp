#include <iostream>
#include <string>
#include <utility>
using namespace std;
class Guest {
public:
    string name;
    string contact;
    string iftar_date;

    Guest(string n, string c, string d)  {
        name = std::move(n);
        contact = std::move(c);
        iftar_date = std::move(d);
    }
    // Prints the data of the guest
    void display_guest() const{
        cout << " (Name: " << name << ", Contact info: " << contact << ", Iftar Date: " << iftar_date << ')' << endl;
    }
    // Function to update the date in invitation
    void update_invitation(string new_date) {
        iftar_date = std::move(new_date);
    }
};

class IftarManager {
private:
    Guest** guest_list;
    int capacity;
    int no_guests;

public:
    IftarManager(int capacity) : capacity(capacity), no_guests(0) {
        // Dynamically allocates an array of Guest* pointers with a size of capacity & initialize with nullptr.
        guest_list = new Guest*[capacity]();
    }

    ~IftarManager() {
        for (int i = 0; i < no_guests; i++) {
            delete guest_list[i];
        }
        delete[] guest_list;
    }

    void add_guest(Guest *guest) {
        // add the guest if the max capacity is not reached
        if (no_guests < capacity) {
            guest_list[no_guests++] = guest;
            cout << "Guest " << guest->name << ", is successfully added in the list" << endl;
        }
        else {
            cout << "Cant add " << guest->name << ", guest list is full!" << endl;
            // Delete the guest if it can't be added to prevent memory leak
            delete guest;
        }
    }

    void display_all_guests() const{
        for (int i = 0; i < no_guests; i++) {
            cout << "Guest " << i + 1;
            guest_list[i]->display_guest();
        }
    }

    void update_guest_invitation(const string& name, const string& new_date) {
        for (int i = 0; i < no_guests; i++) {
            // If the name existed in the list update the date
            if (guest_list[i]->name == name) {
                guest_list[i]->update_invitation(new_date);
                cout << "The date is updated for " << name  << endl;
                return;
            }
        }
        cout << "Guest " << name << " not found!" << endl;
    }

    void remove_guest(const string& name) {
        for (int i = 0; i < no_guests; i++) {
            // If the name existed in the list remove it
            if (guest_list[i]->name == name) {
                delete guest_list[i];

                // Shift the guests to the left in the list to fill the gap
                for (int j = i; j < no_guests - 1; j++) {
                    guest_list[j] = guest_list[j + 1];
                }

                no_guests--;
                guest_list[no_guests] = nullptr; // Set the last element to nullptr
                cout << "Guest " << name << " removed from guest list" << endl;
                return;
            }
        }
        cout << "Guest " << name << " not found!" << endl;
    }

    void send_reminder(const string& date) {
        bool found = false;
        for (int i = 0; i < no_guests; i++) {
            // Sends a reminder if it is the same date passed
            if (guest_list[i]->iftar_date == date) {
                cout << "Reminder sent to " << guest_list[i]->name
                     << ": Your Iftar invitation is on " << date <<  endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No guests found for date: " << date << endl;
        }
    }
    // Sorts the array by the date using insertion sort
    void InsertionSort_guestList() {
        if (no_guests <= 1) {
            return;
        }
        for (int i = 1; i < no_guests; i++) {
            Guest* key = guest_list[i];
            int j = i - 1;

            while (j >= 0 && guest_list[j]->iftar_date > key->iftar_date) {
                guest_list[j + 1] = guest_list[j];
                j--;
            }
            guest_list[j + 1] = key;
        }
    }
};

int main() {
    // Create an IftarManager list with a capacity of 5
    IftarManager manager(5);

    auto* guest1 = new Guest("ahmed", "ahmed@example.com", "2025-03-15");
    auto* guest2 = new Guest("ali", "ali@example.com", "2025-03-18");
    auto* guest3 = new Guest("fares", "fares@example.com", "2025-03-12");
    auto* guest4 = new Guest("shika", "shika@example.com", "2025-03-20");

    manager.add_guest(guest1);
    manager.add_guest(guest2);
    manager.add_guest(guest3);
    manager.add_guest(guest4);

    cout << "-> Guest list Before Sorting: " << endl;
    manager.display_all_guests();
    cout << "-----------------------------------------\n";

    manager.InsertionSort_guestList();

    cout << "-> Guest list After Sorting: " << endl;
    manager.display_all_guests();
    cout << "-----------------------------------------\n";

    cout << "-> Sending Reminder  "<< endl;
    manager.send_reminder("2025-03-18");
    manager.send_reminder("2025-08-01");
    cout << "-----------------------------------------\n";

    cout << "-> Updating invitation "<< endl;
    manager.update_guest_invitation("ali", "2025-03-22");
    manager.update_guest_invitation("kareem", "2025-03-08");
    cout << "-----------------------------------------\n";

    cout << "-> Updated Guest List: " << endl;
    manager.display_all_guests();
    cout << "-----------------------------------------\n";

    cout << "-> Removing guest "<<endl;
    manager.remove_guest("ahmed");
    manager.remove_guest("mohamed");
    cout << "-----------------------------------------\n";

    cout << "-> Guest List After Remove: "<<endl;
    manager.display_all_guests();
    cout << "-----------------------------------------\n";

    auto* guest5 = new Guest("Omar", "omar@example.com", "2025-07-06");
    auto* guest6 = new Guest("Mohamed", "mohamed@example.com", "2025-07-08");
    auto* guest7 = new Guest("Kareem", "kareem@example.com", "2025-07-11");

    manager.add_guest(guest5);
    manager.add_guest(guest6);
    manager.add_guest(guest7);

    cout << "-> Guest List After adding and sorting them: "<<endl;
    manager.InsertionSort_guestList();
    manager.display_all_guests();
    cout << "-----------------------------------------\n";

    return 0;
}