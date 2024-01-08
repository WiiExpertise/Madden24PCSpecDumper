#include <iostream>

int main()
{
	// Starting prompt and waiting for user to continue
	std::cout << "This program will dump some of your key PC specs for running Madden 24 to a text file that can be shared.\n\nPress enter to begin the dumping process.";
	std::cin.get();
	std::cout << std::endl;

	// Dump command output to temporary file to be scrubbed afterwards
	std::cout << "Dumping general system info..." << std::endl << std::endl;

	system("systeminfo>temp.txt");

	std::cout << "Dumping CPU info..." << std::endl << std::endl;

	system("echo: >> temp.txt");
	system("echo CPU INFO>>temp.txt");
	system("wmic cpu get caption, deviceid, name, numberofcores, maxclockspeed, status |more>>temp.txt");

	std::cout << "Dumping graphics card info..." << std::endl << std::endl;

	system("echo: >> temp.txt");
	system("echo GPU INFO>>temp.txt");
	system("wmic path win32_VideoController get name |more>>temp.txt");

	std::cout << "Dumping memory info..." << std::endl << std::endl;

	system("echo: >> temp.txt");
	system("echo RAM INFO>>temp.txt");
	system("wmic memorychip get speed |more>>temp.txt");

	// Scrub unneeded lines and dump to final file
	std::cout << "Scrubbing unwanted info..." << std::endl << std::endl;

	system("findstr /V /C:\"Host Name\" /C:\"Registered Owner\" /C:\"Registered Organization\" /C:\"Product ID\" /C:\"Domain\" /C:\"Logon Server\" /C:\"192.168\" /C:\"IP address\" /C:\"Hyper-V\" /C:\"::\" /C:\"Locale\" /C:\"Time Zone\" /C:\"Hotfix\" /C:\"KB\" /C:\"Virtual Memory\" /C:\"OS Manufacturer\" /C:\"OS Configuration\" /C:\"OS Build Type\" temp.txt >YourPCSpecs.txt");

	// Delete temporary file
	std::cout << "Cleaning up..." << std::endl << std::endl;

	system("del /Q temp.txt");

	// Completion message and waiting for user to exit.
	std::cout << "Spec dumping complete! You can find your specs in YourPCSpecs.txt, located in the same folder as this exe. Press enter to exit.";
	std::cin.get();

	return 0;
}