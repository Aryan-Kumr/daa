#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    int k = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = k = i; j < n; j++) {
            if(arr[j] < arr[k]) {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}
int main() {
    int arr[] = {8, 6, 2, 3, 4, 7};
    int n = sizeof(arr) / sizeof(int);
    selectionSort(arr, n);
    for(auto it: arr) {
        cout<<it<<" ";
    }
    return 0;
}