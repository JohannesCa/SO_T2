/*
 * FIFO.cpp
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#include "FIFO.h"

FIFO::FIFO(std::vector<unsigned int> in):
	_faults(0)
{
	this->_n = in[0];
	in.erase(in.begin());

	this->_quadro.clear();
	this->_accessOrder = in;

	this->Process();
}

void FIFO::Process(void)
{
	for(unsigned int i = 0; i < this->_accessOrder.size(); ++i){
		if(this->_quadro.size() < this->_n){
			this->_faults++;
			this->_quadro.push_back(this->_accessOrder[i]);

		}else if(!SearchInt(this->_accessOrder[i], &this->_quadro, 0)){
			this->_faults++;
			this->_quadro.erase(this->_quadro.begin());
			this->_quadro.push_back(this->_accessOrder[i]);
		}
	}
}

void FIFO::Print(void)
{
	printf("FIFO %i\n", this->_faults);
}


