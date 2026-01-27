//-------------------------------------- 
// Included Libraries
//--------------------------------------
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//-------------------------------------- 
// Class Definition
//--------------------------------------
class Task {
public:
    string description;         // Decription for the tast
    bool completed;             // Where task is completed

    // initializes task with a description
    Task(string desc) {
        description = desc;
        completed = false;      // Tasks all start as incomplete
    }

    void markComplete() {
        completed = true;
    }
};

//-------------------------------------- 
// Function Prototypes
//--------------------------------------
void showMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void completeTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveToFile(const vector<Task>& tasks);

//-------------------------------------- 
// Main
//--------------------------------------
int main() {
    vector<Task> tasks; // Stores tasks
    int choice = 0;

    // Loops menu until 6 (Exit) is chosen
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

//-------------------------------------- 
// Displays MAIN MENU
//--------------------------------------
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

//-------------------------------------- 
// Adds A Task To The List
//--------------------------------------
void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";

    cin.ignore();                   // Clear leftover newline
    getline(cin, desc);             // Reads line

    tasks.push_back(Task(desc));    // Add new task
    cout << "Task added.\n";
}

//-------------------------------------- 
// Displays Task Status 
//--------------------------------------
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    // Loops through and prints each task
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].description
             << "["
             << (tasks[i].completed ? "Completed" : "Pending")
             << "]\n";
    }
}

//-------------------------------------- 
// Marks A Specific Task As Complete 
//--------------------------------------
void completeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);   // Shows task 

    if (tasks.empty()) return;

    cout << "Enter task number to complete: \n";
    cin >> index;

    // Validate input
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markComplete();
    cout << "Task marked complete.\n";
}

//-------------------------------------- 
// Deletes A Task From The List 
//--------------------------------------
void deleteTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);

    if (tasks.empty()) return;

    cout << "Enter task number to delete: \n";
    cin >> index;

    // Validate input
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));   // Deletes a chosen task
    cout << "Task deleted.\n";
}

//-------------------------------------- 
// Saves All Tasks To A Text File 
//--------------------------------------
void saveToFile(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    // Write tasks to tasks.txt file
    for (const auto& task : tasks) {
        file << task.description << " | "
             << (task.completed ? "Completed" : "Pending")
             << "\n";
    }

    file.close();
    cout << "Tasks saved to tasks.txt\n";
}