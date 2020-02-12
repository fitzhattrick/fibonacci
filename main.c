// Mark Fitzpatrick 
// February 2020

// main.c

//
//
//  In mathematics, the Fibonacci numbers are the numbers in the following
//  integer sequence, called the Fibonacci sequence, and characterized by
//  the fact that every number after the first two is the sum of the two 
//  preceding ones (from Wikipedia).  The sequence appears as follows:
// 
//  0, 1, 1, 2, 3, 5, 8, 13,...
// 
// The 0th number of the series(f0) is 0, f1=1, f2=1, f3=2, etc. 
//
//
//
// Write two functions, preferably in C or C++, that both take an integer n
// and return the nth number in the Fibonacci sequence, i.e. fib(1) should
// return 1 and fib(10) should return 55.  One function should implement a
// recursive algorithm, the other should implement an iterative algorithm.
// Expect inputs up to n=100. Please ensure code can be compiled and provide
// code files and header files if needed.  Treat this problem as if the code
//  is to be released to production and include anything you think is 
// appropriate. 



//
// Part II
//
// From your implementation of the above two functions (recursive and
// iterative), which would you use in an actual release?  For the version
// you wouldn’t choose, please include your reasons why you wouldn’t use it.i
// Is there any situation you can think of where you would use the ‘bad’
// version? (might need to be a little creative here)

//
// Part III (optional)
// If you’re still enjoying this - what would you do to optimize the code?
//  (think both for a single function call as well as over the long term)
//  What’s the cost for doing so?  


// See file fibonacci.c for my answers to the above questions.


#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "fibonacci.h"

int unit_test ()
{ 
    unsigned long test_input;
    unsigned long test_result;
    int test_index;

    int fail_count = 0;

    unsigned long unit_test_input[12] = {0, 1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    unsigned long unit_test_output[12] = { 0, 1, 55, 6765, 832040, 102334155, 
                                    12586269025, 1548008755920,
                                    190392490709135, 23416728348467685,
                                    2880067194370816120, 3736710778780434371};

    // =============
    // run unit test
    // =============

    printf ("Start of unit test\n");


    printf ("Testing fib_iterative algorithm\n");
    for (test_index = 0; test_index <= 11; test_index++)
    {
        test_result = fib_iterative(unit_test_input[test_index]);

        if (test_result == unit_test_output[test_index])
        {
            printf ("Pass: fib(%ld) = %ld\n",
              unit_test_input[test_index], test_result);
        } else {
            fail_count++;
            printf ("Fail: fib(%ld) = %ld expected result %ld\n",
              unit_test_input[test_index], test_result,
              unit_test_output[test_index]);
        }
    }

    printf ("Testing fib_recursive algorithm\n");
    for (test_index = 0; test_index <= 6; test_index++)
    {
       test_result = fib_recursive(unit_test_input[test_index]);

       if (test_result == unit_test_output[test_index])
       {
           printf ("Pass: fib(%ld) = %ld\n",
             unit_test_input[test_index], test_result);
       } else {
           fail_count++;
           printf ("Fail: fib(%ld) = %ld expected result %ld\n",
             unit_test_input[test_index], test_result,
             unit_test_output[test_index]);
       }
    }

    if (fail_count == 0)
    {
        printf ("Unit Test Passed\n");
    } else {
        printf ("Unit Test Failed with %d error(s)\n", fail_count);
    }


    // return the number of tests that failed; 0 indicates Pass
    return (fail_count);

}

unsigned long do_fibonnaci (unsigned long n)
{ 
    unsigned long fib_input;
    unsigned long fib_iter;
    unsigned long fib_rec;
    

    fib_input = (unsigned long) n;
    // compute the nth integer in the Fibonacci sequence, iterative method
    fib_iter = fib_iterative(fib_input);


    printf ("fib_iterative: f(%ld) = %ld\n", n, fib_iter);


    // compute the nth integer in the Fibonacci sequence, recursive method
    // Note: I capped this at 50
    if (fib_input <= 50) {
        fib_rec = fib_recursive(fib_input); 
        printf ("fib_recursive: f(%ld) = %ld\n", n, fib_rec);
    }


    return (fib_iter);
}


int main(int argc, char *argv[])
{ 
    int n = 0, num_errors = 0;
    unsigned long fib_result;
    
    //const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size 16 MB
    const rlim_t kStackSize = 32 * 1024 * 1024; // min stack size 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            printf ("original stack size: %ld\n", rl.rlim_cur);
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);

            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);    
            } else {
                printf ("stack size set to: %ld\n", kStackSize);
            }
        } else {
            printf ("stack size: %ld\n", rl.rlim_cur);
        }

    }



    if (argc == 2)
    {
        n = atoi(argv[1]);
    }

    
    if ((argc == 2) && (n == -1))
    {
        // =============
        // run unit test
        // =============
        num_errors = unit_test();
        return (num_errors);

    } else if ((argc == 2) && (n >= 0) && (n <= 100)) {

        fib_result = do_fibonnaci((unsigned long) n);

    } else {
        printf ("\nusage: fibonacci n\n where n is between 0 and 100\n"); 
        printf (" to return the *Nth* integer in the fibonacci sequence\n");
        printf ("\nor to run the unit test, enter\nfibonacci -1\n");

    }

    return (0);
}

