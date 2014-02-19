// DelfinoG2Main.cpp

#include "dragonCurve.h"

int winWidth = 850;
int winHeight = 850;
float xLoc=50;
float yLoc=50;
float lineLength=1;
short numClicks=0;
char color = 'b';
bool erased = false;
float curRot = 0.0;
float ROT = 5.0;
const float NUM_TICKS = 15000;
bool hypnotize = false;
dragonCurve DRAGON;

void menuOptions(int);
void printTitle();
void printSettings(int,int);

void display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(hypnotize)
	{
		glTranslatef(xLoc, yLoc, 0.0);
		glRotatef(curRot,0.0,0.0,1.0);
    	glTranslatef(0-xLoc, 0-yLoc, 0.0); 
	}

	if(!erased)
	{
		DRAGON.print();
	}
	
	glutSwapBuffers();
}

void init()
{
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	glClearColor(1, 1, 0.7, 0.0);
	glEnable (GL_DEPTH_TEST);
	glOrtho(0.0, 850.0, 0.0, 850.0, -1.0, 1.0);
	printTitle();
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
	glutAddMenuEntry("Erase Fractal",8);
	glutAddMenuEntry("Redisplay Fractal",9);
	glutAddMenuEntry("Erase and Restart",4);
	glutAddMenuEntry("",0);
	glutAddMenuEntry("RESTART with New",0);
	glutAddMenuEntry("Segment Length:",0);
	glutAddMenuEntry("0.25",6);
	glutAddMenuEntry("0.5",3);
	glutAddMenuEntry("1 (default)",1);
	glutAddMenuEntry("2",2);
	glutAddMenuEntry("5",5);
	glutAddMenuEntry("10",10);
	glutAddMenuEntry("",0);
	glutAddMenuEntry("Hypnotize!",11);
	glutAddMenuEntry("Freeze!",12);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menuOptions(int val)
{
	switch(val)
	{
		case 1: lineLength = 1;
				numClicks = 0;
				erased = false;
				DRAGON.reset();
				break;
		case 2: lineLength = 2;
				numClicks = 0;
				erased = false;
				DRAGON.reset();
				break;
		case 3: lineLength = 0.5;
				numClicks = 0;
				erased = false;
				hypnotize = false;
				DRAGON.reset();
				break;
		case 5: lineLength = 5;
				numClicks = 0;
				erased = false;
				hypnotize = false;
				DRAGON.reset();
				break;
		case 6: lineLength = 0.25;
				numClicks = 0;
				erased = false;
				hypnotize = false;
				DRAGON.reset();
				break;
		case 10: lineLength = 10;
				 numClicks = 0;
				 erased = false;
				 hypnotize = false;
				 DRAGON.reset();
				 break;
		case 4: numClicks = 0;
				erased = false;
				hypnotize = false;
				DRAGON.reset();
				break;
		case 8: erased = true;
				glClear(GL_COLOR_BUFFER_BIT);
				glutSwapBuffers();
				break;
		case 9: erased = false;
				glutPostRedisplay();
				break;
		case 11: hypnotize = true;
				 glutPostRedisplay();
				 break;
		case 12: hypnotize = false;
				 curRot = 0.0;
				 glutPostRedisplay();
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
		case 'r': color = 'r';
				  cout << "\nChanging Color Scheme to Red...\n" << endl;
			 	  break;
		case 'g': color = 'g';
				  cout << "\nChanging Color Scheme to Green...\n" << endl;
				  break;
		case 'b': color = 'b';
				  cout << "\nChanging Color Scheme to Blue...\n" << endl;
				  break;
		case 'c': if(ROT > 0)
				  {
				  	ROT = -5.0;
				  }
				  else
				  {
				  	ROT = 5.0;
				  }
				  break;
		case 'q': exit(1);
				  break;
	}
}


static void Idle(void)
{
	if(hypnotize)
	{
		clock_t endwait;
   		curRot += ROT;

   		endwait = clock()+NUM_TICKS;
   		while(clock()<endwait);

   		glutPostRedisplay();
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
	cout << "\n * ========================================================================== *" << endl;
	cout << " *                                                                            *" << endl;
	cout << " *                           DRAGON CURVE FRACTAL                             *" << endl;
	cout << " *                                                                            *" << endl;
	cout << " * ========================================================================== *\n" << endl;
	cout << " Mouse Instructions:\n"<< endl;
	cout << " Left Button  - The first click indicates the starting point of the fractal"<< endl;
	cout << "                Every subsequent click displays the next iteration of the fractal\n" << endl;
	cout << " Right Button - A right click brings up a menu of the following options:\n" << endl;
	cout << "                Erase Fractal: Erases fractal, but does not delete it"<< endl;
	cout << "                Redisplay Fractal: Redisplays the previously erased fractal"<< endl;
	cout << "                Erase and Restart: Erases and deletes the fractal, starting a new sequence"<< endl;
	cout << "                Restarting with New Segment Length: Restarts sequence with chosen segment length"<< endl;
	cout << "                Hypnotize!: Begins to hypnotize the user"<< endl;
	cout << "                Freeze!: Stops hypnotizing the user\n\n"<< endl;

	cout << " Keyboard Instructions:\n"<< endl;
	cout << " 'r' - Changes the color scheme to red" << endl;
	cout << " 'g' - Changes the color scheme to green" << endl;
	cout << " 'b' - Changes the color scheme to blue" << endl;
	cout << " 'c' - Reverses the direction of the rotation during Hypnotize Mode" << endl;
	cout << " 'q' - Quits the program\n\n" << endl;






}

int main(int argc, char **argv)
// main function
{  
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
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
   glutIdleFunc(Idle);
   glutMainLoop(); 
   return 0;  
}
