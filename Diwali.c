#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int playThemeMusic = 1;

const int smallFont=(int)GLUT_BITMAP_HELVETICA_18;
const int bigFont=(int)GLUT_BITMAP_TIMES_ROMAN_24;

float scr_width = 0;
float scr_height = 0;

float passiveX;
float passiveY;

char name1[300];
char name2[300];
int name1Iter = 0;
int name2Iter = 0;

int status = 0;
const int DISPLAY_MENU = 0;
const int LEFT_MENU = 1;
const int RIGHT_MENU = 2;
const int FLOWERPOT_STEADY = 3;
const int FLOWERPOT = 4;
const int CHAKRI_STEADY = 5;
const int CHAKRI = 6;
const int ROCKET_STEADY = 7;
const int ROCKET = 8;
const int ROCKETBLINK = 9;
const int GREETING1 = 10;
const int GREETING2 = 11;
const int GREETING1SIGNED = 12;
const int GREETING2SIGNED = 13;

void fireworks();
void rocketicon();
void chakriicon();
void flowerpoticon();
void greeting1icon();
void greeting2icon();
void backButton();
void resetMaterialProperties();

GLUquadric* qobj;

GLfloat texture[10];
GLfloat titleImg;
GLfloat happydiwali;
GLfloat ganpati;
     
const ParticleCount = 400;

GLubyte space[] =
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
GLubyte letters[][13] = {
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}
};


GLuint fontOffset;

void makeRasterFont(void)
{
GLuint i, j;
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
fontOffset = glGenLists (128);
for (i = 0,j = 'A'; i < 26; i++,j++) {
glNewList(fontOffset + j, GL_COMPILE);
glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, letters[i]);
glEndList();
}
glNewList(fontOffset + ' ', GL_COMPILE);
glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
glEndList();
}

void printString(char *s)
{
glPushAttrib (GL_LIST_BIT);
glListBase(fontOffset);
glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte *) s);
glPopAttrib ();
}


void renderBitmapString(float x, float y, float z, void *font,const char *string){
    const char *c;
    glRasterPos3f(x, y, z);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
} 

typedef struct
{
double Xpos;
double Ypos;
double Zpos;
double Xmov;
double Zmov;
double Red;
double Green;
double Blue;
double Direction;
double Acceleration;
double Deceleration;
double Scalez;
int Visible;
}PARTICLES;

PARTICLES Particle[400];

GLuint LoadTextureRAW( const char * filename, int width,int height);
void FreeTexture( GLuint texturez );

void square (void) {
    glBindTexture( GL_TEXTURE_2D, texture[0] );
    glBegin (GL_QUADS);
    glTexCoord2d(0.0,0.0); 
    glVertex2d(-1.0,-1.0);
    glTexCoord2d(1.0,0.0); 
    glVertex2d(1.0,-1.0);
    glTexCoord2d(1.0,1.0); 
    glVertex2d(1.0,1.0);
    glTexCoord2d(0.0,1.0); 
    glVertex2d(-1.0,1.0);
    glEnd();
}

void glCreateParticles (void) {
    int i;
    for (i = 1; i < ParticleCount; i++)
    {
        Particle[i].Xpos = 0;
        Particle[i].Ypos = -5;
        Particle[i].Zpos = -5;
        Particle[i].Xmov = (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005) - (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005);
        Particle[i].Zmov = (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005) - (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005);
        Particle[i].Red = 1;
        Particle[i].Green = 1;
        Particle[i].Blue = 1;
        Particle[i].Scalez = 0.25;
        Particle[i].Direction = 0;
        Particle[i].Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5) - 1 + 1) * rand()%11+1) + 1) * 0.02;
        Particle[i].Deceleration = 0.0025;
    }
}


 
void glUpdateParticles (void)
{
    int i;
    for (i = 1; i < ParticleCount; i++)
    {
        glColor3f (Particle[i].Red, Particle[i].Green, Particle[i].Blue);
        
        Particle[i].Ypos = Particle[i].Ypos + Particle[i].Acceleration - Particle[i].Deceleration;
        Particle[i].Deceleration = Particle[i].Deceleration + 0.0025;
        
        Particle[i].Xpos = Particle[i].Xpos + Particle[i].Xmov;
        Particle[i].Zpos = Particle[i].Zpos + Particle[i].Zmov;
        
        Particle[i].Direction = Particle[i].Direction + ((((((int)(0.5 - 0.1 + 0.1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1);
        
        if (Particle[i].Ypos < -5)
        {
        Particle[i].Xpos = 0;
        Particle[i].Ypos = -5;
        Particle[i].Zpos = -5;
        Particle[i].Red = 1;
        Particle[i].Green = 1;
        Particle[i].Blue = 1;
        Particle[i].Direction = 0;
        Particle[i].Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5) - 1 + 1) * rand()%11+3) + 1) * 0.02;
        Particle[i].Deceleration = 0.0025;
    }
    
    }
}

void glDrawParticles (void) {
int i;
for (i = 1; i < ParticleCount; i++)
{
glPushMatrix();

    glTranslatef (Particle[i].Xpos, Particle[i].Ypos, Particle[i].Zpos);
    glRotatef (Particle[i].Direction - 90, 0, 0, 1);
   
    glScalef (Particle[i].Scalez, Particle[i].Scalez, Particle[i].Scalez);
   
    glDisable (GL_DEPTH_TEST);
    glEnable (GL_BLEND);
        
    glBlendFunc (GL_DST_COLOR, GL_ZERO);
    glBindTexture (GL_TEXTURE_2D, texture[0]);

    glBegin (GL_QUADS);
    glTexCoord2d (0, 0);
    glVertex3f (-1, -1, 0);
    glTexCoord2d (1, 0);
    glVertex3f (1, -1, 0);
    glTexCoord2d (1, 1);
    glVertex3f (1, 1, 0);
    glTexCoord2d (0, 1);
    glVertex3f (-1, 1, 0);
    glEnd();
    
    glBlendFunc (GL_ONE, GL_ONE);
    glBindTexture (GL_TEXTURE_2D, texture[1]);
    
    glBegin (GL_QUADS);
    glTexCoord2d (0, 0);
    glVertex3f (-1, -1, 0);
    glTexCoord2d (1, 0);
    glVertex3f (1, -1, 0);
    glTexCoord2d (1, 1);
    glVertex3f (1, 1, 0);
    glTexCoord2d (0, 1);
    glVertex3f (-1, 1, 0);
    glEnd();
        
    glEnable(GL_DEPTH_TEST);

glPopMatrix();

}
glDisable(GL_BLEND);
}




void fillLowerBG()
{
     GLubyte upperGreenColor[] = {20, 71, 1};
     GLubyte lowerGreenColor[] = {68, 210, 12};
     
     glBegin(GL_POLYGON) ;
     glColor3ubv(upperGreenColor);
     glVertex3i(-5, -1,-1);
     glVertex3i(5, -1,-1);
     glColor3ubv(lowerGreenColor);
     glVertex3i(5, -5,-1);
     glVertex3i(-5, -5,-1);

     glEnd();    
} 

void fillUpperBG()
{
     glBegin(GL_POLYGON);
                         glColor3ub(0,0,0);
                         glVertex3f(-10,10,-5);
                         glColor3ub(60,60,60);
                         glVertex3f(10,10,-5);
                         glColor3ub(1,5,2);
                         glVertex3f(10,-10,-5);
                         glColor3ub(3,3,1);
                         glVertex3f(-10,-10,-5);
     glEnd();
     
     glColor3f(1,1,1);
     int dir;
     int i;
     float j;
     glPointSize(1.5);
     glEnable(GL_POINT_SMOOTH);
     glBegin(GL_POINTS);
                        for(i=0; i<5; i++)
                        {
                                 glVertex2f(-5 + 10*(rand()%100 / 100.0), 3*(rand()%100 / 100.0));
                        }
     glEnd();
     glDisable(GL_POINT_SMOOTH);
}

void drawGrass()
{
     GLubyte lightGreenColor[] = {37, 186, 7};
     GLubyte darkGreenColor[] = {20, 71, 1};
     
     float beginX = -5;
     float beginY = -0.5;
     glBegin(GL_TRIANGLES) ;
     while(beginX<5)
     {
         glColor3ubv(lightGreenColor);
         glVertex2f(beginX, beginY);
         glColor3ubv(darkGreenColor);
         glVertex3f(beginX - 0.025, beginY - 0.5,0);
         glVertex3f(beginX + 0.025, beginY - 0.5,0);
         beginX += 0.05;
     }
     glEnd();
}

drawUnitFence()
{
     GLubyte upBrownColor1[] = {144, 97, 7};
     GLubyte downBrownColor1[] = {146, 100, 10};
     GLubyte upBrownColor2[] = {84, 47, 0};
     GLubyte downBrownColor2[] = {180, 121, 6};
     
     glBegin(GL_QUADS) ;  
     glColor3ubv(upBrownColor1);          
     glVertex3f( 0, 0, 0 );    
     glVertex3f( 0.75, 0, 0 );    
     glColor3ubv(downBrownColor1);          
     glVertex3f( 0.75, -0.50, 0 );
     glVertex3f( 0, -0.50, 0 );    

     
     glColor3ubv(upBrownColor1);          
     glVertex3f( 0, -1.30, 0 );    
     glVertex3f( 0.75, -1.30, 0 );    
     glColor3ubv(downBrownColor1);          
     glVertex3f( 0.75, -1.80, 0 );  
     glVertex3f( 0, -1.80, 0 );    
     
     glColor3ubv(upBrownColor2);          
     glVertex3f( 0.75, 0.50, 0 );
     glVertex3f( 1.55, 0.50, 0 );
     glColor3ubv(downBrownColor2);          
     glVertex3f( 1.55, -2.30, 0 );
     glVertex3f( 0.75, -2.30, 0 );

     glEnd(); 
}

void drawFence()
{
     float beginX = -5;
     float beginY = -0.3;
     
     while(beginX < 5)
     {   
         glPushMatrix();
         glTranslatef(beginX, beginY, -1);
         glScalef(0.3,0.3,0.2);
         drawUnitFence();
         glPopMatrix();
         beginX += 0.4;
    }
         
}


void drawBackground()
{
     glDisable(GL_LIGHTING);
     fillLowerBG();
     fillUpperBG();
     glPushMatrix();
          glScalef(1.1,1.2,1.1);
          glTranslatef(0,0.1,-1.2);
          drawGrass();
     glPopMatrix();
     drawFence();
     glEnable(GL_LIGHTING);
}









//light position variables
GLfloat lx = 5.0;
GLfloat ly = 2.0;
GLfloat lz = 5.0;
GLfloat lw = 0.0;

void init (void) {
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glEnable (GL_LIGHT1); //enable LIGHT1, our Ambient Light
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader

    makeRasterFont();
    name1[0] = '\0';
    name2[0]='\0';
    
    glEnable( GL_TEXTURE_2D );      
    
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);

}

void glFermatSpiral(float a, float b, float thetaStart, float thetaEnd, int samples )
{
    int dir = 0;
    float spiral_color1[] = {1,0.54,0};
    float spiral_color2[] = {0.8,0.2,0};
    float spiral_color3[] = {1,0,0};
    glBegin( GL_LINE_STRIP );

    float dt = (thetaEnd - thetaStart) / (float)samples;
    
    dir = rand()%3;
    if(dir==0)
        glColor3f(spiral_color1[0],spiral_color1[1],spiral_color1[2]);
    else if(dir==1)
        glColor3f(spiral_color2[0],spiral_color2[1],spiral_color2[2]);
    else
        glColor3f(spiral_color3[0],spiral_color3[1],spiral_color3[2]);
    int i;
    for(  i = 0; i <= samples; ++i )
    {     
          // archimedean spiral
        float theta = thetaStart + (i * dt);
        // Specific to made a Fermat Spiral.
        float r = sqrt( theta );
     
     
     
        // polar to cartesian
        float x = r * cos( theta );
        float y = r * sin( theta );

        // Square root means two solutions, one positive and other negative. 2 points to be drawn.
        glVertex3f( x, y ,-0.5);

        x = -r * cos( theta );
        y = -r * sin( theta );

        glVertex3f( x, y ,-0.5);
    }

    glEnd();
}





float pushUp = 0;
float pushBelow = 0;


void titleBelow()
{
     pushUp = -2.3;
     glDisable(GL_LIGHTING);
     glEnable(GL_TEXTURE_2D);
     glEnable(GL_BLEND);     
     glBlendFunc (GL_ONE, GL_ONE);
     

     
     
     titleImg = LoadTextureRAW("hdtitle.raw",300,156);
     
     glBindTexture (GL_TEXTURE_2D, titleImg);

     if(pushBelow >= -2.3)          //IDEAL -2.42
                  pushBelow -= 0.1;
     glPushMatrix();
     
         glTranslatef(0,pushBelow,0.1);
         glScalef(1.7,1.7,1);
         glBegin(GL_QUADS);
                             glTexCoord3f(-1,1,0.3);
                             glVertex3f(-1,1,0.2);
                             glTexCoord3f(0,1,0.3);
                             glVertex3f(1,1,0.2);
                             glTexCoord3f(0,0,0.3);
                             glVertex3f(1,0,0.2);
                             glTexCoord3f(-1,0,0.3);
                             glVertex3f(-1,0,0.2);                                                  
         glEnd();         
     glPopMatrix();

     glDisable(GL_TEXTURE_2D);
     glDisable(GL_BLEND);
     glEnable(GL_LIGHTING);     
}


void titleOnTop()
{
     pushBelow = 0;
     glDisable(GL_LIGHTING);
     glEnable(GL_TEXTURE_2D);
     glEnable(GL_BLEND);     
     glBlendFunc (GL_ONE, GL_ONE);
     

     
     
     titleImg = LoadTextureRAW("hdtitle.raw",300,156);
     
     glBindTexture (GL_TEXTURE_2D, titleImg);

     if(pushUp <= 0 )          //IDEAL 0
                  pushUp += 0.1;
     glPushMatrix();
         glTranslatef(0,pushUp,0.1);
         glScalef(1.7,1.7,1);
         glBegin(GL_QUADS);
                             glTexCoord3f(-1,1,0.3);
                             glVertex3f(-1,1,0.2);
                             glTexCoord3f(0,1,0.3);
                             glVertex3f(1,1,0.2);
                             glTexCoord3f(0,0,0.3);
                             glVertex3f(1,0,0.2);
                             glTexCoord3f(-1,0,0.3);
                             glVertex3f(-1,0,0.2);                                                  
         glEnd();         
     glPopMatrix();

     glDisable(GL_TEXTURE_2D);
     glDisable(GL_BLEND);
     glEnable(GL_LIGHTING);
}





float brickColor = 0;
int brickDir = 0;
void displayMenu()
{
     
     if(playThemeMusic)
     {
                       PlaySound(TEXT("theme.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
                       playThemeMusic = 0;
     }
     
     glutSetCursor(GLUT_CURSOR_INHERIT);
     drawBackground();
     //LEFT MENU
    glPushMatrix();
                   GLfloat left_diffuse[] = {1,0.16,0.16};
                   GLfloat left_ambient[] = {1,0.68,0.68};
                   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, left_diffuse);
                   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, left_ambient);
                   glTranslatef(-1.75,2.4,0);
                   glScalef(3.4,0.4,1);
                   glutSolidCube(1);
    glPopMatrix();
    
    
    //RIGHT MENU
    glPushMatrix();
                   GLfloat right_diffuse[] = {0.17,0.74,0.27};
                   GLfloat right_ambient[] = {0.78,1,0.68};
                   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, right_diffuse);
                   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, right_ambient);
                   glTranslatef(1.75,2.4,0);
                   glScalef(3.4,0.4,1);
                   glutSolidCube(1);
    glPopMatrix();
    
    //EXIT BUTTON
    glPushMatrix();
                   GLfloat exit_diffuse[] = {0,0.06,0.4};      //INITIAL : {0,0.06,0.4};
                   GLfloat exit_ambient[] = {1,0.99,0.53};
                   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, exit_diffuse);
                   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, exit_ambient);
                   glTranslatef(0,-2.8,-0.01);
                   glScalef(1,0.3,0.2);
                   glutSolidCube(1);
    glPopMatrix();
    
    if(brickColor>=1)
                     brickDir = 1;
    else if(brickColor <= 0)
                     brickDir = 0;
    if(brickDir==0)
                   brickColor+=0.05;
    else
                   brickColor-=0.05;
                   
    GLfloat details_diffuse[] = {0,0.16,brickColor};
    GLfloat details_ambient[] = {1,0.99,0.53};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, details_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, details_ambient);
    //ID BRICK
    glPushMatrix();
                   glTranslatef(-3.2,-2.8,-0.01);
                   glScalef(1.5,0.3,0.2);
                   glutSolidCube(1);
    glPopMatrix();
    
    //NAME BRICK
    glPushMatrix();
                   glTranslatef(3.2,-2.8,-0.01);
                   glScalef(1.5,0.3,0.2);
                   glutSolidCube(1);
    glPopMatrix();
    
    glDisable(GL_LIGHTING);
     
    glColor3ub(255,255,255);    
    glRasterPos3f(-1.7,1.6,2);
    printString("BURST SOME CRACKERS");
    
    glColor3ub(0,34,6);    
    glRasterPos3f(0.5,1.6,2);
    printString("SEND SOME GREETINGS");

    glColor3ub(0,23,197);
    renderBitmapString(-3.76,-2.8,0.1,(void *)smallFont,"2010A7PS070G");
    renderBitmapString(2.5,-2.8,0.1,(void *)smallFont,"Aniket Pednekar");
    glColor3f(1,1,1);
    renderBitmapString(-0.1,-2.57,0.5,(void *)smallFont,"Exit");
    
    glEnable(GL_LIGHTING);

}

void leftMenu()
{
    //LEFT POP DOWN
    glPushMatrix();
                   GLfloat left_down_diffuse[] = {0,0.12,0.35};
                   GLfloat left_down_ambient[] = {0.62,0.75,1};
                   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, left_down_diffuse);
                   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, left_down_ambient);
                   glTranslatef(-1.75,1,0);
                   glScalef(3.4,3.5,1);
                   glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
                   glScalef(0.5,0.5,0.5);
                   glTranslatef(-1.3,1,3);
                   rocketicon();
                   glTranslatef(-3,0,0);
                   flowerpoticon();
                   glTranslatef(1.5,2,0);
                   chakriicon();

    glPopMatrix();
}

void rightMenu()
{
    //RIGHT POP DOWN
    glPushMatrix();
                   GLfloat right_down_diffuse[] = {0,0.12,0.35};
                   GLfloat right_down_ambient[] = {0.62,0.75,1};
                   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, right_down_diffuse);
                   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, right_down_ambient);
                   glTranslatef(1.75,1.4,0);
                   glScalef(3.4,2.0,1);
                   glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
                   glScalef(0.5,0.5,0.5);
                   glTranslatef(1.5,2.8,3);
                   greeting1icon();
                   glTranslatef(2.5,0,0);
                   greeting2icon();

    glPopMatrix();
    
}

















float cangle = 20;
int chakri_axes[] = {0,0,0};

void steadychakri()
{
     glutSetCursor(GLUT_CURSOR_NONE);
     sparkler();
    backButton();
    glDisable(GL_LIGHTING);
     glBegin(GL_POLYGON);
                         glColor3ub(12,32,2);
                         glVertex3f(-50,50,-50);
                         glColor3ub(0,0,0);
                         glVertex3f(50,50,-50);
                         glColor3ub(32,77,10);
                         glVertex3f(50,-50,-50);
                         glColor3ub(0,0,0);
                         glVertex3f(-50,-50,-50);
     glEnd();
     glEnable(GL_LIGHTING);
     
     glPushMatrix();
     glRotatef(-45,1,0,0);
                        glPushMatrix();
                        glScalef(0.2,0.2,0.2);   
                        
                        
                        
                        //TORUS
                       GLfloat torus_diffuse[] = {0.8,0,0};
                       glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, torus_diffuse);
                       glPushMatrix();
                       glScalef(0.25,0.25,0.25);
                       glutWireTorus(1,10,15,30);
                       glPopMatrix();
                       
                       
                       
                       
                       //LIGHTING DISABLED
                       glDisable(GL_LIGHTING);                       
                       
                       //CHAKRI CENTER   
                        float radius=2.4;
                    
                        glBegin(GL_POLYGON);
                        glColor3f(0,0,0);
                        glVertex2f(0,0);
                        glColor3f(1,0.54,0);
                        int i;
                        float degInRad;
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0);
                       }
                       glEnd();
                       
                       //GREEN LINES
                         
                       glColor3f(0,1,0);
                       radius=2.0;
                        glBegin(GL_LINE_LOOP);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.02);
                       }
                       glEnd();
                       
                       radius=1.8;
                        glBegin(GL_LINE_LOOP);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.02);
                       }
                       glEnd();
                       
                       radius=0.7;
                        glBegin(GL_POLYGON);
                        glColor3f(0,0.7,0);
                        glVertex2f(0,0);
                        glColor3f(0,0.3,0);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.03);
                       }
                       glEnd();
                       
                       //RED CENTRE  
                      radius=1.2;
                        glBegin(GL_POLYGON);
                        glColor3f(0.5,0,0);
                        glVertex2f(0,0);
                        glColor3f(1,0,0);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),0.02);
                       }
                       glEnd();
                        glPopMatrix();
                        
                         glEnable(GL_LIGHTING);
     glPopMatrix();

}


void chakri()
{
     glutSetCursor(GLUT_CURSOR_NONE);
     sparkler();
     backButton();
     glDisable(GL_LIGHTING);
     glBegin(GL_POLYGON);
                         glColor3ub(12,32,2);
                         glVertex3f(-50,50,-50);
                         glColor3ub(0,0,0);
                         glVertex3f(50,50,-50);
                         glColor3ub(32,77,10);
                         glVertex3f(50,-50,-50);
                         glColor3ub(0,0,0);
                         glVertex3f(-50,-50,-50);
     glEnd();
     glEnable(GL_LIGHTING);
     
     glPushMatrix();
     glRotatef(-45,1,0,0);

                         
                         int dir = 0;
                        glPushMatrix();
                        glScalef(0.2,0.2,0.2);
                        glTranslatef(chakri_axes[0],chakri_axes[1],chakri_axes[2]);
                       
                       //TORUS
                       GLfloat torus_diffuse[] = {0.8,0,0};
                       glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, torus_diffuse);
                       glPushMatrix();
                       glScalef(0.25,0.25,0.25);
                       glutWireTorus(1,10,15,30);
                       glPopMatrix();
         
         
                       //LIGHTING DISABLED
                       glDisable(GL_LIGHTING);
                       
                       
                       //CHAKRI CENTER   
                        float radius=2.5;
                    
                        glBegin(GL_POLYGON);
                        glColor3f(0,0,0);
                        glVertex2f(0,0);
                        glColor3f(1,0.54,0);
                        int i;
                        float degInRad;
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0);
                       }
                       glEnd();
                       
                       //GREEN LINES
                         
                       glColor3f(0,1,0);
                       radius=2.0;
                        glBegin(GL_LINE_LOOP);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.02);
                       }
                       glEnd();
                       
                       radius=1.8;
                        glBegin(GL_LINE_LOOP);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.02);
                       }
                       glEnd();
                       
                       radius=0.7;
                        glBegin(GL_POLYGON);
                        glColor3f(0,0.7,0);
                        glVertex2f(0,0);
                        glColor3f(0,0.3,0);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.03);
                       }
                       glEnd();
                       
                       //RED CENTRE  
                      radius=1.2;
                        glBegin(GL_POLYGON);
                        glColor3f(0.5,0,0);
                        glVertex2f(0,0);
                        glColor3f(1,0,0);
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),0.02);
                       }
                       glEnd();
                       
                        glFermatSpiral(0.05, 0.5, cangle+1, cangle+75.0, 80);
                        glPopMatrix();
                        
                        cangle -= 0.1;
                        dir = rand()%2;
                        int incAxis = rand()%3;
                        if(dir)
                        {
                               if(chakri_axes[incAxis] < 4)
                                   chakri_axes[incAxis]++;
                        }
                        else
                        {
                               if(chakri_axes[incAxis] > -4)
                                   chakri_axes[incAxis]--;
                        }
                         glEnable(GL_LIGHTING);
                   
     glPopMatrix();
}

void steadyflowerpot() {
     
     glutSetCursor(GLUT_CURSOR_NONE);
     sparkler();
     drawBackground();
     GLfloat flowerpot_diffuse[] = {0.02,0,1};
     GLfloat flowerpot_ambient[] = {1,0,1};
     GLfloat flowerpot_shininess[] = { 100 };
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, flowerpot_diffuse);
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, flowerpot_ambient);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, flowerpot_shininess);
     backButton();
     
     glPushMatrix();
          glRotatef(-100.0, 1,0,0);
          glTranslatef(0,0,-2);
          glutSolidCone(0.2,0.5,20,20);
     glPopMatrix();
         
}

void flowerpot() {
     
     glutSetCursor(GLUT_CURSOR_NONE);
     sparkler();
     drawBackground();
     GLfloat flowerpot_diffuse[] = {0.02,0,1};
     GLfloat flowerpot_ambient[] = {1,0,1};
     GLfloat flowerpot_shininess[] = { 100 };
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, flowerpot_diffuse);
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, flowerpot_ambient);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, flowerpot_shininess);
     backButton();
     
     glPushMatrix();
          glRotatef(-100.0, 1,0,0);
          glTranslatef(0,0,-2);
          glutSolidCone(0.2,0.5,20,20);
     glPopMatrix();
     
     
     glPushMatrix();
          glTranslatef(0,1,0);
          fireworks();
     glPopMatrix();

     
}

void fireworks(void) {
     
     glEnable(GL_TEXTURE_2D); 
     GLfloat sparks_diffuse[] = {0.2,0.5,1};
     GLfloat sparks_ambient[] = {1,1,0};
     GLfloat sparks_shininess[] = { 100 };
     GLfloat temp_ambient[] = {1,1,1};
     
     glLightfv (GL_LIGHT0, GL_AMBIENT, temp_ambient);
     
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sparks_diffuse);
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sparks_ambient);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, sparks_shininess);
     glUpdateParticles();
        glPushMatrix();
                    glScalef(0.7,0.9,1);
                    glTranslatef(0,0.7,0);
                    glUpdateParticles();
                    glDrawParticles();
        glPopMatrix();  
      glDisable(GL_TEXTURE_2D);
      
}




int playBlastMusic = 1;

float rocketx = -2;
float rockety = -1;
float rocketz = 0;
float rocketangle = 0;

void steadyrocket()
{
     playBlastMusic = 1;
     glutSetCursor(GLUT_CURSOR_NONE);
     sparkler();
     drawBackground();
     
     glPushMatrix();
     glScalef(0.6,0.6,0.6);
                         GLfloat cyl_red[] = {1,0,0};
                         GLfloat cyl_yellow[] = {1,1,0};
                         GLfloat cyl_dark_red[] = {0.4,0,0};                         
                         GLfloat cyl_dark_yellow[] = {0.5,0.5,0};
                         GLfloat cyl_white[] = {0.8,0.8,0.8};
                         GLfloat rocket_ambient[] = {0.2,0.2,0.2};
                     
                     glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, rocket_ambient);      
                     glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_white);      
                     glPushMatrix();
                                 
                                 glTranslatef(-2,-2,0);            //-1 0 1
                                 glRotatef(90,1,0,0);
                                 gluCylinder(qobj, 0.4, 0.4, 1.4, 15, 16);
                     glPopMatrix();
                
                         
                     glPushMatrix();
                        glTranslatef(-2,-1,0);                     //-1 0 0
                        glRotatef(-1*rocketangle, 1,0,1);
                        glPushMatrix();
                                 glRotatef(90,1,0,0);
                                 glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_red); 
                                 gluCylinder(qobj, 0.2, 0.2, 1.0, 15, 16);
                                 glPushMatrix();
                                                glTranslatef(0,0,0.22);
                                                glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_dark_yellow);                                 
                                                gluCylinder(qobj, 0.21, 0.21, 0.5, 15, 16);                                 
                                 glPopMatrix();
                                 glRotatef(180,1,0,0);
                                 glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_dark_red); 
                                 glutSolidCone(0.3,0.5,20,20);                                 
                                 glTranslatef(-0.18,0,-2);
                                 
                                 glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_yellow);
                                 gluCylinder(qobj, 0.01, 0.01, 1.0, 15, 16);
                        glPopMatrix();
                     glPopMatrix();
     glPopMatrix();
     backButton();
}

float blinkTime = 0;
void rocketBlinkScreen()
{
     if(playBlastMusic)
     {
         PlaySound(TEXT("blast.wav"), NULL, SND_ASYNC|SND_FILENAME);
         playBlastMusic = 0;
     }
     sparkler();
     backButton();
     glDisable(GL_LIGHTING);
     glColor3ub(rand()%255,rand()%255,rand()%255);
     glBegin(GL_QUADS);
                       glVertex3f(-6,4,0);
                       glVertex3f(6,4,0);
                       glVertex3f(6,-4,0);
                       glVertex3f(-6,-4,0);                                              
     glEnd();
     glEnable(GL_LIGHTING);
     blinkTime += 0.1;
     if(blinkTime >= 10)
     {
             status = DISPLAY_MENU;
             resetMaterialProperties();
             glDisable(GL_TEXTURE_2D);
             rocketx = -2;
             rockety = -1;
             rocketz = 0;
             rocketangle = 0;
             glutSetCursor(GLUT_CURSOR_INHERIT);
     }
}


void rocket()
{
     glutSetCursor(GLUT_CURSOR_NONE);
     sparkler();
     
     drawBackground();
     
     GLfloat rocket_ambient[] = {0.2,0.2,0.2};
     glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, rocket_ambient);      
     
     glPushMatrix();
     glScalef(0.6,0.6,0.6);
                         GLfloat cyl_red[] = {1,0,0};
                         GLfloat cyl_yellow[] = {1,1,0};
                         GLfloat cyl_dark_red[] = {0.4,0,0};                         
                         GLfloat cyl_dark_yellow[] = {0.5,0.5,0};                         
                         GLfloat cyl_white[] = {0.8,0.8,0.8};
                
                     glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_white);      
                     glPushMatrix();
                                 glTranslatef(-2,-2,0);
                                 glRotatef(90,1,0,0);
                                 gluCylinder(qobj, 0.4, 0.4, 1.4, 15, 16);
                     glPopMatrix();
                
     
                     glPushMatrix();
                        glTranslatef(rocketx,rockety, rocketz);
                        //glTranslatef(-1,0,0);
                        glRotatef(-1*rocketangle, 1,0,1);
                        glPushMatrix();
                                 glRotatef(90,1,0,0);
                                 glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_red);
                                 gluCylinder(qobj, 0.2, 0.2, 1.0, 15, 16);
                                 glPushMatrix();
                                                glTranslatef(0,0,0.22);
                                                glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_dark_yellow);                                 
                                                gluCylinder(qobj, 0.21, 0.21, 0.5, 15, 16);                                 
                                 glPopMatrix();
                                 glRotatef(180,1,0,0);                                 
                                 glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_dark_red);
                                 glutSolidCone(0.3,0.5,20,20);
                                 glTranslatef(-0.18,0,-2);
                                 
                                 glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, cyl_yellow);
                                 gluCylinder(qobj, 0.01, 0.01, 1.0, 15, 16);
                        glPopMatrix();
                        //glutSolidCone(0.3,0.5,20,20);
                     glPopMatrix();
                     rocketx += 0.1;
                     rockety += 0.4;
                     rocketz -= 0.2;
                     if(rocketangle < 90)
                          rocketangle += 1;
     glPopMatrix();
     backButton();
     if(rockety >= 10)
                status=ROCKETBLINK;
}

void rocketicon()
{
            
            
            glDisable(GL_LIGHTING);

            
            int i;
            float degInRad;
            float radius = 0.9;
            
            glPushMatrix();
            glTranslatef(0,-0.8,0);
                glBegin(GL_POLYGON);
                glColor3f(1,1,1);
                glVertex2f(0,0);
                glColor3ub(255,253,87);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),-0.01);
               }
               glEnd();
            glPopMatrix();
            
            glBegin(GL_POLYGON);
                                 glColor3ub(221,0,0);
                                 glVertex2f(0,0);
                                 glColor3ub(228,78,78);
                                 glVertex2f(-0.2,-0.4);
                                 glVertex2f(0.2,-0.4);
            glEnd();
            glBegin(GL_POLYGON);
                                 glColor3ub(162,76,0);
                                 glVertex2f(-0.15,-0.4);
                                 glVertex2f(0.15,-0.4);
                                
                                 glColor3ub(247,117,0);
                                 glVertex2f(0.15,-1);
                                 glVertex2f(-0.15,-1);
            glEnd();
            
            glBegin(GL_LINES);
                              glColor3f(0,0,0);
                              glVertex2f(-0.15,-1);
                              glColor3f(1,1,0);
                              glVertex2f(-0.15,-1.5);
            glEnd();
            glEnable(GL_LIGHTING);
}

void flowerpoticon()
{
            
            
            glDisable(GL_LIGHTING);

            
            int i;
            float degInRad;
            float radius = 0.9;
            
            glPushMatrix();
            glTranslatef(0,-0.8,0);
                glBegin(GL_POLYGON);
                glColor3f(1,1,1);
                glVertex2f(0,0);
                glColor3ub(255,253,87);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),-0.01);
               }
               glEnd();
            glPopMatrix();
            
            glBegin(GL_POLYGON);
                                 glColor3ub(25, 42, 119);
                                 glVertex2f(0,0);
                                 glColor3ub(0,48,255);
                                 glVertex2f(-0.5,-1.3);
                                 glColor3ub(60,97,255);
                                 glVertex2f(0.5,-1.3);
            glEnd();
            glEnable(GL_LIGHTING);
}

void chakriicon()
{
            
            
            glDisable(GL_LIGHTING);

            
            int i;
            float degInRad;
            float radius = 0.9;
            
            glPushMatrix();
            glTranslatef(0,-0.8,0);
                glBegin(GL_POLYGON);
                glColor3f(1,1,1);
                glVertex2f(0,0);
                glColor3ub(255,253,87);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),-0.01);
               }
               glEnd();
               
               radius = 0.5;
               glBegin(GL_POLYGON);
                glColor3ub(255,84,0);
                glVertex2f(0,0);
                glColor3ub(148,30,2);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),0.00);
               }
               glEnd();
               
               radius = 0.2;
               glBegin(GL_POLYGON);
                glColor3ub(40,163,16);
                glVertex2f(0,0);
                glColor3ub(11,66,0);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),0.01);
               }
               glEnd();
            glPopMatrix();
            
            glEnable(GL_LIGHTING);
}

void backButton()
{
     glDisable(GL_LIGHTING);
     glPushMatrix();
     glScalef(0.4,0.1,1);
     glTranslatef(7.5,-27,0);
                            glBegin(GL_POLYGON);
                                                 glColor3ub(133,18,0);
                                                 glVertex3f(-1,1,0);
                                                 glColor3ub(205,21,7);
                                                 glVertex3f(1,1,0);
                                                 glColor3ub(79,9,4);
                                                 glVertex3f(1,-1,0);
                                                 glColor3ub(205,21,7);
                                                 glVertex3f(-1,-1,0);
                            glEnd();
     glPopMatrix();
     
     glColor3f(1,1,1);
     glRasterPos3f(2.85,-2.75,0.01);
                        printString("BACK");
     glEnable(GL_LIGHTING);
}


void resetMaterialProperties()
{
     GLfloat DefaultDiffuseLight[] = {0.8, 0.8, 0.8, 1.0};
     GLfloat DefaultAmbientLight[] = {0.2, 0.2, 0.2, 1.0};
     GLfloat DefaultEmissionLight[] = {0.0, 0.0, 0.0, 1.0};
     GLfloat DefaultSpecularLight[] = {0.0, 0.0, 0.0, 1.0};
     GLfloat DefaultShininess[] = {0};
     
     glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, DefaultDiffuseLight);
     glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, DefaultAmbientLight);
     glMaterialfv (GL_FRONT_AND_BACK, GL_EMISSION, DefaultEmissionLight);
     glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR, DefaultSpecularLight);
     glMaterialfv (GL_FRONT_AND_BACK, GL_SHININESS, DefaultShininess);
}




sparkler()
{
          glDisable(GL_LIGHTING);
          glPushMatrix();
          glTranslatef(passiveX,passiveY,3);
          glRotatef(75,0,0,1);
          glScalef(0.1,0.2,1);
          glBegin(GL_POLYGON);
                              
                              glColor3ub(3,42,108);
                              glVertex2f(-0.1,0);
                              glColor3ub(255,255,255);
                              glVertex2f(0,0.2);
                              glColor3ub(3,42,108);
                              glVertex2f(0.1,0);
                              glColor3ub(0,0,0);
                              glVertex2f(0.1,-2);
                              glVertex2f(-0.1,-2);
          glEnd();
          glBegin(GL_POLYGON);
                              
                              glColor3ub(83,28,3);
                              glVertex2f(-0.01,-2);
                              glVertex2f(0.01,-2);
                              glColor3f(1,1,1);
                              glVertex2f(0.01,-3);
                              glVertex2f(-0.01,-3);
          glEnd();
          
          
          glPopMatrix();;
          glEnable(GL_LIGHTING);
}

void diya()
{
     int i;
     float radius;
    float degInRad;
    float centerX,centerY;
    
          radius=0.6;
                       centerX=-1.5, centerY=0;
                        glBegin(GL_POLYGON);
                        glColor3ub(21,6,1);
                        glVertex3f(centerX,centerY,0.1);
                        glColor3ub(91,35,5);
                       for (i=180; i <= 360; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius +centerX,sin(degInRad)*radius+centerY,0.1);
                       }
                       glEnd();
         glPushMatrix();
                        glScalef(0.2,0.7,1);
                        radius=0.6;
                        centerX= -4.5, centerY=0.7;
                        glBegin(GL_POLYGON);
                        glColor3ub(255,248,0);
                        glVertex3f(centerX,centerY,0.1);
                        glColor3ub(255,127,0);
                        degInRad;
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius +centerX,sin(degInRad)*radius+centerY,0.1);
                       }
                       glEnd();
                       
         glPopMatrix();
}

float openAngle1 = 135;
int colRed[] = {255,177,15,94};
int cDir[] = {0,0,0,0};
int diyaRotator=361;
void greeting1()
{
    backButton();
    
    int i;
    float diyaRotationRadius=0.5;
    float radius;
    float degInRad;
     
     glDisable(GL_LIGHTING);
     glBegin(GL_QUADS);
                       glColor3f(1,1,1);
                       glVertex3f(-5,5,-0.2);
                       glColor3f(50,1,1);
                       glVertex3f(5,5,-0.2);
                       glColor3ub(colRed[0],colRed[0],colRed[0]);
                       glVertex3f(5,-5,-0.2);
                       glColor3f(0,0.5,0.5);
                       glVertex3f(-5,-5,-0.2);
     glEnd();
     
     glBegin(GL_QUADS);
                       glColor3ub(colRed[0],0,0);
                       glVertex3f(0,2,0);
                       glColor3ub(colRed[1],1,0);
                       glVertex3f(3,2,0);
                       glColor3ub(colRed[2],3,1);
                       glVertex3f(3,-2,0);
                       glColor3ub(colRed[3],2,1);
                       glVertex3f(0,-2,0);
     glEnd();
     
     
     //TEXT
     glColor3ub(255,200,0);
     renderBitmapString(0.8,1,0.1,(void *)bigFont,"Happy Diwali");
     
     glColor3ub(255,201,106);

     renderBitmapString(0.4,0.5,0.1,(void *)smallFont,"With a hope that you attain");     

     renderBitmapString(0.7,0.25,0.1,(void *)smallFont,"Success and Bliss,");     

     renderBitmapString(0.4,0,0.1,(void *)smallFont,"With every light that is lit");     

     renderBitmapString(0.62,-0.25,0.1,(void *)smallFont,"on the Day of Diwali.");     
     
     glColor3ub(225,82,54);

     renderBitmapString(0.85,-0.75,0.1,(void *)smallFont,"Best Regards,");     

     glColor3ub(226,74,0);     
     if(status==GREETING1)
     {
          renderBitmapString(0.6,-0.95,0.1,(void *)smallFont,"ENTER YOUR NAME");
     }
     else
     {
         renderBitmapString(1.1,-0.95,0.1,(void *)smallFont,name1);
     }
     
     glColor3f(0.3,0,0);
     glBegin(GL_LINES);
                       glVertex3f(0,2,0.01);
                       glVertex3f(0,-2,0.01);
     glEnd();
    
    glPushMatrix();
     
         glRotatef(openAngle1,0,1,0);
         glBegin(GL_QUADS);
         glColor3f(1,1,1);
                       glColor3ub(colRed[0],0,0);
                       glVertex3f(0,2,0);
                       glColor3ub(colRed[1],1,0);
                       glVertex3f(-3,2,0);
                       glColor3ub(colRed[2],3,1);
                       glVertex3f(-3,-2,0);
                       glColor3ub(colRed[3],2,1);
                       glVertex3f(0,-2,0);
         glEnd();
                 glPushMatrix();
                       degInRad = diyaRotator*3.14/180;
                       glTranslatef(cos(degInRad)*diyaRotationRadius,sin(degInRad)*diyaRotationRadius,0);
                       diya();
                       
                       diyaRotator -= 5;
                       if(diyaRotator <= 0)
                                      diyaRotator = 361;
                 glPopMatrix();
                       
         
         
         
     glPopMatrix();

     
     if(openAngle1>30)
                      openAngle1 -= 3;

     
     for(i=0;i<4;i++)
     {
                     
                     if(cDir[i]==0)
                        colRed[i] += 10;
                     else
                        colRed[i] -= 10;
                     if(colRed[i] >= 255)
                     {
                        cDir[i] = 1;
                        colRed[i] = 255;
                     }
                     else if(colRed[i] <= 0)
                     {  
                        cDir[i] = 0;
                        colRed[i] = 0;
                     }
     }
     
     glEnable(GL_LIGHTING);
}

void greeting1icon()
{
            
            
            glDisable(GL_LIGHTING);

            
            int i;
            float degInRad;
            float radius = 0.9;
            
            glPushMatrix();
            glTranslatef(0,-0.8,0);
                glBegin(GL_POLYGON);
                glColor3f(1,1,1);
                glVertex2f(0,0);
                glColor3ub(255,253,87);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),-0.01);
               }
               glEnd();
               
               glScalef(0.7,0.7,0.7);
               glTranslatef(1.5,-0.2,0);
               diya();
            glPopMatrix();
            
            
            glEnable(GL_LIGHTING);
}

void sideLight(int color)
{
     //RED: 0
     //GREEN: 1
     //BLUE: 2
     
     int i;
     float radius;
     float degInRad;
    
    GLubyte red[]  = { 255, 0, 0};
    GLubyte green[]  = {   0, 255,   0};
    GLubyte blue[]  = { 0,  0, 255};
    
    glPushMatrix();
          radius=0.6;
          glScalef(0.07,0.3,1);
          glBegin(GL_POLYGON);
              switch(color)
              {
                           case 0:
                                glColor3ubv(red);
                                break;
                           case 1:
                                glColor3ubv(green);
                                break;
                           case 2:
                                glColor3ubv(blue);
                                break;
                           default:
                                glColor3ubv(red);
                                break;
              }
               
               glVertex3f(0,0,0.1);
               glColor3ub(0,0,0);
               for (i=0; i <= 361; i++)
               {
                    degInRad = i*3.14/180;
                    glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.1);
               }
               glEnd();     
    glPopMatrix();
}


void greeting2img()
{
     int i;
     
     glDisable(GL_LIGHTING);
     glEnable(GL_TEXTURE_2D);
         
     ganpati = LoadTextureRAW("ganpati.raw",400,400);     
     
     glBindTexture (GL_TEXTURE_2D, ganpati);
          
     glPushMatrix();
         glTranslatef(1.2,0,0);
         glScalef(1.5,1.5,1);
         glBegin(GL_POLYGON);
                             glTexCoord3f(-1,1,0.3);
                             glVertex3f(-1,1,0.2);
                             glTexCoord3f(0,1,0.3);
                             glVertex3f(1,1,0.2);
                             glTexCoord3f(0,0,0.3);
                             glVertex3f(1,-1,0.2);
                             glTexCoord3f(-1,0,0.3);
                             glVertex3f(-1,-1,0.2);                                                  
         glEnd();         
     glPopMatrix();
     
     happydiwali = LoadTextureRAW("happydiwali.raw",300,300);
     glBindTexture( GL_TEXTURE_2D,happydiwali );
     glPushMatrix();
         glTranslatef(-1.55,0,0);
         glScalef(1.3,1.3,1);
         glBegin(GL_POLYGON);
                             glTexCoord3f(-1,1,0.3);
                             glVertex3f(-1,1,0.2);
                             glTexCoord3f(0,1,0.3);
                             glVertex3f(1,1,0.2);
                             glTexCoord3f(0,0,0.3);
                             glVertex3f(1,-1,0.2);
                             glTexCoord3f(-1,0,0.3);
                             glVertex3f(-1,-1,0.2);                                                  
         glEnd();
     glPopMatrix();
     
     glEnable(GL_LIGHTING);
     glDisable(GL_TEXTURE_2D);
}

float triangleAngle2 = 1;
int dir;
int startColor = 0;
void greeting2()
{
     backButton();
     greeting2img();
     float i;
     int toggler = 0;
     glDisable(GL_LIGHTING);
     
            //BACKGROUND
                 glBegin(GL_QUADS);
                       glColor3f(0,0,0);
                       glVertex3f(-5,5,-0.2);
                       glColor3f(50,50,1);
                       glVertex3f(5,5,-0.2);
                       glColor3ub(153,153,255);
                       glVertex3f(5,-5,-0.2);
                       glColor3f(0,0.5,0.5);
                       glVertex3f(-5,-5,-0.2);
                glEnd();
            
            glBegin(GL_POLYGON);
                    glColor3ub(252,255,5);
                    glVertex3f(-3.2,2.5,0);
                    glColor3ub(248,228,0);
                    glVertex3f(3.2,2.5,0);
                    glColor3ub(68,63,2);                    
                    glVertex3f(3.2,-2.5,0);                    
                    glColor3ub(68,63,2);
                    glVertex3f(-3.2,-2.5,0);
            glEnd();
            
            glPushMatrix();
            glTranslatef(0,2.4,0);
            glRotatef(triangleAngle2,1,0,0);

            
                
                glBegin(GL_TRIANGLES);
                   for(i=-3.2; i<=3.2; i=i+0.4 )
                   {
                        glColor3ub(107,3,3);
                        glVertex3f(i,0,0.01);
                        glVertex3f(i+0.4,0,0.01);
                        if(toggler)
                        {
                            glColor3ub(255,0,0);
                            toggler = 0;
                        }
                        else
                        {
                            glColor3ub(255,96,0);
                            toggler = 1;  
                        }
                        glVertex3f(i+0.2,-0.6,0.01);
                        }
                glEnd();
            
            glPopMatrix();
            
            //LIGHTS
            int colorIterator = startColor;
            int numLights;
            
            //LEFT
            glPushMatrix();
                           glTranslatef(-3,1.4,0);
                           for(numLights = 11; numLights>0; numLights-=1)
                           {
                                            colorIterator=(colorIterator + 1)%3;
                                             sideLight(colorIterator);
                                             glTranslatef(0,-0.35,0);
                           }
            glPopMatrix();
            
            //RIGHT
            glPushMatrix();
                           glTranslatef(3,1.4,0);
                           for(numLights = 11; numLights>0; numLights-=1)
                           {
                                            colorIterator=(colorIterator + 1)%3;
                                             sideLight(colorIterator);
                                             glTranslatef(0,-0.35,0);
                           }

            glPopMatrix();
            
            //BOTTOM
            glPushMatrix();
                           glTranslatef(-2.8,-2.3,0);
                           glRotatef(90,0,0,1);
                           for(numLights = 17; numLights>0; numLights-=1)
                           {
                                            colorIterator=(colorIterator + 1)%3;
                                             sideLight(colorIterator);
                                             glTranslatef(0,-0.35,0);
                           }

            glPopMatrix();
            
            startColor = (startColor + 1)%3;
            //sleep(25);
            
            if(triangleAngle2>=0)
                  dir = 1;
             else if(triangleAngle2<=-45)
                  dir = 0;
                  
             if(dir==0)
                  triangleAngle2 += 2;
             else
                  triangleAngle2 -= 2;

     
     //TEXT
     glColor3ub(255,255,255);
     if(status==GREETING2)
     {
          renderBitmapString(-1.4,-1.8,0.1,(void *)bigFont,"ENTER YOUR MESSAGE");
     }
     else
     {
         glRasterPos3f(-1,-1.8,0.1);
         renderBitmapString(-2,-1.8,0.1,(void *)bigFont,name2);
     }
               
     glEnable(GL_LIGHTING);
}

int iconColorIter=0;
int sleepCount = 0;
void greeting2icon()
{
            sleepCount += 1;
            
            glDisable(GL_LIGHTING);
            
            if(sleepCount >= 10)
            {
                         iconColorIter = (iconColorIter+1)%3;
                         sleepCount = 0;
            }
                        
            int i;
            float degInRad;
            float radius = 0.9;
            
            glPushMatrix();
            glTranslatef(0,-0.8,0);
                glBegin(GL_POLYGON);
                glColor3f(1,1,1);
                glVertex2f(0,0);
                glColor3ub(255,253,87);
               for (i=0; i <= 361; i++)
               {
                  degInRad = i*3.14/180;
                  glVertex3f(cos(degInRad)*(1.0*radius),sin(degInRad)*(1.0*radius),-0.01);
               }
               glEnd();
            glTranslatef(-0.05,-0.05,0);
            glScalef(14.28,3.33,1);

            sideLight(iconColorIter);
            glPopMatrix();

            
            glEnable(GL_LIGHTING);
}


void display (void) {
    glDisable( GL_TEXTURE_2D );
     
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();  
    GLfloat DiffuseLight[] = {1,1,1}; //set DiffuseLight[] to the specified values
    GLfloat AmbientLight[] = {0,0,0}; //set AmbientLight[] to the specified values
    glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight); //change the light accordingly
    glLightfv (GL_LIGHT0, GL_AMBIENT, AmbientLight); //change the light accordingly
    GLfloat LightPosition[] = {lx, ly, lz, lw}; //set the LightPosition to the specified values
    glLightfv (GL_LIGHT0, GL_POSITION, LightPosition); //change the light accordingly
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //camera position, x,y,z, looking at x,y,z, Up Positions of the camera

    
    if(status==DISPLAY_MENU)
    {
         displayMenu();
         titleOnTop();
    }
    else if(status==LEFT_MENU)
    {
         displayMenu();
         titleBelow();         
         leftMenu();
    }
    else if(status==RIGHT_MENU)
    {
         displayMenu();
         titleBelow();         
         rightMenu();
    }
    else if(status==CHAKRI_STEADY)
    {
         steadychakri();
    }
    else if(status==CHAKRI)
    {
         playThemeMusic = 1;      //When back to display, play theme music         
         chakri();
    }
    else if(status==FLOWERPOT_STEADY)
    {
         steadyflowerpot();
    }
    else if(status==FLOWERPOT)
    {
         playThemeMusic = 1;      //When back to display, play theme music         
         flowerpot();
    }
    else if(status==ROCKET_STEADY)
    {
         steadyrocket();
    }
    else if(status==ROCKET)
    {
         playThemeMusic = 1;      //When back to display, play theme music         
         rocket();
    }
    else if(status==ROCKETBLINK)
    {
         rocketBlinkScreen();
    }
    else if(status==GREETING1 || status==GREETING1SIGNED)
    {
         greeting1();
    }
    else if(status==GREETING2 || status==GREETING2SIGNED)
    {
         greeting2();
    }
    
    glutSwapBuffers(); //swap the buffers
    //angle++; //increase the angle
    if(status!=0 && status !=1 && status !=2) 
         sleep(35);
}

void reshape (int w, int h) {
     scr_width = w;
     scr_height = h;
     
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

void mouseClick(int button, int state, int xClick, int yClick)
{
     //printf("%d %d\n", xClick, yClick);
     if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
     {
            
                 float x, y;
                 float sceneWidth, sceneHeight;
                 
                    sceneHeight = scr_height;
                    sceneWidth = scr_height * 4.0/3.0;
                    x = (xClick - (scr_width - sceneWidth)/2)/sceneWidth * 800.0;
                    y = yClick/sceneHeight * 600.0;
            
                 
                 if(status==DISPLAY_MENU)
                 {
                     if(x>0 && x<390 && y>0 && y<45)
                            status = LEFT_MENU;
                     else if(x>405 && x<800 && y>0 && y<45)
                            status = RIGHT_MENU;
                     else if(x>350 && x<455 && y>570 && y<600)
                               exit(0);
                 }
                 else if(status==LEFT_MENU)
                 {
                      if(x>125 && x<260 && y>65 && y<205)
                               status = CHAKRI_STEADY;
                      else if(x>15 && x<150 && y>215 && y<350)
                               status = FLOWERPOT_STEADY;
                      else if(x>235 && x<370 && y>215 && y<350)
                               status = ROCKET_STEADY;
                      else if(x>405 && x<800 && y>0 && y<45)
                               status = RIGHT_MENU;
                      else if(x>350 && x<455 && y>570 && y<600)
                               exit(0);
                      else
                               status = DISPLAY_MENU;
            
                 }
                 else if(status==RIGHT_MENU)
                 {
                      if(x>0 && x<390 && y>0 && y<45)
                            status = LEFT_MENU;
                      else if(x>445 && x<580 && y>85 && y<220)
                               status = GREETING1;
                      else if(x>630 && x<763 && y>85 && y<220)
                               status = GREETING2;
                      else if(x>350 && x<455 && y>570 && y<600)
                               exit(0);                               
                      else
                               status = DISPLAY_MENU;                      
            
                            
                 }
                 else if(status==CHAKRI_STEADY)
                 {
                      if(x>347 && x<452 && y>247 && y<353)
                      {
                               PlaySound(TEXT("chakri.wav"), NULL, SND_ASYNC|SND_FILENAME);
                               status = CHAKRI;
                      }
                      else if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                      }
                 }
                 else if(status==FLOWERPOT_STEADY)
                 {
                      if(x>375 && x<425 && y>460 && y<525)
                      {
                               PlaySound(TEXT("flowerpot.wav"), NULL, SND_ASYNC|SND_FILENAME);
                               status = FLOWERPOT;
                               glCreateParticles();
                               texture[0] = LoadTextureRAW( "particle_mask.raw",256,256); //load our texture
                               texture[1] = LoadTextureRAW( "particle.raw",256,256); 
                      }
                      else if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                                 FreeTexture(texture[0]);
                                 FreeTexture(texture[1]);
                      }
                 }
                 else if(status==ROCKET_STEADY)
                 {
                      if(x>250 && x<300 && y>330 && y<530)
                      {
                               PlaySound(TEXT("whoosh.wav"), NULL, SND_ASYNC|SND_FILENAME);
                               sleep(50);
                               status = ROCKET;
                      }
                      else if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                      }
                 }
                 else if(status==CHAKRI)
                 {
                      if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 cangle = 50;
                                 chakri_axes[0] = 0;
                                 chakri_axes[1] = 0;
                                 chakri_axes[2] = 0;
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                      }
                 }
                 else if(status==FLOWERPOT)
                 {
                      if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                                 FreeTexture(0);
                                 FreeTexture(1);
                                 FreeTexture(2);
                                 GLfloat restore_ambient[] = {0,0,0};
                                 glLightfv (GL_LIGHT0, GL_AMBIENT, restore_ambient);
                      }
                 }
                 else if(status==ROCKET)
                 {
                      if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 glDisable(GL_TEXTURE_2D);
                                 rocketx = -2;
                                 rockety = -1;
                                 rocketz = 0;
                                 rocketangle = 0;
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                      }
                 }
                  else if(status==ROCKETBLINK)
                 {
                      if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 resetMaterialProperties();
                                 glDisable(GL_TEXTURE_2D);
                                 rocketx = -2;
                                 rockety = -1;
                                 rocketz = 0;
                                 rocketangle = 0;
                                 glutSetCursor(GLUT_CURSOR_INHERIT);
                      }
                 }
                 else if(status==GREETING1 || status==GREETING1SIGNED)
                 {
                      if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 openAngle1 = 135;
                                 name1[0] = '\0';
                                 name1Iter = 0;
                      }
                 }
                 else if(status==GREETING2 || status==GREETING2SIGNED)
                 {
                      if(x>670 && x<750 && y>570 && y<590)
                      { 
                                 status = DISPLAY_MENU;
                                 name2[0] = '\0';
                                 name2Iter = 0;
                                 FreeTexture(ganpati);
                                 FreeTexture(happydiwali);
                      }
                 }
     }
}

void keyboard (unsigned char key, int x, int y) {
     if(status==GREETING1)
     {
                          if(key==13) //ENTER
                          {
                                      status=GREETING1SIGNED;
                                      name1[name1Iter]='\0';
                          }
                          else
                          {
                                      name1[name1Iter]=key;
                                      name1Iter++;
                          }
     }
     
     if(status==GREETING2)
     {
                          if(key==13) //ENTER
                          {
                                      status=GREETING2SIGNED;
                                      name2[name2Iter]='\0';
                          }
                          else
                          {
                                      name2[name2Iter]=key;
                                      name2Iter++;
                          }
     }
    
}

void passiveMotion(int x, int y)
{
     passiveX = x/800.0*3.06 -1.53;
     passiveY = -1*(y/600.0*2.28 -1.14);
}

int main (int argc, char **argv) {

    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); //set the display to Double buffer, with depth
    glutInitWindowSize (800, 600); //set the window size
    glutInitWindowPosition (100, 100); //set the position of the window
    glutCreateWindow ("Happy Diwali"); //the caption of the window
    init (); //call the init function
    glutDisplayFunc (display); //use the display function to draw everything
    glutIdleFunc (display); //update any variables in display, display can be changed to anyhing, as long as you move the variables to be updated, in this case, angle++;
    glutReshapeFunc (reshape); //reshape the window accordingly
    glutMouseFunc(mouseClick);
    glutKeyboardFunc (keyboard); //check the keyboard
    glutPassiveMotionFunc(passiveMotion);
    glutMainLoop (); //call the main loop

    return 0;
}


//function to load the RAW file

GLuint LoadTextureRAW( const char * filename, int width, 
int height )
{
  GLuint texture;
  unsigned char * data;
  FILE * file;

  file = fopen( filename, "rb" );
  if ( file == NULL ) return 0;

  data = (unsigned char *)malloc( width * height * 3 );

  fread( data, width * height * 3, 1, file );
  fclose( file );

  glGenTextures(1, &texture );            

  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

  free( data );

  return texture;
}

void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture );
}
