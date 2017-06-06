#include <iostream>
#include "..\..\src\ezfilter.h"

int main(){
	std::cout << "recursive filters" << std::endl;


	std::cout << "----- avg sample -----" << std::endl;
	RecursiveAvg<int> avg;
	std::cout << "avg x:10 = " << avg.average(10) << std::endl;// first average : average of [10] = 10
	std::cout << "avg x:20 = " << avg.average(20) << std::endl;// average of [10, 20] = 15
	std::cout << "avg x:40 = " << avg.average(40) << std::endl;// average of [10, 20, 40] = 23.33333...
	std::cout << "avg x:10 = " << avg.average(10) << std::endl;// average of [10, 20, 40, 10] = 20

	std::cout << "-----moving avg sample 1-----" << std::endl;
	RecursiveMovAvg<int> movingAvg(5);  //the size of moving average : 5	
	std::cout << "moving avg x:10 = " << movingAvg.average(10) << std::endl;// first moving average : average of [10, 10, 10, 10, 10] = 10
	std::cout << "moving avg x:20 = " << movingAvg.average(20) << std::endl;// average of [10, 10, 10, 10, 20] = 12
	std::cout << "moving avg x:30 = " << movingAvg.average(30) << std::endl;// average of [10, 10, 10, 20, 30] = 16
	std::cout << "moving avg x:40 = " << movingAvg.average(40) << std::endl;// average of [10, 10, 20, 30, 40] = 22
	std::cout << "moving avg x:50 = " << movingAvg.average(50) << std::endl;// average of [10, 20, 30, 40, 50] = 30
	std::cout << "moving avg x:61 = " << movingAvg.average(61) << std::endl;// average of [20, 30, 40, 50, 61] = 40.2
	std::cout << "moving avg x:55 = " << movingAvg.average(55) << std::endl;// average of [30, 40, 50, 61, 55] = 47.2
	std::cout << "moving avg x:57 = " << movingAvg.average(57) << std::endl;// average of [40, 50, 61, 55, 57] = 52.6

	
	std::cout << "-----moving avg sample 2-----" << std::endl;
	RecursiveMovAvg<float> movingAvg2(4);  //the size of moving average : 4
	std::cout << "moving avg x:10.0 = " << movingAvg2.average(10.0) << std::endl;// first moving average : average of [10.0, 10.0, 10.0, 10.0] = 10.0
	std::cout << "moving avg x:20.5 = " << movingAvg2.average(20.5) << std::endl;// average of [10.0, 10.0, 10.0, 20.5] = 12.625
	std::cout << "moving avg x:30.2 = " << movingAvg2.average(30.2) << std::endl;// average of [10.0, 10.0, 20.5, 30.2] = 17.675
	std::cout << "moving avg x:40.125 = " << movingAvg2.average(40.125) << std::endl;// average of [10.0, 20.5, 30.2, 40.125] = 25.2062
	std::cout << "moving avg x:50.7 = " << movingAvg2.average(50.7) << std::endl;// average of [20.5, 30.2, 40.125, 50.7] = 35.3812


	std::cout << "-----low pass filter sample -----" << std::endl;
	LPF<int> lpf(0.7);
	std::cout << "lpf x:10 = "		<< lpf.get(10) << std::endl;
	std::cout << "lpf x:20 = "		<< lpf.get(20) << std::endl;
	std::cout << "lpf x:80 = "		<< lpf.get(80) << std::endl;
	std::cout << "lpf x:0 = "		<< lpf.get(0) << std::endl;
	std::cout << "lpf x:10 = "		<< lpf.get(10) << std::endl;
	std::cout << "lpf x:20 = "		<< lpf.get(20) << std::endl;
	std::cout << "lpf x:21 = "		<< lpf.get(21) << std::endl;
	std::cout << "lpf x:22 = "		<< lpf.get(22) << std::endl;
	std::cout << "lpf x:17 = "		<< lpf.get(17) << std::endl;
	std::cout << "lpf x:-80 = "		<< lpf.get(-80) << std::endl;
	std::cout << "lpf x:22 = "		<< lpf.get(22) << std::endl;
	std::cout << "lpf x:23 = "		<< lpf.get(23) << std::endl;
	std::cout << "lpf x:20 = "		<< lpf.get(20) << std::endl;
	std::cout << "lpf x:19 = "		<< lpf.get(19) << std::endl;
}

