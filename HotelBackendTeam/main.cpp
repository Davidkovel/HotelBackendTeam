#include "domain.h"

int main()
{
	Guest guest("John", "Doe", "+380230123", 20, 1);
	Staff staff("John", "Doe", "+380230123", "Manager", 20, 2000);
	guest.printInfo();
	staff.printInfo();
	cout << "[DEBUG] Test run" << endl;
	return 0;
}