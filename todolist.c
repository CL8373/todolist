#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* tasks[100];
int num = 0;
int main() {
    printf("Welcome to your daily list of what you need to do: ");
    int choice = 0;
    int MAX_TASKS = 100;
    while(choice != -1){
        printf("\nwhat would you like to do now?");
        printf("\n1. Add a task");
        printf("\n2. Remove a task");
        printf("\n3. See task list");
        printf("\n4. Clear the entire list\n");
        scanf("%d", &choice);
        while (getchar() != '\n');
        if (choice == 1) {
            printf("\nWrite your task: ");
            char buffer[100];
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                buffer[strcspn(buffer, "\n")] = 0;
                if (num < MAX_TASKS) {
                    tasks[num] = malloc(strlen(buffer) + 1);
                    if (tasks[num] != NULL) {
                        strcpy(tasks[num], buffer);
                        num++;
                    } else {
                        printf("Memory allocation failed!\n");
                    }
                } else {
                    printf("Task list is full!\n");
                }
            }
        }
        if(choice == 2){
            tasks[num] = "";
            num--;
        }
        if(choice == 3){
            for(int i = 0; i < num; i++){
                printf("%s", tasks[i]);
                printf("\n");
            }
        }
        if(choice == 4){
            for(int i = 0; i < num; i++){
                tasks[i] = "";
            }
            num = 0;
        }
        
    }
}


