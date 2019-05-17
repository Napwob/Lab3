#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>
#include <func.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(errortext__test1, result_test)
{
    // Given
    char f[] = "circle";

    // When
    const int result = rtext(f);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext__test2, result_test)
{
    // Given
    char f[] = "cirgse";

    // When
    const int result = rtext(f);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext__number3, result_test)
{
    // Given
    char f[] = "circle(1,5)";

    // When
    const int result = rnumber(f);

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext__numbers4, result_test)
{
    // Given
    char f[] = "circle(1,2,3)";

    // When
    const int result = rnumber(f);

    // Then
    const int expected = 4;
    ASSERT_EQUAL(expected, result);
}
CTEST(peres__test5, result_test)
{
    // Given
    const int x1 = 1;
    const int y1 = 2;
    const int r1 = 3;
    const int x2 = 1;
    const int y2 = 2;
    const int r2 = 3;

    // When
    const int result = ati(x1, y1, r1, x2, y2, r2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(peres__test6, result_test)
{
    // Given
    const int x1 = 1;
    const int y1 = 1;
    const int r1 = 1;
    const int x2 = 10;
    const int y2 = 10;
    const int r2 = 1;

    // When
    const int result = ati(x1, y1, r1, x2, y2, r2);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(peres__test7, result_test)
{
    // Given
    const int x1 = 2;
    const int y1 = 0;
    const int r1 = 5;
    const int x2 = 0;
    const int y2 = 2;
    const int r2 = 5;

    // When
    const int result = ati(x1, y1, r1, x2, y2, r2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(figurearea__test8, result_test)
{
    // Given
    double s;
    int r = 5;

    // When
    s = fsp(1, r);
    const double tol = 0.01;
    // Then
    const double expected = 78.5398;
    ASSERT_DBL_NEAR_TOL(expected, s, tol);
}
CTEST(figurearea__test9, result_test)
{
    // Given
    double p;
    int r = 5;

    // When
    p = fsp(0, r);
    const double tol = 0.01;
    // Then
    const double expected = 31.416;
    ASSERT_DBL_NEAR_TOL(expected, p, tol);
}
