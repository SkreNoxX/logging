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

static enum Target : short {
	LOGE_CONSOLE = 1,
	LOGE_FILE = 2,
	LOGE_CONSOLE_AND_FILE = 3
};

class Logger {
public:
	Logger();
	Logger(Level);
	Logger(Level level, Target target);
	void setLevel(Level);
	Level getLevel() const;
	void setTarget(Target);
	void write(Level level, const string message);
	void changeFileLogeName(string);
private:
	Level level = ERROR_LEVEL;
	string logeFileName = "data.log";
	Target target = LOGE_CONSOLE;
};