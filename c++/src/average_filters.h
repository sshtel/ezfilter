/****************************************************
 *
 * Author : Steve (Seunghwa) Song <sshtel@gmail.com>
 *
****************************************************/
#ifndef __AVERAGE_FILTERS_H
#define __AVERAGE_FILTERS_H

#include "ezfilter.h"

#ifdef USE_DOUBLE_TYPE_FOR_EZFILTER
#define CALC_TYPE double
#else
#define CALC_TYPE float
#endif

//////////////////////////////////// Recursive Average Filter ////////////////////////////////////

/*
example : 
{
	RecursiveAvg<int> avg;
	CALC_TYPE result = (CALC_TYPE) 0.0;
	result = avg.average(10);  // first average : average of [10] = 10
	result = avg.average(20);  // average of [10, 20] = 15
	result = avg.average(40);  // average of [10, 20, 40] = 23.33333...
	result = avg.average(10);  // average of [10, 20, 40, 10] = 20
}
*/


template<typename T>
class RecursiveAvg {
	
public:
	RecursiveAvg() : prevAvg(0.0), count_k(1) { }
private:
	CALC_TYPE prevAvg;
	unsigned int count_k;
public:
	CALC_TYPE average(T x){
		CALC_TYPE alpha = (CALC_TYPE)(count_k - 1) / (CALC_TYPE)count_k;
		prevAvg = alpha*prevAvg + (1-alpha)*x;
		count_k++;
		return prevAvg;
	}

};




#include <deque>

/*
example : 
{
	CALC_TYPE result = (CALC_TYPE) 0.0;
	RecursiveMovAvg<int> movingAvg(5);  //the size of moving average : 5	
	result = movingAvg.average(10);  // first moving average : average of [10, 10, 10, 10, 10] = 10
	result = movingAvg.average(20);  // average of [10, 10, 10, 10, 20] = 12
	result = movingAvg.average(30);  // average of [10, 10, 10, 20, 30] = 16
	result = movingAvg.average(40);  // average of [10, 10, 20, 30, 40] = 22
	result = movingAvg.average(50);  // average of [10, 20, 30, 40, 50] = 30
	result = movingAvg.average(60);  // average of [20, 30, 40, 50, 60] = 40
	result = movingAvg.average(60);  // average of [30, 40, 50, 60, 60] = 48
	result = movingAvg.average(60);  // average of [40, 50, 60, 60, 60] = 54
}
*/

template<typename T>
class RecursiveMovAvg {
	
public:
	RecursiveMovAvg(unsigned int N) : prevAvg(0.0), N(N) { 
		nBuf.clear();
	}
	~RecursiveMovAvg(){
	}
private:
	std::deque <T>nBuf;
	unsigned int N;
	CALC_TYPE prevAvg;

public:
	CALC_TYPE average(T x){
		if(nBuf.empty()){
			for(int i=0; i<N+1; i++) nBuf.push_back(x);
			prevAvg = x;
		}
		else {
			nBuf.pop_front();
			nBuf.push_back(x);
		}
		prevAvg = prevAvg + ( ((CALC_TYPE)nBuf.back() - (CALC_TYPE)nBuf.front()) ) / (CALC_TYPE)N;
		return prevAvg;
	}

};



#endif