#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    // Find the maximum element in the array

    int max_element = 1;
    max_element = arr[0];
    for(int i=0;i<arr.size() - 1;i++){
        if(arr[i] < arr[i+1]){
            max_element = arr[i+1];
        }
    }

    cout<<endl<<max_element<<endl;

    // Create a count array to store frequency of each element
    vector<int> count(max_element + 1, 0);

    // Store the frequency of each element in the count array
    for (int num : arr) {
        count[num]++;
    }

    // Modify the count array to store the starting index of each element
    for (int i = 1; i <= max_element; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    vector<int> sorted(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = sorted[i];
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}