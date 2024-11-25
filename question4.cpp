/*
Name: [shawn]
Student ID: [s1113570]
Date of Submission: 25-Nov-2024

Description:
This program schedules tasks to maximize profit. Each task has a profit and a deadline, and the goal is to schedule tasks so that the total profit is as high as possible while respecting their deadlines.

Steps:
1. Read the number of tasks (`n`).
2. Input each task's profit and deadline.
3. Sort the tasks in descending order of profit.
4. Create a schedule:
   - Assign each task to the latest available slot before its deadline.
   - Add the profit of scheduled tasks to the total profit.
5. Print the scheduled tasks and the maximum profit.

Functions:
- `scheduleTasksMaxProfit`: Schedules tasks to maximize total profit and returns the profit.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Task {
    int profit;
    int deadline;
};

bool compareTasks(const Task& t1, const Task& t2) {
    return t1.profit > t2.profit;
}

int scheduleTasksMaxProfit(vector<Task>& tasks) {
    
    sort(tasks.begin(), tasks.end(), compareTasks);

    
    int max_deadline = 0;
    for (const Task& task : tasks) {
        max_deadline = max(max_deadline, task.deadline);
    }

    
    vector<int> schedule(max_deadline, -1);
    int total_profit = 0;

    
    for (const Task& task : tasks) {
    
        for (int i = task.deadline - 1; i >= 0; --i) {
            if (schedule[i] == -1) {
                schedule[i] = task.profit;
                total_profit += task.profit;
                break;
            }
        }
    }

    
    vector<int> scheduled_tasks;
    for (int profit : schedule) {
        if (profit != -1) {
            scheduled_tasks.push_back(profit);
        }
    }
    reverse(scheduled_tasks.begin(), scheduled_tasks.end());

    
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduled_tasks.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << scheduled_tasks[i];
    }
    cout << "]" << endl;

    return total_profit;
}

int main() {
    int n;
    cin >> n;
    vector<Task> tasks(n);

    
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

    
    int max_profit = scheduleTasksMaxProfit(tasks);
    cout << "Maximum Profit: " << max_profit << endl;

    return 0;
}
	