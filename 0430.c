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
        printf("1. ť�� ���Ҹ� ����\n");
        printf("2. ť���� ���Ҹ� ����\n");
        printf("3. ť�� ���Ҹ� ���\n");
        printf("4. ����\n");
        printf("�޴��� �����Ͻÿ� : \n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        {
            printf("ť�� ������ ���ڸ� �Է��ϼ��� : ");
            element item;
            scanf("%d", &item);
            enqueue(&queue, item);
            printf("���� %d�� ť�� ���ԵǾ����ϴ�.\n", item);
            break;
        }
        case 2:
        {
            element removed_item = dequeue(&queue);
            printf("ť���� ������ ���� : %d\n", removed_item);
            break;
        }
        case 3:
            printf("���� ť�� ���� : ");
            print_queue(&queue);
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�\n");
        }
    }
    return 0;
}