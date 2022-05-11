#include <libgeometry/functions.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    int lines = check_line();

    circle circles[lines];
    int circles_count;
    FILE* file = fopen("input.txt", "r");
    for (int line = 0; line < lines; line++) {
        fgets(str, 100, file);
        str[strlen(str) - 1] = '\0';

        if (isCorrect(str))
            circles[circles_count++] = getcircle(str);
    }
    fclose(file);

    for (int i = 0; i < circles_count; i++)
        writePandS(circles[i]);

    PrintIntersect(circles, circles_count);

    return 0;
}