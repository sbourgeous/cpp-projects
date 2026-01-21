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



//-------- Function Definitions--------

void showMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Add Task\n";
    cout << "2. View tasks\n";
    cout << "3. Mark Task Complete\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}