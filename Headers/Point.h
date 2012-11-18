#ifndef POINT_H
#define POINT_H
#include "size.h"
struct Point
{
	// USE IT TO ACCESS matrix, matrix[x][y]
	int x;
	int y;

	Point(int a, int b): x(a), y(b){};

	Point(){};

	int toX() {
		return ((x-1)*picW + boardLeftTopX);
	}

	int toY() {
		return ((y-1)*picH + boardLeftTopY);
	}
};

#endif