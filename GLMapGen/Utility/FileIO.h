#pragma once
#include <string>
class FileIO
{
public:
	FileIO();
	~FileIO();
	static std::string ReadTextFile(std::string filename);
};

