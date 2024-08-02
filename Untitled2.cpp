#include<iostream>
using namespace std;

int fib(int indis)
{
	if(indis<=1) return 1;
	else{
	return fib(indis-2)+fib(indis-1);
	}
}

int iterative(int n)
{
	 
	    if (n == 1) return 1;
	    int prevPrev = 1;
	    int prev=1;
	    int currentNumber;
	    for (int i = 2; i <=n; i++) {
	        currentNumber = prevPrev + prev; //current =3oldu
	        prevPrev = prev;	//prevprev 2
	        prev = currentNumber;	//prev=3 oldu prevprev=2 oldu
	}
	return currentNumber;
	}

int main()
{

int a=0;
a=iterative(5);
int b=fib(5);
	cout<<b;
	return 0;
}
/*
 public static int fibonacciLoop(int nthNumber) {
        //use loop
        int previouspreviousNumber, previousNumber = 0, currentNumber = 1;

        for (int i = 1; i < nthNumber ; i++) {

            previouspreviousNumber = previousNumber;

            previousNumber = currentNumber;

            currentNumber = previouspreviousNumber + previousNumber;

        }
        return currentNumber;
    }

*/