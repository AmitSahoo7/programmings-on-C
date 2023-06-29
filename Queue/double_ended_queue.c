#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
    printf("Element %d inserted at the front.\n\n", data);
}

void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("Element %d inserted at the rear.\n\n", data);
}

void deleteFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Underflow: Deque is empty.\n");
    } else {
        struct Node* temp = deque->front;
        deque->front = deque->front->next;
        if (deque->front == NULL) {
            deque->rear = NULL;
        }
        printf("Element %d deleted from the front.\n\n", temp->data);
        free(temp);
    }
}

void deleteRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Underflow: Deque is empty.\n");
    } else {
        struct Node* temp = deque->rear;
        struct Node* current = deque->front;
        while (current->next != deque->rear) {
            current = current->next;
        }
        deque->rear = current;
        deque->rear->next = NULL;
        printf("Element %d deleted from the rear.\n\n", temp->data);
        free(temp);
    }
}

void display(struct Deque* deque) {
    struct Node* current = deque->front;
    if (current == NULL) {
        printf("Deque is empty.\n");
    } else {
        printf("Elements of the deque are: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n\n");
    }
}

int main() {
    struct Deque* deque = createDeque();
    insertFront(deque, 5);
    insertFront(deque, 10);
    insertRear(deque, 15);
    insertFront(deque, 25);
    insertFront(deque, 18);
    insertRear(deque, 27);
    display(deque);
    deleteFront(deque);
    deleteFront(deque);
    deleteRear(deque);
    display(deque);
    return 0;
}
