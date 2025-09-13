#include<iostream>
using namespace std;

class Node{
    string book_Name;
    Node* next;
public:
    Node()
        {
            book_Name = "";
            next = NULL;
        }
    
    Node(string name)
        {
            book_Name= name;
            next = NULL;
        }
    Node(string name, Node* next)
        {
            book_Name = name;
            this ->next = next;
        }
    Node(const Node &other)
        {
            book_Name = other.book_Name;
            next = NULL;
        }
    string getBookName() { return book_Name; }
    void setNext(Node* nxt){next = nxt;}
    Node* getNext(){return next;}
    ~Node()
        {

        }

};

class LinkList{
    Node* head;
public:
    LinkList(){
        head = NULL;
    }

    void addFront(Node* book){
        book->setNext(head);
        head = book;
    }

    void addEnd(Node*newbook){
        newbook->setNext(NULL);
        if(head==NULL){
            head = newbook;
            return;
        }

        Node* temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->setNext(newbook);
    }

    void insertAfter(Node* target, Node* newNode) {
        if (target == NULL) return;
        newNode->setNext(target->getNext());
        target->setNext(newNode);
    }

    Node* search(string book) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->getBookName() == book)
                return temp;
            temp = temp->getNext();
        }
        return NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->getBookName() << " -> ";
            temp = temp->getNext();
        }
        cout << "NULL\n";
    }

    
    ~LinkList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->getNext();
            delete temp;
            temp = next;
        }
    }
};

int main(){
    LinkList books;

    Node* n1 = new Node("Data Structures");
    Node* n2 = new Node("Operating Systems");
    Node* n3 = new Node("Computer Networks");
    Node* n4 = new Node("Database Systems");

    books.addEnd(n1);
    books.addEnd(n2);
    books.addEnd(n3);
    books.addEnd(n4);

    Node* n5 = new Node("Artificial Intelligence");
    books.addFront(n5);

    Node* n6 = new Node("Machine Learning");
    books.addEnd(n6);

    Node* osNode = books.search("Operating Systems");
    Node* n7 = new Node("Cyber Security");
    books.insertAfter(osNode, n7);

    cout << "Searching for Database Systems: "<< (books.search("Database Systems") ? "Found" : "Not Found") << endl;

    books.display();

    return 0;
}