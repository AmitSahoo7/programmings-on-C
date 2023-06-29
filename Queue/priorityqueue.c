#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->front = NULL;
    return queue;
}

void enqueue(struct PriorityQueue* queue, int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    if (queue->front == NULL || priority < queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        struct Node* current = queue->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Element %d with priority %d inserted.\n", data, priority);
}

void dequeue(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("Underflow: Priority queue is empty.\n");
    } else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        printf("Element %d with priority %d deleted.\n", temp->data, temp->priority);
        free(temp);
    }
}

void display(struct PriorityQueue* queue) {
    struct Node* current = queue->front;
    if (current == NULL) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Elements of the priority queue are: ");
        while (current != NULL) {
            printf("(%d, %d) ", current->data, current->priority);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct PriorityQueue* queue = createPriorityQueue();
    enqueue(queue, 10, 2);
    enqueue(queue, 20, 1);
    enqueue(queue, 15, 3);
    enqueue(queue, 5, 5);
    enqueue(queue, 25, 4);
    dequeue(queue);
    display(queue);
    return 0;
}
