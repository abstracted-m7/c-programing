
// add tasks and show the task and then quit.

#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_LENGTH 50

int main() {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int numTasks = 0;
    
    printf("Welcome to the To-Do List!\n");
    
    while (1) {
        printf("1. Add task\n");
        printf("2. View tasks\n");
        printf("3. Quit\n");
        printf("Select an option: ");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (numTasks < MAX_TASKS) {
                    printf("Enter task: ");
                    scanf(" %[^\n]", tasks[numTasks]);
                    numTasks++;
                    printf("Task added!\n");
                } else {
                    printf("Task list is full!\n");
                }
                break;
            case 2:
                printf("Tasks:\n");
                for (int i = 0; i < numTasks; i++) {
                    printf("%d. %s\n", i + 1, tasks[i]);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    
    return 0;
}
