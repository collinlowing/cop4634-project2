#include <iostream>
#include <string>
#include <cstring>
#include <pthread.h>
#include <cstdlib>

// TODO: Record Runtime
// TODO: Create Threads

int counter = 12;

int collatzFunction(int);


int main(int argCount, char** argArr)
{
  std::cout << "test" << std::endl;
    // Guard for no commadline arguments
    if(argCount <= 2)
    {
      std::cout << "FATAL ERROR: Not enough commadline arguments, please try again." << std::endl;

      return 1;
    }
std::cout << "test" << std::endl;


    std::string argCommandRangeMax =            argArr[1];
    std::string argCommandThreadCount =         argArr[2];

    int rangeMax =                              stoi(argCommandRangeMax);
    int threadCount =                           stoi(argCommandThreadCount);


    collatzFunction(counter);

    //TEST OUTPUT
    std::cout << "collatz number range 2 - " << rangeMax 	<< std::endl;
    std::cout << "active thread count " << threadCount 		<< std::endl
    								<< std::endl;

    // TODO: Print out runtime in stderr output
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
