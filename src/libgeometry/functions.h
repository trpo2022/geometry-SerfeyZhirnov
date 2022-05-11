#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

typedef struct {
    double x;
    double y;
    double r;
} circle;

int check_line();
int isCorrect(char*);
circle getcircle(char*);
void writePandS(circle);
void PrintIntersect(circle *, int);

#endif //  _FUNCTIONS_H_