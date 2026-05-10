#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;



// 노드 생성 함수
Node* createNode(int data) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}



// 리스트 끝에 노드 추가
void append(Node** head, int data) {

    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}



/* =========================
   실습 1-4 : printList 함수
   ========================= */

// 연결리스트 출력 함수
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}



/* =========================
   실습 1-5 : searchValue1
   ========================= */

// 특정 값의 위치 찾기
int searchValue1(Node* head, int val) {

    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {

        if (temp->data == val) {
            return pos;
        }

        temp = temp->next;
        pos++;
    }

    return -1;
}



/* =========================
   실습 1-5 : searchValue2
   ========================= */

// 특정 값의 앞/뒤 노드 출력
void searchValue2(Node* head, int val) {

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {

        if (curr->data == val) {

            if (prev == NULL)
                printf("앞 노드 없음\n");
            else
                printf("앞 노드 값 : %d\n", prev->data);

            if (curr->next == NULL)
                printf("뒤 노드 없음\n");
            else
                printf("뒤 노드 값 : %d\n", curr->next->data);

            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("값을 찾을 수 없음\n");
}



/* =========================
   실습 1-5 : freeList
   ========================= */

// 연결리스트 메모리 해제
void freeList(Node* head) {

    Node* temp;

    while (head != NULL) {

        temp = head;
        head = head->next;

        free(temp);
    }

    printf("메모리 해제 완료\n");
}



/* =========================
   메인 함수
   ========================= */

int main() {

    Node* head = NULL;

    // 리스트 생성
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    
    // 실습 1-4 테스트
    printList(head);


    // 실습 1-5 테스트
    int val = 30;
    int pos;

    pos = searchValue1(head, val);

    if (pos != -1)
        printf("%d의 위치는 %d번째\n", val, pos);
    else
        printf("값 없음\n");

    searchValue2(head, val);


    // 메모리 해제
    freeList(head);

    return 0;
}