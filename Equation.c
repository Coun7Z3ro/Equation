#include <stdio.h>
#include <math.h>

int SolveLin (double b, double c, double *answer1);
int SolveQuadro (double a, double b, double c, double *answer1, double *answer2);


int main ()
    {
    double a, b, c, answer1, answer2 = 0;
    int mode, SolNum = 0;

    printf ("SolveEq - solves linear or quadratic equation v1.0 by CountZero\n"
            "Enter 1 for a linear equation, enter 2 for a quadratic equation\n"
            "Choose mode:");
    scanf  ("%d", &mode);

    switch (mode)
        {
        case 1:
            printf ("Enter coefficients for linear equation ax+b=0:");

            printf ("scanning a");
            scanf  ("%lf", &b);
            printf ("scanning b");
            scanf  ("%lf", &c);

            SolNum = SolveLin (b, c, &answer1);

            break;

        case 2:
            printf ("Enter coefficients for quadratic equation ax^2+bx+c=0:");

            printf ("scanning a");
            scanf  ("%lf", &a);
            printf ("scanning b");
            scanf  ("%lf", &b);
            printf ("scanning c");
            scanf  ("%lf", &c);

            SolNum = SolveQuadro (a, b, c, &answer1, &answer2);

            break;

        default:
            printf ("ERROR mode");
        }



    switch (SolNum)
        {
        case -1:
            printf ("Infinite answers");
            break;
        case 0:
            printf ("No answers here");
            break;
        case 1:
            printf ("answer 1 = %lf, number of solutions = %i\n", answer1, SolNum);
            break;
        case 2:
            printf ("answer 1 = %lf, answer 2 = %lf, number of solutions = %i\n", answer1, answer2, SolNum);
            break;
        default: 
            printf ("error printing answers");
            break;
        }

    return 0;
    }


int SolveQuadro (double a, double b, double c, double *answer1, double *answer2)
    {
    int n = 0;
    double sqrtD = sqrt (b*b-4*a*c);

    if  (a == 0 && b == 0 && c == 0)
        {
        n = -1;
        }
    else
    if  (a == 0)
        {
        SolveLin (b, c, answer1);
        }
    else 
    if (sqrtD > 0 && a != 0)
        {
        *answer1 = ((-b+sqrtD)/(2*a));
        *answer2 = ((-b-sqrtD)/(2*a));
        n = 2;
        }
    else 
    if (sqrtD == 0 && a != 0)
        {
        *answer1 = ((-b+sqrtD)/(2*a));
        n = 1;
        }
    else 
    if (sqrtD < 0 && a != 0)
        {
        n = 0;
        }
    else
        {
         printf ("ERROR! qSol");
        }
    return n;
    }


int SolveLin (double b, double c, double *answer1)
    {
    int n = 0;
    if  (b != 0)
        {
        *answer1 = -c/b;
        n = 1;
        }
    else if  (b == 0 && c != 0)
        {
        n = 0;
        }
    else if  (b == 0 && c == 0)
        {
        n = -1;
        }
    else
        {
        n = -2
        printf ("error. lSol");
        }
    return n;
    }
