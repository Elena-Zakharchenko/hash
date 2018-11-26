#pragma once
#ifndef HASH_H_
#define HASH_H_
#include <string>

std::string itos(int n)
{
	const int max_size = std::numeric_limits<int>::digits10 + 1 /*sign*/ + 1 /*0-terminator*/;
	char buffer[max_size] = { 0 };
	sprintf(buffer, "%d", n);
	return std::string(buffer);
}

std::string generetichash(std::string nameofbook)
{
	std::string hash = "";
	float mark = 0;
	for (int i = 0; i < nameofbook.length(); i++)
	{
		mark = sqrt((int)(nameofbook[i]));
		mark = (int)mark;
		mark = (mark + 56) - (int)(nameofbook[i]) % 10;
		mark = pow((mark), 4);
		hash += itos(mark);

	}

	return hash;

}

#endif
