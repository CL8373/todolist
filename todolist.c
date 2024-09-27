#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"

#define MAX_TASKS 100
#define BUFFER_SIZE 100


char* tasks[MAX_TASKS];
int num = 0;

void add_task() {
    if (num >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("\nWrite your task: ");
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        tasks[num] = malloc(strlen(buffer) + 1);
        if (tasks[num] != NULL) {
            strcpy(tasks[num], buffer);
            num++;
        } else {
            printf("Memory allocation failed!\n");
        }
    } else {
        printf("Failed to get input!\n");
    }
}

void remove_task() {
    if (num > 0) {
        int choice;
        printf("Which task would you like to remove? ");
        scanf("%d", &choice);
        free(tasks[choice - 1]);
        tasks[choice - 1] = NULL;
        for(int i = choice - 1; i < num - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        num--;
    } else {
        printf("No tasks to remove!\n");
    }
}

void see_tasks() {
    if (num == 0) {
        printf("No tasks in the list.\n");
    } else {
        for (int i = 0; i < num; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

void clear_tasks() {
    for (int i = 0; i < num; i++) {
        free(tasks[i]);
        tasks[i] = NULL;
    }
    num = 0;
}

int main() {
    printf("Welcome to your daily list of what you need to do: ");
    int choice = 0;

    while (choice != -1) {
        printf("\nWhat would you like to do now?");
        printf("\n1. Add a task");
        printf("\n2. Remove a task");
        printf("\n3. See task list");
        printf("\n4. Clear the entire list");
        printf("\n-1. Exit\n");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                see_tasks();
                break;
            case 4:
                clear_tasks();
                break;
            case -1:
                clear_tasks();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
