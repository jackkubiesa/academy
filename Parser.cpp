// Parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>


struct fileData
{
	char* name;
	char file_size;
	char no_of_lines;
};


std::string read_file(char *filename)
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
		return(contents);
	}
	throw(errno);
}


class Parser
{
	char* Config_File = "c:\Parser\config.txt";
public:
	Parser();
	~Parser();
	bool enabled;
	fileData* file_metadata;
	Parser operator=(const Parser& other);

private:
	std::string folderLocation;
	char files_per_run;
	int warning_level;
	
};

Parser::Parser() :files_per_run(char(2)), file_metadata(new fileData())
{
	throw(20);
	//read_file(Config_File); //uncomment
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

Parser Parser::operator=(const Parser& other)
{
	file_metadata = other.file_metadata;
	return *this;
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

		printf("input is wrong length\n");
	}

	//gets(input); //uncomment
	std::cin >> input; //delete

	// if (strcmp_pass == strcmp(start, input)) //uncomment
	{
		char filename[32];
		

		std::cout << "give name of file to parse:  ";
		std::cin >> filename; //comment
		// gets(filename); //uncomment
		std::cout << filename <<"\n";
		
		Parser new_parser;
		new_parser.enabled = true;
		new_parser.file_metadata->file_size = (char)GetFileSize(filename);
		
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
	//just return an acceptable lenght for now
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
