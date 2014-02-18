// dragonCurve.h

#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

#ifndef dragon
#define dragon

const long MAX = 1050000;
float getX(double,float,float,float,float);
float getY(double,float,float,float,float);
void redScheme(int);
void greenScheme(int);
void blueScheme(int);

class dragonCurve
{
private:;
	long numPoints;
	float x[MAX];
	float y[MAX];
	char colors[MAX];
	short shades[MAX];
	bool full;

	long pivotX;
	long pivotY;
public:
	dragonCurve();
	~dragonCurve();

	void reset();
	void append(float,float,char,short);
	void rotate(char,short);
	void print();
};

#endif