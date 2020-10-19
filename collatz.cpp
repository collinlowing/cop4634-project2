//Test PUSH
#include<iostream>
#include<string>
#include<cstring>
#include <pthread.h>
#include <cstdlib>
int collatzFunction(int);

int counter = 12;

int main(int argCount, char** argArr)
{
    std::string argCommandRangeMax =            argArr[1];
    std::string argCommandThreadCount =         argArr[2];

    int rangeMax =                              stoi(argCommandRangeMax);
    int threadCount =                           stoi(argCommandThreadCount);


    collatzFunction(counter);

    //TEST OUTPUT
    std::cout << "collatz number range 2 - " << rangeMax << std::endl;
    std::cout << "active thread count " << threadCount << std::endl;
    std::endl;

    return 0;
}

int collatzFunction(int counter)
{
    int stoppingTime = 0;

    while(counter != 1)
    {
        stoppingTime++;
        if(counter % 2 == 0)
        {
            counter = counter/2;
        }
        else
            counter = counter * 3 + 1;
        }
    //TEST OUTPUT BELOW
    std::cout << counter << std::endl;
    std::cout << stoppingTime << std::endl;
}
