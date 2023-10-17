#include <iostream>
#include <array>
#include <Windows.h>
#include <cstdlib>
#include "Logger.h"

#include <fstream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    Logger logger(Level::ERROR_LEVEL);

    int choice;
    while (true) {
        cout << "Выберите место вывода логов:\n(1)Консоль\n(2)Файл\n(3)Консоль и файл" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            logger.LogeInConsole("User logged in");
            logger.LogeInConsole("User logged in");
            logger.LogeInConsole("User logged in");
            break;
        case 2:
            logger.LogInFile("Сохранение данных в файл", "data.log");
            logger.LogInFile("Сохранение данных в файл", "data.log");
            logger.LogInFile("Сохранение данных в файл", "data.log");
            break;
        case 3:
            logger.LogeInConsoleAndFile("Сохранение в консоль и в файл", "data.log");
            break;
        }
    }
}