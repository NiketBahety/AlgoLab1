#include <iostream>
#include <random>
#include <fstream>

using namespace std;
 
int main()
{
    default_random_engine generator;
    normal_distribution<double> distribution(500.0, 200.0); // Mean=500 // SD=200
    ofstream myFile("dataset2.txt");
 
    for(int i = 0; i<100000; i++)
    myFile << distribution(generator) << "," << " ";

    myFile.close(); 
    return 0;
}