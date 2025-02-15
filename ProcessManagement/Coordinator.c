#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

void create_process(char* divisor, char* divisee);

int main(int argc, char* argv[]) {
    // specify array attributes
    int array_length = argc - 1;
    size_t array_size = array_length * sizeof(char*);

    // allocate array
    char **array = (char**)malloc(array_size);

    // handle potential malloc failure
    if (array == NULL) {
        return 0;
    }

    // read in command line args
    for (int i = 0; i < array_length; i++) {
        array[i] = argv[i + 1];
    }
    char *divisor = array[0];

    // number of divisees = number of processes forked
    int divisee_count = array_length - 1;

    // run for all divisees
    for (int i = 1; i <= divisee_count; i++) {
        create_process(divisor, array[i]);
    }

    // clear allocated memory
    free(array);
    return 0;
}

void create_process(char* divisor, char* divisee) {
    int status = 0;
    pid_t pid = fork();

    // parent process
    if (pid > 0) {
        printf("Coordinator: forked process with ID %d\n", pid);
        printf("Coordinator: waiting for process [%d]\n", pid);

        // waits for child to exit
        wait(&status);
        int result = WEXITSTATUS(status);
        printf("Coordinator: child process %d returned %d.\n", pid, result);
        printf("Coordinator: exiting.\n");
    }
    // child process
    else if (pid == 0) {
        printf("Child process running with ID %d\n", getpid());
        execlp("checker", "checker", divisor, divisee, NULL);
    }
    // process creation failed
    else {
        printf("Coordinator: process creation failed.");
    }
}