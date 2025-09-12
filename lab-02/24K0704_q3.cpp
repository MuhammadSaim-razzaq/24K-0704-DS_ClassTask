#include <iostream>
using namespace std;

int main() {
    int groupCount;
    cout << "How many groups? ";
    cin >> groupCount;

    int** marks = new int*[groupCount];
    int* members = new int[groupCount];

    for (int i = 0; i < groupCount; i++) {
        cout << "Enter size of group " << i + 1 << ": ";
        cin >> members[i];
        marks[i] = new int[members[i]];

        cout << "Input values for group " << i + 1 << ": ";
        for (int j = 0; j < members[i]; j++) {
            cin >> marks[i][j];
        }
    }

    cout << "\nSum per Group:\n";
    for (int i = 0; i < groupCount; i++) {
        int total = 0;
        for (int j = 0; j < members[i]; j++) {
            total += marks[i][j];
        }
        cout << "Group " << i + 1 << " Total: " << total << endl;
    }

    for (int i = 0; i < groupCount; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] members;

    return 0;
}
