#ifndef __LOW_PASS_FILTER_H
#define __LOW_PASS_FILTER_H

#include "ezfilter.h"

#ifdef USE_DOUBLE_TYPE_FOR_EZFILTER
#define CALC_TYPE double
#else
#define CALC_TYPE float
#endif


template<typename T>
class LPF {

private:
	bool isFirst;

private:
	CALC_TYPE prevX;
	CALC_TYPE alpha;
public:
	LPF(CALC_TYPE alpha) : prevX(0.0), isFirst(true) { 
		setAlpha(alpha);	
	}
	void setAlpha(CALC_TYPE alpha) { 
		if(alpha <= 0) { alpha = 0.1; }
		else if(alpha >= 1) { alpha = 0.9; }
		else { this->alpha = alpha; }
	}
	CALC_TYPE get(T x){
		if(isFirst){ prevX = (CALC_TYPE) x; isFirst = false; }
		prevX = (alpha * prevX) + ( ((CALC_TYPE)1.0 - alpha) * (CALC_TYPE)x );
		return prevX;
	}

};

#endif