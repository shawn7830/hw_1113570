/*
Name: [shawn]
Student ID: [s1113570]
Date of Submission: 25-Nov-2024

Description:
This program manages a list of tasks with priorities using a priority queue. Tasks with higher priority are processed first.

Steps:
1. Read the number of commands (`n`).
2. Perform the following commands:
   - "ADD": Add a task with a name and priority to the queue.
   - "GET": Get and remove the task with the highest priority. If the queue is empty, print "No tasks available."
3. After processing all commands, display the remaining tasks in the queue.

Functions:
- The `priority_queue` is used to keep tasks sorted by priority (highest first).
- Remaining tasks are displayed in the format: `("task_name", priority)`
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>

using namespace std;

struct Task {
    string name;
    int priority;

    
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<Task> pq;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string task_name;
            int priority;
            cin >> task_name >> priority;
            pq.push({task_name, priority});
        } else if (command == "GET") {
            if (!pq.empty()) {
                Task top_task = pq.top();
                pq.pop();
                cout << top_task.name << endl;
            } else {
                cout << "No tasks available" << endl;
            }
        }
    }

    
    vector<pair<string, int>> remaining_tasks;
    while (!pq.empty()) {
        Task task = pq.top();
        pq.pop();
        remaining_tasks.push_back({task.name, task.priority});
    }

    
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remaining_tasks.size(); ++i) {
        cout << "('" << remaining_tasks[i].first << "', " << remaining_tasks[i].second << ")";
        if (i != remaining_tasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
