/*
Name: [shawn]
Student ID: [s1113570]
Date of Submission: 25-Nov-2024

Description:
This program merges `k` sorted arrays into a single sorted array using a min heap (priority queue). It ensures that the merged array is sorted efficiently.

Steps:
1. Input the number of arrays (`k`).
2. Read each sorted array.
3. Use a min heap to:
   - Store the smallest element from each array.
   - Extract the smallest element and add the next element from the same array to the heap.
4. Repeat until all elements are merged into a single sorted array.
5. Print the merged array.

Functions:
- `merge_k_sorted_arrays`: Merges `k` sorted arrays using a min heap.
- The `Element` struct stores the value, array index, and element index for heap operations.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <sstream> 

using namespace std;

struct Element {
    int value;
    int array_index;
    int element_index;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> merge_k_sorted_arrays(const vector<vector<int>>& arrays) {
    
    priority_queue<Element, vector<Element>, greater<Element>> min_heap;

    
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            min_heap.push({arrays[i][0], i, 0});
        }
    }

    
    vector<int> result;

    
    while (!min_heap.empty()) {
        Element current = min_heap.top();
        min_heap.pop();
        result.push_back(current.value);

    
        if (current.element_index + 1 < arrays[current.array_index].size()) {
            int next_value = arrays[current.array_index][current.element_index + 1];
            min_heap.push({next_value, current.array_index, current.element_index + 1});
        }
    }

    return result;
}

int main() {
    int k;
    cin >> k;
    vector<vector<int>> arrays(k);

    
    for (int i = 0; i < k; ++i) {
        string line;
        getline(cin >> ws, line);
        istringstream iss(line);
        int num;
        while (iss >> num) {
            arrays[i].push_back(num);
        }
    }

    
    vector<int> merged_array = merge_k_sorted_arrays(arrays);
    cout << "Merged Array: [";
    for (size_t i = 0; i < merged_array.size(); ++i) {
        cout << merged_array[i];
        if (i != merged_array.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
