#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    Node* next;
};

class Library {
    Node* head;
public:
    Library() { head = NULL; }

    void addBookTail(string t) {
        Node* n = new Node;
        n->title = t;
        n->next = NULL;
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void deleteBookFront() {
        if (!head) {
            cout << "Catalog is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByTitle(string t) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->title == t) {
                cout << "Book found at position " << pos << ": " << temp->title << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Book not found\n";
    }

    void searchByPosition(int p) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (pos == p) {
                cout << "Book at position " << pos << ": " << temp->title << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Invalid position\n";
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "Catalog is empty\n";
            return;
        }
        cout << "Catalog:\n";
        while (temp) {
            cout << temp->title << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    Library lib;
    int ch;
    string title;
    int pos;
    do {
        cout << "1. Add Book to Tail\n2. Delete Book from Front\n3. Search by Title\n4. Search by Position\n5. Display Catalog\n6. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                lib.addBookTail(title);
                break;
            case 2:
                lib.deleteBookFront();
                break;
            case 3:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                lib.searchByTitle(title);
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                lib.searchByPosition(pos);
                break;
            case 5:
                lib.display();
                break;
        }
    } while (ch != 6);
}
