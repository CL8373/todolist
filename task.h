#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100

/// @brief Priority levels for tasks.
typedef enum {
    LOW,
    MEDIUM,
    HIGH
} PRIORITY;

/// @brief Status of a task.
typedef enum {
    INCOMPLETE,
    COMPLETE
} STATUS;

/// @brief Represents a task.
typedef struct {
    char title[MAX_TITLE_LENGTH];
    PRIORITY priority;
    STATUS completed;
} Task;

/// @brief Allocates memory for a task and returns a pointer to it.
/// Default priority is MEDIUM and status is INCOMPLETE.
/// @param char* title
/// @return *Task - pointer to a Task struct
Task* create_task(char* title) {
    // Allocate memory for task.
    Task* task = (Task*)malloc(sizeof(Task));

    // Check if null pointer.
    if (task == NULL) {
        fprintf(stderr, "Could not allocate memory for task!\n");
        return NULL;
    }
    
    // Check if title is too long.
    if (strlen(title) > MAX_TITLE_LENGTH) {
        fprintf(stderr, "Title is too long!\n");
        return NULL;
    }

    // Populate task. Default priority is MEDIUM and status is INCOMPLETE.
    strcpy(task->title, title);
    task->priority = MEDIUM;
    task->completed = INCOMPLETE;
}