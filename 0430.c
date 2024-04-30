#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char* message) {
    fprintf(stderr, "%s", message);
    return -1;
}

int is_full(QueueType* q) {
    return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        error("Queue is full\n");
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        error("Queue is empty\n");
    }
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return (q->data[q->front]);
    }
}

void print_queue(QueueType* q) {
    int i;
    for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("[%2d] %2d, ", i, q->data[i]);
    }
    printf("[%2d] %2d\n", i, q->data[i]);
}

int main() {
    QueueType queue;
    init_queue(&queue);

    while (1) {
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하시오 : \n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        {
            printf("큐에 삽입할 숫자를 입력하세요 : ");
            element item;
            scanf("%d", &item);
            enqueue(&queue, item);
            printf("원소 %d가 큐에 삽입되었습니다.\n", item);
            break;
        }
        case 2:
        {
            element removed_item = dequeue(&queue);
            printf("큐에서 삭제된 원소 : %d\n", removed_item);
            break;
        }
        case 3:
            printf("현재 큐의 상태 : ");
            print_queue(&queue);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다\n");
        }
    }
    return 0;
}