#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime (int number);

//function primeHelper
//input parameter - positive integer, divisor
// returns true if prime, false otherwise
bool primeHelper (int number, int divisor);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.
void printPrimes (int n);

void printHelper(int n, int start);
//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
int findFibo (int n);

//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
void findFactors (int number);

void findFactorsHelper (int number, int divisor);
//******************  MAIN  *****************************

int main () {
    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);

    if (isPrime(testNum))
        printf("%d is prime\n",testNum);
    else
        printf("%d is not prime.", testNum);

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);

    printPrimes(testNum);

    printf("\n");

    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);

    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum));

    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);

    findFactors(testNum);
    printf("\n");

    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
    if(number == 1) {
        return false;
    }
    const int START_DIVISOR = 2;//HINT: You may want a helper function
    primeHelper(number, START_DIVISOR);

    //YOUR CODE GOES HERE

}

//function primeHelper
//input parameter - positive integer, divisor
// returns true if prime, false otherwise

bool primeHelper (int number, int divisor) {
    if(divisor == number){
        return true;
    }
    else{
        if((number % divisor) != 0){
            primeHelper(number, divisor+1);
        }
        else{
            return false;
        }
    }
}

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n) {
   const int startingNum = 1;
   printHelper(n, startingNum);

}

void printHelper(int n, int start){
    if(start <= n) {
        if (isPrime(start) == true) {
            //printPrimes(n-1);
            printf("%d \n", start);
            printHelper(n,start+1);
        }
        else{
            printHelper(n,start+1);
        }
    }
    else {
        return;
    }
}

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    else {
        return (findFibo(n - 2) + findFibo(n - 1));
    }
}

//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    if(number == 0) {
        printf("0");
        return;
    }
    else {
        const int START_DIVISOR = 2; //HINT: You may want a helper function
        printf("1");
        findFactorsHelper(number, START_DIVISOR);
    }
}

void findFactorsHelper (int number, int divisor) {
    if(isPrime(number) == true) {
        printf("*%d", number);
    }
    else{
        if((number % divisor) == 0){
            printf("*%d", divisor);
            findFactorsHelper((number/divisor), divisor);
        }
        else {
            findFactorsHelper(number, divisor+1);
        }
    }
}
