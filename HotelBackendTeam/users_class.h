#ifndef user_class
#define user_class

#include "lib.h"

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
			cout << "DEBUG: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}

	static void info(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _info);
			cout << "INFO: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
	static void error(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _error);
			cout << "ERROR: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}
	}
	static void warning(string message)
	{
		if (is_print_logs)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, _warning);
			cout << "WARNING: " << message << endl;
			SetConsoleTextAttribute(hConsole, _default);
		}

	}
};


class User {

private:
    string name;
    string surname;
    string phone_number;

public:
    User() = default;
	User(string name, string surname, string phone_number)
		: name(name), surname(surname), phone_number(phone_number) {
		Logger::debug("New user created with custom parameters");
	}

    virtual void printInfo() const = 0;

    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getPhoneNumber() const { return phone_number; }

    void setName(const string& name) { this->name = name; }
    void setSurname(const string& surname) { this->surname = surname; }
    void setPhoneNumber(const string& phone_number) { this->phone_number = phone_number; }

    virtual ~User() = default;
};

class Guest : public User {
private:
    int flat_number;
    int floor;

public:
    Guest(string name, string surname, string phone_number, int flat_number, int floor)
        : User(name, surname, phone_number), flat_number(flat_number), floor(floor) {
		Logger::debug("New guest user created with custom parameters");
	}

    int getFlatNumber() const { return flat_number; }
    int getFloor() const { return floor; }

    void printInfo() const override {
		Logger::info("Guest object info printed in console");
        cout << "Guest: " << getName() << " " << getSurname()
            << ", Phone: " << getPhoneNumber()
            << ", Flat number: " << flat_number
            << ", Floor: " << floor << endl;
    }

    ~Guest() override = default;
};

class Staff : public User {
private:
	string post;
	int work_experience;
	int salary;
public:
	Staff(string name, string surname, string phone_number, string post, int work_experience, int salary)
		: User(name, surname, phone_number), post(post), work_experience(work_experience), salary(salary) {
		Logger::debug("New staff user created with custom parameters");
	}

	string getPost() const { return post; }
	int getWork_experience() const { return work_experience; }
	int getSalary() const { return salary; }

	void printInfo() const override {
		Logger::info("Staff object info printed in console");
		cout << "Staff: " << getName() << " " << getSurname()
			<< ", Phone: " << getPhoneNumber()
			<< ", Post: " << post
			<< ", Work experience: " << work_experience << " years"
			<< ", Salary: " << salary << " $" << endl;
	}

	~Staff() override = default;
};

#endif