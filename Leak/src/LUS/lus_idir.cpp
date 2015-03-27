#include "lus_internal_dir.h"

#include <fstream>
#include <cstdio>

#ifndef _LUS_WIN32
	#ifdef _DIRENT_HAVE_D_RECLEN
			#define _LUS_RECLEN dirp->d_reclen
	#else
			#define _LUS_RECLEN "Unknown"
	#endif
#endif

using namespace LUS_Constant

std::string correctSeperator(std::string directory)
{
	if(dir_sep != def_dir_sep)
	{
		int loc = directory.find(def_dir_sep) ;
		while(loc != std::string::npos)
		{
			directory[loc] = dir_sep;
			loc = directory.find(def_dir_sep);
		}
	}
	return directory;
}

std::vector<std::string> getFileNames(std::string directory)
{
	std::vector<std::string> result;
	directory += dir_sep+'*';
	#if _LUS_WIN32
		WIN32_FIND_DATA ffd;
		HANDLE hnd =  INVALID_HANDLE_VALUE;
		LARGE_INTEGER filesize;
		
		hnd = FindFirstFile(directory, &ffd);
		if(hnd == INVALID_HANDLE_VALUE)
		{
			throw Exception("Win32 File Search Failed for:\n"+directory);
		}
		
		do
		{
			if(!ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				filesize.LowPart = ffd.nFileSizeLow;
				filesize.HighPart = ffd.nFileSizeHigh;
				result.push_back(ffd.cFileName+"\nSpace:"+filesize.QuadPart);
			}
		}
		while(FindNextFile(hnd, &ffd) != 0);
		
		if(getLastError() != ERROR_NO_MORE_FILES)
		{
			throw Exception("Win32 Unknown File Search Failure for:\n"+directory);
		}
		
		FindClose(hnd);
	#else	
		DIR* dp;
		struct dirent *dirp;
		if((dp  = opendir(directory.c_str())) == NULL)
		{
			throw Exception("Linux File Search Failed for:\n"+directory);
		}
		while ((dirp = readdir(dp)) != NULL) {
			if(dirp->d_name[0] != '.')
				result.push_back(dirp->d_name+"\nSpace:"+dirp->d_reclen);
		}
		closedir(dp);
	#endif
	
	return result;
}

std::vecort<std::string> getDirectoryNames(std::string directory)
{
	std::vector<std::string> result;
	directory += dir_sep+'*';
	#ifdef _LUS_WIN32
		WIN32_FIND_DATA ffd;
		HANDLE hnd =  INVALID_HANDLE_VALUE;
		
		hnd = FindFirstFile(directory, &ffd);
		if(hnd == INVALID_HANDLE_VALUE)
		{
			throw Exception("Win32 Directory Search Failed for:\n"+directory);
		}
		
		do
		{
			if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				result.push_back(ffd.cFileName);
			}
		}
		while(FindNextFile(hnd, &ffd) != 0);
		
		if(getLastError() != ERROR_NO_MORE_FILES)
		{
			throw Exception("Win32 Unknown Directory Search Failure for:\n"+directory);
		}
		
		FindClose(hnd);
	#else	
		DIR* dp;
		struct dirent *dirp;
		if((dp  = opendir(directory.c_str())) == NULL)
		{
			throw Exception("Linux File Search Failed for:\n"+directory);
		}
		while ((dirp = readdir(dp)) != NULL) {
			if(dirp->d_name[0] == '.')
			{
				dirp->d_name[0] = ' ';
				result.push_back(dirp->d_name);
			}
		}
		closedir(dp);
	#endif
	
	return result;
}

std::string getAbsDirectory()
{
	std::string result;
	#ifdef _LUS_WIN32
		LPTSTR str;
		GetCurrentDirectory(&str, MAX_PATH);
		result = str;
	#else
		result = get_current_dir_name();
	#endif
	return result;
}

std::string setCurDirectory(std::string dir)
{
	std::string prevDir = getAbsDirectory();
	#ifdef _LUS_WIN32
		SetCurrentDirectory(dir);
	#else
		
	#endif
	return prevDir;
}

std::string reportNextDirectory(std::string dir, char sep = dir_sep)
{
	int loc = dir.find(sep);
	int length = dir.find(sep, loc)-loc;
	return dir.substr(loc, length);
}

std::string reportDirectory(std::string dir, char sep = dir_sep)
{
	int loc = dir.find(sep);
	return dir.substr(loc);
}

bool createDirectory(std::string dir)
{
	int loc = dir.find(dir_sep);
	std::string tempDir = reportDirectory(dir);
	std::string baseDir = getAbsDirectory();
		
	while(loc != std::string::npos)
	{
		#ifdef _LUS_WIN32
		CreateDirectory(reportNextDirectory(tempDir).c_str());
		setCurDirectory(getAbsDirectory()+dir_sep+tempDir);
		#else
		mkdir(reportNextDirectory(tempDir).c_str());
		chdir(getAbsDirectory()+dir_sep+tempDir);
		#endif
		
		createDirectory(tempDir);
		loc = dir.find(dir_sep);
	}
	
	setCurDirectory(baseDir);
	return true;
}

bool removeDirectory(std::string dir)
{
	//TODO: Actual care to implement portable directory remove code
	#ifdef _LUS_WIN32
	#else
	#endif
	return false;
}

bool pushInDir(std::string dir, std::string name, _IFileData data, bool bin)
{
	fstream fstrm(dir+dir_sep+name, bin?std::ios::out|std::ios::binary:std::ios::out);
	fstrm << data.fileData;
	fstrm.close();
	return true;
}

bool removeFromDir(std::string dir, std::string name)
{
	return std::remove(dir+dir_sep+name.c_str())==0;
}