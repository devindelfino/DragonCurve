/*
 * Name: Devin Delfino
 *
 * Filename: dragonCurve.h
 *
 * Description: This program displays a Dragon Curve Fractal! Depending on user input (mouse,keyboard)
 *				the fractal is displayed with various line segment lengths and colors. The first left click
 *				will determine the starting position of the fractal, and each subsequent click will display
 *				the next iteration in the fractal. A right click will display a menu including options to
 *				erase/redisplay the fractal, erase and restart a new fractal, choosing a new segment length,
 *				and activating hypnotize mode.
 *
 * Input: This program requires both mouse input and keyboard input from the user. The mouse input
 *		  consists of left button clicks and right button clicks. The right button click will display
 *		  a menu of options to choose from. These options include:
 *			- Erase Fractal: Erases fractal but does not delete it
 *			- Redisplay Fractal: Redisplays the erased fractal
 *			- Erase and Restart: Erases the current fractal and starts a new fractal sequence
 *			- Restart with New Line Segment Length: Changes the line segment length to either 0.25,
 *													0.5, 1 (default), 2, 5, or 10 depending on which
 *													is chosen, then erases and starts a new sequence.
 *			- Hypotize!: Initiates Hypnotize mode! The fractal begins to spin, hypnotizing the user.
 *			- Freeze!: Exits Hypnotize mode by stopping the spinning fractal and returning it to its former orientation.
 * 
 *		  The left mouse button is used to choose a starting point for the fractal, and also for displaying
 *		  each iteration of the fractal. The first left button click of a new sequence will indicate the starting
 *		  location of the fractal. Each subsequent left button click will display the next iteration of the fractal.
 *		  The keyboard input consists of various key clicks to mainly alter the visual effects of the fractal.
 *		  The key commands include:
 *			- 'r': Changes the color scheme of the fractal to red
 *			- 'g': Changes the color scheme of the fractal to green
 *			- 'b': Changes the color scheme of the fractal to blue (default)
 *			- 'c': Reverses the direction of the rotation during Hypnotize Mode
 *			- 'q': Quits the program
 *			    
 * Output: The output of the program is the Dragon Curve Fractal. Starting with a simple vertical line segment,
 *		   each iteration of the fractal produces a 90 degree rotation of the previously displayed portion to add
 *		   on to the fractal. By default, the fractal is displayed using a blue color scheme and line segment length of 1, but
 *		   these options are easily altered via user input. The fractal is space filling, so the smaller line segment
 *		   size is used, the more solid the fractal will appear. On the console window (stdout), instructions
 *		   are displayed at the very start of the program, explaining all of the input options. Also, 
 *		   each time a new fractal sequence is started (at the start of the program or after a restart), the
 *		   starting position, line segment length, and color scheme is displayed. Every time the color change is switched,
 *		   the update is displayed in the console window. There is a limit to how many points the fractal is made up of
 *		   before it stops iterating. The fractal can display up to and including 21 iterations, before displaying
 *		   a message on the console window indicating that a limit is reached.
 *
 */

#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

#ifndef dragon
#define dragon

const long MAX = 1050000;						// maximum number of points
float getX(double,float,float,float,float);		// gets new X value of point after multiplied by the transformation matrix
float getY(double,float,float,float,float);		// gets new Y value of point after multiplied by the transformation matrix
void redScheme(int);							// determines what shade of red the next portion of the fractal will be
void greenScheme(int);							// determines what shade of green the next portion of the fractal will be
void blueScheme(int);							// determines what shade of blue the next portion of the fractal will be

class dragonCurve
{
private:;
	long numPoints;			// total number of points in the fractal
	float x[MAX];			// x values of all points in the fractal
	float y[MAX];			// y values of all points in the fractal
	char colors[MAX];		// array of chars determining which color scheme the portion of the fractal will be displayed in
	short shades[MAX];		// array of shorts determining what shade the portion of the fractal will be displayed in
	bool full;				// boolean indicating if the fractal is 'full'

	long pivotX;			// x location of the pivot point
	long pivotY;			// y location of the pivot point
public:
	dragonCurve();	// constructor
	~dragonCurve();	// destructor

	void spin(float);						// spins the fractal
	void reset();							// resets the numPoints and full datamembers of the class
	void append(float,float,char,short);	// appends a new point to the fractal
	void rotate(char,short);				// rotates each point in the fractal *in reverse order
	void print();							// draws each point in the fractal
};

#endif