#include <iostream>
using namespace std;

class FlexArray {
private:
    int* ptr;
    int cap;
    int size;

    void grow() {
        cap *= 2;
        int* temp = new int[cap];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
    }

public:
    FlexArray(int init = 3) {
        cap = init;
        size = 0;
        ptr = new int[cap];
    }

    void add(int num) {
        if (size == cap) {
            grow();
        }
        ptr[size++] = num;
    }

    void printArray() {
        cout << "Stored Values: ";
        for (int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ~FlexArray() {
        delete[] ptr;
    }
};

int main() {
    FlexArray obj;
    int total, x;
    cout << "Enter count of elements: ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        cout << "Provide element " << i + 1 << ": ";
        cin >> x;
        obj.add(x);
    }

    obj.printArray();
    return 0;
}
