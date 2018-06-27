#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "create.hpp"
#include "extract.hpp"
#include <stdio.h>
#include <string.h>

using namespace std;

void version()
{
	cout << "bsdtar 2.8.3 - libarchive 2.8.3" << endl;
}
void help()
{
	cout << "tar(bsdtar): manipulate archive files" << endl;
}
void missing()
{
	 cout <<"tar: Must specify one of -c, -r, -t, -u, -x"<<endl;
}
int main (int argc, char *argv[])
{

if (argc >1) {
	int extract_bool = 0;
	int create_bool = 0;
	int i = 1;
	int wait_f_ex = 0;
	int wait_f_creat = 0;
	while (i<argc && argv[i][0] == '-')
	{
		if (!strcmp(argv[i], "--version")) 
		{
			version();
		}
		else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-?")) 
		{
			help();
		}
		else if (!strcmp(argv[i], "-xf"))
		{
			extract_bool = 1;
		}
		else if	(!strcmp(argv[i], "--extract") || !strcmp(argv[i], "-x") || !strcmp(argv[i], "--get"))
		{
			wait_f_ex = 1;
		}

		else if (!strcmp(argv[i], "-cf"))
		{
			create_bool = 1;	
		}
		else if(!strcmp(argv[i], "--create") || !strcmp(argv[i], "-c"))
		{
			wait_f_creat = 1;
		}
		else if (!strcmp(argv[i], "-f"))
		{
			if(wait_f_ex)
			{
				extract_bool = 1;
			}
			else if (wait_f_creat)
			{
				create_bool = 1;
			}
		}
		else 
		{
			missing();
		}
		++i;
	}
	if (i<argc)
	{
		if(extract_bool)
		{
			extract(argc, argv, i);
		}
		else if (create_bool)
			create(argc, argv, i);
	}
}
return 0;
}
