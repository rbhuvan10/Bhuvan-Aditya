#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create_ll(struct node *start) {
    struct node *newnode, *ptr;
    int num;

    printf("\nEnter -1 to end");
    printf("\nEnter a value: ");
    scanf("%d", &num);

    while (num != -1) {
        if (start == NULL) {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->prev = NULL;
            newnode->data = num;
            newnode->next = NULL;
            start = newnode;
        } else {
            ptr = start;
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = num;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = NULL;
        }

        printf("\nEnter the data: ");
        scanf("%d", &num);
    }

    return start;
}

struct node *insert_before(struct node *start) {
    struct node *ptr, *newnode;
    int num, val;

    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data has to be inserted: ");
    scanf("%d", &val);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    ptr = start;
    while (ptr->data != val) {
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("Value not found in the list.\n");
            return start;
        }
    }

    newnode->next = ptr;
    newnode->prev = ptr->prev;

    if (ptr->prev != NULL) {
        ptr->prev->next = newnode;
    } else {
        start = newnode;
    }

    ptr->prev = newnode;

    return start;
}

struct node *delete_node(struct node *start) {
    struct node *ptr;
    int val;

    printf("\nEnter the value of the node to be deleted: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value not found in the list.\n");
        return start;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        start = ptr->next;
    }

    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    free(ptr);

    printf("Node with value %d deleted.\n", val);

    return start;
}

void display(struct node *start) {
    struct node *ptr = start;

    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The list is: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node *start = NULL;
    int choice;

    do {
        printf("\n1. Create List");
        printf("\n2. Insert Before");
        printf("\n3. Delete Node");
        printf("\n4. Display List");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create_ll(start);
                break;
            case 2:
                start = insert_before(start);
                break;
            case 3:
                start = delete_node(start);
                break;
            case 4:
                display(start);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
Output:
1. Create List
2. Insert Before
3. Delete Node
4. Display List
5. Exit
Enter your choice: 1

Enter -1 to end
Enter a value: 5

Enter the data: 6

Enter the data: 7

Enter the data: 8

Enter the data: 9

Enter the data: -1

1. Create List
2. Insert Before
3. Delete Node
4. Display List
5. Exit
Enter your choice: 4
The list is: 5 6 7 8 9 

1. Create List
2. Insert Before
3. Delete Node
4. Display List
5. Exit
Enter your choice: 2

Enter the data: 4

Enter the value before which the data has to be inserted: 5

1. Create List
2. Insert Before
3. Delete Node
4. Display List
5. Exit
Enter your choice: 4
The list is: 4 5 6 7 8 9 

1. Create List
2. Insert Before
3. Delete Node
4. Display List
5. Exit
Enter your choice: 3

Enter the value of the node to be deleted: 7
Node with value 7 deleted.

1. Create List
2. Insert Before
3. Delete Node
4. Display List
5. Exit
Enter your choice: 4
The list is: 4 5 6 8 9
