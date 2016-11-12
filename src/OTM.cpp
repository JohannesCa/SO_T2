/*
 * OTM.cpp
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#include "OTM.h"

OTM::OTM(std::vector<unsigned int> in):
	_faults(0)
{
	this->_n = in[0];
	in.erase(in.begin());

	this->_quadro.clear();
	this->_accessOrder = in;

	this->Process();
}

void OTM::Process(void)
{
	for(unsigned int i = 0; i < this->_accessOrder.size(); ++i){
		if(this->_quadro.size() < this->_n){
			this->_faults++;
			this->_quadro.push_back(this->_accessOrder[i]);

		}else if(!SearchInt(this->_accessOrder[i], &this->_quadro, 0)){
			this->_faults++;

			int swap = this->GetNextLastAccess(i);

			this->_quadro[swap] = this->_accessOrder[i];
		}
	}
}

int OTM::GetNextLastAccess(int index)
{
	int swapIndex = 0;
	unsigned int lastPos = index + 1;

	for(unsigned int i = 0; i < this->_quadro.size(); ++i){
		if(!SearchInt(this->_quadro[i], &this->_accessOrder, index + 1)){
			swapIndex = i;
			break;
		}

		for(unsigned int j = index + 1; j < this->_accessOrder.size(); ++j){
			if(this->_quadro[i] == this->_accessOrder[j]){
				if(lastPos < j){
					lastPos = j;
					swapIndex = i;
				}
				break;
			}
		}
	}

	return swapIndex;
}

void OTM::Print(void)
{
	printf("OTM %i\n", this->_faults);
}

