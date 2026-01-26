#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

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
void deleteTask(vector<Task>& tasks);
void saveToFile(const vector<Task>& tasks);

//-------- Main --------

int main() {
    vector<Task> tasks;
    int choice = 0;

    while (choice != 6) {
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
            deleteTask(tasks);
        }
        else if (choice ==5) {
            saveToFile(tasks);
        }
        else if (choice == 6) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again. \n";
        }
    }
}

//-------- Function Definitions--------

void showMenu() {
    cout << "\n============================\n";
    cout << "          MAIN MENU         \n";
    cout << "============================\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task Complete\n";
    cout << "4. Delete Task\n";
    cout << "5. Save To File\n";
    cout << "6. Exit\n";
    cout << "============================\n";
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

    cout << "Enter task number to complete: \n";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markComplete();
    cout << "Task marked complete.\n";
}

void deleteTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);

    if (tasks.empty()) return;

    cout << "Enter task number to delete: \n";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task deleted.\n";
}

void saveToFile(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.description << " | "
             << (task.completed ? "Completed" : "Pending")
             << "\n";
    }

    file.close();
    cout << "Tasks saved to tasks.txt\n";
}