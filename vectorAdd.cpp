#include <iostream>
#include <vector>

using namespace std;

vector<int> addVector (vector<int> v1, vector<int> v2){
  vector<int> sum = v1;
  for(long unsigned int i = 0; i <= (v1.size()-v2.size()); ++i){
    v2.insert(v2.begin(),0);
  }

  for(int i = (sum.size()-1);i>=0;--i){
     int r =  (sum.at(i)+v2.at(i))%10;
     if(sum.at(i)+v2.at(i) >= 10 && i == 0 ){
       sum.insert(sum.begin(),(sum.at(i)+v2.at(i))/10);//carry number
       ++i;
       sum.at(i) = r;//remainder stays
     }
     else if(sum.at(i)+v2.at(i)>= 10){
       
        sum.at(i-1) += (sum.at(i)+v2.at(i))/10;//carry number
        sum.at(i) = r;//remainder stays
     }
     else{
        sum.at(i)+=v2.at(i);
     }
  }
  return sum;
}

int main () {
   vector<int>  num1 = {9,9,9};
   vector<int>  num2 = {1};
   vector<int>  sum;
   

   
   sum =  addVector(num1,num2);
   for (auto n: sum) {
      cout << n;
   }
   
 
	return 0;
}
