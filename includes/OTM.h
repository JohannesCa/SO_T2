/*
 * OTM.h
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#ifndef OTM_H_
#define OTM_H_

#include "etc.h"

class OTM {
private:
	unsigned int _n;
	int _faults;
	std::vector<unsigned int> _accessOrder;
	std::vector<unsigned int> _quadro;
	int GetNextLastAccess(int index);
	void Process(void);

public:
	OTM(std::vector<unsigned int> in);
	void Print(void);
	int getFaults(void){return this->_faults;};
};

#endif /* OTM_H_ */
