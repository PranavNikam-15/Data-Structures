// Implement Queue using Array

/* 
    Problem: Design a queue using a fixed-size array with the following operations:
    - enqueue(x) → Add an element to the queue.
    - dequeue() → Remove the front element.
    - peek() → Return the front element.
    - isEmpty() and isFull() → Check conditions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int *arr;
    int front, rear, size;
};

bool isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}

bool isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot insert %d\n", data);
        return;
    }

    // first insertion
    if (q->front == -1) q->front = 0;  
    q->arr[++q->rear] = data;
    printf("Inserted %d\n", data);
}

int dequeue(struct Queue *q) {

    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return -1;
    }
    int data = q->arr[q->front++];

    if (q->front > q->rear) { 
        // reset queue when empty
        q->front = q->rear = -1;
    }
    printf("Deleted %d\n", data);
    return data;
}

int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;
    q.size = 10;

    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    display(&q);

    printf("Front element is: %d\n", peek(&q));

    free(q.arr);
    return 0;
}