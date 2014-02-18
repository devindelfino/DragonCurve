// dragonCurve.cpp

#include "dragonCurve.h"

dragonCurve::dragonCurve()
{
	numPoints = 0;
	pivotX = 0;
	pivotY = 0;
	full = false;
}

dragonCurve::~dragonCurve()
{
	//
}

void dragonCurve::append(float newX,float newY,char color,short shade)
{
	x[numPoints] = newX;
	y[numPoints] = newY;
	pivotX = numPoints;
	pivotY = numPoints;
	colors[numPoints] = color;
	shades[numPoints] = shade;
	numPoints++;
}

void dragonCurve::rotate(char color, short shade)
{
	
	long j = pivotX-1;
	long pivXtemp = pivotX;
	long pivYtemp = pivotY;
	short newX,newY,newXr,newYr;
	short angle = 90;
	double PI = 3.14159265358979323846;
	while(j >= 0 && !full)
	{
		newX = getX(PI/2,x[j],y[j],x[pivXtemp], y[pivYtemp]);
		newY = getY(PI/2,x[j],y[j],x[pivXtemp], y[pivYtemp]);
		cout << numPoints << endl;
		if(numPoints < MAX)
		{
			append(newX,newY,color,shade);
			j--;
		}
		else
		{
			cout << "\n\nLIMIT REACHED! PLEASE START A NEW FRACTAL...\n"<< endl;
			full = true;
		}
	}
}

void dragonCurve::reset()
{
	numPoints = 0;
	full = false;
}

void dragonCurve::print()
{
	glBegin(GL_LINE_STRIP);
	   for(int i=0;i<numPoints;i++)
		{
		   	if(colors[i]=='r')
			{
				redScheme(shades[i]);
			}
			else if(colors[i] == 'g')
			{
				greenScheme(shades[i]);
			}
			else if(colors[i] == 'b')
			{
				blueScheme(shades[i]);
			}

		    glVertex2f(x[i],y[i]);
	   }
	glEnd();
}

// external functions ----------------------------------------------------------------------------

float getX(double Q,float X,float Y, float pivX, float pivY)
{
	float negpivX = 0-pivX;


	return (X*cos(Q)) - (Y*sin(Q)) - (pivX*cos(Q)) + (pivY*sin(Q)) + pivX;
}

float getY(double Q,float X,float Y, float pivX, float pivY)
{
	float negpivX = 0-pivX;
	float negpivY = 0-pivY;


	return (X*sin(Q)) + (Y*cos(Q)) - (pivX*sin(Q)) - (pivY*cos(Q)) + pivY;
}

void redScheme(int point)
{
	if(point%4==0)
	{
		glColor3f(1.0,0.0,0.0);
	}
	else if(point%4==1)
	{
		glColor3f(0.698,0.0,0.0);
	}
	else if(point%4==2)
	{
		glColor3f(0.996, 0.749, 0.749);
	}
	else //point%4==3
	{
		glColor3f(0.996, 0.502, 0.502);
	}
}

void greenScheme(int point)
{
	if(point%4==0)
	{
		glColor3f(0.149, 0.416, 0.18);
	}
	else if(point%4==1)
	{
		glColor3f(0.106, 0.29, 0.125);
	}
	else if(point%4==2)
	{
		glColor3f(0.839, 0.996, 0.859);
	}
	else //point%4==3
	{
		glColor3f(0.678, 0.996, 0.718);
	}
}

void blueScheme(int colorCount)
{
	if(colorCount%4==0)
	{
		glColor3f(0.098, 0.098, 0.702);
	}
	else if(colorCount%4==1)
	{
		glColor3f(0.071, 0.071, 0.49);
	}
	else if(colorCount%4==2)
	{
		glColor3f(0.784, 0.784, 0.996);
	}
	else //colorCount%4==3
	{
		glColor3f(0.569, 0.569, 0.996);
	}
}
