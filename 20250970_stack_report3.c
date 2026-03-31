#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

void initCharStack(CharStack *s) {
    s->top = -1;
}

int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

void pushChar(CharStack *s, char value) {
    s->data[++(s->top)] = value;
}

char popChar(CharStack *s) {
    return s->data[(s->top)--];
}

char peekChar(CharStack *s) {
    return s->data[s->top];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&s, num);
        }
        else if (ch == ' ') {
            continue;
        }
        else {
            int b = pop(&s);
            int a = pop(&s);
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&s, result);
        }
    }

    return pop(&s);
}

int infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);

    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            popChar(&s);
        }
        else {
            while (!isEmptyChar(&s) && priority(peekChar(&s)) >= priority(ch)) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            pushChar(&s, ch);
        }
    }

    while (!isEmptyChar(&s)) {
        postfix[j++] = popChar(&s);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';

    return evaluatePostfix(postfix);
}

int main(void) {
    char infix[MAX];
    char postfix[MAX];
    int result;

    printf("중위표기식 입력 : ");
    scanf("%s", infix);

    result = infixToPostfix(infix, postfix);

    printf("후위표기식 : %s\n", postfix);
    printf("후위표기식 계산 결과 : %d\n", result);

    return 0;
}