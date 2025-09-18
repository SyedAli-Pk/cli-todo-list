#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool done;
};

void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty! Add something.\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].done ? 'x' : ' ') << "] " << tasks[i].description << "\n";
    }
    cout << endl;
}

void addTask(vector<Task>& tasks) {
    cout << "Enter a new task: ";
    string desc;
    getline(cin, desc);
    if (desc.empty()) {
        cout << "Task can't be empty!\n";
        return;
    }
    tasks.push_back({desc, false});
    cout << "Added: " << desc << "\n";
}

void markDone(vector<Task>& tasks) {
    showTasks(tasks);
    if (tasks.empty()) return;
    cout << "Enter task number to mark done: ";
    int num;
    cin >> num;
    cin.ignore();
    if (num < 1 || num > (int)tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[num - 1].done = true;
    cout << "Task " << num << " marked as done!\n";
}

void deleteTask(vector<Task>& tasks) {
    showTasks(tasks);
    if (tasks.empty()) return;
    cout << "Enter task number to delete: ";
    int num;
    cin >> num;
    cin.ignore();
    if (num < 1 || num > (int)tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    cout << "Deleted: " << tasks[num - 1].description << "\n";
    tasks.erase(tasks.begin() + num - 1);
}

int main() {
    vector<Task> tasks;
    while (true) {
        cout << "\n1. Add Task\n2. Show Tasks\n3. Mark Done\n4. Delete Task\n5. Quit\nChoose: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: showTasks(tasks); break;
            case 3: markDone(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
