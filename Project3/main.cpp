#include <iostream>
#include<cmath>
#include <utility> 

//Exhaustive search
std::pair<int, int> root_exhaustive(int n, uint64_t x) {
    int number_of_loops = 0; //set loops equal to zero
    for (int i = 0; i < x + 1; i++) { //loop through the range of numbers from 0 to x
        number_of_loops += 1;   //add a loop everytime loop is entered
        if (pow(i, n) == x){       //calculate if the iteration to the nth power is equal to x
          return std::make_pair(i, number_of_loops);    //if true, return that root
        }
    }
    return std::make_pair(NAN, -1); //if nothing is found in the range, return nothing
}

//Decrease-by-half search
std::pair<int, int> root_dbh_range(uint64_t x, int n, uint64_t lo, uint64_t hi, int i) {
    uint64_t mid = (lo + hi) / 2; //set middle as number between low and high range value
    if (mid == lo) { //if no root value is found   
        return std::make_pair<int, int>(NAN, -1); //if nothing is found in the range, return nothing
    }
    else if (pow(mid, n) == x) { //if root to the nth power is equal to x
        return std::make_pair(mid, i); //return the root and the number of loops
    }
    else if (pow(mid, n) < x) { //if mid value is too low
        i += 1; //add a loop to the total amount
        return root_dbh_range(x, n, mid, hi, i); //recursive call to reset low
    }
    else //if mid value is too high
        i += 1; //add a loop to the total amount
    return root_dbh_range(x, n, lo, mid, i); //recursive call to reset high
}

//Decrease-by-half search
std::pair<int, int> root_dbh(int n, uint64_t x) { //first method called in decrease-by half to set values
    return root_dbh_range(x, n, 0, x, 0); //low is set to 0 and high is set to x value
}

int main() {
    int n = 11; //the exponential value of the root
    uint64_t x = 16985107389382393856;  //the value we are looking for root^n to equal

    //Exhaustive Search
    std::pair<int, int> r2 = root_exhaustive(n, x); //pair for the root and for the number of loop
    std::cout <<"Exhaustive Search: \n";
    std::cout << "The positive int r is "<< r2.first << ".\nThe function looped "<< r2.second << " times." << '\n';
    std::cout << "\n";
    //Decrease-by-half Search
    std::cout << "Decrease-by-half Search (Bisection Method): \n";
    std::pair<int, int> r1 = root_dbh(n, x); //pair for the root and for the number of loop
    std::cout <<"The positive int r is "<< r1.first << ".\nThe function looped "<< r1.second << " times." << '\n';
}