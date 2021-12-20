#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_beginning() {
    int item;
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = head;
    head = new_node;
}

void del_begin() {
    if (head == NULL) {
        printf("attempt to delete empty list\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void del_end() {
    if (head == NULL) {
        printf("attempt to delete empty list\n");
        return;
    }
    if (head->next == NULL) {
        head = NULL;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void del_pos() {
    printf("enter deletion position: ");
    int pos;
    scanf("%d", &pos);
    
    if (head == NULL) {
        printf("attempt to delete empty list\n");
        return;
    }
    if (pos == 1) {
        del_begin();
        return;
    }
    
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    struct Node* del_node = temp->next;
    temp->next = del_node->next;
    free(del_node);
}

void display() {
    struct Node* temp = head;
    printf("List elements:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    int choice;
    do {
        printf("(1) display\n(2) insert\n(3) delete beginning\n(4) delete ending\n(5) delete at position\n"
               "(6) stop\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                insert_beginning();
                break;
            case 3:
                del_begin();
                break;
            case 4:
                del_end();
                break;
            case 5:
                del_pos();
                break;
        }
    } while (choice != 6);

    return 0;
}
