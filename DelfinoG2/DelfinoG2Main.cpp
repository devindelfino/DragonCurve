// DelfinoG2Main.cpp

#include "dragonCurve.h"

int winWidth = 850;
int winHeight = 850;
float xLoc=50;
float yLoc=50;
float lineLength=1;
short numClicks=0;
char color = 'b';
dragonCurve DRAGON;

void menuOptions(int);
void printTitle();
void printSettings(int,int);

void display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DRAGON.print();

	glFlush();
}

void init()
{
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	glClearColor(0.7, 0.7, 0.7, 0.0);
	glOrtho(0.0, 850.0, 0.0, 850.0, -1.0, 1.0);
}

void resizeWindow(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glOrtho(0.0, 850.0, 0.0, 850.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void initMenu()
{
	glutCreateMenu(menuOptions);
	glutAddMenuEntry("Choose Line",0);
	glutAddMenuEntry("Segment Length",0);
	glutAddMenuEntry("",0);
	glutAddMenuEntry("0.1",7);
	glutAddMenuEntry("0.25",6);
	glutAddMenuEntry("0.5",3);
	glutAddMenuEntry("1 (default)",1);
	glutAddMenuEntry("2",2);
	glutAddMenuEntry("5",5);
	glutAddMenuEntry("10",10);
	glutAddMenuEntry("",0);
	glutAddMenuEntry("RESTART...",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menuOptions(int val)
{
	switch(val)
	{
		case 1: lineLength = 1;
				numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;
		case 2: lineLength = 2;
				numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;
		case 3: lineLength = 0.5;
				numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;
		case 5: lineLength = 5;
				numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;
		case 6: lineLength = 0.25;
				numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;
		case 7: lineLength = 0.1;
				numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;
		case 10: lineLength = 10;
				 numClicks = 0;
				 DRAGON.reset();
				 glClear(GL_COLOR_BUFFER_BIT);
				 glFlush();
				 break;
		case 4: numClicks = 0;
				DRAGON.reset();
				glClear(GL_COLOR_BUFFER_BIT);
				glFlush();
				break;

	}
}

void mouseClick(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(numClicks==0)
		{
			xLoc = x;
			yLoc = winHeight - y;
			numClicks++;
			DRAGON.append(xLoc,yLoc,color,0);
			DRAGON.append(xLoc,yLoc-lineLength,color,0);
			printSettings(x,y);
		}
		else
		{
			// DRAGON.update(xLoc,yLoc,numClicks,lineLength);
			// DRAGON.rotateGrow();
			numClicks++;
			bool rotate = true;
			if(numClicks >= 3 )
			{
				DRAGON.rotate(color,numClicks-2);
			}
			glutPostRedisplay();
		}
	}
	else
	{
		//
	}
}

void keyboardInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'q': exit(1);
				  break;
		case 'r': color = 'r';
				  cout << "\nChanging Color Scheme to Red...\n" << endl;
			 	  break;
		case 'g': color = 'g';
				  cout << "\nChanging Color Scheme to Green...\n" << endl;
				  break;
		case 'b': color = 'b';
				  cout << "\nChanging Color Scheme to Blue...\n" << endl;
				  break;
	}
}

void printSettings(int x, int y)
{
	cout << "\n------------------------" << endl;
	cout << " Starting New Fractal  |" << endl;
	cout << "-----------------------------------------------------------------------" <<endl;
	cout << "Starting Position: ("<< x << ", " << y << ")"<< endl;
	cout << "Line Segment Length: " << lineLength << endl;
	if(color=='b')
	{
		cout << "Color Scheme: Blue" << endl;
	}
	else if(color=='g')
	{
		cout << "Color Scheme: Green" << endl;
	}
	else
	{
		cout << "Color Scheme: Red" << endl;
	}
	cout << "-----------------------------------------------------------------------\n" <<endl;

}

void printTitle()
{
	//
}

int main(int argc, char **argv)
// main function
{  
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   glutInitWindowSize(winWidth,winHeight);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("Dragon Curve");
   init();
   initMenu();
   //glutKeyboardFunc(keyboardInput);   // the default keyboard function of the openGL program
   glutDisplayFunc(display);        // the default display function of the openGL program
   glutReshapeFunc(resizeWindow);     // the default reshape function of the openGL program
   glutMouseFunc(mouseClick);
   glutKeyboardFunc(keyboardInput);
   glutMainLoop(); 
   return 0;  
}
