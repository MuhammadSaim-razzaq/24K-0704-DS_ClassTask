#include <iostream>
#include <algorithm>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    int index = interpolationSearch(arr, n, key);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
