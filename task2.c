#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int a = 10;
    int b = 25;
    int fq = 0;
    int fr = 0;
    fq = fork(); // fork process Q
    if (fq == 0) // process Q
    {
        a = a + b;
        printf("––––––––––––––––––in process Q––––––––––––––––––\na = %d\nb = %d\npid = %d\n", a, b, getpid());
        fflush(0); // to avoid the printf above appearing in the output buffer of the child
        fr = fork(); // fork process R
        if (fr != 0) // process Q
        {
            b = b + 15;
            printf("––––––––––––––––––in process Q––––––––––––––––––\na = %d\nb = %d\npid = %d\n", a, b, getpid());
        }
        else // process R
        {
            a = (a * b) + 20;
            printf("––––––––––––––––––in process R––––––––––––––––––\na = %d\nb = %d\npid = %d\n", a, b, getpid());
        }
    }
    else // process P
    {
        b = a + b - 5;
        printf("––––––––––––––––––in process P––––––––––––––––––\na = %d\nb = %d\npid = %d\n", a, b, getpid());
    }
}