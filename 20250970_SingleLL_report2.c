#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

    char name[30];
    char phone[30];

    struct Node* next;

} Node;



// 새 노드 생성
Node* createNode(char name[], char phone[]) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);

    newNode->next = NULL;

    return newNode;
}



// 연락처 추가
void addContact(Node** head, char name[], char phone[]) {

    Node* newNode = createNode(name, phone);

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



// 연락처 검색
void searchContact(Node* head, char name[]) {

    Node* temp = head;

    while (temp != NULL) {

        if (strcmp(temp->name, name) == 0) {

            printf("이름 : %s\n", temp->name);
            printf("전화번호 : %s\n", temp->phone);

            return;
        }

        temp = temp->next;
    }

    printf("연락처를 찾을 수 없음\n");
}



// 연락처 삭제
void deleteContact(Node** head, char name[]) {

    Node* temp = *head;
    Node* prev = NULL;

    // 첫 노드 삭제
    if (temp != NULL && strcmp(temp->name, name) == 0) {

        *head = temp->next;
        free(temp);

        printf("%s 삭제 완료\n", name);

        return;
    }

    // 중간 또는 마지막 노드 삭제
    while (temp != NULL && strcmp(temp->name, name) != 0) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("삭제할 연락처 없음\n");

        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("%s 삭제 완료\n", name);
}



// 전체 연락처 출력
void printContacts(Node* head) {

    Node* temp = head;

    printf("\n===== 전화번호부 =====\n");

    while (temp != NULL) {

        printf("이름 : %s\n", temp->name);
        printf("전화번호 : %s\n", temp->phone);
        printf("------------------\n");

        temp = temp->next;
    }
}



// 메모리 해제
void freeList(Node* head) {

    Node* temp;

    while (head != NULL) {

        temp = head;
        head = head->next;

        free(temp);
    }

    printf("메모리 해제 완료\n");
}



int main() {

    Node* head = NULL;

    
    // 1. 연락처 추가
    addContact(&head, "Kim", "010-1111-1111");
    addContact(&head, "Lee", "010-2222-2222");
    addContact(&head, "Park", "010-3333-3333");


    // 2. 연락처 검색
    printf("\n[연락처 검색]\n");
    searchContact(head, "Lee");


    // 3. 연락처 삭제
    printf("\n[연락처 삭제]\n");
    deleteContact(&head, "Lee");


    // 4. 현재 전화번호부 출력
    printContacts(head);


    // 메모리 해제
    freeList(head);

    return 0;
}