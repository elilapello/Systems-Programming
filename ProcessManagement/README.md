# Process Management Program
An implementation of process management techniques using system calls in C.
## Description
This program takes a divisor and ***n*** divisee arguments and determines if each divisee is divisible by the divisor. 
To acomplish this a new process is forked for every division check by the **Coordinator** program.
After **Coordinator** forks a new process and replaces the current process with the **Checker** program, passing two arguments, divisor and divisee.
**Checker** then determines if the divisee is divisible by the divisor and returns 1 if so and 0 if not.
**Coordinator** waits for **Checker** to finish executing and then prints the returned value.
## Installation
**Note:** this program is designed to run in Linux-based environments
1. Download Coordinator.c, Checker.c, and Makefile onto a Linux-based machine.
## Usage
3. Once in the directory containing the files run `make all` in the command line.
4. To run the program type `./coordinator <divisor> <divisee_1> <divisee_2> ... <divisee_n>` where each argument provided should be an integer.
5. To delete executable files run `make clean`.
