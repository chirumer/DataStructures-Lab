// headers
#include <stdio.h>
#include <stdbool.h>

// constants
#define MAX 50

// queue parameters
int queue_array[MAX];
int front = -1;
int rear = -1;

void queue_insert(int item, bool* is_overflow) {
    *is_overflow = false;
    if (rear == MAX - 1) {
        *is_overflow = true;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    ++rear;
    queue_array[rear] = item;
}

int queue_delete(bool* is_underflow) {
    *is_underflow = false;
    if (front == -1) {
        *is_underflow = true;
        return -1;
    }
    int item = queue_array[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
    ++front;
    }
    return item;
}

void queue_display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:");
    for (int i = front; i <= rear; ++i) {
        printf(" %d", queue_array[i]);
    }
    printf("\n");
}

int main()
{
    
    bool is_running = true;
    while (is_running) {
        int choice;
        printf("(1) for insertion\n(2) for delection\n(3) for display\nChoose--> ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                int item;
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                bool is_overflow;
                queue_insert(item, &is_overflow);
                if (is_overflow) {
                    printf("OVERFLOW\n");
                }
                else {
                    printf("Item inserted.\n");
                }
                break;
            }
            case 2: {
                bool is_underflow;
                int item = queue_delete(&is_underflow);
                if (is_underflow) {
                    printf("UNDERFLOW\n");
                }
                else {
                    printf("Deleted item: %d\n", item);
                }
                break;
            }
            case 3:
                queue_display();
                break;
            default:
                is_running = false;
        }
    }
    
    printf("Program Terminated\n");
    return 0;
}
