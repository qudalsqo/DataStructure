#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    wchar_t input[101];
    wchar_t *stack;
    int top = -1;
    int length = 0;

    wprintf(L"문자열을 입력하세요: ");
    fgetws(input, 101, stdin);

    while (input[length] != L'\0' && input[length] != L'\n')
        length++;

    stack = (wchar_t*)malloc(sizeof(wchar_t) * length);

    for (int i = 0; i < length; i++)
        stack[++top] = input[i];

    wprintf(L"거꾸로 출력된 문자열: ");
    while (top >= 0)
        wprintf(L"%lc", stack[top--]);

    wprintf(L"\n");

    free(stack);

    return 0;
}