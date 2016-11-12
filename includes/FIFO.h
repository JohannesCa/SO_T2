/*
 * FIFO.h
 *
 *  Created on: 5 de nov de 2016
 *      Author: johannes
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <etc.h>

class FIFO {
private:
	unsigned int _n;
	int _faults;
	std::vector<unsigned int> _accessOrder;
	std::vector<unsigned int> _quadro;
	void Process(void);

public:
	FIFO(std::vector<unsigned int> in);
	void Print(void);
	int getFaults(void){return this->_faults;};
};

#endif /* FIFO_H_ */
