#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("Checker process [%d]: Starting.\n", getpid());

    // assign equation values
    int divisor = atoi(argv[1]);
    int divisee = atoi(argv[2]);

    // if divisible print details
    if (divisee % divisor == 0) {
        printf("Checker process [%d]: %d *IS* divisible by %d\n", getpid(), divisee, divisor);
        printf("Checker process [%d: Returning 1.\n", getpid());
        return 1;
    }
    // if not divisible print details
    else {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d\n", getpid(), divisee, divisor);
        printf("Checker process [%d]: Returning 0.\n", getpid());
        return 0;
    }
}
