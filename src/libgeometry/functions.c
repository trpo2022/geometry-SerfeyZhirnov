#include "functions.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_line()
{
    FILE* file = fopen("input.txt", "r");
    int lines = 0;

    while (!feof(file))
        if (fgetc(file) == '\n')
            lines++;

    fclose(file);
    return lines;
}

int isCorrect(char* str)
{
    int check = 1;

    int open = 0, close = 0;
    int open_brackets, close_braket; // position
    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] == '(') {
            open++;
            open_brackets = i + 1;
        }
        if (str[i] == ')') {
            close++;
            close_braket = i - 1;
        }
    }
    if (open != close) {
        check = 0;
        int position = strlen(str);
        printf("%s\n", str);
        for (int i = 0; i < (position - 1); i++)
            printf(" ");
        printf("^\nError at column %ld: expected ')'\n", strlen(str));
        return check;
    }

    int k = 0;
    for (int i = open_brackets; i <= close_braket; i++)
        if (isalpha(str[i])) {
            k = i;
            break;
        }
    if (k != 0) {
        check = 0;
        printf("%s\n", str);
        for (int i = 0; i < k; i++)
            printf(" ");
        printf("^\nError at column %d: expected '<double>'\n", k);
        return check;
    }

    int j = 0, i = 0;
    char object[10];
    while (str[i] != '(') {
        if (str[i] != ' ') {
            object[j] = tolower(str[i]);
            j++;
        }
        i++;
    }

    if (strstr(object, "circle") == NULL) {
        check = 0;
        printf("%s\n^\nError at column 0: expected 'circle'\n", str);
        return check;
    }

    if ((int)strlen(str) > close_braket + 2) {
        check = 0;
        printf("%s\n", str);
        for (int i = 0; i <= (close_braket + 2); i++)
            printf(" ");
        printf("^\nError at column %d: unexpected token\n", close_braket + 3);
    }

    return check;
}

circle gettriangle(char* str)
{
    circle buf = {0, 0, 0};
    char* open_bracket = strchr(str, '(');
    // char *close_braket = strchr(str, ')') + 1;
    char* cur = open_bracket + 1;
    char digit[3][128];
    int index = 0;
    while (isdigit(*cur) || *cur == '.')
        digit[0][index++] = *cur++;
    buf.x = atof(digit[0]);
    while (!isdigit(*cur))
        cur++;
    index = 0;
    while (isdigit(*cur) || *cur == '.')
        digit[1][index++] = *cur++;
    buf.y = atof(digit[1]);
    while (!isdigit(*cur))
        cur++;
    index = 0;
    while (isdigit(*cur) || *cur == '.')
        digit[2][index++] = *cur++;
    buf.r = atof(digit[2]);
    return buf;
}

void writePandS(circle tr1)
{
    printf("Circle:\n");
    printf("P: %f\n", 2 * M_PI * tr1.r);
    printf("S: %f\n", M_PI * tr1.r * tr1.r);
}