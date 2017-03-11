#include <iostream>

enum ParseResult
{
    SUCCESS = 0,
    ERROR_OPENING_FILE = -1,
    ERROR_READING_FILE = -2,
    ERROR_PARSING_FILE = -3	
};

ParseResult parse_filecontents()
{
    if (!openfile())
	{
		return ERROR_OPRNING_FILE;	
	}

	if (!readfile())
	{
	    return ERROR_READING_FILE;
	}

	if(!parsefile())
	{
	    return ERROR_PARSING_FILE;
	}
}
