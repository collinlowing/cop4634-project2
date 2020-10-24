#include <iostream>
#include <string>
#include <cstring>
#include <pthread.h>
#include <cstdlib>
#include <bits/stdc++.h>

// TODO: Create Threads

int collatzFunction(int);


int main(int argCount, char** argArr)
{
    time_t start, end;
    double runtime;

    time(&start);

    // Guard for no commadline arguments
    if(argCount <= 2)
    {
      std::cout << "FATAL ERROR: Not enough commadline arguments, please try again." << std::endl;

      return 1;
    }


    std::string argCommandRangeMax =      argArr[1];
    std::string argCommandThreadCount =   argArr[2];

    int rangeMax =      stoi(argCommandRangeMax);
    int threadCount =   stoi(argCommandThreadCount);


    collatzFunction(rangeMax);

    //TEST OUTPUT
    std::cout << "collatz number range 2 - " << rangeMax 	<< std::endl;
    std::cout << "active thread count " << threadCount 		<< std::endl
    								<< std::endl;

    // Record stopping time
    time(&end);

    // Output to standard error (stderr) the program runtime
    runtime = double(end - start);
    std::cerr << rangeMax << "," << threadCount << "," << runtime << std::endl;

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

    // TODO: Output results from Collatz Sequence
    // k + ", " + stoppingTime

    return 0;
}
