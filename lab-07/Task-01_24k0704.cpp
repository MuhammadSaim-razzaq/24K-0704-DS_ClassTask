#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int score;
    Student* next;
    
    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

class StudentList {
private:
    Student* head;
    
    int getMaxScore() {
        int maxScore = 0;
        Student* current = head;
        while (current) {
            if (current->score > maxScore) maxScore = current->score;
            current = current->next;
        }
        return maxScore;
    }
    
    void countSort(int exp) {
        Student* output[10] = {nullptr};
        Student* tails[10] = {nullptr};
        int count[10] = {0};
        
        Student* current = head;
        while (current) {
            int digit = (current->score / exp) % 10;
            count[digit]++;
            if (!output[digit]) {
                output[digit] = current;
                tails[digit] = current;
            } else {
                tails[digit]->next = current;
                tails[digit] = current;
            }
            current = current->next;
        }
        
        Student* newHead = nullptr;
        Student* tail = nullptr;
        for (int i = 0; i < 10; i++) {
            if (output[i]) {
                if (!newHead) {
                    newHead = output[i];
                    tail = tails[i];
                } else {
                    tail->next = output[i];
                    tail = tails[i];
                }
            }
        }
        if (tail) tail->next = nullptr;
        head = newHead;
    }

public:
    StudentList() : head(nullptr) {}
    
    void insert(string name, int score) {
        Student* newNode = new Student(name, score);
        newNode->next = head;
        head = newNode;
    }
    
    void radixSort() {
        int maxScore = getMaxScore();
        for (int exp = 1; maxScore / exp > 0; exp *= 10) {
            countSort(exp);
        }
    }
    
    void display() {
        cout << "\nSorted Students by Score:\n";
        cout << string(30, '-') << "\n";
        Student* current = head;
        while (current) {
            cout << "Name: " << current->name << "\n";
            cout << "Score: " << current->score << "\n";
            cout << string(30, '-') << "\n";
            current = current->next;
        }
    }
    
    ~StudentList() {
        Student* current = head;
        while (current) {
            Student* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    StudentList list;
    list.insert("choti khan", 85);
    list.insert("saib khan", 92);
    list.insert("ali shimal", 78);
    
    list.radixSort();
    list.display();
    
    return 0;
}
