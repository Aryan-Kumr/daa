#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int low, int high) {
    int i = low;   // to find original position of pivot ele.
    int pivot = arr[high];   //returns last elemrnt of array(vector)
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    vector<int> arr = {3, 9, 1, 7, 10, 2, 4, 6, 8, 5, 1};
    int n = arr.size();
    quickSort(arr, 0, n-1);
    for(auto it: arr) {
        cout<<it<<" ";
    }
    return 0;
}