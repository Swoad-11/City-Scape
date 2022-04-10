
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <time.h>
#include <iostream>
using namespace std;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;
static GLfloat spin = 0.0;
float spin_x=1.0;
float spin_y=0.0;
float spin_z=0.0;
int day=1;
bool rain=false;
bool carv=false;
bool planev=false;
bool top=false;
int flag=0;
bool help=false;


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1366, 0.0, 768.0);
}


void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}

void Full(int r,int g,int b)
{
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1366,0,0);
    glVertex3i(1366,768,0);
    glVertex3i(-200,768,0);
}
//Road
void Road()
{
    glColor3ub(78,78,78);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1366,0,0);
    glVertex3i(1366,120,0);
    glVertex3i(-200,120,0);
    glEnd();
}
void roadBorder()
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1366,120,0);
    glVertex3i(1366,130,0);
    glVertex3i(-200,130,0);
    glEnd();
}
void TranslateRoadLine(int x,int y,int z)
{
    x-=50;
    if(x<=0)
    {
        x=1050;
    }
    glutPostRedisplay();
    Sleep(50);
}
//ROad Line
void RoadLine(int x,int y,int z)
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+50,y,z);
    glVertex3i(x+50,y+10,z);
    glVertex3i(x,y+10,z);
    glEnd();
    //Sleep(50);
    //TranslateRoadLine(x,y,z);
}

void tprint(int x, int y,int z, char *string)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

    //loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
    }
};
void ttprint(int x, int y,int z, char *string)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

    //loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
};


void ground(int r,int g,int b)
{
    //Grass
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1366,120,0);
    glVertex3i(1366,260,0);
    glVertex3i(-200,260,0);
    glEnd();

    //Walkway
    glColor3ub(94, 65, 33);
    glBegin(GL_QUADS);
    glVertex3i(-200,250,0);
    glVertex3i(1366,250,0);
    glVertex3i(1366,260,0);
    glVertex3i(-200,260,0);

}

void buildings()
{
    //building-1
    glColor3ub(148, 184, 184);
    glBegin(GL_QUADS);
    glVertex3i(0,400,0);
    glVertex3i(80,400,0);
    glVertex3i(80,260,0);
    glVertex3i(0,260,0);
    glEnd();

    //building-2
    glColor3ub(82, 122, 122);
    glBegin(GL_QUADS);
    glVertex3i(80,340,0);
    glVertex3i(110,340,0);
    glVertex3i(110,260,0);
    glVertex3i(80,260,0);
    glEnd();

    //building-3
    glColor3ub(51, 77, 77);
    glBegin(GL_QUADS);
    glVertex3i(110,360,0);
    glVertex3i(160,360,0);
    glVertex3i(160,260,0);
    glVertex3i(110,260,0);
    glEnd();

    //building-4
    glColor3ub(96, 159, 159);
    glBegin(GL_QUADS);
    glVertex3i(160,420,0);
    glVertex3i(210,420,0);
    glVertex3i(210,260,0);
    glVertex3i(160,260,0);
    glEnd();

    //building-5
    glColor3ub(102, 153, 153);
    glBegin(GL_QUADS);
    glVertex3i(210,390,0);
    glVertex3i(250,390,0);
    glVertex3i(250,260,0);
    glVertex3i(210,260,0);
    glEnd();

    //tower--mid
    glColor3ub(41, 61, 61);
    glBegin(GL_QUADS);
    glVertex3i(258,610,0);
    glVertex3i(272,610,0);
    glVertex3i(272,260,0);
    glVertex3i(258,260,0);
    glEnd();


    //tower-midtop-1
    glColor3ub(41, 61, 61);
    glBegin(GL_QUADS);
    glVertex3i(245,580,0);
    glVertex3i(285,580,0);
    glVertex3i(285,560,0);
    glVertex3i(245,560,0);
    glEnd();

    //tower-midtop-2
    glColor3ub(41, 61, 61);
    glBegin(GL_QUADS);
    glVertex3i(240,605,0);
    glVertex3i(288,605,0);
    glVertex3i(288,585,0);
    glVertex3i(240,585,0);
    glEnd();

    //tower
    glColor3ub(41, 61, 61);
    glBegin(GL_QUADS);
    glVertex3i(250,550,0);
    glVertex3i(280,550,0);
    glVertex3i(280,260,0);
    glVertex3i(250,260,0);
    glEnd();

    //building-5
    glColor3ub(102, 153, 153);
    glBegin(GL_QUADS);
    glVertex3i(275,410,0);
    glVertex3i(325,410,0);
    glVertex3i(325,260,0);
    glVertex3i(275,260,0);
    glEnd();

    //building-6
    glColor3ub(163, 194, 194);
    glBegin(GL_QUADS);
    glVertex3i(140,310,0);
    glVertex3i(300,310,0);
    glVertex3i(300,260,0);
    glVertex3i(140,260,0);
    glEnd();

    //building-7
    glColor3ub(163, 194, 194);
    glBegin(GL_QUADS);
    glVertex3i(325,310,0);
    glVertex3i(365,310,0);
    glVertex3i(365,260,0);
    glVertex3i(325,260,0);
    glEnd();

    //building-8
    glColor3ub(71, 107, 107);
    glBegin(GL_QUADS);
    glVertex3i(365,330,0);
    glVertex3i(385,330,0);
    glVertex3i(385,260,0);
    glVertex3i(365,260,0);
    glEnd();

    //building-
    glColor3ub(71, 107, 107);
    glBegin(GL_QUADS);
    glVertex3i(395,370,0);
    glVertex3i(615,370,0);
    glVertex3i(615,260,0);
    glVertex3i(395,260,0);
    glEnd();

    glColor3ub(82, 122, 122);
    glBegin(GL_QUADS);
    glVertex3i(385,360,0);
    glVertex3i(625,360,0);
    glVertex3i(625,260,0);
    glVertex3i(385,260,0);
    glEnd();


}

//dynamic lamp post function
void lampPost(int x,int y,int z)
{
    //verticle
    glColor3ub(220,220,220);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+100,z);
    glVertex3i(x,y+100,z);
    glEnd();

    //horizontal
    glColor3ub(220,220,220);
    glBegin(GL_QUADS);
    glVertex3i(x,y+93,z);
    glVertex3i(x+40,y+93,z);
    glVertex3i(x+40,y+100,z);
    glVertex3i(x,y+100,z);
    glEnd();

    //lightholder
    glColor3ub(220,220,220);
    glBegin(GL_TRIANGLES);
    glVertex3i(x+20,y+85,z);
    glVertex3i(x+40,y+85,z);
    glVertex3i(x+30,y+93,z);
    glEnd();
}
//light
void Light(int x,int y,int z)
{
    //light
    glColor3ub(255,255,77);
    glBegin(GL_QUADS);
    glVertex3i(x+9,y,z);
    glVertex3i(x+50,y,z);
    glVertex3i(x+40,y+85,z);
    glVertex3i(x+20,y+85,z);
    glEnd();

}






void otherCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius,int r,int g,int b)
{
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//radius
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y, z); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount)),z
			);
		}
	glEnd();
}

void car() //red car
{
    static float a=-400.0f;
    if(a>=1324)
    {
         a=-400.0f;

    }
    else
    {
        a+=0.2f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(205,112,84);
    glPushMatrix();
    glTranslatef(a,0,0);
    glBegin(GL_QUADS);
    glVertex3i(20,40,0);
    glVertex3i(220,40,0);
    glVertex3i(220,80,0);
    glVertex3i(20,80,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(40,80,0);
    glVertex3i(200,80,0);
    glVertex3i(160,110,0);
    glVertex3i(80,110,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(115,80,0);
    glVertex3i(190,80,0);
    glVertex3i(155,105,0);
    glVertex3i(115,105,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(45,80,0);
    glVertex3i(110,80,0);
    glVertex3i(110,105,0);
    glVertex3i(80,105,0);
    glEnd();

    //handle
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(115,70,0);
    glVertex3i(135,70,0);
    glVertex3i(135,75,0);
    glVertex3i(115,75,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(45,70,0);
    glVertex3i(65,70,0);
    glVertex3i(65,75,0);
    glVertex3i(45,75,0);
    glEnd();

    //backbumper
    otherCircle(30.0f,60.0f,0.0f,19.0f,205,112,84);
    //front bumper
    otherCircle(210.0f,60.0f,0.0f,19.0f,205,112,84);

//Light
    glColor3ub(250,250,0);
    glBegin(GL_QUADS);
    glVertex3i(225,55,0);
    glVertex3i(230,55,0);
    glVertex3i(230,65,0);
    glVertex3i(225,65,0);
    glEnd();

    //carlight
    if(day==2)
    {
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex3i(230,55,0);
        glVertex3i(280,20,0);
        glVertex3i(280,95,0);
        glVertex3i(225,65,0);
        glEnd();
    }

    otherCircle(60.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(60.0f,40.0f,0.0f,10.0f,137,137,137);
    otherCircle(170.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(170.0f,40.0f,0.0f,10.0f,137,137,137);

    glPopMatrix();
    glutPostRedisplay();
}


void car2() //blue car
{
    static float a=-1100.0f;
    if(a>=1324)
    {
         a=-1100.0f;

    }
    else
    {
        a+=0.2f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(135,206,250);
    glPushMatrix();
    glTranslatef(a,0,0);
    glBegin(GL_QUADS);
    glVertex3i(20,40,0);
    glVertex3i(220,40,0);
    glVertex3i(220,80,0);
    glVertex3i(20,80,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(40,80,0);
    glVertex3i(200,80,0);
    glVertex3i(160,110,0);
    glVertex3i(80,110,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(115,80,0);
    glVertex3i(190,80,0);
    glVertex3i(155,105,0);
    glVertex3i(115,105,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(45,80,0);
    glVertex3i(110,80,0);
    glVertex3i(110,105,0);
    glVertex3i(80,105,0);
    glEnd();

    //handle
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(115,70,0);
    glVertex3i(135,70,0);
    glVertex3i(135,75,0);
    glVertex3i(115,75,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(45,70,0);
    glVertex3i(65,70,0);
    glVertex3i(65,75,0);
    glVertex3i(45,75,0);
    glEnd();

    //backbumper
    otherCircle(30.0f,60.0f,0.0f,19.0f,135,206,250);
    //front bumper
    otherCircle(210.0f,60.0f,0.0f,19.0f,135,206,250);

    //Light
    glColor3ub(250,250,0);
    glBegin(GL_QUADS);
    glVertex3i(225,55,0);
    glVertex3i(230,55,0);
    glVertex3i(230,65,0);
    glVertex3i(225,65,0);
    glEnd();

    //carlight
    if(day==2)
    {
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex3i(230,55,0);
        glVertex3i(280,20,0);
        glVertex3i(280,95,0);
        glVertex3i(225,65,0);
        glEnd();
    }

    otherCircle(60.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(60.0f,40.0f,0.0f,10.0f,137,137,137);
    otherCircle(170.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(170.0f,40.0f,0.0f,10.0f,137,137,137);

    glPopMatrix();
    glutPostRedisplay();
}



void truck()
{
    static float a=650.0f;
    if(a<=-1300)
    {
         a=550.0f;

    }
    else
    {
        a-=0.2f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(119,136,153);
    //frontbumper
    glPushMatrix();
    glTranslatef(a,0,0);

    //main body
    glBegin(GL_QUADS);
    glVertex3i(750,90,0);
    glVertex3i(1100,90,0);
    glVertex3i(1100,190,0);
    glVertex3i(750,190,0);
    glEnd();


    glBegin(GL_QUADS);
    glVertex3i(750,190,0);
    glVertex3i(860,190,0);
    glVertex3i(860,160,0);
    glVertex3i(750,160,0);
    glEnd();
    //window


    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(760,160,0);
    glVertex3i(800,160,0);
    glVertex3i(800,185,0);
    glVertex3i(760,185,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(805,160,0);
    glVertex3i(825,160,0);
    glVertex3i(825,185,0);
    glVertex3i(805,185,0);
    glEnd();

    //handle
    glBegin(GL_QUADS);
    glVertex3i(820,145,0);
    glVertex3i(830,145,0);
    glVertex3i(830,150,0);
    glVertex3i(820,150,0);
    glEnd();

    //back windows

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(850,160,0);
    glVertex3i(885,160,0);
    glVertex3i(885,185,0);
    glVertex3i(850,185,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(890,160,0);
    glVertex3i(930,160,0);
    glVertex3i(930,185,0);
    glVertex3i(890,185,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(935,160,0);
    glVertex3i(975,160,0);
    glVertex3i(975,185,0);
    glVertex3i(935,185,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(980,160,0);
    glVertex3i(1020,160,0);
    glVertex3i(1020,185,0);
    glVertex3i(980,185,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(1025,160,0);
    glVertex3i(1085,160,0);
    glVertex3i(1085,185,0);
    glVertex3i(1025,185,0);
    glEnd();




    //wheel-1
    otherCircle(800.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(800.0f,90.0f,0.0f,15.0f,131,131,131);
    //wheel-2
    otherCircle(1000.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(1000.0f,90.0f,0.0f,15.0f,131,131,131);
    //wheel-3
    otherCircle(1050.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(1050.0f,90.0f,0.0f,15.0f,131,131,131);

    //backlight
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex3i(1100,110,0);
    glVertex3i(1105,110,0);
    glVertex3i(1105,120,0);
    glVertex3i(1100,120,0);
    glEnd();

    //frontlignt
    glColor3ub(255,255,0);
    glBegin(GL_QUADS);
    glVertex3i(740,90,0);
    glVertex3i(750,90,0);
    glVertex3i(750,102,0);
    glVertex3i(740,102,0);
    glEnd();



    //trucklight
    if(day==2)
    {
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex3i(680,60,0);
        glVertex3i(740,90,0);
        glVertex3i(740,102,0);
        glVertex3i(680,130,0);
        glEnd();
    }
    glColor3ub(255,255,255);
    //ttprint(860,110,0,"AIUB");
    glPopMatrix();
    glutPostRedisplay();
}

//Plane

void plane()
{
    static float a=-300.0f;
    static float b=0.0f;
    if(a>=1324)
    {
         a=-300.0f;
         b=0.0f;

    }
    else
    {
        a+=0.1f;
        b+=0.005f;
        //glColor3ub(r,g,b);
    }
    //Body
    glColor3ub(66, 66, 66);
    glPushMatrix();
    glTranslatef(a,b,0);
    glBegin(GL_QUADS);
    glVertex3i(30,700,0);
    glVertex3i(100,700,0);
    glVertex3i(100,715,0);
    glVertex3i(35,715,0);
    glEnd();

    //front
    glBegin(GL_TRIANGLES);
    glVertex3i(100,700,0);
    glVertex3i(110,707,0);
    glVertex3i(100,715,0);
    glEnd();

    //fanback
    glBegin(GL_QUADS);
    glVertex3i(37,715,0);
    glVertex3i(57,715,0);
    glVertex3i(40,730,0);
    glVertex3i(20,730,0);
    glEnd();

    //fanFrontUp
    glBegin(GL_QUADS);
    glVertex3i(70,715,0);
    glVertex3i(80,715,0);
    glVertex3i(60,735,0);
    glVertex3i(50,735,0);
    glEnd();

    //FanFrontDown
    glBegin(GL_QUADS);
    glVertex3i(70,700,0);
    glVertex3i(80,700,0);
    glVertex3i(60,680,0);
    glVertex3i(50,680,0);
    glEnd();

    //window
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex3i(95,710,0);
    glVertex3i(90,710,0);
    glVertex3i(85,710,0);
    glVertex3i(80,710,0);
    glVertex3i(75,710,0);
    glVertex3i(70,710,0);
    glVertex3i(65,710,0);
    glVertex3i(60,710,0);
    glVertex3i(55,710,0);
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}


//clouds
void clouds(float x,float y,float z,int m,int l,int n)
{
    static float a=-1300.0f;
    if(a>=1324)
    {
         a=-1300.0f;

    }
    else
    {
        a+=0.005f;
        //glColor3ub(r,g,b);
    }
    glPushMatrix();
    glTranslatef(a,0,0);


    //cloud1
    otherCircle(x,y,z,50.0f,m,l,n);
    otherCircle(x-50,y,z,40.0f,m,l,n);
    otherCircle(x+50,y,z,40.0f,m,l,n);
    glPopMatrix();
    glutPostRedisplay();
}


void rainf()
{
    int x=0;
    int y=778;
    static float a=-760.0f;
    if(a<=-768)
    {
         a=-760.0f;

    }
    else
    {
        a-=0.5f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0f,a,0.0f);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3i(x,y,0);
            glVertex3i(x+3,y+10,0);
            x+=rand()%1050;
        }
        y+=rand()%15;
        x=0;

    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}



void nightMode()
{
    int roadlineX=-300;
    int treeXf=-350;
    int treeXl=528;
    int lamp=-350;
    int light=-350;
    //Full Body
        Full(55,55,55);
        //Road
        Road();
        //RoadLine
        for(int i=55;i>0;i--)
        {
            roadlineX+=100;
            RoadLine(roadlineX,55,0);
        }

        //moon
        otherCircle(300.0f,670.0f,0.0f,32.0f,255, 255, 153);
        //cloud-1
        clouds(-450.0f,670.0f,0.0f,170, 170, 120);

        //cloud0
        clouds(-150.0f,630.0f,0.0f,170, 170, 120);

        //cloud1
        clouds(150.0f,670.0f,0.0f,170, 170, 120);


        if(planev)
        {
            plane();

        }
        //cloud2
        clouds(450.0f,600.0f,0.0f,205, 205, 177);
        //cloud3
        clouds(750.0f,690.0f,0.0f,173, 173, 133);
        //cloud4
        clouds(1050.0f,680.0f,0.0f,173, 173, 133);

        ground(42,55,17);

        buildings();


        //lamp post
        for(int i=9;i>=0;i--)
        {
            lamp+=255;
            lampPost(lamp,130,0);
        }
        //light
        for(int i=9;i>=0;i--)
        {
            light+=255;
            Light(light,130,0);
        }
        roadBorder();
        glColor3ub(0,0,255);
        if(carv)
        {
            truck();
            car();
            car2();
        }
        glPopMatrix();

        if(rain)
        {

            rainf();

        }
}

void dayMode()
{
        int roadlineX=-300;
        int treeXf=-350;
        int treeXl=528;
        int lamp=-350;
        int light=-350;

        Full(131,183,231);
        //Road
        Road();
        //RoadLine
        for(int i=55;i>0;i--)
        {
            roadlineX+=100;
            RoadLine(roadlineX,55,0);
        }
        //cloud0
        clouds(-100.0f,630.0f,0.0f,250,250,250);
        //cloud1
        clouds(150.0f,670.0f,0.0f,250,250,250);
       if(planev)
        {
            plane();
        }
        //cloud2
        clouds(450.0f,600.0f,0.0f,250,250,250);
        //cloud3
        clouds(750.0f,690.0f,0.0f,250,250,250);
        //cloud4
        clouds(1050.0f,710.0f,0.0f,250,250,250);
        //Play Ground
        ground(42,95,17);

        buildings();


        //lamp post
        for(int i=9;i>=0;i--)
        {
            lamp+=255;
            lampPost(lamp,130,0);
        }
        //light
        roadBorder();


        if(carv)
        {
            truck();
            car();
            car2();
        }
        glPopMatrix();

        if(rain)
        {
            rainf();
        }
}





void controlsScreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.000, 0.000, 0.000,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 128, 0);
    drawstring(570.0,700.0,0.0,"INSTRUCTIONS");
    glColor3f(255, 255, 255);
    drawstring(450.0,640.0,0.0,"DAY MODE");
    glColor3f(255, 255, 255);
    drawstring(800.0,640.0,0.0,"PRESS 'D'");
    glColor3f(255, 255, 255);
    drawstring(450.0,600.0,0.0,"NIGHT MODE");
    glColor3f(255, 255, 255);
    drawstring(800.0,600.0,0.0,"PRESS 'N'");
    glColor3f(255, 255, 255);
    drawstring(450.0,560.0,0.0,"CAR MOVING");
    glColor3f(255, 255, 255);
    drawstring(800.0,560.0,0.0,"PRESS 'C'");
    glColor3f(255, 255, 255);
    drawstring(450.0,520.0,0.0,"RAIN MODE");
    glColor3f(255, 255, 255);
    drawstring(800.0,520.0,0.0,"PRESS 'R'");
    glColor3f(255, 255, 255);
    drawstring(450.0,480.0,0.0,"NO RAIN");
    glColor3f(255, 255, 255);
    drawstring(800.0,480.0,0.0,"PRESS 'E'");
    glColor3f(255, 255, 255);
    drawstring(450.0,440.0,0.0,"PLANE MOVEMENT");
    glColor3f(255, 255, 255);
    drawstring(800.0,440.0,0.0,"PRESS 'P'");
    glColor3f(255, 255, 255);
    drawstring(450.0,400.0,0.0,"HELP");
    glColor3f(255, 255, 255);
    drawstring(800.0,400.0,0.0,"PRESS 'H'");
    glColor3f(255, 255, 255);
    drawstring(450.0,360.0,0.0,"ESCAPE");

    glColor3f(255, 255, 255);
    drawstring(800.0,360.0,0.0,"PRESS 'E'");
    glColor3f(0, 255, 255);
    drawstring(550.0,320.0,0.0,"NOW PRESS ENTER");
    glFlush();
}


void display()
{
    glPushMatrix();
    glTranslatef(translate_x,translate_y,translate_z);

    if(day==2)
    {
       nightMode();
    }
    else if(day==1)
    {
        dayMode();
    }


    glFlush();
    glutSwapBuffers();
}


//Main Display Function
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(flag==0)
        controlsScreen();

    if(flag>=1)
        display();

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
//-------- spin --------
if(key=='d')
{
    day=1;
}
else if(key=='n')
{
    day=2;
}

else if(key=='r')
{
    rain=true;
}
else if(key=='e')
{
    rain=false;
}
else if(key=='c')
{
    carv=true;
}
else if(key=='p')
{
    planev=true;
}
else if(key==13)
{
    flag++;
    myDisplay();
}
else if(key=='h')
{
    flag=0;
    myDisplay();
}
else if(key==27)
{
    exit(0);
}
}


void SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
            if(translate_x<200)
            {
                translate_x+=5;
                glutPostRedisplay();
            }
			break;

		case GLUT_KEY_RIGHT:
            if(translate_x>-300)
            {
                translate_x-=5;
                glutPostRedisplay();
            }
			break;

        case GLUT_KEY_UP:
            spin-=5;
            if(spin>=360)
            {
                spin=0;
            }
            glutPostRedisplay();
			break;

        case GLUT_KEY_DOWN:
            spin+=5;
            if(spin<=360)
            {
                spin=0;
            }
            glutPostRedisplay();
			break;
	}
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1366, 768);
glutInitWindowPosition (0, 0);
glutCreateWindow ("City Scape");
myInit();
glutDisplayFunc(myDisplay);
glutKeyboardFunc(keyboard);
glutSpecialFunc(SpecialKeys);
glutMainLoop();
return 0;
}
