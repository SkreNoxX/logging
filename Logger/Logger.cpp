#include "Logger.h"

Logger::Logger() { }
Logger::Logger(Level levelError)
	: level(levelError) {};
Logger::Logger(Level levelError, Target targetError) { level = levelError; target = targetError; }
void Logger::setLevel(Level levelError) { level = levelError; }
Level Logger::getLevel() const { return level; }
void Logger::setTarget(Target targetError) { target = targetError; }

void Logger::changeFileLogeName(const string fileName) {
	if (strlen(fileName.c_str()) < 5) {
		cout << "Слишком короткое название\n";
	}
	else if (fileName[strlen(fileName.c_str()) - 1] != 'g' && fileName[strlen(fileName.c_str() - 2)] != 'o' && fileName[strlen(fileName.c_str() - 3)] != 'l' && fileName[strlen(fileName.c_str() - 4)] != '.') {
		cout << "Необходимо указать имя файла c форматом (.log)\n";
		cout << fileName[strlen(fileName.c_str()) - 1] << endl;
		cout << fileName[strlen(fileName.c_str()) - 2] << endl;
		cout << fileName[strlen(fileName.c_str()) - 3] << endl;
		cout << fileName[strlen(fileName.c_str()) - 4] << endl;
	}
	else {
		logeFileName = fileName;
		cout << "Название файла изменено, новое название файла: " << logeFileName << endl;
	}
}
void Logger::write(Level levelFunc, const string message) {
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	if (target == LOGE_CONSOLE && levelFunc <= level) {
		switch (levelFunc) {
			case 0:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay
					<< " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | " << "TRACE -> " << message << endl;
				break;
			case 1:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay
					<< " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | " << "DEBUG -> " << message << endl;
				break;
			case 2:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay
					<< " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | " << "INFO -> " << message << endl;
				break;
			case 3:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay
					<< " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | " << "WARNING -> " << message << endl;
				break;
			case 4:
				cout << sysTime.wYear << "-" << sysTime.wMonth << "-" << sysTime.wDay
					<< " " << sysTime.wHour << ":" << sysTime.wMinute << ":" << sysTime.wSecond << " | " << "ERROR -> " << message << endl;
				break;
		}
	}
	else if (target == LOGE_FILE) {
		ofstream fout;
		fout.open(logeFileName, fstream::app);

		if (fout.is_open() && levelFunc <= level) {
			switch (levelFunc) {
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
		fout.close();
	}
	else if (target == LOGE_CONSOLE_AND_FILE) {
		ofstream fout;
		fout.open(logeFileName, fstream::app);

		if (fout.is_open() && levelFunc <= level) {
			switch (levelFunc) {
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
		fout.close();
	}
}