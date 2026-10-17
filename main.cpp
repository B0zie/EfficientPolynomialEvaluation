#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "BigInt.hpp"
using namespace std;
using namespace std::chrono;

vector<long> GetCoefficients(long n){
   vector<long> P;
   for(int i = 0; i <= n; ++i) {
      if(i == 0) 
        P.push_back(1);
      else
        P.push_back(i);
   }
  return P; 
}


//example of overflow scenario
//x = 9223372036854775807
//n = 1
//this will set sign bit to 1 
long BruteForceOverflow(long x, long n){
   vector<long> P = GetCoefficients(n);
   long p = 0;//init sum val to 0  

   for (int i = n; i >= 0; --i ){
      long power = 1;//init multiplication val by 1
      for(int j = 1; j <= i; ++j ){
         power = power * x;
      }
      p = p + P.at(i) * power;
   } 

   return p;
}

//Handled with header file
BigInt BruteForce(long x, long n){
   vector<long> P = GetCoefficients(n);
   BigInt p = 0;//init sum val to 0  

   for (int i = n; i >= 0; --i ){
      BigInt power = 1;//init multiplication val by 1

      for(int j = 1; j <= i; ++j ){
         power = power * x;
      }
      p = p + P.at(i) * power;
   } 

   return p;
}

//Walk through with paper
//Mark page number
BigInt Horners(long x,long n){
   vector<long> P = GetCoefficients(n);   
   BigInt p = P.at(n);  // p <- P[n]

   for(int i = n-1; i >= 0; --i){
      p = x * p + P[i];
   }
   return p;
}


//evaluates monomial
BigInt RepeatedSquaringMono(long x, long n){
   BigInt prod;
   BigInt result;
   
   if(n == 0)
      return 1;
   else if (n == 1)
      return x;
   else{
      prod = RepeatedSquaringMono(x,n/2);
      result = prod * prod;
   }
   if((n%2) == 1)
      result = x * result;

   return result;

}
//Adds its evaluated monimial 
BigInt RepeatedSquaring(long x, long n){
  BigInt sum = 0;
  while(n>=0){
    if(n!=0)
       sum += (n * RepeatedSquaringMono(x,n));
    else
       sum += RepeatedSquaringMono(x,n);
    --n;
  }
  return sum;
}

void CompareRandDigitRange (BigInt bruteForce, BigInt horner, BigInt repeatedSquaring){
   srand(13);  
   int a = ((rand()%101)+100);//Random number 100-200
   int b = a + 20;
   //cout << bruteForce.to_string().size() << endl;
   //cout << horner.to_string().size() << endl;
   //cout << repeatedSquaring.to_string().size() << endl;
   if((bruteForce.to_string().size() == horner.to_string().size()) && (horner.to_string().size() == repeatedSquaring.to_string().size())){
     long m = bruteForce.to_string().size();
       cout << "success: Digits Length Match!" << endl;
       cout << "BruteForce chunk ->" << bruteForce.to_string().substr(a,b) << endl;
       cout << "Horner chunk     ->" << horner.to_string().substr(a,b) << endl;
       cout << "RepeatedSQ chunk ->" <<repeatedSquaring.to_string().substr(a,b) << endl;
      
   }
   else
      cout << "Error: Digits do not match!";
}


int main () {
	long n;
	long x;
   BigInt bruteForceNum;
   BigInt hornerNum;
   BigInt repeatedSquaringNum;

   
   cout << "x = " ;
   cin >> x;
   cout << "n = " ;
   cin >> n;


   cout << "BruteForce OverFlow -> " << BruteForceOverflow(x,n) << endl;
   
   auto start = high_resolution_clock::now();
   bruteForceNum = BruteForce(x,n);
   auto end = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(end - start);
   cout << "BruteForce: " << duration.count() << "ms" << endl;
   
   start = high_resolution_clock::now();
   hornerNum = Horners(x,n);
   end = high_resolution_clock::now();
   duration = duration_cast<microseconds>(end - start);
   cout << "Horners: " << duration.count() << "ms" << endl;

   start = high_resolution_clock::now();
   repeatedSquaringNum = RepeatedSquaring(x,n);
   end = high_resolution_clock::now();
   duration = duration_cast<microseconds>(end - start);
   cout << "Repeated Squaring: " << duration.count() << "ms" << endl;

   CompareRandDigitRange(bruteForceNum,hornerNum,repeatedSquaringNum);
   return 0;
}
