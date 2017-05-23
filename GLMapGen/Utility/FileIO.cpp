#include "stdafx.h"
#include "FileIO.h"
#include <fstream>
#include <streambuf>

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

std::string FileIO::ReadTextFile(std::string filename)
{
	std::ifstream t(filename);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	return str;
}
