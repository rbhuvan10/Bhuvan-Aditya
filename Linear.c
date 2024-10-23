#include <stdio.h>
#define MAX 3
int front = -1, rear = -1;
int q[MAX];

int isFull() {
    if(rear == MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if(front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void enqueue(int num) {
    if(isFull()) {
        printf("Queue is full");
    }
    else {
        if(front == -1) {
            front++;
        }
        rear++;
        q[rear] = num;
    }
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty");
    }
    else {
        front++;
    }
    if(front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    if(isEmpty()) {
        printf("Queue is empty");
    }
    for(int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
}

int main() {
    int num = 0;
    int value;
    while(num != -1) {
        printf("Enter '1' for enqueue\nEnter '2' for dequeue\nEnter '-1' to exit\n");
        scanf("%d", &num);
        switch(num){
            case 1:
                printf("Enter number to insert to queue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                printf("\n");
                break;
            case 2:
                dequeue();
                display();
                printf("\n");
                break;
            case -1:
                break;
        }
    }
}

Output:
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 8
8 
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 6
8 6 
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 5
8 6 5 
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 5
Queue is full8 6 5 
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
6 5 
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
5
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
Queue is empty0 
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
-1
