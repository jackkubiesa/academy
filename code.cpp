// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

const string FOLDER = "c:\test_data";

struct fileData
{
	string name;
	char file_size;
	char no_of_lines;
};


int main()
{
	int DONT_CHANGE = 1;
	bool b = true;

	if (b == 3)
	{
		return DONT_CHANGE;
	}
	return 0;
}

class Parser
{
public:
	~Parser();

private:
	void Parser::openFile(void);

};

Parser::~Parser()
{
}

void Parser::openFile(void)
{
	fileData newFile;
	newFile.name = "test_file.txt";
	newFile.name = 
	uppercase(newFile.name);
}


string uppercase(const string& s)
{
	string result(s.length(), ' ');
	transform(
		s.begin(),
		s.end(),
		result.begin(),
		ptr_fun <int, int>(std::toupper)
		);
	return result;
}
