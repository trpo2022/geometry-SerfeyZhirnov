#include <libgeometry/functions.h>

#include <ctest.h>

CTEST(getcircle, test1)
{
    char str[] = "(1.0 2.0, 3)";
    circle c1 = getcircle(str);

    double x = 1.0, y = 2.0, r = 3.0;

    ASSERT_DBL_NEAR(c1.x, x);
    ASSERT_DBL_NEAR(c1.y, y);
    ASSERT_DBL_NEAR(c1.r, r);
}
