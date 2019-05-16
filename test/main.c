#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>
#include <text.h>

CTEST(read__test, result_test)
{
    // Given
    char h[]="(1,2,3)"
    int i = 1;
    // When
    char result = readin(h, i, ',');
    // Then
    const char expected = '1';
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext_test(right), result_test)
{
    // Given
    char f[] = "circle";

    // When
    const int result = rtext(f);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext_test(False), result_test)
{
    // Given
    char f[] = "cirgse";

    // When
    const int result = rtext(f);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext_numbers(False), result_test)
{
    // Given
    char f[] = "(1,5)";

    // When
    const int result = rnumber(f);

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}
CTEST(errortext_numbers(right), result_test)
{
    // Given
    char f[] = "(1,2,3)";

    // When
    const int result = rnumber(f);

    // Then
    const int expected = 4;
    ASSERT_EQUAL(expected, result);
}
CTEST(peres__test(right), result_test)
{
    // Given
    const int x1 = 1;
    const int y1 = 2;
    const int r1 = 3;
    const int x2 = 1;
    const int y2 = 2;
    const int r2 = 3;

    // When
    const int result = ait(x1, y1, r1, x2, y2, r2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(peres__test(False), result_test)
{
    // Given
    const int x1 = 1;
    const int y1 = 1;
    const int r1 = 1;
    const int x2 = 10;
    const int y2 = 10;
    const int r2 = 1;

    // When
    const int result = ait(x1, y1, r1, x2, y2, r2);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(peres__test(right), result_test)
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
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(figurearea__test, result_test)
{
    // Given
    double s;
    double p;
    int r = 5;


    // When
    fsp(s, p, r)
    s*=p;
    const double tol = 0.01;
    // Then
    const int expected = 2467.3985;
    ASSERT_DBL_NEAR_TOL(expected, result);
}
