#include<iostream>
#include <windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include <GL/gl.h>

using namespace std;


bool isRed=false;
bool isGreen=false;
bool isMoving = false;
bool isTrainMove1=false;
//bool isRaining = false;

float move_car1 = 0.250f;
float speed_car1 = 0.09f;

float move_car2 = 0.0f; // for car 2
float speed_car2 = 0.01f;

float move_car3 = -0.0f; // for car 3
float speed_car3 = 01.1f;

float move_car4 = 0.0f; // for car 4
float speed_car4 = 0.01f;

float move_train1 = 0.0f;
float speed_train1 = 0.01f;





//F01
void toggleDayNight(unsigned char key, int x, int y) {
    switch (key) {

        case 'R':
        case 'r':
            isRed = true;
            isGreen=false;
            isMoving = true;
            break;

         case 'G':
        case 'g':
            isRed =false ;
            isGreen=true;
            isMoving = false;
            break;

        case 'A':
        case 'a':
            isTrainMove1 = true;
            break;

        case 'S':
        case 's':
            isTrainMove1 = false;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}



void tree1() {
    // Small Tree (right) Stem
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();

    // Small Tree (right) Leaf
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.60f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();

    /*
    // Small Tree (Left)
    glPushMatrix();
    glTranslated(-1.1f, 0.0f, 0.0f);

    // Small Tree (Left) Stem
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();

    // Small Tree (Left) Leaf
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.60f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();*/

    glPopMatrix();
}


///################################### Tree 3

const int numSegments = 100; // Number of segments to approximate the circle

// Function to draw a circle
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415926f * i / numSegments;
        float dx = radius * cosf(angle);
        float dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Function to draw a tree with cloud-like leaves
void treeWithCloudLeaves() {
    // Tree Stem
    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.184f, 0.149f); // Brown color for the stem
    glVertex2f(-0.035f, 0.07f);
    glVertex2f(-0.035f, 0.35f);
    glVertex2f(0.035f, 0.35f);
    glVertex2f(0.035f, 0.07f);
    glEnd();

    // Cloud-like Leaves
    glColor3f(0.0f, 0.6f, 0.0f); // Green color for the leaves

    // Bottom Layer
    drawCircle(-0.15f, 0.35f, 0.15f); // Left circle
    drawCircle(0.0f, 0.35f, 0.15f);  // Center circle
    drawCircle(0.15f, 0.35f, 0.15f);  // Right circle

    // Middle Layer
    drawCircle(-0.11f, 0.45f, 0.13f); // Left circle
    drawCircle(0.11f, 0.45f, 0.13f);  // Right circle

    // Top Layer
    drawCircle(0.0f, 0.55f, 0.11f); // Top center circle
}


//############################################################################################################
//OBJ 09
void LampPost1(float pX, float pY){

    //LampPost Bulb
    glBegin(GL_QUADS);

	glColor3ub(247, 242, 124 );

	glVertex2f(-1.52+pX, 0.74+pY);
	glVertex2f(-1.48+pX, 0.74+pY);
	glVertex2f(-1.48+pX, 0.86+pY);
	glVertex2f(-1.52+pX, 0.86+pY);

	glEnd();


	// Lamp post bulb stand
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3 );

	glVertex2f(-1.49+pX, 0.86+pY);
	glVertex2f(-1.48+pX, 0.86+pY);
	glVertex2f(-1.48+pX, 0.94+pY);
	glVertex2f(-1.49+pX, 0.94+pY);

	glEnd();


	//Lamp Post Stand
    glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );


	glVertex2f(-1.57+pX, 0.93+pY);
	glVertex2f(-1.488+pX, 0.93+pY);
	glVertex2f(-1.48+pX, 0.94+pY);
	glVertex2f(-1.57+pX, 0.94+pY);

	glEnd();


	// lamp post poal
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );

	glVertex2f(-1.6+pX, 0.95+pY);
	glVertex2f(-1.57+pX, 0.95+pY);
	glVertex2f(-1.57+pX, 0.92+pY);
	glVertex2f(-1.6+pX, 0.92+pY);

	glEnd();
}

//OBJ 10
void LampPost2(float pX, float pY){

    //lamp post bulb
    glBegin(GL_QUADS);

	glColor3ub(247, 242, 124 );

	glVertex2f(-1.32+pX, -0.87+pY);
	glVertex2f(-1.28+pX, -0.87+pY);
	glVertex2f(-1.28+pX, -0.75+pY);
	glVertex2f(-1.32+pX, -0.75+pY);

	glEnd();


	//lamp post bulb stand
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3 );

	glVertex2f(-1.29+pX, -0.96+pY);
	glVertex2f(-1.28+pX, -0.96+pY);
	glVertex2f(-1.28+pX, -0.87+pY);
	glVertex2f(-1.29+pX, -0.87+pY);

	glEnd();


	//lamp post stand
    glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );


	glVertex2f(-1.37+pX, -0.96+pY);
	glVertex2f(-1.28+pX, -0.96+pY);
	glVertex2f(-1.28+pX, -0.95+pY);
	glVertex2f(-1.37+pX, -0.95+pY);

	glEnd();


	//lamp post poal
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );

	glVertex2f(-1.4+pX, -0.97+pY);
	glVertex2f(-1.37+pX, -0.97+pY);
	glVertex2f(-1.37+pX, -0.94+pY);
	glVertex2f(-1.4+pX, -0.94+pY);

	glEnd();
}

//OBJ 11
void LampPost3(float pX, float pY){

    //lamppost bulb
    glBegin(GL_QUADS);

        glColor3ub(240, 240, 240 ); // Day color


	glVertex2f(0.25+pX, -1.32+pY);
	glVertex2f(0.37+pX, -1.32+pY);
	glVertex2f(0.37+pX, -1.28+pY);
	glVertex2f(0.25+pX, -1.28+pY);

	glEnd();


	//lamp post bulb stand
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3 );

	glVertex2f(0.37+pX, -1.288+pY);
	glVertex2f(0.45+pX, -1.288+pY);
	glVertex2f(0.45+pX, -1.28+pY);
	glVertex2f(0.37+pX, -1.28+pY);

	glEnd();


	//lamp post stand
    glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );


	glVertex2f(0.44+pX, -1.37+pY);
	glVertex2f(0.45+pX, -1.37+pY);
	glVertex2f(0.45+pX, -1.28+pY);
	glVertex2f(0.44+pX, -1.28+pY);


	glEnd();


	//lamppost poal
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );

	glVertex2f(0.43+pX, -1.4+pY);
	glVertex2f(0.46+pX, -1.4+pY);
	glVertex2f(0.46+pX, -1.37+pY);
	glVertex2f(0.43+pX, -1.37+pY);


	glEnd();
}

//OBJ 12
void LampPost4(float pX, float pY){

    //lamp post bulb
    glBegin(GL_QUADS);
    // if (isDay)
        glColor3ub(240, 240, 240 ); // Day color


	glVertex2f(-0.36+pX, 1.38+pY);
	glVertex2f(-0.24+pX, 1.38+pY);
	glVertex2f(-0.24+pX, 1.42+pY);
	glVertex2f(-0.36+pX, 1.42+pY);
	glEnd();


	//lamp post bulb stand
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3 );

	glVertex2f(-0.45+pX, 1.41+pY);
	glVertex2f(-0.36+pX, 1.41+pY);
	glVertex2f(-0.36+pX, 1.42+pY);
	glVertex2f(-0.45+pX, 1.42+pY);

	glEnd();


	//lamp post stand
    glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );


	glVertex2f(-0.45+pX, 1.33+pY);
	glVertex2f(-0.44+pX, 1.33+pY);
	glVertex2f(-0.44+pX, 1.42+pY);
	glVertex2f(-0.45+pX, 1.42+pY);

	glEnd();


	//lamp post poal
	glBegin(GL_QUADS);

	glColor3ub(165, 43, 3  );

	glVertex2f(-0.46+pX, 1.3+pY);
	glVertex2f(-0.43+pX, 1.3+pY);
	glVertex2f(-0.43+pX, 1.33+pY);
	glVertex2f(-0.46+pX, 1.33+pY);

	glEnd();
}


//##########################################################################################



//OBJ 01 Roadside
void RoadSide(){
    glBegin(GL_POLYGON);
	glColor3ub(216,209,205);
	glVertex2f(-2.0, -01.5);
	glVertex2f(-2.0, -01.5);
	glVertex2f(2.0, -01.5);
	glVertex2f(2.0, 01.5);
	glVertex2f(-2.0, 01.5);
	glEnd();
}

//OBJ 02 Buielding1
void Building1(){
    //top
	glBegin(GL_QUADS);
	glColor3ub(14, 48, 76);
	glVertex2f(-2.0,1.5);
	glVertex2f(-2.0,1.4);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.3,1.5);
	glEnd();

	//top2
	glBegin(GL_QUADS);
	glColor3ub(14, 48, 76);
    glVertex2f(-0.85,1.5);
	glVertex2f(-0.5,1.5);
	glVertex2f(-0.5,1.4);
	glVertex2f(-1.0,1.4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 81,150);
	glVertex2f(-2.0,1.4);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.5,1.1);
	glVertex2f(-2.0,1.1);

	glEnd();

	//2nd

	glBegin(GL_QUADS);
	glColor3ub(0, 81,150);
	glVertex2f(-1.0,1.4);
	glVertex2f(-0.7,1.4);
	glVertex2f(-0.7,1.1);
	glVertex2f(-1.0,1.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 81,150);
	glVertex2f(-0.7,1.4);
	glVertex2f(-0.5,1.5);
	glVertex2f(-0.5,1.2);
	glVertex2f(-0.7,1.1);
	glEnd();

	//3rd

	glBegin(GL_QUADS);
	glColor3ub(0, 81,150);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.3,1.5);
	glVertex2f(-1.3,1.2);
	glVertex2f(-1.5,1.1);
	glEnd();
}

//OBJ 03 BuildingLine
void BuildingLine(){

glLineWidth(2.5);
	glBegin(GL_LINES);
	glColor3ub(0, 0,0);
	glVertex2f(-2.0,1.4);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.3,1.5);
	glEnd();

//horizontal line
	for(int i=0;i<3;i++){
        float f= (i+1)*0.08;
        glLineWidth(1);
        glBegin(GL_LINES);
	glColor3ub(0, 0,0);
	glVertex2f(-2.0,1.4-f);
	glVertex2f(-1.5,1.4-f);
	glVertex2f(-1.5,1.4-f);
	glVertex2f(-1.3,1.5-f);
	glEnd();

	}
	//vertical line
	glLineWidth(2.5);
	  glBegin(GL_LINES);
	glColor3ub(0, 0,0);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.5,1.1);
	glEnd();


	//2nd part of left buiidings
    //horizontal line
	for(int i=0;i<4;i++){
    float f= (i+1)*0.08;
    glLineWidth(1);
    glBegin(GL_LINES);
	glColor3ub(0, 0,0);
	glVertex2f(-1.0,1.48-f);
	glVertex2f(-0.7,1.48-f);
	glVertex2f(-0.7,1.48-f);
	glVertex2f(-0.5,1.58-f);
	glEnd();

	}
	//vertical line
	glLineWidth(2.5);
    glBegin(GL_LINES);
	glColor3ub(0, 0,0);
	glVertex2f(-0.7,1.4);
	glVertex2f(-0.7,1.1);
	glEnd();


}

//OBJ 04 Buildinng2
void Building2(){

    // Mirror on positive side of x-axis
    glBegin(GL_POLYGON);
    glColor3ub(216, 209, 205);
    glVertex2f(2.0, -1.5);
    glVertex2f(2.0, -1.5);
    glVertex2f(2.0, -1.5);
    glVertex2f(2.0, 1.5);
    glVertex2f(2.0, 1.5);
    glEnd();
}


//OBJ 05 Buildinng1_right
void Building1_right() {

    // Original Building1 (left side)
    glBegin(GL_QUADS);
    glColor3ub(14, 48, 76);
    glVertex2f(-2.0, 1.5);
    glVertex2f(-2.0, 1.4);
    glVertex2f(-1.5, 1.4);
    glVertex2f(-1.3, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(14, 48, 76);
    glVertex2f(-0.85, 1.5);
    glVertex2f(-0.5, 1.5);
    glVertex2f(-0.5, 1.4);
    glVertex2f(-1.0, 1.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(-2.0, 1.4);
    glVertex2f(-1.5, 1.4);
    glVertex2f(-1.5, 1.1);
    glVertex2f(-2.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(-1.0, 1.4);
    glVertex2f(-0.7, 1.4);
    glVertex2f(-0.7, 1.1);
    glVertex2f(-1.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(-0.7, 1.4);
    glVertex2f(-0.5, 1.5);
    glVertex2f(-0.5, 1.2);
    glVertex2f(-0.7, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(-1.5, 1.4);
    glVertex2f(-1.3, 1.5);
    glVertex2f(-1.3, 1.2);
    glVertex2f(-1.5, 1.1);
    glEnd();

    // Mirror Building1 (right side)
    glBegin(GL_QUADS);
    glColor3ub(14, 48, 76);
    glVertex2f(2.0, 1.5);
    glVertex2f(2.0, 1.4);
    glVertex2f(1.5, 1.4);
    glVertex2f(1.3, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(14, 48, 76);
    glVertex2f(0.85, 1.5);
    glVertex2f(0.5, 1.5);
    glVertex2f(0.5, 1.4);
    glVertex2f(1.0, 1.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(2.0, 1.4);
    glVertex2f(1.5, 1.4);
    glVertex2f(1.5, 1.1);
    glVertex2f(2.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(1.0, 1.4);
    glVertex2f(0.7, 1.4);
    glVertex2f(0.7, 1.1);
    glVertex2f(1.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(0.7, 1.4);
    glVertex2f(0.5, 1.5);
    glVertex2f(0.5, 1.2);
    glVertex2f(0.7, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(1.5, 1.4);
    glVertex2f(1.3, 1.5);
    glVertex2f(1.3, 1.2);
    glVertex2f(1.5, 1.1);
    glEnd();
}


//OBJ 06 BuildingLine_right
void BuildingLine_right() {
    // Original BuildingLine
    // [Original BuildingLine code here]
    // Mirror BuildingLine on positive side of x-axis

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0, 1.4);
    glVertex2f(1.5, 1.4);
    glVertex2f(1.5, 1.4);
    glVertex2f(1.3, 1.5);
    glEnd();

    for (int i = 0; i < 3; i++) {
        float f = (i + 1) * 0.08;
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(2.0, 1.4 - f);
        glVertex2f(1.5, 1.4 - f);
        glVertex2f(1.5, 1.4 - f);
        glVertex2f(1.3, 1.5 - f);
        glEnd();
    }

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.5, 1.4);
    glVertex2f(1.5, 1.1);
    glEnd();

    // Mirror other parts similarly...
    // 2nd part of left buildings
    // Horizontal line
 for (int i = 0; i < 4; i++) {
    float f = (i + 1) * 0.08;
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.0, 1.48 - f);
    glVertex2f(0.7, 1.48 - f);
    glVertex2f(0.7, 1.48 - f);
    glVertex2f(0.5, 1.58 - f);
    glEnd();
}

// Vertical line
glLineWidth(2.5);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f(0.7, 1.4);
glVertex2f(0.7, 1.1);
glEnd();

}

//OBJ 07 Buildinng_down
void Building1_down() {
    // top
    glBegin(GL_QUADS);
    glColor3ub(14, 48, 76);
    glVertex2f(2.0, -1.5);
    glVertex2f(2.0, -1.4);
    glVertex2f(1.5, -1.4);
    glVertex2f(1.3, -1.5);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(2.0, -1.4);
    glVertex2f(1.5, -1.4);
    glVertex2f(1.5, -1.1);
    glVertex2f(2.0, -1.1);
    glEnd();

    // 3rd
    glBegin(GL_QUADS);
    glColor3ub(0, 81, 150);
    glVertex2f(1.5, -1.4);
    glVertex2f(1.3, -1.5);
    glVertex2f(1.3, -1.2);
    glVertex2f(1.5, -1.1);
    glEnd();
}

//OBJ 08 BuildingLinr_down
void BuildingLine_down() {

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0, -1.4);
    glVertex2f(1.5, -1.4);
    glVertex2f(1.5, -1.4);
    glVertex2f(1.3, -1.5);
    glEnd();

    // horizontal line
    for (int i = 0; i < 3; i++) {
        float f = (i + 1) * 0.08;
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(2.0, -1.4 + f);
        glVertex2f(1.5, -1.4 + f);
        glVertex2f(1.5, -1.4 + f);
        glVertex2f(1.3, -1.5 + f);
        glEnd();
    }

    // vertical line
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.5, -1.4);
    glVertex2f(1.5, -1.1);
    glEnd();

}





//OBJ 09 Roads
void Roads(){
    glBegin(GL_POLYGON);
    glColor3ub(116, 116, 116 );


    // X axis road
    glVertex2f(-2.0, -0.9);
    glVertex2f(-2.0, 0.9);
	glVertex2f(2.0, 0.9);
	glVertex2f(2.0, -0.9);
    glEnd();


    //Y axis Road
    glBegin(GL_POLYGON);
    glColor3ub(116, 116, 116 );

    glVertex2f(-0.40, -01.5);
	glVertex2f(0.40, -01.5);
	glVertex2f(0.40, 01.5);
	glVertex2f(-0.40, 01.5);
    glEnd();
}


//OBJ 10 Railpath
void Railpath(float nX,float nY){
    glLineWidth(10);

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0 );
	glVertex2f(-1.95+nX, -0.15+nY);
	glVertex2f(-1.95f+nX, -0.35+nY);
	glEnd();

	glBegin(GL_LINES);
    glColor3ub(0, 0, 0 );

	glVertex2f(-1.95f+nX, 0.15+nY);
	glVertex2f(-1.95f+nX, 0.35+nY);
	glEnd();
}



void TrafficSignal1(){

    //Traffic Signal light body
    glBegin(GL_QUADS);

	glColor3ub(63, 47, 42  );

	glVertex2f(-0.34,0.58);
	glVertex2f(-0.26,0.58);
	glVertex2f(-0.26,0.78);
	glVertex2f(-0.34,0.78);

	glEnd();
// for Red Light
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {  if (isRed)
        glColor3ub(255, 0, 0 );
    else
            glColor3ub(124, 37, 9 );
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.025;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.3,y+0.74);
        }

        glEnd();

        // for Yellow Light
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(175, 169, 41  );
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.025;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.3,y+0.68);
        }

        glEnd();

         // for Green Light
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        { if (isGreen)
        glColor3ub(0,255, 0 ); // Day color
    else
            glColor3ub(8, 85, 15   );
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.025;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.3,y+0.625);
        }

        glEnd();


    //Traffic Signal light body stand
    glBegin(GL_QUADS);
	glColor3ub(63, 47, 42  );

	glVertex2f(-0.31,0.78);
	glVertex2f(-0.29,0.78);
	glVertex2f(-0.29,1.08);
	glVertex2f(-0.31,1.08);

	glEnd();


	//Traffic Signal light stand
    glBegin(GL_QUADS);
	glColor3ub(63, 47, 42  );

	glVertex2f(-0.46,1.06);
	glVertex2f(-0.29,1.06);
	glVertex2f(-0.29,1.08);
	glVertex2f(-0.46,1.08);

	glEnd();


	//Traffic Signal light poal
	glBegin(GL_QUADS);
	glColor3ub(63, 47, 42  );

	glVertex2f(-0.54,1.03);
	glVertex2f(-0.46,1.03);
	glVertex2f(-0.46,1.11);
	glVertex2f(-0.54,1.11);

	glEnd();
}

//OBJ 14
void TrafficSignal2(){

    //Traffic Signal light body
    glBegin(GL_QUADS);

	glColor3ub(63, 47, 42  );

	glVertex2f(0.13,-0.98);
	glVertex2f(0.21,-0.98);
	glVertex2f(0.21,-0.78);
	glVertex2f(0.13,-0.78);

	glEnd();
// for Red Light
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        { if (isGreen)
        glColor3ub(255, 0, 0 );
    else
            glColor3ub(124, 37, 9 );
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.025;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0.17,y-0.815);
        }

        glEnd();

        // for Yellow Light
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(175, 169, 41  );
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.025;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0.17,y-0.875);
        }

        glEnd();

         // for Green Light
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        { if (isRed)
        glColor3ub(0,255, 0 );
    else
            glColor3ub(8, 85, 15   );
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.025;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0.17,y-0.935);
        }

        glEnd();


    //Traffic Signal light body stand
    glBegin(GL_QUADS);
	glColor3ub(63, 47, 42  );

	glVertex2f(0.21,-0.89);
	glVertex2f(0.54,-0.89);
	glVertex2f(0.54,-0.87);
	glVertex2f(0.21,-0.87);

	glEnd();

	//Traffic Signal light stand
    glBegin(GL_QUADS);
	glColor3ub(63, 47, 42  );

	glVertex2f(0.52,-1.04);
	glVertex2f(0.54,-1.04);
	glVertex2f(0.54,-0.87);
	glVertex2f(0.52,-0.87);


	glEnd();


	//Traffic Signal light poal
	glBegin(GL_QUADS);
	glColor3ub(63, 47, 42  );

	glVertex2f(0.49,-1.12);
	glVertex2f(0.57,-1.12);
	glVertex2f(0.57,-1.04);
	glVertex2f(0.49,-1.04);


	glEnd();
}

//OBJ 11 Car1
void Car1(){
    //Car Body
    glBegin(GL_POLYGON);
	glColor3ub(37, 60, 225  );

	glVertex2f(-1.16,0.66);
	glVertex2f(-1.14,0.64);
	glVertex2f(-0.86,0.64);
	glVertex2f(-0.79,0.66);
	glVertex2f(-0.765,0.695);
	glVertex2f(-0.765,0.8);
	glVertex2f(-0.79,0.838);
    glVertex2f(-0.86,0.86);
	glVertex2f(-1.14,0.86);
	glVertex2f(-1.16,0.84);
	glEnd();


	//back glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-1.11,0.66);
	glVertex2f(-1.085,0.685);
	glVertex2f(-1.085,0.815);
	glVertex2f(-1.11,0.85);

	glEnd();


	//left  back glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-1.08,0.82);
	glVertex2f(-0.995,0.82);
	glVertex2f(-0.995,0.845);
	glVertex2f(-1.105,0.845);

	glEnd();


	//left front glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.99,0.82);
	glVertex2f(-0.9,0.82);
	glVertex2f(-0.875,0.845);
	glVertex2f(-0.99,0.845);

	glEnd();


	//front glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.9,0.82);
	glVertex2f(-0.895,0.685);
	glVertex2f(-0.87,0.66);
	glVertex2f(-0.87,0.84);

	glEnd();


	//right back glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-1.105,0.655);
	glVertex2f(-0.995,0.655);
	glVertex2f(-0.995,0.68);
	glVertex2f(-1.108,0.68);

	glEnd();

	//right front glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.99,0.655);
	glVertex2f(-0.875,0.655);
	glVertex2f(-0.9,0.68);
	glVertex2f(-0.99,0.68);

	glEnd();


	//bulb 1
	glBegin(GL_TRIANGLES);
    glColor3ub(240, 240, 240 );

	glVertex2f(-0.79,0.66);
	glVertex2f(-0.79,0.695);
	glVertex2f(-0.765,0.695);
	glEnd();


	//bulb 2
	glBegin(GL_TRIANGLES);
    glColor3ub(240, 240, 240 );

	glVertex2f(-0.79,0.838);
	glVertex2f(-0.79,0.8);
	glVertex2f(-0.765,0.8);
	glEnd();

}

//OBJ 12 Car2
void Car2(){

    //car 2 body
    glBegin(GL_POLYGON);
	glColor3ub(97, 28, 86 );

	glVertex2f(0.1,1.08);
	glVertex2f(0.12,1.06);
	glVertex2f(0.24,1.06);
	glVertex2f(0.26,1.08);
	glVertex2f(0.28,1.16);
	glVertex2f(0.28,1.4);
	glVertex2f(0.08,1.4);
	glVertex2f(0.08,1.16);

	glEnd();

	//back glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(0.12,1.36);
	glVertex2f(0.24,1.36);
	glVertex2f(0.26,1.38);
	glVertex2f(0.1,1.38);

	glEnd();


	//right back glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(0.12,1.35);
	glVertex2f(0.12,1.28);
	glVertex2f(0.09,1.28);
	glVertex2f(0.09,1.37);

	glEnd();


	//right front glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(0.12,1.22);
	glVertex2f(0.12,1.27);
	glVertex2f(0.09,1.27);
	glVertex2f(0.09,1.17);

	glEnd();


	//front glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(0.12,1.2);
	glVertex2f(0.24,1.2);
	glVertex2f(0.26,1.16);
	glVertex2f(0.1,1.16);

	glEnd();


	//left front glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(0.24,1.22);
	glVertex2f(0.24,1.27);
	glVertex2f(0.27,1.27);
	glVertex2f(0.27,1.17);

	glEnd();

	//left back glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(0.24,1.35);
	glVertex2f(0.24,1.28);
	glVertex2f(0.27,1.28);
	glVertex2f(0.27,1.37);

	glEnd();

	//bulb 1
	glBegin(GL_TRIANGLES);
    glColor3ub(240, 240, 240 );

	glVertex2f(0.1,1.08);
	glVertex2f(0.12,1.08);
	glVertex2f(0.12,1.06);
	glEnd();

	//bulb 2
	glBegin(GL_TRIANGLES);
    glColor3ub(240, 240, 240 );

	glVertex2f(0.26,1.08);
	glVertex2f(0.24,1.08);
	glVertex2f(0.24,1.06);
	glEnd();


}



//OBJ 17
void Car3(){
    glBegin(GL_POLYGON);
	glColor3ub(163, 7, 7 );

	glVertex2f(1.26,-0.65);
	glVertex2f(1.24,-0.7);
    glVertex2f(1.24,-0.82);
    glVertex2f(1.26,-0.86);
    glVertex2f(1.45,-0.86);
    glVertex2f(1.45,-0.65);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(1.38,-0.69);
    glVertex2f(1.435,-0.69);
    glVertex2f(1.435,-0.655);
    glVertex2f(1.345,-0.655);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(1.34,-0.85);
    glVertex2f(1.375,-0.82);
    glVertex2f(1.375,-0.695);
    glVertex2f(1.34,-0.66);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(1.38,-0.825);
    glVertex2f(1.435,-0.825);
    glVertex2f(1.435,-0.855);
    glVertex2f(1.345,-0.855);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(99, 87, 87 );

	glVertex2f(1.45,-0.82);
    glVertex2f(1.47,-0.82);
    glVertex2f(1.47,-0.69);
    glVertex2f(1.45,-0.69);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(229, 229, 229  );

	glVertex2f(1.47,-0.65);
    glVertex2f(1.47,-0.86);
    glVertex2f(1.86,-0.86);
    glVertex2f(1.86,-0.65);

	glEnd();

	glBegin(GL_TRIANGLES);

    glColor3ub(240, 240, 240 ); // Day color

	glVertex2f(1.26,-0.65);
	glVertex2f(1.24,-0.7);
    glVertex2f(1.26,-0.7);
	glEnd();

	glBegin(GL_TRIANGLES);
    glColor3ub(240, 240, 240 ); // Day color

	glVertex2f(1.24,-0.82);
    glVertex2f(1.26,-0.82);
    glVertex2f(1.26,-0.86);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(252, 245, 91  );

	glVertex2f(1.24,-0.82);
    glVertex2f(1.26,-0.86);
    glVertex2f(1.1,-0.95);
    glVertex2f(1.1,-0.75);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(252, 245, 91  );

	glVertex2f(1.24,-0.7);
    glVertex2f(1.26,-0.65);
    glVertex2f(1.1,-0.55);
    glVertex2f(1.1,-0.75);

	glEnd();
	}


//OBJ 18
void Car4(){

    //Main Body
    glBegin(GL_POLYGON);
	glColor3ub(7, 122, 25 );

	glVertex2f(-0.26,-1);
	glVertex2f(-0.28,-1);
	glVertex2f(-0.33,-1.06);
	glVertex2f(-0.33,-1.22);
	glVertex2f(-0.21,-1.22);
	glVertex2f(-0.21,-1.06);

	glEnd();

    //Front Glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.265,-1.005);
	glVertex2f(-0.275,-1.005);
	glVertex2f(-0.3,-1.04);
    glVertex2f(-0.24,-1.04);

	glEnd();

	//Right Glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.22,-1.065);
	glVertex2f(-0.22,-1.205);
	glVertex2f(-0.24,-1.185);
    glVertex2f(-0.24,-1.045);

	glEnd();

	//Back Glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.3,-1.19);
	glVertex2f(-0.24,-1.19);
	glVertex2f(-0.22,-1.21);
    glVertex2f(-0.32,-1.21);

	glEnd();

	//Left Glass
	glBegin(GL_QUADS);
	glColor3ub(12, 20, 73 );

	glVertex2f(-0.32,-1.065);
	glVertex2f(-0.32,-1.205);
	glVertex2f(-0.3,-1.185);
    glVertex2f(-0.3,-1.045);


	glEnd();

	//HeadLight
	glBegin(GL_QUADS);

        glColor3ub(240, 240, 240 ); // Day color

	glVertex2f(-0.275,-1.005);
	glVertex2f(-0.265,-1.005);
	glVertex2f(-0.26,-1.0);
    glVertex2f(-0.28,-1.0);
	glEnd();

    /*//Light
	if(!isDay){
        glBegin(GL_QUADS);
	glColor3ub(252, 245, 91  );

	glVertex2f(-0.28,-1.0);
	glVertex2f(-0.26,-1.0);
	glVertex2f(-0.2,-0.92);
    glVertex2f(-0.34,-0.92);

	glEnd();
	}*/
}


//OBJ 13 Path
void Path(){
    Railpath(0,0);
	Railpath(0.09,0);
	Railpath(0.18,0);
	Railpath(0.27,0);
	Railpath(0.36,0);
	Railpath(0.45,0);
	Railpath(0.54,0);
	Railpath(0.63,0);
	Railpath(0.72,0);
	Railpath(0.81,0);
	Railpath(0.90,0);
	Railpath(0.99,0);
	Railpath(1.08,0);
	Railpath(1.17,0);
	Railpath(1.26,0);
	Railpath(1.35,0);
	Railpath(1.44,0);
	Railpath(1.53,0);
	Railpath(1.62,0);
	Railpath(1.71,0);
	Railpath(1.80,0);
	Railpath(1.89,0);
	Railpath(1.98,0);
	Railpath(2.07,0);
	Railpath(2.16,0);
	Railpath(2.25,0);
	Railpath(2.34,0);
	Railpath(2.43,0);
	Railpath(2.52,0);
	Railpath(2.61,0);
	Railpath(2.70,0);
	Railpath(2.77,0);
	Railpath(2.86,0);
	Railpath(2.95,0);
	Railpath(3.04,0);
	Railpath(3.13,0);
	Railpath(3.22,0);
	Railpath(3.31,0);
	Railpath(3.40,0);
	Railpath(3.49,0);
	Railpath(3.58,0);
	Railpath(3.67,0);
	Railpath(3.76,0);
	Railpath(3.85,0);
	Railpath(3.92,0);

}

//OBJ 14 Metro_Bridge
void metroBridge(){
    glBegin(GL_QUADS);
	glColor3ub(182, 182, 182  );

	glVertex2f(-2,-0.5);
	glVertex2f(2.0,-0.5);
	glVertex2f(2.0,0.5);
	glVertex2f(-2.0,0.5);

	glEnd();

    glLineWidth(4);

	glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-2.0f, -0.5);
	glVertex2f(2.0f, -0.5);
	glEnd();

	glBegin(GL_LINES);
    glColor3ub(255, 255, 255 );

	glVertex2f(-2.0f, 0.5);
	glVertex2f(2.0f, 0.5);
	glEnd();

	Path();
    glLineWidth(4);

	glBegin(GL_LINES);
	glColor3ub(161, 126, 114 );
	glVertex2f(-2.0f, -0.35);
	glVertex2f(2.0f, -0.35);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(161, 126, 114 );
	glVertex2f(-2.0f, -0.15);
	glVertex2f(2.0f, -0.15);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(161, 126, 114 );
	glVertex2f(-2.0f, 0.35);
	glVertex2f(2.0f, 0.35);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(161, 126, 114 );
	glVertex2f(-2.0f, 0.15);
	glVertex2f(2.0f, 0.15);
	glEnd();
}


//OBJ 15 Train
void Train(float tx,float ty){

    //Train front Head
    glBegin(GL_POLYGON);
	glColor3ub(250, 250, 250  );

	glVertex2f(1.8+tx,0.2+ty);
	glVertex2f(1.78+tx,0.16+ty);
	glVertex2f(1.76+tx,0.12+ty);
	glVertex2f(1.72+tx,0.08+ty);
	glVertex2f(1.64+tx,0.06+ty);
	glVertex2f(1.5+tx,0.05+ty);
	glVertex2f(1.5+tx,0.45+ty);
	glVertex2f(1.64+tx,0.44+ty);
	glVertex2f(1.72+tx,0.42+ty);
	glVertex2f(1.76+tx,0.38+ty);
	glVertex2f(1.78+tx,0.34+ty);
	glVertex2f(1.8+tx,0.3+ty);

	glEnd();

	//BLU
    glBegin(GL_POLYGON);
	glColor3ub(74,86,160);

	glVertex2f(1.6+tx,0.42+ty);
	glVertex2f(1.7+tx,0.38+ty);
	glVertex2f(1.74+tx,0.38+ty);
	glVertex2f(1.76+tx,0.28+ty);
	glVertex2f(1.76+tx,0.22+ty);
	glVertex2f(1.74+tx,0.16+ty);
	glVertex2f(1.7+tx,0.12+ty);
	glVertex2f(1.6+tx,0.08+ty);

    glEnd();

    //GREEN
    glBegin(GL_QUADS);
	glColor3ub(46,54,91);
    glVertex2f(1.5+tx,0.45+ty);
	glVertex2f(1.6+tx,0.42+ty);
	glVertex2f(1.6+tx,0.08+ty);
	glVertex2f(1.5+tx,0.05+ty);
    glEnd();



	//Train back Head
    glBegin(GL_POLYGON);
	glColor3ub(250, 250, 250  );

	glVertex2f(0+tx,0.2+ty);
	glVertex2f(0.02+tx,0.16+ty);
	glVertex2f(0.04+tx,0.12+ty);
	glVertex2f(0.08+tx,0.08+ty);
	glVertex2f(0.16+tx,0.06+ty);
	glVertex2f(0.3+tx,0.05+ty);
	glVertex2f(0.3+tx,0.45+ty);
	glVertex2f(0.16+tx,0.44+ty);
	glVertex2f(0.08+tx,0.42+ty);
	glVertex2f(0.04+tx,0.38+ty);
	glVertex2f(0.02+tx,0.34+ty);
	glVertex2f(0+tx,0.3+ty);

	glEnd();

    //BLU GLASS
    glBegin(GL_POLYGON);
	glColor3ub(74,86,160);

	glVertex2f(0.1+tx,0.1+ty);
	glVertex2f(0.07+tx,0.13+ty);
	glVertex2f(0.05+tx,0.17+ty);
	glVertex2f(0.04+tx,0.22+ty);
	glVertex2f(0.04+tx,0.28+ty);
	glVertex2f(0.05+tx,0.33+ty);
	glVertex2f(0.07+tx,0.37+ty);
	glVertex2f(0.1+tx,0.4+ty);
	glVertex2f(0.2+tx,0.415+ty);
	glVertex2f(0.2+tx,0.083+ty);

	glEnd();

    //GREEN
	glBegin(GL_QUADS);
	glColor3ub(46,54,91);

	glVertex2f(0.2+tx,0.083+ty);
	glVertex2f(0.3+tx,0.0656+ty);
	glVertex2f(0.3+tx,0.4314+ty);
	glVertex2f(0.2+tx,0.416+ty);

	glEnd();



	//Train body

	glBegin(GL_QUADS);
    glColor3ub(255,156,92);
	glVertex2f(0.3+tx,0.05+ty);
	glVertex2f(1.5+tx,0.05+ty);
	glVertex2f(1.5+tx,0.45+ty);
	glVertex2f(0.3+tx,0.45+ty);

	glEnd();

    glLineWidth(4);
    glColor3ub(252, 22, 22);

    glBegin(GL_LINES);
    glVertex2f(0.2+tx,0.08283+ty);
    glVertex2f(0.1+tx,0.1+ty);
    glVertex2f(0.07+tx,0.13+ty);
    glVertex2f(0.05+tx,0.17+ty);
    glVertex2f(0.04+tx,0.22+ty);
    glVertex2f(0.04+tx,0.28+ty);
    glVertex2f(0.05+tx,0.33+ty);
    glVertex2f(0.07+tx,0.37+ty);
    glVertex2f(0.1+tx,0.4+ty);
    glVertex2f(0.2+tx,0.42+ty);
    glVertex2f(0.3+tx,0.45+ty);
    glVertex2f(1.5+tx,0.45+ty);
    glVertex2f(1.6+tx,0.42+ty);
    glVertex2f(1.7+tx,0.38+ty);
    glVertex2f(1.74+tx,0.38+ty);
    glVertex2f(1.76+tx,0.28+ty);
    glVertex2f(1.76+tx,0.22+ty);
    glVertex2f(1.74+tx,0.16+ty);
    glVertex2f(1.7+tx,0.12+ty);
    glVertex2f(1.6+tx,0.08+ty);
    glVertex2f(1.5+tx,0.05+ty);
    glVertex2f(0.3+tx,0.05+ty);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
	glColor3ub(22, 134, 228);
    glVertex2f(1.5+tx,0.45+ty);
    glVertex2f(1.5+tx,0.05+ty);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(22, 134, 228);
    glVertex2f(1.1+tx,0.45+ty);
    glVertex2f(1.1+tx,0.05+ty);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(22, 134, 228);
    glVertex2f(0.7+tx,0.45+ty);
    glVertex2f(0.7+tx,0.05+ty);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(22, 134, 228);
    glVertex2f(0.3+tx,0.45+ty);
    glVertex2f(0.3+tx,0.05+ty);
    glEnd();


}


//OBJ 16 RailPower
void RailPower(float xA,float yA){
    glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(0, 0,0);
	glVertex2f(-1.92+xA,-0.5+yA);
	glVertex2f(-1.88+xA,-0.46+yA);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(0, 0,0);
    glVertex2f(-1.92+xA,-0.51+yA);
    glVertex2f(-1.92+xA,0.51+yA);

	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(0, 0,0);
    glVertex2f(-1.88+xA,0.46+yA);
	glVertex2f(-1.92+xA,0.5+yA);
	glEnd();



}

//OBJ 17 ZebraCrosing1
void ZebraCrosing1(float Ax,float By){
    glLineWidth(4);

	glBegin(GL_LINES);
	glColor3f(1.0f, 01.0f, 01.0f);
	glVertex2f(-0.38f+Ax, 0.99f+By);
	glVertex2f(-0.38f+Ax, 0.91f+By);
	glEnd();

}

//OBJ 18 ZebraCrosing2
void ZebraCrosing2(float Ax,float By){
    glLineWidth(4);

	glBegin(GL_LINES);
	glColor3f(1.0f, 01.0f, 01.0f);
	glVertex2f(0.42f+Ax, 0.87f+By);
	glVertex2f(0.5f+Ax, 0.87f+By);
	glEnd();

}


//OBJ 19 ZebraCrosing3
void ZebraCrosing3(float Ax,float By){
    glLineWidth(4);

	glBegin(GL_LINES);
	glColor3f(1.0f, 01.0f, 01.0f);
	glVertex2f(-0.38f+Ax, -0.99f+By);
	glVertex2f(-0.38f+Ax, -0.91f+By);
	glEnd();

}

//OBJ 20 ZebraCrosing4
void ZebraCrosing4(float Ax,float By){
    glLineWidth(4);

	glBegin(GL_LINES);
	glColor3f(1.0f, 01.0f, 01.0f);
	glVertex2f(-0.42f+Ax, 0.87f+By);
	glVertex2f(-0.5f+Ax, 0.87f+By);
	glEnd();

}

//OBJ 21 ZebraCrosing
ZebraCrosing(){
    ZebraCrosing1(0,0);
	ZebraCrosing1(0.04,0);
	ZebraCrosing1(0.08,0);
	ZebraCrosing1(0.12,0);
	ZebraCrosing1(0.16,0);
	ZebraCrosing1(0.20,0);
	ZebraCrosing1(0.24,0);
	ZebraCrosing1(0.28,0);
	ZebraCrosing1(0.32,0);
	ZebraCrosing1(0.36,0);
	ZebraCrosing1(0.40,0);
	ZebraCrosing1(0.44,0);
	ZebraCrosing1(0.48,0);
	ZebraCrosing1(0.52,0);
	ZebraCrosing1(0.56,0);
	ZebraCrosing1(0.60,0);
	ZebraCrosing1(0.64,0);
	ZebraCrosing1(0.68,0);
	ZebraCrosing1(0.72,0);
	ZebraCrosing1(0.76,0);


	ZebraCrosing2(0,0);
	ZebraCrosing2(0,-0.05);
	ZebraCrosing2(0,-0.10);
	ZebraCrosing2(0,-0.15);
	ZebraCrosing2(0,-0.20);
	ZebraCrosing2(0,-0.25);
	ZebraCrosing2(0,-0.30);
	ZebraCrosing2(0,-0.35);
	ZebraCrosing2(0,-0.40);
	ZebraCrosing2(0,-0.45);
	ZebraCrosing2(0,-0.50);
	ZebraCrosing2(0,-0.55);
	ZebraCrosing2(0,-0.60);
	ZebraCrosing2(0,-0.65);
	ZebraCrosing2(0,-0.70);
	ZebraCrosing2(0,-0.75);
	ZebraCrosing2(0,-0.80);
	ZebraCrosing2(0,-0.85);
	ZebraCrosing2(0,-0.90);
	ZebraCrosing2(0,-0.95);
	ZebraCrosing2(0,-1.0);
	ZebraCrosing2(0,-1.05);
	ZebraCrosing2(0,-1.10);
	ZebraCrosing2(0,-1.15);
	ZebraCrosing2(0,-1.20);
	ZebraCrosing2(0,-1.25);
	ZebraCrosing2(0,-1.30);
	ZebraCrosing2(0,-1.35);
	ZebraCrosing2(0,-1.40);
	ZebraCrosing2(0,-1.45);
	ZebraCrosing2(0,-1.50);
	ZebraCrosing2(0,-1.55);
	ZebraCrosing2(0,-1.60);
	ZebraCrosing2(0,-1.65);
	ZebraCrosing2(0,-1.70);
	ZebraCrosing2(0,-1.75);


	ZebraCrosing3(0,0);
    ZebraCrosing3(0.04,0);
	ZebraCrosing3(0.08,0);
	ZebraCrosing3(0.12,0);
	ZebraCrosing3(0.16,0);
	ZebraCrosing3(0.20,0);
	ZebraCrosing3(0.24,0);
	ZebraCrosing3(0.28,0);
	ZebraCrosing3(0.32,0);
	ZebraCrosing3(0.36,0);
	ZebraCrosing3(0.40,0);
	ZebraCrosing3(0.44,0);
	ZebraCrosing3(0.48,0);
	ZebraCrosing3(0.52,0);
	ZebraCrosing3(0.56,0);
	ZebraCrosing3(0.60,0);
	ZebraCrosing3(0.64,0);
	ZebraCrosing3(0.68,0);
	ZebraCrosing3(0.72,0);
	ZebraCrosing3(0.76,0);

	ZebraCrosing4(0,0);
    ZebraCrosing4(0,-0.05);
	ZebraCrosing4(0,-0.10);
	ZebraCrosing4(0,-0.15);
	ZebraCrosing4(0,-0.20);
	ZebraCrosing4(0,-0.25);
	ZebraCrosing4(0,-0.30);
	ZebraCrosing4(0,-0.35);
	ZebraCrosing4(0,-0.40);
	ZebraCrosing4(0,-0.45);
	ZebraCrosing4(0,-0.50);
	ZebraCrosing4(0,-0.55);
	ZebraCrosing4(0,-0.60);
	ZebraCrosing4(0,-0.65);
	ZebraCrosing4(0,-0.70);
	ZebraCrosing4(0,-0.75);
	ZebraCrosing4(0,-0.80);
	ZebraCrosing4(0,-0.85);
	ZebraCrosing4(0,-0.90);
	ZebraCrosing4(0,-0.95);
	ZebraCrosing4(0,-1.0);
	ZebraCrosing4(0,-1.05);
	ZebraCrosing4(0,-1.10);
	ZebraCrosing4(0,-1.15);
	ZebraCrosing4(0,-1.20);
	ZebraCrosing4(0,-1.25);
	ZebraCrosing4(0,-1.30);
	ZebraCrosing4(0,-1.35);
	ZebraCrosing4(0,-1.40);
	ZebraCrosing4(0,-1.45);
	ZebraCrosing4(0,-1.50);
	ZebraCrosing4(0,-1.55);
	ZebraCrosing4(0,-1.60);
	ZebraCrosing4(0,-1.65);
	ZebraCrosing4(0,-1.70);
	ZebraCrosing4(0,-1.75);

	return 0;

}



// Function to play sounds
void playCarSound1() {
    PlaySound("car1.wav", NULL, SND_ASYNC | SND_FILENAME);
}
void playCarSound2() {
    PlaySound("car2.wav", NULL, SND_ASYNC | SND_FILENAME);
}

void playTrainSound() {
    PlaySound("train2.wav", NULL, SND_ASYNC | SND_FILENAME);
}

// Callback functions for car and train movements
void updatecar1(int value) {
    if (isGreen) {
        speed_car1 = 0.01f;
        if (move_car1 > 3.9) {
            move_car1 = -1.0f;
            playCarSound1(); // Play car sound when it resets position
        }
        move_car1 += speed_car1;
    } else {
        if (move_car1 > 0.0) {
            speed_car1 = 0.0f;
            move_car1 = 0.250f;
        }
        move_car1 += speed_car1;
    }
    glutPostRedisplay();
    glutTimerFunc(10, updatecar1, 0);
}
//F03
void updatecar3(int value) {
    if (isGreen) {
        speed_car3 = 0.01f;
        if (move_car3 < -3.9)
            move_car3 = 2.7f;


        move_car3 -= speed_car3;
    } else {
        if (move_car3 < -0.70) {
            speed_car3 = 0.0f;
            move_car3 = -0.70;
        }
        move_car3 -= speed_car3;
    }

    glutPostRedisplay();
    glutTimerFunc(10, updatecar3, 0);
}

//F04
void updatecar2(int value) {
    if (isRed) {
        // When it's red, move the car
        speed_car2 = 0.01f;
        if (move_car2 < -2.7){
            move_car2 = 01.9f;
            playCarSound2();
        }
        move_car2 -= speed_car2;
    } else {
         if (move_car2 < 0.0) {
            speed_car2 = 0.0f;
            move_car2 = -0.05;
        }
        move_car2 -= speed_car2;
    }

    glutPostRedisplay();
    glutTimerFunc(10, updatecar2, 0);
}


//F05
void updatecar4(int value) {
    if (isRed) {
        // When it's green, move the car
        speed_car4 = 0.01f;
        if (move_car4 > 2.7f) {
            move_car4 = -2.7f;
        }
        move_car4 += speed_car4;
    } else {
        // When it's not green, stop the car
        speed_car4 = 0.0f;
        if (move_car4 >0.0) {
            speed_car4 = 0.0f;
            move_car4 = 0.0f;
        }
        move_car4 += speed_car4;
    }


    glutPostRedisplay();
    glutTimerFunc(10, updatecar4, 0);
}


void updateTrain1(int value) {
    if (isTrainMove1) {
        speed_train1 = 0.01f;
        if (move_train1 > 3.9) {
            move_train1 = -1.0f;
            playTrainSound(); // Play train sound when it resets position
        }
        move_train1 += speed_train1;
    } else {
        speed_train1 = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(10, updateTrain1, 0);
}

//OBJ 22 Display
void display() {
	glClearColor(0.60f, 0.60f, 0.60f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	RoadSide();
	Building1_right();
	BuildingLine_right();
	Building1();
	BuildingLine();
    Building1_down();
	BuildingLine_down();
	Roads();
	Path();
	ZebraCrosing();

	tree1();


	glPushMatrix();
    glTranslatef(move_car1, 0.0f, 0.0f);
	Car1();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0.0f,move_car2, 0.0f);
	Car2();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(move_car3, 0.0f, 0.0f);
	Car3();
	glPopMatrix();
	glPushMatrix();
    glTranslatef( 0.0f,move_car4, 0.0f);
	Car4();
	glPopMatrix();
	metroBridge();
	glPushMatrix();
	glTranslatef(move_train1, 0.0f, 0.0f);
	Train(0,0);
	glPopMatrix();
    glPushMatrix();
	glTranslatef(-move_train1, 0.0f, 0.0f);
	Train(0,-0.5);
	glPopMatrix();

   // Train(0,0);
	RailPower(0,0);
	RailPower(0.4,0);
	RailPower(0.8,0);
	RailPower(1.2,0);
	RailPower(1.6,0);
	RailPower(2.0,0);
	RailPower(2.40,0);
	RailPower(2.80,0);
	RailPower(3.20,0);
	RailPower(3.60,0);




	//############################################################################
	//LampPost1(-0.6,0);
	LampPost1(-0.3,0);
	//LampPost1(0,0);
	LampPost1(0.3,0);
	//LampPost1(0.6,0);
	LampPost1(0.9,0);
	//LampPost1(2.1,0);
	LampPost1(2.3,0);
	//LampPost1(2.7,0);
	LampPost1(2.9,0);
	//LampPost1(3.3,0);
	//LampPost1(3.7,0);
	LampPost1(3.4,0);

	LampPost2(-0.6,0);
	//LampPost2(-0.3,0);
	LampPost2(0,0);
	//LampPost2(0.3,0);
	LampPost2(0.6,0);
	//LampPost2(0.9,0);
	//LampPost2(1.83,0);
	LampPost2(2.13,0);
	//LampPost2(2.43,0);
	LampPost2(2.73,0);
	//LampPost2(3.03,0);
	LampPost2(3.23,0);



	LampPost3(0,-0.1);
	//LampPost3(0,0.1);
	LampPost3(0,0.3);
	LampPost3(0,2.35);
	//LampPost3(0,2.55);
	LampPost3(0,2.75);


	LampPost4(0.01,0.05);
	//LampPost4(0.01,-0.1);
	LampPost4(0.01,-0.3);
	LampPost4(0.01,-2.45);
	//LampPost4(0.01,-2.6);
	LampPost4(0.01,-2.8);
	//###################################################################################


	glPushMatrix();
    glTranslatef(-1.25f, 0.8f, 0.0f);
    tree1();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.25f, 0.8f, 0.0f);
    tree1();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-1.25f, -1.7f, 0.0f);
    tree1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.25f, -1.4f, 0.0f);
    tree1();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-2.3f, 0.8f, 0.0f);
    tree1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.3f, -1.4f, 0.0f);
    tree1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.3f, -1.7f, 0.0f);
    tree1();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.1f, 0.8f, 0.0f);
    tree1();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.1f, -1.7f, 0.0f);
    tree1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1f, -1.3f, 0.0f);
    tree1();
    glPopMatrix();


///############################### Tree 3


    glPushMatrix();
    glTranslatef(1.0f, -1.6f, 0.0f); // Change position of the tree
    treeWithCloudLeaves();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2f, -1.6f, 0.0f);
    treeWithCloudLeaves();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25f, 0.85f, 0.0f); // Change position of the tree
    treeWithCloudLeaves();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2f, 0.875f, 0.0f);
    treeWithCloudLeaves();
    glPopMatrix();

	TrafficSignal1();
	TrafficSignal2();

	glutSwapBuffers();

	glFlush();

}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glLoadIdentity();
	glutCreateWindow("Project");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1920, 1080);
	glutKeyboardFunc(toggleDayNight);
	glutDisplayFunc(display);

	glutTimerFunc(10, updatecar1, 0);
	glutTimerFunc(10, updatecar3, 0);
	glutTimerFunc(10, updatecar4, 0);
	glutTimerFunc(10, updatecar2, 0);
	glutTimerFunc(10, updateTrain1, 0);

	gluOrtho2D(-2, 2, -1.5, 1.5);

	glutMainLoop();

	return 0;
}
