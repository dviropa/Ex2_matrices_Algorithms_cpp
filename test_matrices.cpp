#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"

using namespace matrices;

TEST_CASE("Matrix creation and basic access") {
    SquareMat mat(3, 3);
    mat[0][0] = 1;
    mat[1][1] = 2;
    mat[2][2] = 3;

    CHECK(mat[0][0] == 1);
    CHECK(mat[1][1] == 2);
    CHECK(mat[2][2] == 3);
}

TEST_CASE("Matrix addition") {
    SquareMat a(2, 2);
    SquareMat b(2, 2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    SquareMat c = a + b;
    CHECK(c[0][0] == 6);
    CHECK(c[0][1] == 8);
    CHECK(c[1][0] == 10);
    CHECK(c[1][1] == 12);
}

TEST_CASE("Matrix scalar multiplication") {
    SquareMat a(2, 2);
    a[0][0] = 2;
    a[0][1] = 3;
    a[1][0] = 4;
    a[1][1] = 5;

    SquareMat c = a * 2.0;
    CHECK(c[0][0] == 4);
    CHECK(c[0][1] == 6);
    CHECK(c[1][0] == 8);
    CHECK(c[1][1] == 10);
}

TEST_CASE("Matrix equality and comparison") {
    SquareMat a(2, 2);
    SquareMat b(2, 2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 2; b[0][1] = 2;
    b[1][0] = 2; b[1][1] = 4;

    CHECK(a == b);         // סכום זהה
    CHECK_FALSE(a != b);
}

TEST_CASE("Matrix transpose") {
    SquareMat a(2, 2);
    a[0][1] = 7;
    a[1][0] = 9;

    SquareMat t = ~a;
    CHECK(t[1][0] == 7);
    CHECK(t[0][1] == 9);
}
