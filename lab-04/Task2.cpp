#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ++comparisons && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void shellSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && (++comparisons && arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    srand(time(0));
    int n = 20;
    int arr[100];

    for (int i = 0; i < n; i++) arr[i] = rand() % 100 + 1;

    cout << "Original Array:\n";
    printArray(arr, n);

    int temp[100], comparisons;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    bubbleSort(temp, n, comparisons);
    cout << "\nBubble Sort:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    insertionSort(temp, n, comparisons);
    cout << "\nInsertion Sort:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    selectionSort(temp, n, comparisons);
    cout << "\nSelection Sort:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    shellSort(temp, n, comparisons);
    cout << "\nShell Sort:\n";
    printArray(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
