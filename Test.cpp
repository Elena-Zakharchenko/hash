#include "pch.h"
#include <iostream>
#include "storage.h"


int main()
{
	Repository r;
	r.readfile("listofbooks.txt");
	r.insert("Apple");
	r.find("Apple");
	r.destroy("War and Peace");
	r.find("War and Peace");
	system("pause");
	return 0;
}
