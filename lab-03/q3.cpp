#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
    Node* prev;
};

class Train {
    Node* head;
public:
    Train() { head = NULL; }

    void addCompartment(int n) {
        Node* temp = new Node;
        temp->num = n;
        temp->next = NULL;
        temp->prev = NULL;
        if (!head) {
            head = temp;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = temp;
        temp->prev = cur;
    }

    void removeFront() {
        if (!head) {
            cout << "Train is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    void search(int n) {
        Node* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->num == n) {
                cout << "Compartment " << n << " found at position " << pos << "\n";
                return;
            }
            cur = cur->next;
            pos++;
        }
        cout << "Compartment not found\n";
    }

    void display() {
        if (!head) {
            cout << "Train is empty\n";
            return;
        }
        cout << "Compartments:\n";
        Node* cur = head;
        while (cur) {
            cout << cur->num << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    Train t;
    int ch, n;
    do {
        cout << "1. Add Compartment\n2. Remove First Compartment\n3. Search Compartment\n4. Display Train\n5. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter compartment number: ";
                cin >> n;
                t.addCompartment(n);
                break;
            case 2:
                t.removeFront();
                break;
            case 3:
                cout << "Enter compartment number: ";
                cin >> n;
                t.search(n);
                break;
            case 4:
                t.display();
                break;
        }
    } while (ch != 5);
}
