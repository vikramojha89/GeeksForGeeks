//This Program computes the number i, whose factorial is divisible by number x
/*
   Input:
   x=10
   Output: 5!
*/


#include <iostream>
#include <cmath>
using namespace std;

int gcd(int i, int j);
const int firstNumberGreaterthanX(const int x);

//Function to find GCD of number
int gcd(int i, int j)
{
  if(i%j == 0)
    return j;
  else return gcd(j, i%j);
}

int isPrime(int x)
{
  int sqrt_x = sqrt(x);
  for(int i=2;i<=sqrt_x; i++)
  {
    if (!(x%i))
      return 0;
  }
  return 1;
}

//Main Function to find first Natural Number greater than x
const int firstNumberGreaterthanX(const int x)
{
 //1. When x is prime then we simply return x. As Prime numbers are not 
 //   multiple of any number. 
 if (isPrime(x))
    return x;

 //2. Condition when x is not Prime
 int new_x = x;
 int i;
 for (i = 1; i<x; i++)
 { 
   new_x /= gcd(i, new_x);
   if (new_x ==1)
     break;
 }
 return i;
}

//Driver program
int main()
{
  //x is input given by user , we have to find number whose factorail is
  //divisible by x
  int x;
  cout <<"\nEnter the number X:";
  cin>>x;
  cout<<"\nOutput:\n"<<firstNumberGreaterthanX(x)<<"\n";
  return 0;
}
