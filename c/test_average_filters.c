#include <stdio.h>
#include "average_filters.h"

void test_average() {
	avg_type_t prevAvg = 0.0f;
	avg_type_t x = 0.0f;
	int count = 0;
	
	x = 10.0f; count = 1;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

	x = 20.0f; count = 2;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

	x = 30.0f; count = 3;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

	x = 40.0f; count = 4;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

	x = 50.0f; count = 5;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

	x = -35.32f; count = 6;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

	x = 32.35f; count = 7;
	prevAvg = recursive_avg(prevAvg, count, x) ;
	printf(" cnt:%d x:%f  -> avg:%f \n", count, x, prevAvg);

}

int main() {
	test_average();
	return 0;
}
