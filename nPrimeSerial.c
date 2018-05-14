/**
 File: nPrimeSerial.c
 Created by: Angie Tornetto
 Description: Finds all prime numbers from 1 to a user inputted value, n, taken in as an execution argument. Uses serial base case algorithm to improve with OpenMP and MPI.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

clock_t start, end;
double totTime;

int primes(int n){

    int lim = 0;
    int primeCount = 0;
    int isPrime = 0;
    int i = 0;
    int j = 0;
    
    for(i=2 ;i <= n; i++){ // outer loop to iterate through all numbers up to and including n
        isPrime = 1; //prime=1 , not prime = 0
        lim = i/2;
        
        for(j = 2; j <= lim; j++){
            
            if((i % j) == 0){  // Check prime number
                isPrime = 0; //not prime
                break;
            }
        }
        if(isPrime == 1){
            //printf("%d is a prime number\n", i);
            primeCount++;
        }
    }
    return primeCount;
}

int main(int argc, char* argv[]){
    start = clock();
    int n, tot;
    
    if(argc < 2)
        n = 10000; //default
    else
        n = strtol(argv[1], NULL, 10);
    
    tot = primes(n);
    
    end = clock();
    totTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%d, %d, %f\n", n, tot, totTime);
    return 0;
}
