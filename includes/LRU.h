/*
 * LRU.h
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#ifndef LRU_H_
#define LRU_H_

#include "etc.h"

class LRU {
private:
	unsigned int _n;
	int _faults;
	std::vector<unsigned int> _accessOrder;
	std::vector<unsigned int> _quadro;
	void SearchAndUpdate(unsigned int page);
	void Process(void);

public:
	LRU(std::vector<unsigned int> in);
	void Print(void);
	int getFaults(void){return this->_faults;};
};

#endif /* LRU_H_ */
