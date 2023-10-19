#include <iostream>
#include <array>
#include <Windows.h>
#include <cstdlib>
#include "Logger.h"

#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    Logger logger(Level::ERROR_LEVEL);
    int choice = 0;
    string nameOfFileLoge = "data.log";
    while (choice != 2) {
        string choiceInput;
        string name;
        cout << "Хотите ли вы изменить название файла лога? \n(1)Да\n(2)Нет\n";
        cin >> choiceInput;
        try {
            choice = stoi(choiceInput);
            if (choice == 1) {
                bool isCorrectFileName = false;
                cout << "Введите новое название файла:\n";
                cin >> name;
                while (!isCorrectFileName) {
                    if (strlen(name.c_str()) < 5) {
                        cout << "Слишком короткое название:\n";
                        cin >> name;
                    }
                    else if (name[strlen(name.c_str())] != 'g' && name[strlen(name.c_str() - 1)] != 'o' && name[strlen(name.c_str() - 2)] != 'l' && name[strlen(name.c_str() - 3)] != '.') {
                        cout << "Необходимо указать имя файла c форматом (.log)\n";
                        cin >> name;
                    }
                    else {
                        isCorrectFileName = true;
                    }
                }
                const char* oldName = nameOfFileLoge.c_str();
                const char* newName = name.c_str();

                rename(oldName, newName);
                nameOfFileLoge = newName;
                choice = 2;
            }
            else if (choice == 2)
            {
                cout << "Название файла не изменено" << endl;
            }
            else {
                cout << "Введите значение от 1 до 2\n";
            }
        }
        catch (invalid_argument) {
            cout << "Необходимо вводить только цифры\n";
        }
        catch (out_of_range) {
            cout << "Введите значение от 1 до 2\n";
        }
    }
    choice = 0;

    while (choice != 1 && choice != 2 && choice != 3) {
        string choiceInput;
        cout << "Выберите место вывода логов:\n(1)Консоль\n(2)Файл\n(3)Консоль и файл" << endl;
        cin >> choiceInput;
        try {
            choice = stoi(choiceInput);

            switch (choice) {
                case 1:
                    logger.LogeInConsole("User logged in");
                    logger.LogeInConsole("User logged in");
                    logger.LogeInConsole("User logged in");
                    break;
                case 2:
                    logger.LogInFile("Сохранение данных в файл", nameOfFileLoge);
                    logger.LogInFile("Сохранение данных в файл", nameOfFileLoge);
                    logger.LogInFile("Сохранение данных в файл", nameOfFileLoge);
                    break;
                case 3:
                    logger.LogeInConsoleAndFile("Сохранение в консоль и в файл", nameOfFileLoge);
                    break;
            }
        }
        catch (invalid_argument) {
            cout << "Необходимо вводить только цифры\n";
        }
        catch (out_of_range) {
            cout << "Введите значение от 1 до 2\n";
        }
    }
}