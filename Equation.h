#define ERROR -2

//////////////////////////////////////////////////////////////////////////////////////////
/// Solves quadratic equation. Places roots in appointed variables. Returns amount of roots
/// param[in]     a      first coefficient
/// param[in]     b      second coefficient
/// param[in]     c      third coefficient
/// param[in]  answer1   pointer to first root
/// param[in]  answer2   pointer to second root
/// param[out]    n      number of roots (n stands for number)
//////////////////////////////////////////////////////////////////////////////////////////

int SolveLin (double b, double c, double *answer1);
int SolveQuadro (double a, double b, double c, double *answer1, double *answer2);
int SolveEq (double *answer1, double *answer2);
void SafeInput (double *input, char name);
void PrintResults (int SolNum, double answer1, double answer2);
double UnitTestEq ();
void Normalise (double* number);
int IzZero (double number);

int SolveQuadro (double a, double b, double c, double *answer1, double *answer2)
{
    int n = 0;
    double D = b*b-4*a*c;
    double sqrtD = sqrt (D);
    int ZeroA = IzZero (a);
    //printf ("sqrtD = %lf \n", sqrtD);


    if (ZeroA)  // ToDo: If and return
    {
        n = SolveLin (b, c, answer1);
        return n;
    }

    if (IzZero(sqrtD)) // ToDo: delete iszero
    {
            *answer1 = ((-b+sqrtD)/(2*a));
            n = 1;
    }

    else if (sqrtD > 0) // ToDo: sqrtD == 0 before
    {
        *answer1 = ((-b+sqrtD)/(2*a));
        *answer2 = ((-b-sqrtD)/(2*a));
        n = 2;
    }

    else if (D < 0)
    {
        n = 0;
    }

    else
    {
        n = ERROR;
        printf ("ERROR! Quadratic solver");
    }

    return n;
}


//////////////////////////////////////////////////////////////////////////////////////////
/// Solves linear equation. Places roots in appointed variables. Returns amount of roots
/// param[in]     a      first coefficient
/// param[in]     b      second coefficient
/// param[in]  answer1   pointer to the root
/// param[out]    n      number of roots (n stands for number)
//////////////////////////////////////////////////////////////////////////////////////////

int SolveLin (double a, double b, double *answer1)
{
    int n = 0;
    if  (!IzZero(a)) // ToDo: call function once
    {
        *answer1 = -b/a;
        n = 1;
    }
    else
    if  (IzZero(a) && !IzZero(b))
        n = 0;
    else
    if  (IzZero(a) && IzZero(b))
        n = -1;
    else
    {
        n = ERROR;
        printf ("ERROR! Linear solver");
    }
    return n;
}


//////////////////////////////////////////////////////////////////////////////////////////
/// Determines type of the equation and gets coefficients
/// param[in]  answer1   pointer to first root
/// param[in]  answer2   pointer to second root
/// param[out]    n      number of roots (n stands for number)
//////////////////////////////////////////////////////////////////////////////////////////

int SolveEq (double *answer1, double *answer2)
{
    int SolNum = ERROR;
    int mode = 0;
    double a, b, c = 0; // ToDo: initialize

    scanf  ("%d", &mode);

    switch (mode)
    {
        case 1:
            printf ("Enter coefficients for linear equation ax+b=0:\n");

            SafeInput(&a, 'a');
            SafeInput(&b, 'b');

            SolNum = SolveLin (a, b, answer1);
            Normalise (answer1);

            break;

        case 2:
            printf ("Enter coefficients for quadratic equation ax^2+bx+c=0:\n");

            SafeInput (&a, 'a');
            SafeInput (&b, 'b');
            SafeInput (&c, 'c');

            SolNum = SolveQuadro (a, b, c, answer1, answer2);
            Normalise (answer1);
            Normalise (answer2);


            break;

        default:
            printf ("ERROR! Equation Solver. Mode was %d", mode);
    }

    return SolNum;
}

//////////////////////////////////////////////////////////////////////////////////////////
///Checks, if the number is close to 0
///param[in]   number   number we check
///@note returns 1 if number is close to 0, 0 if it isnt
//////////////////////////////////////////////////////////////////////////////////////////


int IzZero (double number)
{
    return (fabs(number) < pow(10, -4)); // ToDo: const pow
}


//////////////////////////////////////////////////////////////////////////////////////////
///Checks, if the number is close to 0 and < 0
///param[in]   number   pointer to number we check
///@note sets close to 0 number less than 0 to 0
//////////////////////////////////////////////////////////////////////////////////////////

void Normalise (double* number)
{
    //printf("Normalising %lf", *number);
    if (IzZero (*number) == 1 && (*number) <= 0)
        {
        //printf ("I am active \n");
        *number = 0;
        }
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Prints answer(s) to the equation
/// param[in]   SolNum    amount of roots
/// param[in]   answer1   root 1
/// param[in]   answer2   root 2
//////////////////////////////////////////////////////////////////////////////////////////

void PrintResults (int SolNum, double answer1, double answer2)
{
    switch (SolNum)
    {
        case -1:
            printf ("Infinite answers");
            break;

        case 0:
            printf ("No answers here");
            break;
        case 1:
            printf ("answer 1 = %0.3lf, number of solutions = %i\n", answer1, SolNum);
            break;
        case 2:
            printf ("answer 1 = %0.3lf, answer 2 = %0.3lf, number of solutions = %i\n", answer1, answer2, SolNum);
            break;
        default:
            printf ("ERROR! Print results. SolNum = %d", SolNum);
            break;
    }

}


//////////////////////////////////////////////////////////////////////////////////////////
/// Gets a coefficient for the equation
/// param[in]   input     pointer to place to save input
/// param[in]   name      name of the coefficient
/// @note improper input is rejected, and the user is asked to retry
//////////////////////////////////////////////////////////////////////////////////////////

void SafeInput (double *input, char name)
{
    int scanned = 0;

    while (scanned != 1)
    {
        fflush (stdin); // ToDo: undefined behavior, read while not \n
        printf ("scanning %c: ", name);
        scanned = scanf ("%lf", input);

        if (scanned != 1)
            printf ("invalid input. please try again \n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Tests SolveQuadro by accessing 2 files - with input and with answers and compares expected answers to given ones
/// param[out] - amount of successful tests divided by amount of tests
/// prints out if the test if successful. if the test isnt successful prints input, expected data and resulting data
//////////////////////////////////////////////////////////////////////////////////////////



double UnitTestEq ()
{
// ToDo: INITIALIZE ME!!!
    double a, b, c, answer1, right_answer1, answer2, right_answer2, coeff_amount, answer_amount = 0;
    int sol_num, right_sol_num = ERROR;
    int test_number, right_test;
    int i = 1;
    FILE* input   = fopen ("C:\\Users\\CountZero\\Documents\\Ded\\ExternalData\\UnitTests\\SolveQuadroQ.txt", "r");
    FILE* answers = fopen ("C:\\Users\\CountZero\\Documents\\Ded\\ExternalData\\UnitTests\\SolveQuadroA.txt", "r");

    while ((coeff_amount = fscanf (input, "%lf %lf %lf", &a, &b, &c)) > 0 && (answer_amount = fscanf (answers, "%lf %lf %d", &right_answer1, &right_answer2, &right_sol_num)) > 0)
    {
        //printf ("\n I GOT DATA! a = %lf, b = %lf, c = %lf, answer1 = %lf, answer2 = %lf, answer_amount = %d  \n", a, b, c, right_answer1, right_answer2, right_sol_num);
        if (coeff_amount != 3)
        {
            printf ("ERROR. Wrong input in test %d", i);
        }
        else
        {
            sol_num = SolveQuadro (a, b, c, &answer1, &answer2);
            if (sol_num == right_sol_num)
            {
                switch (sol_num)
                {
                    case 0:
                        printf ("OK test %d \n", i);
                        right_test++;

                        break;
                    case -1:
                        printf ("OK test %d \n", i);
                        right_test++;

                        break;
                    case 1:
                        if (answer1 == right_answer1 || answer1 == right_answer2)
                        {
                                printf ("OK test %d \n", i);
                                right_test++;
                        }
                        else

                        {
                            printf ("ERROR in test %i, noted by case 1\n"
                            "input a = %lf, b = %lf, c = %lf \n"
                            "expected answer1 = %lf, answer2 = %lf, amount of answers = %d \n"
                            "result   answer1 = %lf, answer2 = %lf, amount of answers = %d \n",
                            i, a, b, c, right_answer1, right_answer2, right_sol_num, answer1, answer2, sol_num);
                        }
                        break;
                    case 2:
                        if ((answer1 == right_answer1 && answer2 == right_answer2)||(answer1 == right_answer2 && answer2 == right_answer1))
                        {
                                printf ("OK test %d \n", i);
                                right_test++;
                        }
                        else
                        {
                            printf ("ERROR in test %i, noted by case 2\n"
                            "input a = %lf, b = %lf, c = %lf \n"
                            "expected answer1 = %lf, answer2 = %lf, amount of answers = %d \n"
                            "result   answer1 = %lf, answer2 = %lf, amount of answers = %d \n",
                            i, a, b, c, right_answer1, right_answer2, right_sol_num, answer1, answer2, sol_num);
                        }
                        break;
                    default:
                        printf ("Unit Switch wrong\n");
                }


            }
            else
            {
                printf   ("ERROR in test %i, noted by different number of solutions than expected \n"
                          "input a = %lf, b = %lf, c = %lf \n"
                          "expected answer1 = %lf, answer2 = %lf, amount of answers = %d \n"
                          "result   answer1 = %lf, answer2 = %lf, amount of answers = %d \n",
                        i, a, b, c, right_answer1, right_answer2, right_sol_num, answer1, answer2, sol_num);
            }
        }
        i++;
    }
    return (right_test/i)*100;
}

