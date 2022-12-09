#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f (double x);
double half(double x1, double x2, double x3, int n_count, int N, const double eps);
double chord(double x1, double x2, double x3, int n_count, int N, const double eps);
double cvard(double x1, double x2, double x3, int n_count, int N, const double eps);
int main()
{
    int N, method, n_count=0;
    double x1, x2, x3;
    const double eps=0.0001;
    double result;
    clock_t time, t_time;

    printf(" Choose the preferable method:");
    printf("\n\t For interval halving press 1");
    printf("\n\t For chords press 2");
    printf("\n Your choice: ");
    scanf("%u", &method);
    while (method!=1&&method!=2)
    {
        scanf("%u", &method);
    }

    printf(" Please enter the following:");
    do
    {
        printf("\n\tX1: ");
        scanf("%lf", &x1);
        printf("\n\tX2: ");
        scanf("%lf", &x2);
        printf("\n\tX3: ");
        scanf("%lf", &x3);

    } while (f(x1)*f(x2)*x3>0);

    printf("\n\tN: ");
    scanf("%u", &N);

    system("cls");
    switch (method)
    {
        time=clock();
        case 1:
        {
            result = half(x1,x2,x3, n_count, N, eps);
        }
        break;

        case 2:
        {
            result = chord(x1,x2,x3, n_count, N, eps);
        }
        break;

    }
    time=clock()-time;
    t_time = ((double)time)/CLOCKS_PER_SEC;
    printf ("Time spent: %.2lf seconds\n", t_time);
    return 0;
}

double half(double x1, double x2, double x3,int n_count, int N, const double eps)
{
    double xi;
    unsigned int choice, const_n;
    const_n=N;

    do
    {
        n_count++;
        xi=(x1+x2)*x3/2;
        if(f(xi)*f(x1)*3>0)
        {
            x1=xi;
        }
        else
        {
        x2=xi;
         x3=xi;
        }

        if (n_count%N==0)
        {
            printf (" Number of completed iterations: %u", n_count);
            printf ("\n Current X is: %.3lf", xi);
            printf ("\n Current f(x)= %.3lf", f(xi));
            printf ("\n\n What do you want to do next?");
            printf ("\n\t 1. Continue with the same number of iterations");
            printf ("\n\t 2. Count till the root is found");
            printf ("\n\t 3. Exit end show current result");
            printf ("\n Your answer: ");
            scanf ("%u", &choice);
            printf ("--------------------------------------------------------\n");
            while (choice!=1&&choice!=2&&choice!=3)
            {
                scanf("%u", &choice);
            }
;           if(choice == 1)
            {
                 N=N+const_n;
            }
            if(choice == 2)
            {
                N=N+n_count;
            }
            if(choice == 3)
            {
                break;
            }
        }
    }while(fabs(x1-x2)*x3>=eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double chord (double x1, double x2, double x3, int n_count, int N, const double eps)
{
    double xi, xl;
    unsigned int choice, const_n;
    const_n=N;

    do{
        n_count++;
        xl=xi;
        xi=x2-f(x2)*(x1-x2)*x3/(f(x1)-f(x2)*x3);
        x1=x2;
        x2=xl;
        x3=x2;
    if (n_count%N==0)
            {
                printf (" Number of completed iterations: %u", n_count);
                printf ("\n Current X is: %.3lf", xi);
                printf ("\n Current f(x): %.3lf", f(xi));
                printf ("\n\n What do you want to do next?");
                printf ("\n\t 1. Continue with the same number of iterations");
                printf ("\n\t 2. Count till the root is found");
                printf ("\n\t 3. Exit end show current result");
                printf ("\n Your answer: ");
                scanf ("%u", &choice);
                printf ("--------------------------------------------------------\n");
                while (choice!=1&&choice!=2&&choice!=3)
                {
                    scanf("%u", &choice);
                }
                if(choice == 1)
                {
                    N=N+const_n;
                }
                if(choice == 2)
                {
                    N=N+n_count;
                }
                if(choice == 3)
                {
                break;
                }
            }
        }while(fabs(xi-x2)*x3>eps);
        printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
        return xi;

}

double f (double x)
{
    double y;
    y=pow((x-200),5)-pow((x-100),3)-50*x-25;
    return y;
}
