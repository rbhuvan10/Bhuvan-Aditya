#include <stdio.h>

#define MAX 5
int arr[MAX];
int top = -1;

void push(int num) {
    if(top == MAX - 1) {
        printf("Stack overflow.\n");
    }
    else {
        top++;
        arr[top] = num;
        printf("Pushed %d to the stack.\n", num);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack underflow.\n");
    }
    else {
        printf("Popped %d from the stack.\n", arr[top]);
        top--;
    }
}

void display() {
    if(top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack elements: ");
        for(int i = top; i > -1; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int num;
    while(1) {
        printf("Enter '1' for push function.\nEnter '2' for pop function.\nEnter '3' for display function.\nEnter '0' to exit the function.\n");
        scanf("%d", &n);
        if(n == 1) {
            printf("Enter element to push: ");
            scanf("%d", &num);
            push(num);
        }
        if(n == 2) {
            pop();
        }
        if(n == 3) {
            display();
        }
        if(n <= 0 || n >= 4) {
            break;
        }
    }
    return 0;
}
