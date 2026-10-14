#include <iostream>
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
int RepeatedSquaring(long x, long n){
   int prod;
   int result;
   
   if(n == 0)
      return 1;
   else if (n == 1)
      return x;
   else{
      prod = RepeatedSquaring(x,n/2);
      result = prod * prod;
   }
   if((n%2) == 1)
      result = x * result;

   return result;

}

//int RepeatedSquringAlg(int x, int n){
//  
//
//}

int main () {
	long n;
	long x;

   cout << "x = " ;
   cin >> x;
   cout << "n = " ;
   cin >> n;


   cout << "BruteForce OverFlow -> " << BruteForceOverflow(x,n) << endl;   
   //auto start = high_resolution_clock::now();
   //cout << BruteForce(x,n) << endl;
   //auto end = high_resolution_clock::now();
   //auto duration = duration_cast<microseconds>(end - start);
  // cout << "BruteForce: " << duration.count() << "ms" << endl;

   //cout <<Horners(x,n) << endl;

   
  
   return 0;
}
