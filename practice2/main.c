/*
 * Practice 2, variant 13
 *
 * Author: Mykhailo Renkas, group IP-z41, KPI FIOT
 *         <renkas.mykhailo_ipz41@edu.kpi.ua>
 *
 *        sin(a) + cos(2b - a)             1 + sin(2b)
 * z1 = ------------------------    z2 = ---------------
 *        cos(a) - sin(2b - a)               cos(2b)
 *
 * Both expressions are the same function written in two ways,
 * so for any valid a and b the results must match.
 */

#include <math.h>
#include <stdio.h>

#define EPS 1e-12

/* Returns 0 on success, -1 if the denominator is zero. */
static int calc_z1(double a, double b, double *z1)
{
    double den = cos(a) - sin(2.0 * b - a);

    if (fabs(den) < EPS)
        return -1;

    *z1 = (sin(a) + cos(2.0 * b - a)) / den;
    return 0;
}

static int calc_z2(double b, double *z2)
{
    double den = cos(2.0 * b);

    if (fabs(den) < EPS)
        return -1;

    *z2 = (1.0 + sin(2.0 * b)) / den;
    return 0;
}

/* Asks for one number. Returns 0 on success, -1 on bad input. */
static int read_double(const char *prompt, double *x)
{
    printf("%s", prompt);

    if (scanf("%lf", x) != 1)
        return -1;

    return 0;
}

int main(void)
{
    double a, b, z1, z2;

    printf("Practice 2, variant 13\n");
    printf("Author: Mykhailo Renkas, group IP-z41\n");

    if (read_double("Enter alpha (radians): ", &a) != 0) {
        fprintf(stderr, "Error: alpha must be a number\n");
        return 1;
    }

    if (read_double("Enter beta (radians): ", &b) != 0) {
        fprintf(stderr, "Error: beta must be a number\n");
        return 1;
    }

    if (calc_z1(a, b, &z1) != 0) {
        fprintf(stderr, "Error: z1 is undefined, cos(a) - sin(2b - a) = 0\n");
        return 1;
    }

    if (calc_z2(b, &z2) != 0) {
        fprintf(stderr, "Error: z2 is undefined, cos(2b) = 0\n");
        return 1;
    }

    printf("alpha = %g, beta = %g\n", a, b);
    printf("z1 = %.10f\n", z1);
    printf("z2 = %.10f\n", z2);
    printf("|z1 - z2| = %e\n", fabs(z1 - z2));

    return 0;
}
