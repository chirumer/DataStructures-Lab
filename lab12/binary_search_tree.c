#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    struct Node* right;
    int value;
};

struct Node* insert(int value, struct Node* root) {
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    
    if (root == NULL) {
        return new_node;
    }
    else if (value < root->value) {
        root->left = insert(value, root->left);
    }
    else {
        root->right = insert(value, root->right);
    }
    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf(" %d", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf(" %d", root->value);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->value);
}

int main() {
    
    struct Node* root = NULL;
    
    int choice;
    do {
        printf("1) insert element\n"
               "2) display preorder\n"
               "3) display inorder\n"
               "4) display postorder\n"
               "5) exit\n"
               "--> ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                
                root = insert(value, root);
                break;
            }
            case 2:
                printf("preorder:");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("inorder:");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("postorder:");
                postorder(root);
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    
    return 0;
}
