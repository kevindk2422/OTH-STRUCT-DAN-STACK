#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue){
    return queue->front == -1 && queue->rear == -1;
}

bool isFull(Queue *queue){
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int newValue){
    if(!isFull(queue)){
        if(isEmpty(queue)){
            queue->front++;
            queue->data[++queue->rear] = newValue;
            return;
        }
        queue->data[++queue->rear] = newValue;
        return;
    }
    printf("Queue penuh!\n");
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

void handlePatients(Queue *queue) {
    if(!isEmpty(queue)){
        for(int i = queue->front; i <= queue->rear; i++){
            int patient = dequeue(queue);
            if (patient <= 5) {
                printf("Ditangani dokter umum\n");
            } else {
                printf("Ditangani dokter spesialis\n");
            }
        }
        return;
    }
    printf("Queue kosong!\n");
}

int main() {
    Queue q;
    init(&q);

    int input;
    printf("Masukkan 10 tingkat urgensi: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &input);
        enqueue(&q, input);
    }

    handlePatients(&q);

    return 0;
}