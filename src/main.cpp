/*
 * main.cpp
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#include <iostream>

#include <FIFO.h>
#include <OTM.h>
#include <LRU.h>
#include <etc.h>

using namespace std;

int main(int argc, char **argv)
{
	std::vector<unsigned int> pagelist;

	if(argc != 2){
		cerr << ">> Use:\t$ ./so-t2 <file name>\n\n";
		return -1;
	}

	if(!ReadInput(argv[1], &pagelist)){
		cerr << "[ERROR] The file '" << argv[1] << "' doesn't exist!\n";
		return -1;
	}

	FIFO alg1(pagelist);
	OTM alg2(pagelist);
	LRU alg3(pagelist);

	alg1.Print();
	alg2.Print();
	alg3.Print();


/* **************   Testing   **************
	{
		ReadInput("inputs/teste1", &pagelist);

		FIFO alg1(pagelist);
		alg1.Print();
	}

	{
		ReadInput("inputs/teste2", &pagelist);

		FIFO alg1(pagelist);
		alg1.Print();
	}

	{
		ReadInput("inputs/teste1", &pagelist);

		OTM alg1(pagelist);
		alg1.Print();
	}

	{
		ReadInput("inputs/teste2", &pagelist);

		OTM alg1(pagelist);
		alg1.Print();
	}

	{
		ReadInput("inputs/teste1", &pagelist);

		LRU alg1(pagelist);
		alg1.Print();
	}

	{
		ReadInput("inputs/teste2", &pagelist);

		LRU alg1(pagelist);
		alg1.Print();
	}

* ***************************************** */

	return 0;
}

