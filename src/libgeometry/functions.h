#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

typedef struct {
    double x;
    double y;
    double r;
} triangle;

int check_line();
int isCorrect(char* str);
triangle gettriangle(char* str);
void writePandS(triangle tr1);

#endif //  _FUNCTIONS_H_