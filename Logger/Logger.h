#pragma once
#include <iostream>
#include <Windows.h>
#include <array>
#include <random>
#include <cstdlib>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

static enum Level {
	TRACE_LEVEL,
	DEBUG_LEVEL,
	INFO_LEVEL,
	WARNING_LEVEL,
	ERROR_LEVEL
};

class Logger {
public:
	Logger();
	Logger(Level levelError) { level = levelError; }
	void setLevel(Level levelError) { level = levelError; }
	Level getLevel() const { return level; }

	void printEndlessLogger() { // доделать
		srand((unsigned)time(0));
		while (true) {
			switch (rand() % (level + 1)) {
				case 0:
					cout << "TRACE\n";
					break;
				case 1:
					cout << "DEBUG\n";
					break;
				case 2:
					cout << "INFO\n";
					break;
				case 3:
					cout << "WARNING\n";
					break;
				case 4:
					cout << "ERROR\n";
					break;
			}
		}
	}
	void LogeInConsole(string message) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		SYSTEMTIME sysTime;
		GetLocalTime(&sysTime);
		srand((unsigned)time(0));
		switch (rand() % (level + 1)) {
			case 0:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay 
					<< " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "<< "TRACE -> " << message << endl;
				break;
			case 1:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "DEBUG -> " << message << endl;
				break;
			case 2:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "INFO -> " << message << endl;
				break;
			case 3:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "WARNING -> " << message << endl;
				break;
			case 4:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "ERROR -> " << message << endl;
				break;
		}
	}
	void LogInFile(string message, string pathOfFile) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		SYSTEMTIME sysTime;
		GetLocalTime(&sysTime);
		srand((unsigned)time(0));

		ofstream fout;
		fout.open(pathOfFile, fstream::app);

		if (fout.is_open()) {
			switch (rand() % (level + 1)) {
				case 0:
					fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
						<< "TRACE -> " << message << "\n";
					break;
				case 1:
					fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
						<< "DEBUG -> " << message << "\n";
					break;
				case 2:
					fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
						<< "INFO -> " << message << "\n";
					break;
				case 3:
					fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
						<< "WARNING -> " << message << "\n";
					break;
				case 4:
					fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
						<< "ERROR -> " << message << "\n";
					break;
			}
		}
		else {
			cout << "Ошибка с файлом лога";
		}
		fout.close();
	}
	void LogeInConsoleAndFile(string message, string pathOfFile) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		SYSTEMTIME sysTime;
		GetLocalTime(&sysTime);
		srand((unsigned)time(0));

		ofstream fout;
		fout.open(pathOfFile, fstream::app);

		if (fout.is_open()) {
			switch (rand() % (level + 1)) {
			case 0:
				fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "TRACE -> " << message << "\n";
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "TRACE -> " << message << "\n";
				break;
			case 1:
				fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "DEBUG -> " << message << "\n";
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "DEBUG -> " << message << "\n";
				break;
			case 2:
				fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "INFO -> " << message << "\n";
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "INFO -> " << message << "\n";
				break;
			case 3:
				fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "WARNING -> " << message << "\n";
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "WARNING -> " << message << "\n";
				break;
			case 4:
				fout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "ERROR -> " << message << "\n";
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay << " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | "
					<< "ERROR -> " << message << "\n";
				break;
			}
		}
		else {
			cout << "Ошибка с файлом лога";
		}
		fout.close();
	}
private:
	Level level;
};
