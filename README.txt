Name: Shawn  
Student ID: s1113570  
Date of Submission: 25-Nov-2024  

Homework Description:  
This submission contains solutions to four programming tasks written in C++.  
Each task addresses a specific data structure problem, as described below.

Files:  
1. **question1.cpp**:  
   - **Description**: Calculates the diameter of a binary tree. The diameter is the length of the longest path between any two nodes, which may or may not pass through the root.  
   - **Input**: A level-order traversal of the binary tree using `-1` to represent null nodes.  
   - **Output**: The diameter of the binary tree.  

2. **question2.cpp**:  
   - **Description**: Manages a task priority queue using a max heap. Tasks can be added with a priority, the highest-priority task can be fetched, and remaining tasks can be displayed.  
   - **Input**: A series of operations, either `ADD task_name priority` or `GET`.  
   - **Output**: The name of the fetched task for each `GET` operation and the list of remaining tasks.  

3. **question3.cpp**:  
   - **Description**: Merges K sorted arrays into a single sorted array using a min priority queue.  
   - **Input**: The number of arrays, followed by each sorted array on a new line.  
   - **Output**: The merged sorted array.  

4. **question4.cpp**:  
   - **Description**: Schedules tasks to maximize profit using a max priority queue. Tasks are scheduled based on deadlines and profits.  
   - **Input**: The number of tasks, followed by the profit and deadline for each task.  
   - **Output**: The maximum achievable profit and the list of scheduled tasks.  

Sample Input and Output:  

1. **question1.cpp**:  
   Input: `1 2 3 4 5 -1 -1 -1 -1 6 7`  
   Output: `5`  

2. **question2.cpp**:  
   Input: 
6
ADD Task1 10
ADD Task2 15
ADD Task3 5
GET
ADD Task4 20
GET 

Output:  
Task2
Task4
Remaining tasks: [('Task1', 10), ('Task3', 5)]



3. **question3.cpp**:  
Input:  
3
1 4 7
2 5 8
3 6 9


Output:  
Merged Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]


4. **question4.cpp**:  
Input:  
4
100 2
19 1
27 2
25 1


Output:  
Maximum Profit: 127
Scheduled Tasks: [100, 27]


Special Notes:  
- All programs are written in C++ and require a C++ compiler (e.g., g++) to compile and run.  
- To compile a program, use the command:  
g++ questionX.cpp -o questionX

Replace `X` with the question number.  
