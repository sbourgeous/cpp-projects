#include <iostream> 
#include <vector>
#include <string>

using namespace std;

//-------- Class Definiton --------

class Task {
public:
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }

    void markComplete() {
        completed = true;
    }
};

//-------- Function Prototypes --------

void showMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void completeTask(vector<Task>& tasks);

//-------- Main --------

int main() {
    vector<Task> tasks;
    int choice = 0;

    while (choice != 4) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        }
        else if (choice == 2) {
            viewTasks(tasks);
        }
        else if (choice == 3) {
            completeTask(tasks);
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again. \n";
        }
    }
}

//-------- Function Definitions--------

void showMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Add Task\n";
    cout << "2. View tasks\n";
    cout << "3. Mark Task Complete\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);

    tasks.push_back(Task(desc));
    cout << "Task added.\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].description
             << "["
             << (tasks[i].completed ? "Completed" : "Pending")
             << "]\n";
    }
}

void completeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);

    if (tasks.empty()) return;

    cout << "Enter task number to complete\n";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markComplete();
    cout << "Task marked complete.\n";
}