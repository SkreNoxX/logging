#include <iostream>
#include <array>
#include "Logger.h"
using namespace std;


int main()
{
    Logger logger(Level::ERROR);
    logger.printEndlessLogger();
}