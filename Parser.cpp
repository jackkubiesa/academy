#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

bool PrintTime();
uint16_t GetFileSize(char* filename);
std::string ReadFile(const char *filename);

struct fileData
{
	char* name;
	char file_size;
	char no_of_lines;
};


class Parser
{
	char* Config_File = "c:\Parser\config.txt";
public:
	Parser();

	Parser(fileData* file_metadata);

	~Parser();
	bool enabled;
	fileData* file_metadata;
	Parser operator=(Parser& other);
	void ParseFile();

private:
	std::string folderLocation;
	char files_per_run;
	int warning_level;

};

Parser::Parser() :files_per_run(char(2)), file_metadata(new fileData())
{
}

Parser::Parser(fileData* file_metadata) : Parser()
{
	this->file_metadata = file_metadata;
}

Parser::~Parser()
{
	//check if temp file was deleted
	std::ifstream file("temp.txt", std::ios::in);
	if (!file)
	{
		throw("temp file not deleted");
	}
}

Parser Parser::operator=(Parser& other)
{
	other.file_metadata = file_metadata;
	return other;
}

void Parser::ParseFile()
{
	std::cout << "parsing file\n";
	ReadFile(file_metadata->name);
	std::cout << "file " << file_metadata->name << "has been parsed!\n";
}



int main()
{
	std::string end = "\0";
	char input[6];
	char start[] = "start";
	int sizeof_start = sizeof(start);
	bool strcmp_pass = true;
	fileData* file_metadata = new fileData();

	PrintTime();
	std::cout << "welcome to the dirty word checker\n";
	std::cout << "type start to start the parsing\n";
	if (input[sizeof_start] != '\0')
	{
		std::cout << "input is wrong length\n";
	}

	std::cin >> input;

	if (strcmp_pass == strcmp(start, input))
	{
		char filename[32];


		std::cout << "give name of file to parse:  ";
		std::cout << filename << "\n";

		Parser new_parser(file_metadata);
		new_parser.enabled = true;
		new_parser.file_metadata->file_size = GetFileSize(filename);
		new_parser.ParseFile();
		// more awsome code yet to come

	}
	if (strcmp_pass == 0)
	{
		std::cout << "wrong command given: now exiting\n";
	}

	std::system("pause");
	return 0;
}

uint16_t GetFileSize(char* filename)
{
	//code to be completed
	//just return an acceptable length for now
	return UINT16_MAX;
}

bool PrintTime()
{
	time_t raw_time;
	struct tm * time_info;

	time(&raw_time);
	time_info = localtime(&raw_time);
	std::cout << "Current local time and date: " << asctime(time_info);
	return true;
}

std::string ReadFile(const char *filename)
{
	std::ifstream file(filename, std::ios::in);
	if (file)
	{
		std::string contents;
		file.seekg(0, std::ios::end);
		contents.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&contents[0], contents.size());
		file.close();
		std::cout << contents;
		return contents;
	}
	throw(errno);
}
