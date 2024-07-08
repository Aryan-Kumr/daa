#include <iostream>
#include <vector>
using namespace std;
void mergeSort(int arr[], int low, int mid, int high) {
    vector<int> res;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            res.push_back(arr[left]);
            left++;
        }
        else {     //arr[left] > arr[right]
            res.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid) {
        res.push_back(arr[left]);
        left++;
    }
    while(right <= high) {
        res.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = res[i - low];
    }
}
void divide(int arr[], int low, int high) {
    if(low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    divide(arr, low, mid);
    divide(arr, mid+1, high);
    mergeSort(arr, low, mid, high);
}

int main() {
    int arr[] = {8, 6, 2, 3, 4, 7};
    int n = sizeof(arr) / sizeof(int);
    divide(arr, 0, n-1);
    for(auto it: arr) {
        cout<<it<<" ";
    }
    return 0;
}