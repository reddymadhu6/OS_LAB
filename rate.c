#include <stdio.h>

// Maximum number of tasks
#define MAX_TASKS 10

typedef struct {
    int period;       // Task period
    int execution;    // Task execution time
} Task;

int main() {
    Task tasks[MAX_TASKS];  // Array to store tasks
    int numTasks;           // Number of tasks
    int time = 0;           // Current time

    // Prompt the user to input the number of tasks
    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &numTasks);

    // Prompt the user to input task details
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d\n", i+1);
        printf("Enter period: ");
        scanf("%d", &tasks[i].period);
        printf("Enter execution time: ");
        scanf("%d", &tasks[i].execution);
    }

    // Run the scheduler for a total of 100 time units
    while (time < 100) {
        int min_priority = MAX_TASKS;  // Maximum priority value + 1
        int min_index = -1;            // Index of the task with the highest priority

        // Find the task with the highest priority among the ready tasks
        for (int i = 0; i < numTasks; i++) {
            if (time % tasks[i].period == 0 && tasks[i].execution > 0 && tasks[i].period < min_priority) {
                min_priority = tasks[i].period;
                min_index = i;
            }
        }

        // Execute the selected task
        if (min_index != -1) {
            printf("Time: %d, Executing Task %d\n", time, min_index + 1);
            tasks[min_index].execution--;

            // Check if the task is completed
            if (tasks[min_index].execution == 0) {
                tasks[min_index].execution = tasks[min_index].period;  // Reset execution time
            }
        } else {
            printf("Time: %d, Idle\n", time);
        }

        time++;
    }

    return 0;
}
