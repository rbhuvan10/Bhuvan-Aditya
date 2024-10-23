#include <stdio.h>
#define MAX 3
int front = -1, rear = -1;
int q[MAX];

int isFull() {
    if((front == rear + 1) || (front == 0 && rear == MAX - 1)) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if(front == -1) {
        return 1;
    }
    return 0;
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty\n");
    }
    else {
        if(front == rear) {
            front = rear = -1;
        }
        else{
            front = (front + 1) % MAX;
        }
    }
}

void enqueue(int num) {
    if(isFull()) {
        printf("Queue is full\n");
    }
    else {
        if(front == -1) {
            front ++;
        }
        rear = (rear + 1) % MAX;
        q[rear] = num;
    }
}

void display() {
    if(isEmpty()) {
        printf("Queue is empty\n");
    }
    else {
        int i;
        for(i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d ", q[i]);
        }
        printf("%d", q[i]);
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
Enter number to insert to queue: 6
6
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 5
6 5
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 9
6 5 9
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
1
Enter number to insert to queue: 5
Queue is full
6 5 9
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
5 9
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
9
Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
Queue is empty

Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
2
Queue is empty
Queue is empty

Enter '1' for enqueue
Enter '2' for dequeue
Enter '-1' to exit
