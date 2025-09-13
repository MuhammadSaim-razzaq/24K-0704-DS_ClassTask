#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
    Node* head;
public:
    List() { head = NULL; }

    void insert(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;
        if (!head) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void display() {
        Node* t = head;
        if (!t) {
            cout << "List is empty\n";
            return;
        }
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }

    void sort() {
        if (!head) return;
        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    void concat(List& l2) {
        if (!head) {
            head = l2.head;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = l2.head;
        l2.head = NULL;
    }

    void middle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }

    void removeDuplicates() {
        Node* i = head;
        while (i) {
            Node* j = i;
            while (j->next) {
                if (j->next->data == i->data) {
                    Node* d = j->next;
                    j->next = j->next->next;
                    delete d;
                } else {
                    j = j->next;
                }
            }
            i = i->next;
        }
    }

    static List mergeSorted(List& l1, List& l2) {
        List res;
        Node dummy;
        Node* tail = &dummy;
        dummy.next = NULL;
        Node* a = l1.head;
        Node* b = l2.head;
        while (a && b) {
            if (a->data <= b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a ? a : b);
        res.head = dummy.next;
        l1.head = NULL;
        l2.head = NULL;
        return res;
    }
};

int main() {
    List l1, l2, merged;
    int ch, val;
    do {
        cout << "1. Insert in L1\n2. Insert in L2\n3. Display L1\n4. Display L2\n5. Sort L1\n6. Sort L2\n7. Concat L2 into L1\n8. Middle of L1\n9. Remove duplicates from L1\n10. Merge L1 and L2\n11. Display Merged\n12. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                l1.insert(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                l2.insert(val);
                break;
            case 3:
                l1.display();
                break;
            case 4:
                l2.display();
                break;
            case 5:
                l1.sort();
                break;
            case 6:
                l2.sort();
                break;
            case 7:
                l1.concat(l2);
                break;
            case 8:
                l1.middle();
                break;
            case 9:
                l1.removeDuplicates();
                break;
            case 10:
                merged = List::mergeSorted(l1, l2);
                break;
            case 11:
                merged.display();
                break;
        }
    } while (ch != 12);
}
