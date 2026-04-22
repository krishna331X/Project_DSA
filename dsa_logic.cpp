#include <iostream>
#include <string>
using namespace std;

class Booking {
public:
    string name;
    string service;
    string time;
    Booking* next;

    Booking(string n, string s, string t) {
        name = n;
        service = s;
        time = t;
        next = NULL;
    }
};

class LinkedList {
private:
    Booking* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addBooking(string name, string service, string time) {
        Booking* newNode = new Booking(name, service, time);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Booking* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void displayBookings() {
        Booking* temp = head;

        while (temp != NULL) {
            cout << "Name: " << temp->name << endl;
            cout << "Service: " << temp->service << endl;
            cout << "Time: " << temp->time << endl;
            cout << "-----------------" << endl;

            temp = temp->next;
        }
    }

    void searchBooking(string name) {
        Booking* temp = head;

        while (temp != NULL) {
            if (temp->name == name) {
                cout << "Booking Found!" << endl;
                cout << temp->service << " at " << temp->time << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Booking Not Found" << endl;
    }
};

int main() {

    LinkedList studio;

    studio.addBooking("Riya", "Nail Art", "2PM");
    studio.addBooking("Sneha", "Manicure", "3PM");

    cout << "All Bookings:\n";
    studio.displayBookings();

    cout << "\nSearch Booking:\n";
    studio.searchBooking("Riya");

}