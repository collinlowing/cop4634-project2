#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <cstdlib>
#include <iomanip>
#include <mutex>
#include <time.h>



int histogram[550]; // 550 is the max for the histogram
int counter = 2;    // calculations for collatz start at 2

void collatzFunction(int);


int main(int argCount, char** argArr)
{
   // used for execution time
   timespec start, stop;
   double totalExecTime = 0;

   // Guard for no command line arguments
   if (argCount <= 2)
   {
      std::cout << "FATAL ERROR: Not enough commadline arguments, please try again." << std::endl;

      return 1;
   }

   // parses the commandline arguements into strings
   std::string argCommandRangeMax     = argArr[1];
   std::string argCommandThreadCount  = argArr[2];

   // parses the commandline arguements into integer values
   int rangeMax     = stoi(argCommandRangeMax);
   int threadCount  = stoi(argCommandThreadCount);

   // initializes the histogram array to 0
   for (int i = 0; i <= 550; i++)
   {
      histogram[i] = 0;
   }

   // Record start time
   clock_gettime(CLOCK_REALTIME, &start);

   // initializes the threads on the heap
   std::thread *threads = new std::thread[threadCount];

   // Creates the number of threads
   for (int i = 0; i < threadCount; i++)
   {
      threads[i] = std::thread(collatzFunction, rangeMax);
   }


   // joins them back with the main thread
   for (int i = 0; i < threadCount; i++)
   {
      threads[i].join();
   }


   // Record stop time
   clock_gettime(CLOCK_REALTIME, &stop);


    // Prints the histogram
    for(int i = 0; i < 550; i++)
    {
       std::cout << i + 1 << "," << histogram[i] << std::endl;
    }

     //Calculate the difference in time between the start and stop time.
    totalExecTime = (stop.tv_sec - start.tv_sec)
              + ((stop.tv_nsec - start.tv_nsec)*1e-9);

     //Print the execution time of the program.
    std::cerr << rangeMax << ","
              << threadCount << ","
              << std::fixed
              << std::setprecision(9)
              << totalExecTime << std::endl;

    delete [] threads; // deletes memory allocated on the heap; no leaks

    return 0;
}

// Calculates the stopping times for the collatz sequance
void collatzFunction(int range)
{
    std::mutex stopTimeLock;  // used for protecting the
    std::mutex histogramLock; // manipulated shared variables

     while (counter < range)
     {
        unsigned int count = counter; // creates a new counter for manipulation initialized with the global variable.
        int stoppingTime = 0;         // counter for the number of stopping times.

        while (count != 1)
        {
           stopTimeLock.lock();
           stoppingTime++;

           if (count % 2 == 0)    // if even...
           {
              count = count / 2;
           }
           else                   // if odd...
              count = count * 3 + 1;

           stopTimeLock.unlock();

        }

        histogramLock.lock();
        histogram[stoppingTime]++;
        counter++;
        histogramLock.unlock();

      }
}
