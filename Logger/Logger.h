#pragma once
#include <iostream>
#include <Windows.h>
#include <array>
#include <random>
#include <cstdlib>

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

	void printEndlessLogger() {
		srand((unsigned)time(0));
		int number;
		while (true) {
			switch (number = rand() % (level + 1)) {
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
	void LOGE(string message) {
		SYSTEMTIME time;
		GetLocalTime(&time);
		int number;
		switch (number = rand() % (level + 1)) {
			case 0:
				cout << time.wYear << "-" << time.wMonth << "-" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << " | "
					 << "TRACE -> " << message << endl;
				break;
			case 1:
				cout << time.wYear << "-" << time.wMonth << "-" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << " | "
					<< "DEBUG -> " << message << endl;
				break;
			case 2:
				cout << time.wYear << "-" << time.wMonth << "-" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << " | "
					<< "INFO -> " << message << endl;
				break;
			case 3:
				cout << time.wYear << "-" << time.wMonth << "-" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << " | "
					<< "WARNING -> " << message << endl;
				break;
			case 4:
				cout << time.wYear << "-" << time.wMonth << "-" << time.wDay << " " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << " | "
					<< "ERROR -> " << message << endl;
				break;
		}
	}
private:
	Level level;
};
