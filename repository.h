#pragma once
#ifndef REPOSITORY_H_
#define REPOSITORY_H_
#include <string>
#include <cstdlib>
#include <list>
#include "hash.h"


struct Book
{
	std::string name;
};

struct box
{
	std::string hash = "";
	std::list<Book> Box;
};

struct Repository
{
	box repository[2756];

	void createHash();
	void readfile();
	int findBox(std::string nameofbook);
};



void Repository::createHash()
{

	std::string tmp_char_1;
	std::string tmp_char_2;
	std::string tmp_hash_1 = "";
	std::string tmp_hash_2 = "";

	for (int i = 0; i < 52; i++)
	{
		if (i < 26)
		{
			tmp_char_1 = (char)(65 + i);
		}
		else
		{

			tmp_char_1 = (char)(71 + i);
		}

		tmp_hash_1 = generetichash(tmp_char_1);

		for (int j = 0; j < 53; j++)
		{

			if (j < 26)
			{
				tmp_char_2 = (char)(65 + j);
			}
			else if (j == 53)
			{
				tmp_char_2 = (char)(32);


			}
			else
			{

				tmp_char_2 = (char)(71 + j);
			}
			tmp_hash_2 = generetichash(tmp_char_2);

			repository[52 * i + j].hash = tmp_hash_1 + tmp_hash_2;

		}

	}

}


void Repository::readfile()
{


	std::string filename = "listofbooks";

	std::ifstream db(filename);
	std::string tmp_str;
	std::string tmp_hash;
	std::string hash;

	while (db)
	{

		std::string str;
		std::getline(db, str);

		if (str != "")
		{

			tmp_str += str[0];
			tmp_str += str[1];
			tmp_hash = generetichash(tmp_str);
			tmp_str = "";
			hash = generetichash(str);
			for (int i = 0; i < 2704; i++)
			{
				if (tmp_hash == repository[i].hash)
				{
					Book new_book;
					new_book.name = str;
					repository[i].Box.push_back(new_book);
					break;
				}

			}

		}

	}

}

int Repository::findBox(std::string nameofbook)
{
	std::string tmp_hashofbook = "";
	tmp_hashofbook += nameofbook[0];
	tmp_hashofbook += nameofbook[1];
	tmp_hashofbook = generetichash(tmp_hashofbook);
	int index = -1;
	for (int i = 0; i < 2756; i++)
	{
		if (tmp_hashofbook == repository[i].hash)
		{
			index = i;
			return index;
		}

	}

}

#endif
