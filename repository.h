#pragma once
#include<iostream>
#include<list>
#include<string>
#include<fstream> // для работы с файлами
#include"Box.h"
#include"hash.h"

struct Repository
{
	std::list<Box>* repository = new std::list<Box>[1000000];
	void insert(std::string nameofbook);
	void destroy(std::string nameofbook);
	void find(std::string nameofbook);
	void readfile(std::string filename);
};


void Repository::insert(std::string nameofbook)
{
	std::string tmp_str = "";
	for (int i = 0; i < 4; i++)
	{
		tmp_str += nameofbook[i];
	}
	int index = (int)abs(generetichash(tmp_str)/1000);
	std::cout << index << std::endl;
	int hash = generetichash(nameofbook);
	Box book(nameofbook);
	repository[index].push_back(book);
}

void Repository::destroy(std::string nameofbook)
{
	std::string tmp_str = "";
	for (int i = 0; i < 4; i++)
	{
		tmp_str += nameofbook[i];
	}
	int index = (int)abs(generetichash(tmp_str) / 1000);
	int hash = generetichash(nameofbook);
	std::list<Box>::iterator it;
	for (it = repository[index].begin(); it != repository[index].end(); it++)
	{
		if (hash == (*it).hash) //(*it) - разименовали итератор и уже работаем с книгой
		{
			repository[index].erase(it);
			break;
		}
	}
}

void Repository::find(std::string nameofbook)
{
	std::string tmp_str = "";
	for (int i = 0; i < 4; i++)
	{
		tmp_str += nameofbook[i];
	}
	int index = (int)abs(generetichash(tmp_str) / 1000);
	int hash = generetichash(nameofbook);
	std::list<Box>::iterator it;
	for (it = repository[index].begin(); it != repository[index].end(); it++)
	{
		if (hash == (*it).hash) //(*it) - разименовали итератор и уже работаем с книгой
		{
			std::cout << "We have this book" << std::endl;
			break; // (*it) - сама книга, &(*it) - ссылка на книгу
		}
	}
}


void Repository::readfile(std::string filename)
{
	std::ifstream tmp_file(filename); //tmp_file промежуточный объект
	std::string tmp_str = "";
	while (tmp_file)
	{
		std::string str;
		std::getline(tmp_file, str);
		if (str != "")
		{
			Repository::insert(str);
		}

	}
}
