#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 256

typedef enum {
    TASK_SUCCESS,
    TASK_MEMORY_ERROR,
    TASK_TITLE_TOO_LONG,
    TASK_DESCRIPTION_TOO_LONG
} TASK_ERROR;

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
    char description[MAX_DESCRIPTION_LENGTH];
    PRIORITY priority;
    STATUS completed;
} Task;

/// @brief Allocates memory for a task and returns a pointer to it.
/// Default priority is MEDIUM and status is INCOMPLETE.
/// @param title pointer to a string
/// @return Pointer to a Task struct
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
    task->description[0] = '\0';
}

/// @brief Frees task memory
/// @param task pointer to a Task struct
inline void free_task_memory(Task* task) {
    free(task);
}

TASK_ERROR set_description(Task* task, char* description) {
    // Check if description is too long.
    if (strlen(description) > MAX_DESCRIPTION_LENGTH) {
        fprintf(stderr, "Description is too long!\n");
        return TASK_DESCRIPTION_TOO_LONG;
    }

    // Populate task description.
    strcpy(task->description, description);

    return TASK_SUCCESS;
}