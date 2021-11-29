#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000
int queue[MAX_SIZE];
int size = 5;
int front = -1;
int back = -1;

bool is_full() {
    return front == (back + 1) % size && front != -1;
}

bool is_empty() {
    return front == -1;
}

void insert(int item) {
    if (is_full()) {
        printf("overflow\n");
        return;
    }
    if (front == -1) {
        front = back = 0;
    }
    else {
        back = (back + 1) % size;
    }
    queue[back] = item;
    
    printf("inserted successfully\n");
}

void delete() {
    if (is_empty()) {
        printf("underflow\n");
        return;
    }
    printf("popped item: %d\n", queue[front]);
    if (front == back) {
        front = back = -1;
    }
    else {
        front = (front + 1) % size;
    }
}

void display() {
    if (is_empty()) {
        printf("queue is empty\n");
        return;
    }
    printf("queue elements:");
    for (int i = front; i != back; i = (i + 1) % size) {
        printf(" %d", queue[i]);
    }
    printf(" %d", queue[back]);
    printf("\n");
}

int main() {
    
    int choice = -1;
    while (choice != 4) {
        printf("(1) for insertion\n"
               "(2) for deletion\n"
               "(3) for displaying\n"
               "(4) for exiting\n"
               "--> ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                int item;
                printf("Enter item: ");
                scanf("%d", &item);
                insert(item);
                break;
            }
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
        }
    }
    
    return 0;
}
