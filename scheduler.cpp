#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Task {
    string name;
    int priority; // 1 = High, 2 = Medium, 3 = Low
    bool done;
};

vector<Task> tasks;

void addTask() {
    Task t;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, t.name);
    cout << "Enter priority (1-High, 2-Medium, 3-Low): ";
    cin >> t.priority;
    t.done = false;
    tasks.push_back(t);
    cout << "Task added!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks added yet!\n";
        return;
    }

    // Sort by priority
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.priority < b.priority;
    });

    cout << "\nTasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". [" << (tasks[i].done ? "x" : " ") << "] "
             << tasks[i].name << " (Priority: " << tasks[i].priority << ")\n";
    }
}

void markDone() {
    viewTasks();
    int index;
    cout << "Enter task number to mark done: ";
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks[index-1].done = true;
    cout << "Task marked as done!\n";
}

void deleteTask() {
    viewTasks();
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task deleted!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\nCLI Task Scheduler\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markDone(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
