// fibonacci.c

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
// you wouldn’t choose, please include your reasons why you wouldn’t use it.
// Is there any situation you can think of where you would use the ‘bad’
// version? (might need to be a little creative here)

// Mark's answer:
// I would use the fib_iterative() in an actual release because it
// can support a larger input set without wasting as much resources.
// From testing, I could get the recursive version to compute fib(50)
// whereas the iterative version can solve up to the desired fib(100).

//
// Part III (optional)
// If you’re still enjoying this - what would you do to optimize the code?
//  (think both for a single function call as well as over the long term)
//  What’s the cost for doing so?  
// 
// Mark's answer:
//  I already optimized the fib_recursive below by having the n >= 2 case
//  to come first, since this case should happen more frequently then
//  n < 2.
// 
//  Another solution would be to simply store the answers in an array
//  of 101 entries and the result would be found in constant time by
//  simply indexing the result form the table of answers.  That is,
//  fib(0) is stored in result[0] and fib(100) in result[100].  The
//  tradeoff of this is faster execution but more storage requirement.



#include <stdio.h>
#include <stdlib.h>


// recursive version of fibonacci
unsigned long fib_recursive (unsigned long n)
{

    if (n >= 2)
    {
        return (fib_recursive(n - 1) + fib_recursive(n - 2));
    } else {
        return (n);
    }

}


// iterative version of fibonacci
unsigned long fib_iterative(unsigned long n)
{
    // return the nth fibonoacci number....
    unsigned long i;

    unsigned long t1 = 0;
    unsigned long t2 = 1;

    unsigned long next = 0;

    for (i = 2; i <= n; ++i)
    {
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }

    switch (n)
    {
        case 0:
            return t1;
        case 1:
            return t2;
        default:
            return next;
    }

}

