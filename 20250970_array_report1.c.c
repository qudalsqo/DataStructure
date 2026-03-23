#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double avg, int option);

int main() {
    int scores[30];
    int studentNumber;
    double average;
    int option;

    srand(time(0));

    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101;
    }

    average = calculateAverage(scores, 30);
    printf("학급 평균 점수: %.2f\n", average);

    printf("출력 옵션 선택 (0: 전체, 1: 평균 이상, 2: 평균 미만): ");
    scanf("%d", &option);

    printScore(scores, 30, average, option);

    printf("\n학생 번호를 입력하세요 (1 ~ 30): ");
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    } else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }

    return 0;
}

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    } else {
        return -1;
    }
}

void printScore(int scores[], int size, double avg, int option) {

    printf("\n--- 학생 점수 출력 ---\n");

    for (int i = 0; i < size; i++) {

        if (option == 0) {
            printf("%d번 학생 : %d\n", i + 1, scores[i]);
        }

        else if (option == 1 && scores[i] >= avg) {
            printf("%d번 학생 : %d\n", i + 1, scores[i]);
        }

        else if (option == 2 && scores[i] < avg) {
            printf("%d번 학생 : %d\n", i + 1, scores[i]);
        }

    }
}