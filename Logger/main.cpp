#include <iostream>
#include <array>
#include <Windows.h>
#include <cstdlib>
#include "Logger.h"
using namespace std;


int main()
{
    Logger logger(Level::ERROR_LEVEL);
    logger.LOGE("User logged in");
    logger.LOGE("User logged in");
    logger.LOGE("User logged in");
}