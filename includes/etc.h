/*
 * etc.h
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#ifndef INCLUDES_ETC_H_
#define INCLUDES_ETC_H_

#include <iostream>
#include <fstream>
#include <vector>


inline bool ReadInput(std::string in, std::vector<unsigned int>* pageList) // Returns false if the input couldn't be read.
{
	std::ifstream input;
	input.open(in.c_str(), std::ios::in);

	if(!input)
		return false;

	pageList->clear();

	std::string line;
	while(getline(input, line))
		pageList->push_back(std::stoi(line));

	return true;
}

inline bool SearchInt(unsigned int value, std::vector<unsigned int> *source, int begin) // Search int 'value' in 'source' from 'begin'
{
	for(unsigned int i = begin; i < source->size(); ++i){
		if(source->at(i) == value)
			return true;
	}

	return false;
}


#endif /* INCLUDES_ETC_H_ */
