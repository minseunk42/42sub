#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct timeval mytime;
    struct timeval mytime2;

    gettimeofday(&mytime, NULL);
    usleep(2000);
    gettimeofday(&mytime2, NULL);
    printf("%d\n", (mytime2.tv_usec - mytime.tv_usec) / 1000);
    return 0;
}