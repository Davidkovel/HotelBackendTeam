#ifndef LOGGER_H
#define LOGGER_H

#include "library.h"

struct Logger {
	static const bool is_print_logs = 1;
	static const unsigned short _debug = 10;
	static const unsigned short _info = 11;
	static const unsigned short _error = 12;
	static const unsigned short _warning = 14;
	static const unsigned short _default = 7;

	static void debug(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _debug);
			cout << "[DEBUG]: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}

	static void info(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _info);
			cout << "[INFO]: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
	static void error(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _error);
			cout << "[ERROR]: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
	static void warning(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _warning);
			cout << "[WARNING]: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}

	}
};

#endif