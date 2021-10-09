//Sieve of Eratosthenes

/*The sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.
It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the first prime number, 2. 
The multiples of a given prime are generated as a sequence of numbers starting from that prime, with constant difference between them 
that is equal to that prime.[1] This is the sieve's key distinction from using trial division to sequentially test each candidate number
for divisibility by each prime.[2] Once all the multiples of each discovered prime have been marked as composites, the remaining unmarked
numbers are primes.*/

// here we are implementing sieve for numbers upto 1000000;



#include<bits/stdc++.h>
using namespace std;


bool prime[1000001];

void SieveOfEratosthenes()
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
  //  bool prime[n + 1];
  //here n=1000000;
  
   prime[0]=true;
   prime[1]=true;
 
    for (int p = 2; p * p <= 1000000; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == false)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= 1000000; i += p)
                prime[i] = true;
        }
    }
 
   
}


//driver-main function

int main()
{
  
  SieveOfEratosthenes();
  int t;
  cin>>t;
  while(t--)
  {
    int num;
    cin>>num;
    if(prime[num]==false)
      cout<<"Prime"<<"\n";
    else
      cout<<"Not Prime"<<"\n";
  }
  return 0;
  
}
