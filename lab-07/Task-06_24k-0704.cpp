#include <iostream>
#include <string>

using namespace std;

struct Employee {
    string name;
    int id;
    int salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    Employee temp[12];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i].salary >= arr[j].salary) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int p = 0; p < k; p++) arr[left + p] = temp[p];
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Employee employees[12] = {
        {"Ateeb", 1, 50000},
        {"fahad", 2, 60000},
        {"ras gulla", 3, 55000},
        {"Saim", 4, 70000},
        {"arisu", 5, 45000},
        {"Us", 6, 80000},
        {"WE", 7, 65000},
        {"You", 8, 52000},
        {"It", 9, 75000},
        {"he", 10, 48000},
        {"she", 11, 72000},
        {"Laila", 12, 58000}
    };
    mergeSort(employees, 0, 11);
    cout << "Top 3 highest-paid employees:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << employees[i].name << ", ID: " << employees[i].id << ", Salary: " << employees[i].salary << endl;
    }
    return 0;
}
