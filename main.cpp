
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


void playGround(int r,int g,int b)
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

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y,z); // center of circle
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
    glColor3ub(255,0,0);
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
    otherCircle(30.0f,60.0f,0.0f,19.0f,255,0,0);
    //front bumper
    otherCircle(210.0f,60.0f,0.0f,19.0f,255,0,0);

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
    glColor3ub(0,0,255);
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
    otherCircle(30.0f,60.0f,0.0f,19.0f,0,0,255);
    //front bumper
    otherCircle(210.0f,60.0f,0.0f,19.0f,0,0,255);

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
    glColor3ub(0,0,255);
    //frontbumper
    glPushMatrix();
    glTranslatef(a,0,0);
    otherCircle(780.0f,130.0f,0.0f,41.0f,255,255,0);
    //main body
    glBegin(GL_QUADS);
    glVertex3i(750,90,0);
    glVertex3i(1000,90,0);
    glVertex3i(1000,140,0);
    glVertex3i(750,140,0);
    glEnd();


    glBegin(GL_QUADS);
    glVertex3i(750,140,0);
    glVertex3i(860,140,0);
    glVertex3i(860,160,0);
    glVertex3i(750,160,0);
    glEnd();
    //window
    glBegin(GL_QUADS);
    glVertex3i(750,160,0);
    glVertex3i(860,160,0);
    glVertex3i(860,190,0);
    glVertex3i(800,190,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(760,160,0);
    glVertex3i(855,160,0);
    glVertex3i(855,185,0);
    glVertex3i(800,185,0);
    glEnd();

    //handle
    glBegin(GL_QUADS);
    glVertex3i(840,145,0);
    glVertex3i(855,145,0);
    glVertex3i(855,150,0);
    glVertex3i(840,150,0);
    glEnd();






    //wheel
    otherCircle(800.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(800.0f,90.0f,0.0f,15.0f,131,131,131);
    otherCircle(950.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(950.0f,90.0f,0.0f,15.0f,131,131,131);

    //backlight
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex3i(1000,110,0);
    glVertex3i(1005,110,0);
    glVertex3i(1005,120,0);
    glVertex3i(1000,120,0);
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
//LampStand
void toplampPost(int x,int y,int z)
{
    otherCircle(x+60,y+3,0,5,222,250,50);
    glColor3ub(222,250,50);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+70,y,z);
    glVertex3i(x+70,y+5,z);
    glVertex3i(x,y+5,z);
    glEnd();
}
//Car

void topCar()
{
    static float a=-400.0f;
    if(a>=1324)
    {
         a=-500.0f;

    }
    else
    {
        a+=0.5f;
        //glColor3ub(r,g,b);
    }
    glPushMatrix();
    glTranslatef(a,0,0);
    otherCircle(-100,18,0,23,255,0,0);
    otherCircle(-130,18,0,23,255,0,0);
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex3i(-100,0,0);
    glVertex3i(-135,0,0);
    glVertex3i(-135,40,0);
    glVertex3i(-100,40,0);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(-105,5,0);
    glVertex3i(-90,10,0);
    glVertex3i(-90,30,0);
    glVertex3i(-105,35,0);
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

        playGround(42,55,17);


        //lamp post
        for(int i=9;i>=0;i--)
        {
            lamp+=310;
            lampPost(lamp,130,0);
        }
        //light
        for(int i=9;i>=0;i--)
        {
            light+=310;
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
        playGround(42,95,17);


        //lamp post
        for(int i=9;i>=0;i--)
        {
            lamp+=310;
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
else if(key=='v')
{
    carv=false;
}
else if(key=='p')
{
    planev=true;
}
else if(key=='o')
{
    planev=false;
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
