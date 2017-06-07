/****************************************************
 *
 * Author : Steve (Seunghwa) Song <sshtel@gmail.com>
 *
****************************************************/

#pragma once

#include <stdint.h>


#if 1
typedef float avg_type_t;
#endif
#if 0
typedef double avg_type_t
#endif

static inline avg_type_t recursive_avg(avg_type_t prevAvg, unsigned int count_k, avg_type_t x) {
	avg_type_t alpha = (avg_type_t)(count_k - 1) / (avg_type_t)count_k;
	count_k++;
	return (alpha * prevAvg) + ( (1-alpha) * x );
}
