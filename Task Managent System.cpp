#include <iostream>
#include <vector>

struct Task {
    std::string name;
    std::string priority;
    std::string dueDate;
    bool hasNotification;
};

std::vector<Task> taskList;

void createTask() {
    Task newTask;
    std::cout << "Enter task name: ";
    std::cin >> newTask.name;
    std::cout << "Enter task priority (High, Medium, Low): ";
    std::cin >> newTask.priority;
    std::cout << "Enter task due date: ";
    std::cin >> newTask.dueDate;
    std::cout << "Does this task have notification (1 for Yes, 0 for No): ";
    std::cin >> newTask.hasNotification;
    
    taskList.push_back(newTask);
    std::cout << "Task created successfully!\n";
}

void updateTask() {
    std::string taskName;
    std::cout << "Enter the name of the task to update: ";
    std::cin >> taskName;
    
    for (int i = 0; i < taskList.size(); i++) {
        if (taskList[i].name == taskName) {
            Task updatedTask;
            std::cout << "Enter updated priority (High, Medium, Low): ";
            std::cin >> updatedTask.priority;
            std::cout << "Enter updated due date: ";
            std::cin >> updatedTask.dueDate;
            std::cout << "Does this task have notification (1 for Yes, 0 for No): ";
            std::cin >> updatedTask.hasNotification;
            
            taskList[i] = updatedTask;
            std::cout << "Task updated successfully!\n";
            return;
        }
    }
    
    std::cout << "Task not found!\n";
}

void deleteTask() {
    std::string taskName;
    std::cout << "Enter the name of the task to delete: ";
    std::cin >> taskName;
    
    for (int i = 0; i < taskList.size(); i++) {
        if (taskList[i].name == taskName) {
            taskList.erase(taskList.begin() + i);
            std::cout << "Task deleted successfully!\n";
            return;
        }
    }
    
    std::cout << "Task not found!\n";
}

void printTaskList() {
    std::cout << "Task List:\n";
    
    for (int i = 0; i < taskList.size(); i++) {
        std::cout << "Task Name: " << taskList[i].name << std::endl;
        std::cout << "Priority: " << taskList[i].priority << std::endl;
        std::cout << "Due Date: " << taskList[i].dueDate << std::endl;
        std::cout << "Notification: " << (taskList[i].hasNotification ? "Yes" : "No") << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    int choice;
    
    do {
        std::cout << "Task Management System\n";
        std::cout << "1. Create Task\n";
        std::cout << "2. Update Task\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Print Task List\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                createTask();
                break;
            case 2:
                updateTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printTaskList();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
        
        std::cout << std::endl;
    } while (choice != 0);
    
    return 0;
}
