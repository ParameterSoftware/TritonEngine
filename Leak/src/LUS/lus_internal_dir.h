#ifndef  _LUS_I_DIR_H
#define _LUS_I_DIR_H

#include <iostream>
#include <string>
#include <vector>

#include "lus_config.h"

#ifndef _LUS_OS_DEFINED
	#error "OS builder undefined for LUS"
#endif

#ifdef _LUS_WIN32
	#include <windows.h>
#elif _LUS_LINUX
	#include <direct.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

struct _IFileData
{
	char* fileData;
}

namespace LUS_Constant
{
	const char def_dir_sep = '/';
	#ifdef _LUS_WIN32
		const char dir_sep = '\\';
	#else
		const char dir_sep = def_dir_sep;
	#endif
}

std::string correctSeperator(std::string directory);

std::vector<std::string> getFileNames(std::string directory);
std::vecort<std::string> getDirectoryNames(std::string directory);
std::string getAbsDirectory();

bool createDirectory(std::string dir);
bool removeDirectory(std::string dir);

bool pushInDir(std::string dir, std::string name, _IFileData data);
bool removeFromDir(std::string dir, std::string name);

#endif