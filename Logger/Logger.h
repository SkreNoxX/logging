#pragma once
#include <iostream>
#include <array>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

static enum Level {
	TRACE,
	DEBUG,
	INFO,
	WARNING,
	ERROR
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
			number = rand() % 5;
			if (number <= level) {
				switch (number) {
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
	}
private:
	Level level;
};
