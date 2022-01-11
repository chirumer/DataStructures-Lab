/*
To create a doubly linked list with following operations
(1) Create a doubly linked list
(2) Append a new node at the left
(3) Delete nodes based on a value
(4) Display contents of the list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* head = NULL;

void append_left() {

    int value;
    printf("Enter value to append: ");
    scanf("%d", &value);

    struct Node* new_node = (struct Node*) malloc(sizeof(int));
    new_node->left = NULL;
    new_node->data = value;

    if (head == NULL) {
        head = new_node;
        new_node->right = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    temp->left = new_node;
    new_node->right = temp;
}

void display_nodes() {

    if (head == NULL) {
        printf("List Empty.\n");
        return;
    }

    printf("Elements from right to left:");
    struct Node* temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->left;
    }
    printf("\n");
}

void delete_value() {

    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (head != NULL && head->data == value) {
        struct Node* temp = head;
        head = head->left;
        free(temp);
    }
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    while (temp->left != NULL) {
        if (temp->left->data == value) {
            if (temp->left->left == NULL) {
                free(temp->left);
                temp->left = NULL;
            }
            else {
                struct Node* delete_node = temp->left;
                temp->left = delete_node->left;
                delete_node->left->right = temp;
                free(delete_node);
            }
        }
        else {
            temp = temp->left;
        }
    }
}

int main() {

    int choice;
    do {
        printf("--- MENU ---\n"
            "(1) Append a new node to the left\n"
            "(2) Delete nodes with a specific value\n"
            "(3) Display all nodes\n"
            "(4) Exit\n"
            "You Choice --> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                append_left();
                break;
            case 2:
                delete_value();
                break;
            case 3:
                display_nodes();
                break;
            case 4:
                // wishes to exit
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 4);
}
