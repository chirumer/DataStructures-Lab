#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

int get_data() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    return data;
}

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data;
    return new_node;
}

void display() {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    printf("List Elements:");
    struct Node* temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_begin() {
    struct Node* new_node = create_node(get_data());
    if (head == NULL) {
        head = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void insert_end() {
    struct Node* new_node = create_node(get_data());
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node* last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    new_node->prev = last_node;
}

void insert_loc() {
    int loc;
    printf("Enter Insertion Location: ");
    scanf("%d", &loc);

    if (loc == 1) {
        insert_begin();
        return;
    }
    else if (loc < 1) {
        printf("Invalid Insertion Location.\n");
        return;
    }

    struct Node* temp = head;
    if (temp == NULL) {
        printf("Invalid Insertion Location.\n");
        return;
    }
    for (int i = 1; i < loc - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid Insertion Location.\n");
            return;
        }
    }
    struct Node* new_node = create_node(get_data());
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void del_begin() {
    if (head == NULL) {
        printf("Underflow.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void del_end() {
    if (head == NULL) {
        printf("Underflow.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free (temp->next);
    temp->next = NULL;
}

void del_val() {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    int del_val;
    printf("Enter Value to Delete: ");
    scanf("%d", &del_val);

    if (head->data == del_val) {
        struct Node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != del_val) {
        temp = temp->next;
    }

    if (temp != NULL ) {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void search() {
    int search_item;
    printf("Enter Search Item: ");
    scanf("%d", &search_item);

    struct Node* temp = head;
    int found_pos = 1;

    while (temp != NULL) {
        if (temp->data == search_item) {
            printf("Found at %d.\n", found_pos);
        }
        temp = temp->next;
        found_pos++;
    }
    printf("Element not found.\n");
}

int main() {
    
    int choice;
    do {
        printf("(1) Insert at Beginning.\n"
               "(2) Insert at End.\n"
               "(3) Insert at Location.\n"
               "(4) Display.\n"
               "(5) Delete at Beginning.\n"
               "(6) Delete at End.\n"
               "(7) Delete on Value.\n"
               "(8) Search for Value.\n"
               "--> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_loc();
                break;
            case 4:
                display();
                break;
            case 5:
                del_begin();
                break;
            case 6:
                del_end();
                break;
            case 7:
                del_val();
                break;
            case 8:
                search();
                break;
        }
    } while (choice != 10);

    return 0;
}
