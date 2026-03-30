#include <stdio.h>
#include <stdlib.h>

int main() {
    int *students;
    int capacity = 3;   
    int size = 0;       
    int choice;

    students = (int*)malloc(sizeof(int) * capacity);

    while(1) {
        printf("\n1. 학생 추가\n");
        printf("2. 학생 삭제\n");
        printf("3. 학생 목록 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if(choice == 1) {

            if(size == capacity) {
                capacity = capacity * 2;
                students = realloc(students, sizeof(int) * capacity);
                printf("배열 크기 확장: %d\n", capacity);
            }

            printf("학생 점수 입력: ");
            scanf("%d", &students[size]);
            size++;

        }

        else if(choice == 2) {

            int index;
            printf("삭제할 학생 인덱스 입력 (0~%d): ", size-1);
            scanf("%d", &index);

            if(index < 0 || index >= size) {
                printf("잘못된 인덱스\n");
                continue;
            }

            for(int i = index; i < size-1; i++) {
                students[i] = students[i+1];
            }

            size--;
            printf("삭제 완료\n");

        }

        else if(choice == 3) {

            printf("\n학생 점수 목록:\n");

            for(int i = 0; i < size; i++) {
                printf("[%d] %d\n", i, students[i]);
            }

        }

        else if(choice == 4) {
            break;
        }

        else {
            printf("잘못된 선택\n");
        }
    }

    free(students);
    return 0;
}