#include "Debug.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
bool Debug::drawGizmo = true; 

void Debug::s_WarningLog(std::string message)
{
	SetConsoleTextAttribute(hConsole, LevelWarning);
	std::cout << "[WARNING]: " << message << std::endl;
}

void Debug::s_ErrorLog(std::string message)
{
	SetConsoleTextAttribute(hConsole, LevelError);
	std::cout << "[ERROR]: " << message << std::endl;
}

void Debug::s_InfoLog(std::string message)
{
	SetConsoleTextAttribute(hConsole, LevelInfo);
	std::cout << "[INFO]: " << message << std::endl;
}