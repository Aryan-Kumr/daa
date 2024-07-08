#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main() {
    int arr[] = {8, 6, 2, 3, 4, 7};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    for(auto it: arr) {
        cout<<it<<" ";
    }
    return 0;
}