#include <stdio.h>
#include <math.h>
#include "Equation.h"
// ToDo: #include "equation.h"
#define ERROR -2

//////////////////////////////////////////////////////////////////////////////////////////
/// Program solves linear or quadratic equation and prints the answers
/// @note type of equation depends on mode chosen, with 1 for linear and 2 for quadratic
/// @note if there is infinite number of solutions prints "Infinite answers"
/// @note if there is no solutions prints "No answers here"
//////////////////////////////////////////////////////////////////////////////////////////

int main ()
{
    double answer1 = 0,
           answer2 = 0;
    int SolNum = ERROR;

    //printf ("SolveEq - solves linear or quadratic equation v1.0\n"
    //        "Enter 1 for a linear equation, enter 2 for a quadratic equation\n"
    //        "Choose mode: ");

    //SolNum = SolveEq (&answer1, &answer2);
    //PrintResults (SolNum, answer1, answer2);

    double right_percent = UnitTestEq ();
    //printf ("percent of right answers %0.2f", right_percent);

    return 0;
}

