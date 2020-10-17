# cop4634-project2
## To-Do
1. Take in commandline arguements ,`N`, range of numbers for Collatz sequence. `T` number of threads for program to create
`./mt-collatz <N> <T>`
2. create threads with `pthread_create()`
  Each thread selects a number in the specified range, computes the stopping time and records the result in the global histogram array before it chooses the next number not yet selected by another thread.
3. compute Collatz sequence of numbers between 1 and N
4. Print out stopping times from Collatz sequence
`<k=1,...,N>, <frequency of Collatz stopping timeswhere i = k>`
Ask for an example because I'm not entirely sure what this means
```
1, 1
2, 2
3, 3
4, 6
5, 7
6, 9
```
5. The time required to produce the entire histogram must be written to the standard error stream  (`stderr`) using `clock_gettime()`
`<N>, <T>, <time required to complete the program in seconds and nanoseconds>`
`500,8,3.852953000`
6. Make sure there are no race conditions.
https://stackoverflow.com/questions/34510/what-is-a-race-condition

## Report
1. Results from testing code with 1 to 30 threads and a large N value. N will be constant for the experiement.
2. Create a graph with the time required to test the code as the number of threads increases.
3. Analyze the results and discuss what is observed.
4. State the machine that the experiment was conducted on. Specs?
