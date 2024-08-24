#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>

class Debug
{
public:
	static enum s_LogLevel
	{
		LevelWarning = 4, LevelError = 6, LevelInfo = 15
	};

	static bool drawGizmo; 

public:
	static void s_InfoLog(std::string message);
	static void s_ErrorLog(std::string message);
	static void s_WarningLog(std::string message);
};

