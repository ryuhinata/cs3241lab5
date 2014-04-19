#include "drawHouses.h"


void drawMyHouse(GLuint texSet[])
{
	//plot dimension
	//x: -4:4
	//y: 0:12
	//z: -4:4
	
	//bounding volume
	glPushMatrix();
	glTranslatef(0, 6, 0);
	glScalef(8, 12, 8);	
	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1);
	glPopMatrix();
	
	glEnable(GL_TEXTURE_2D);
//
	drawFloor(texSet);

//…


//drawSphere(texSet, 27);

float degInRad, radius=2;
const float DEG2RAD = 3.14159/180;
glBindTexture(GL_TEXTURE_2D, texSet[27]);
glBegin(GL_POLYGON);
for(int i=0;i<180;++i){
degInRad = i*DEG2RAD;
glTexCoord2d(cos(degInRad)/2+0.6,
sin(degInRad)/2+0.5);
glVertex3f(cos(degInRad)*radius,
sin(degInRad)*radius,-2);
}
glEnd();
glDisable(GL_TEXTURE_2D);	
}

void drawSphere(GLuint texSet[], int no)
{
	glBindTexture(GL_TEXTURE_2D, texSet[no]);
	glPushMatrix();
    int i,j;
	double r = 1;
	int n = 20;
    for(i=0;i<n;i++)
	{
		for(j=0;j<2*n;j++)
		{
			
				glBegin(GL_POLYGON);

			    // the normal of each vertex is actaully its own coordinates normalized for a sphere
						    // your normal here
				glTexCoord3f(sin(i*M_PI/n)*cos(j*M_PI/n), cos(i*M_PI/n)*cos(j*M_PI/n), sin(j*M_PI/n));
				glNormal3d(sin(i*M_PI/n)*cos(j*M_PI/n), cos(i*M_PI/n)*cos(j*M_PI/n), sin(j*M_PI/n));
				glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
							// your normal here
				glTexCoord3f(sin((i+1)*M_PI/n)*cos(j*M_PI/n),cos((i+1)*M_PI/n)*cos(j*M_PI/n),sin(j*M_PI/n));
				glNormal3d(sin((i+1)*M_PI/n)*cos(j*M_PI/n),cos((i+1)*M_PI/n)*cos(j*M_PI/n),sin(j*M_PI/n));
				glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
							// your normal here
				//glTexCoord3f(sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),sin((j+1)*M_PI/n));
				glNormal3d(sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),sin((j+1)*M_PI/n));
				glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
							// your normal here
				//glTexCoord3f(sin(i*M_PI/n)*cos((j+1)*M_PI/n),cos(i*M_PI/n)*cos((j+1)*M_PI/n),sin((j+1)*M_PI/n));
				glNormal3d(sin(i*M_PI/n)*cos((j+1)*M_PI/n),cos(i*M_PI/n)*cos((j+1)*M_PI/n),sin((j+1)*M_PI/n));
				glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
 				glEnd();
			}
	}
	glPopMatrix();
}

void drawFloor(GLuint texSet[])
{
	
	glPushMatrix();
	glTranslatef(-4, 0, -4);
	glPushMatrix();
	for(int i = 0; i<8; i++)
	{
		if(i >= 5)
		{
			glBindTexture(GL_TEXTURE_2D, texSet[6]);
		}
		else if(i == 0)
		{
			glBindTexture(GL_TEXTURE_2D, texSet[8]);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, texSet[9]);
		}
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3f(0, 0.1, 0);	//mapping the texture to object
		glTexCoord2d(1,0);glVertex3f(1, 0.1, 0);
		glTexCoord2d(1,1);glVertex3f(1, 0.1, 1);
		glTexCoord2d(0,1);glVertex3f(0, 0.1, 1);
		glEnd();
		glTranslatef(0,0,1);
	}
	glPopMatrix();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texSet[8]);
	for(int i = 0; i<7; i++)
	{
		glTranslatef(1,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3f(0, 0.1, 0);	//mapping the texture to object
		glTexCoord2d(1,0);glVertex3f(1, 0.1, 0);
		glTexCoord2d(1,1);glVertex3f(1, 0.1, 1);
		glTexCoord2d(0,1);glVertex3f(0, 0.1, 1);
		glEnd();
	}
	glBindTexture(GL_TEXTURE_2D, texSet[9]);
	for(int i = 0; i<7; i++)
	{
		if(i >= 3)
		{
			glBindTexture(GL_TEXTURE_2D, texSet[6]);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, texSet[9]);
		}
		glTranslatef(0,0,1);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3f(0, 0.1, 0);	//mapping the texture to object
		glTexCoord2d(1,0);glVertex3f(1, 0.1, 0);
		glTexCoord2d(1,1);glVertex3f(1, 0.1, 1);
		glTexCoord2d(0,1);glVertex3f(0, 0.1, 1);
		glEnd();
	}
	glPopMatrix();
	glTranslatef(0,0,5);
	for(int i=0; i<7; i++)
	{
		glTranslatef(1,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3f(0, 0.1, 0);	//mapping the texture to object
		glTexCoord2d(1,0);glVertex3f(1, 0.1, 0);
		glTexCoord2d(1,1);glVertex3f(1, 0.1, 1);
		glTexCoord2d(0,1);glVertex3f(0, 0.1, 1);
		glEnd();
	}
	glPopMatrix();
}
