#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

//Create a function to calculate the mean of a vector
int mean(std::vector<int> vect) {
  int total = 0;              
  int len = vect.size();      //get the size of the vect.

  //Use a for loop to iterate the vector and add all the elements
  for (int i = 0; i < len; ++i) {
      total += vect.at(i);
  }

  //print the vector size and the mean
  std::cout <<"Then length of the vector is: " << len <<'\n';
  std::cout <<"The mean is: ";
  return total / len;  //returns the mean
}

///Create a function to construct a square matrix of a given row/column length made up of a specified number
void construct_sqaure_matrix(int n, int x) {    
    // Matrix is initialized
    std::vector<std::vector<int > > rows(n,std::vector<int>(n));

    //Matrix is created with random number x at each index
    for (int r = 0; r < n; ++r) {   //rows
        for (int c = 0; c < n; ++c) {  //columns
            rows[r][c] = x;  //random number x inserted into matrix here
            std::cout << rows[r][c] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
  std::cout << "/////////////////////////////3-14(a)////////////////////////"<<"\n\n";

  //Use a loop to run 10 test case
  for(int i=1; i < 11; ++i)
  {
    std::cout <<"-----------------Calculate the Mean, case " << i << "-------------------\n";
    //makes the size of the vector equal to i*i*10. i stands for the number of the test case.
    int n = i*i*10;
    //generates an empty array
    std::vector<int> L;

    for (int i = 0; i < n; i++) {
      // a random number is generated to be inserted into the vector
      int x = std::rand() / ((RAND_MAX + 1u)/100);
      L.push_back(x);  //adds value onto array
    }

  //List in full view if needed
    // for (int i = 0; i < L.size(); i++){
    //   //Our complete list
    //   std::cout << L.at(i) << " " ;
    // }
    // std::cout << "\n";
    
    //run the mean function and record the runtime.
    auto start = std::chrono::steady_clock::now();
    std::cout << mean(L) <<'\n';  //sends list of random integers to mean call
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << "\n";
  }
  
  std::cout << "\n\n\n/////////////////////////////3-14(b)////////////////////////"<<"\n\n";
  
  //Use a loop to run 10 test case
  for (int i = 1; i < 11; ++i) {
        //make the size of matrix to n * n, and makes n equals to i*i*i. i stands for the number of the test case.
        int n = i*2;

        //the random number that will be the element in the matrix
        int x = std::rand() / ((RAND_MAX + 1u)/100);

        std::cout <<"-----------------Create a Matrix, case " << i << "-------------------\n";
        //run the mean function and record the runtime.
        auto start = std::chrono::steady_clock::now();
        std::cout<< "Created a "<< n << " * " <<n <<" matrix\n";
        construct_sqaure_matrix(n, x);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        std::cout << "\n";
    }

  return 0;
}
