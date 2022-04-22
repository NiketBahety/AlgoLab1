#include <iostream>
#include <random>
#include <fstream>

using namespace std;
 
int main()
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 200);
    ofstream myFile("dataset1.txt");
 
    for(int i = 0; i<100000; i++)
    myFile << distribution(generator) << "," << " ";

    myFile.close(); 
    return 0;
}