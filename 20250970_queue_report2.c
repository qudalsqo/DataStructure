#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct {
    char name[50];
    int pages;
} Job;

Job queue[MAX];
int front = 0;
int rear = 0;

// 큐가 비었는지 확인
int isEmpty() {
    return front == rear;
}

// 큐가 찼는지 확인
int isFull() {
    return (rear + 1) % MAX == front;
}

// 1. enqueue (페이지 제한 추가)
void enqueue(char name[], int pages) {
    if (pages > 50) {
        printf("페이지 수 50장 초과 → 출력 거부\n");
        return;
    }

    if (isFull()) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }

    strcpy(queue[rear].name, name);
    queue[rear].pages = pages;
    rear = (rear + 1) % MAX;

    printf("작업 추가됨\n");
}

// 2. cancelJob (특정 문서 삭제)
void cancelJob(char name[]) {
    if (isEmpty()) {
        printf("큐가 비어있습니다.\n");
        return;
    }

    int i = front;
    int found = 0;

    while (i != rear) {
        if (strcmp(queue[i].name, name) == 0) {
            found = 1;

            // 뒤에 있는 작업들을 앞으로 당김
            int j = i;
            while (j != rear) {
                int next = (j + 1) % MAX;
                if (next != rear) {
                    queue[j] = queue[next];
                }
                j = next;
            }

            rear = (rear - 1 + MAX) % MAX;

            printf("작업 취소됨\n");
            break;
        }
        i = (i + 1) % MAX;
    }

    if (!found) {
        printf("해당 문서가 없습니다\n");
    }
}

// 3. clearQueue (전체 초기화)
void clearQueue() {
    front = rear = 0;
    printf("대기열 초기화\n");
}

// 출력 확인용
void printQueue() {
    if (isEmpty()) {
        printf("큐 비어있음\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("문서: %s (%d장)\n", queue[i].name, queue[i].pages);
        i = (i + 1) % MAX;
    }
}

// 메뉴
int main() {
    int choice;
    char name[50];
    int pages;

    while (1) {
        printf("\n1. 작업 추가\n2. 작업 취소\n3. 전체 삭제\n4. 출력\n0. 종료\n선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("문서 이름: ");
                scanf("%s", name);
                printf("페이지 수: ");
                scanf("%d", &pages);
                enqueue(name, pages);
                break;

            case 2:
                printf("취소할 문서 이름: ");
                scanf("%s", name);
                cancelJob(name);
                break;

            case 3:
                clearQueue();
                break;

            case 4:
                printQueue();
                break;

            case 0:
                return 0;
        }
    }
}