#include <iostream>

int main()
{
	// Starting prompt and waiting for user to continue
	std::cout << "This program will dump some of your key PC specs for running Madden 24 to a text file that can be shared.\n\nPress enter to begin the dumping process.";
	std::cin.get();
	std::cout << std::endl;

	std::cout << "Dumping general system info..." << std::endl << std::endl;

	system("systeminfo>YourPCSpecs.txt");

	std::cout << "Dumping CPU info..." << std::endl << std::endl;

	system("echo: >> YourPCSpecs.txt");
	system("echo CPU INFO>>YourPCSpecs.txt");
	system("wmic cpu get caption, deviceid, name, numberofcores, maxclockspeed, status |more>>YourPCSpecs.txt");

	std::cout << "Dumping graphics card info..." << std::endl << std::endl;

	system("echo: >> YourPCSpecs.txt");
	system("echo GPU INFO>>YourPCSpecs.txt");
	system("wmic path win32_VideoController get name |more>>YourPCSpecs.txt");

	std::cout << "Dumping memory info..." << std::endl << std::endl;

	system("echo: >> YourPCSpecs.txt");
	system("echo RAM INFO>>YourPCSpecs.txt");
	system("wmic memorychip get speed |more>>YourPCSpecs.txt");

	// Completion message and waiting for user to exit.
	std::cout << "Spec dumping complete! You can find your specs in YourPCSpecs.txt, located in the same folder as this exe. Press enter to exit.";
	std::cin.get();

	return 0;
}