#include <iostream>
#include <algorithm>
#include <array>

//global variable initialization 
int F[50] = { };

//naive pattern solution
int Naive(int n) {
  if (n == 1 || n == 2)
    return 0; // value at 1 and 2 is always zero
  else if (n == 3)
    return 1; // value at 3 is always one
  int a = 0; //first position
  int b = 0; //second position
  int c = 1; //third position
  int result;
  //gets values of previous three elements
  for(int i = 4; i < n + 1; ++i) {
    result = (a + b + c); //gets sum of all three values in position 1,2,3
    a = b; //gets value from one postion up
    b = c; //gets value from one postion up
    c = result; //gets value from one postion up
  }
  return result; //return sum of 3 numbers at position sent to Naive() function
}

//recursive solution
int recursive(int n){
  if (n == 1 || n == 2) {
    return 0; // value at 1 and 2 is always zero
  }
  else if (n == 3) {
    return 1; // value at 3 is always one
  }
  else {
    //recursive calls to get sum of numbers at postion 1, 2, 3
    return recursive(n-1) + recursive(n-2) + recursive(n-3);
  }
}

//recursive solution using memoization
int recursive_memorization(int n) {
  int result;
  //checks if value at index from parameter value is not zero
  if(F[n] != 0) {
    return F[n]; 
  }
  else{
    result = recursive(n); //uses function from previous algorithm
    F[n] = result; //set result to value obtained
    return result; //send result value back
  }

}

int dynamic_pattern (int n) {
  int Array[50]; //array initialized inside of method
  //initializes first three numbers to reduce time complexity
  Array[1] = 0; //first number will always be 0
  Array[2] = 0; //second number will always be 0
  Array[3] = 1; //third number will always be 1
  //start at 4 because first three numbers are already initialized
  for (int i = 4; i <= n; i++) 
  //gets values of previous three elements
    Array[i] = Array[i - 3] + Array[i - 2] + Array[i - 1];
  return Array[n]; //returns value at index from parameter value
}

int main() {
  //All programs are iterated 25 times 

  //Naive Pattern
  std::cout << "\e[1mNaive Pattern"<<std::endl;
  for (int i = 1; i <= 25; i++) {
    std::cout << "The " << i << " th tribonacci is " <<Naive(i) << std::endl; 
  }
  //Recursive
  std::cout << "\n\e[1mRecursive Pattern"<<std::endl;
  for (int i = 1; i <= 25; i++) {
    std::cout << "The " << i << " th tribonacci is " << recursive(i) << std::endl;  
  }
  //Recursive with memorization
  std::cout << "\n\e[1mRecursive with Memorize Pattern"<<std::endl;
  for (int i = 1; i <= 25; i++) {
    std::cout << "The " << i << " th tribonacci is " <<recursive_memorization(i) << std::endl;  
  }
  //Dynamic Pattern
  std::cout << "\n\e[1mDynamic Pattern"<<std::endl;
  for (int i = 1; i <= 25; i++) {
    std::cout << "The " << i << " th tribonacci is " <<dynamic_pattern(i) << std::endl;  //feel free to comment out to test out other code
  }
}