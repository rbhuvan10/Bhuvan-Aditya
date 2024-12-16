#include <stdio.h>
#include <malloc.h>

typedef struct BST {
    int data;
    struct BST *left;
    struct BST *right;
} node;

node *create() {
    node *temp;
    printf("Enter data: ");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node *root, node *temp) {
    if (temp->data < root->data) {
        if (root->left != NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    } else if (temp->data > root->data) {
        if (root->right != NULL)
            insert(root->right, temp);
        else
            root->right = temp;
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    char ch;
    node *root = NULL, *temp;

    printf("Do you want to enter data? ");
    printf("\Y/N:");
    scanf("%c", &ch);  // Initial check to start the loop

    while (ch == 'y' || ch == 'Y') {
        temp = create();
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);

        printf("\nEnter more data?\nY/N:");
        getchar(); // To consume the newline character left by scanf
        scanf("%c", &ch);  // Read the user's input
    }

    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}

OUPUT:
Do you want to enter data? Y/N:y
Enter data: 5

Enter more data?
Y/N:y
Enter data: 3

Enter more data?
Y/N:y
Enter data: 7

Enter more data?
Y/N:y
Enter data: 2

Enter more data?
Y/N:y
Enter data: 4

Enter more data?
Y/N:n

Preorder Traversal: 5 3 2 4 7
Inorder Traversal: 2 3 4 5 7
Postorder Traversal: 2 4 3 7 5
Process returned 0 (0x0)   execution time : 25.126 s
Press any key to continue.
