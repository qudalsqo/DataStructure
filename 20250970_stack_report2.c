#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101];
    char *stack;
    int top = -1;
    int valid = 1;

    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    stack = (char*)malloc(len * sizeof(char));

    for(int i = 0; i < len; i++) {
        char c = input[i];

        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else if(c == ')' || c == '}' || c == ']') {
            if(top == -1) {
                valid = 0;
                break;
            }

            char pop = stack[top--];

            if((c == ')' && pop != '(') ||
               (c == '}' && pop != '{') ||
               (c == ']' && pop != '[')) {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1) valid = 0;

    if(valid)
        printf("유효한 괄호\n");
    else
        printf("유효하지 않은 괄호\n");

    free(stack);

    return 0;
}