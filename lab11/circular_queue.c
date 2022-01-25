// implementation of a queue using a circular list

#include <stdio.h>
#include <stdbool.h>

// queue properties
#define SIZE 10
int elements[SIZE];
int beginning = -1;
int end = -1;

bool is_full() {
    return (end+1) % SIZE == beginning;
}

bool is_empty() {
    return beginning == -1;
}

void enqueue() {

    if (is_full()) {
        printf("Attempt to Push to Full Queue.\n");
        return;
    }

    int new_ele;
    printf("Enter Element: ");
    scanf("%d", &new_ele);

    if (beginning == -1) {
        beginning = 0;
    }
    elements[end = (end+1) % SIZE] = new_ele;
    printf("Added Element: %d.\n", new_ele);
}

void dequeue() {
    if (is_empty()) {
        printf("Attempt to Delete Empty Queue.\n");
        return;
    }
    printf("Deleted Element: %d.\n", elements[beginning]);
    beginning = (beginning+1) % SIZE;
}

void display_queue() {
    if (is_empty()) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue Elements:");
    for (int i = beginning; i <= end; i += (i+1) % SIZE) {
        printf(" %d", elements[i]);
    }
    printf("\n");
}

int main() {

    int choice;
    do {
        printf("\n"
               "1 > Enqueue\n"
               "2 > Dequeue\n"
               "3 > Display\n"
               "4 > Exit\n"
               "Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice.\n");
        }
    } while (choice != 4);

    return 0;
}
