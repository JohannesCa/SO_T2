/*
 * LRU.cpp
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#include "LRU.h"

LRU::LRU(std::vector<unsigned int> in):
	_faults(0)
{
	this->_n = in[0];
	in.erase(in.begin());

	this->_quadro.clear();
	this->_accessOrder = in;

	this->Process();
}

void LRU::Process(void)
{
	for(unsigned int i = 0; i < this->_accessOrder.size(); ++i){
		if(this->_quadro.size() < this->_n){
			this->_faults++;
			this->_quadro.push_back(this->_accessOrder[i]);

		}else if(!SearchInt(this->_accessOrder[i], &this->_quadro, 0)){
			this->_faults++;

			this->_quadro.push_back(this->_accessOrder[i]);
			this->_quadro.erase(this->_quadro.begin());
		}else
			this->SearchAndUpdate(this->_accessOrder[i]);
	}
}

void LRU::SearchAndUpdate(unsigned int page)
{
	for(std::vector<unsigned int>::iterator it = this->_quadro.begin(); it != this->_quadro.end(); ++it){
		if(*it == page){
			int aux = *it;
			this->_quadro.erase(it);
			this->_quadro.push_back(aux);
			break;
		}
	}
}

void LRU::Print(void)
{
	printf("LRU %i\n", this->_faults);
}
