#pragma comment (lib,"glu32.lib")
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"user32.lib")
#pragma comment (lib,"gdi32.lib")
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include <vector>
#include <math.h>
#include "SOIL.h"


float rotationAngle = 0.0f;
float size = 2;

float r = 1.0f, g = 0.0f, b = 0.0f;
float r1 = 1.0f, g1 = 0.0f, b1 = 0.0f;
float r2 = 1.0f, g2 = 0.0f, b2 = 0.0f;
float r3 = 1.0f, g3 = 0.0f, b3 = 0.0f;
float r4 = 1.0f, g4 = 0.0f, b4= 0.0f;
bool isRed = false;

int value = 0;

void display() {

    // Текс на екране

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);  
    glRasterPos2f(0.55 , 0.9 );  
    const char* text = "KFR - 2003-2024A";  
    for (const char* char_ptr = text; *char_ptr; ++char_ptr) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *char_ptr);  
    }


    glColor3f(1.0, 0.0, 0.0); // Красный цвет
    glRasterPos2f(0.7, -0.3);
    char valueText[20];
    snprintf(valueText, sizeof(valueText), "Value: %d", value);
    for (const char* char_ptr = valueText; *char_ptr; ++char_ptr) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *char_ptr);
    }

    glFlush();

    //
    

    // Круг основы + контор круга

    float radius1 = 0.13f;
    int num_segments = 100;
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float dx = radius1 * cosf(theta);
        float dy = radius1 * sinf(theta);
        glVertex2f(dx, dy);
    }
    glEnd(); 

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float dx = radius1 * cosf(theta);
        float dy = radius1 * sinf(theta);
        glVertex2f(dx, dy);
    }
    glEnd();
    glFlush();

    // Круги + контуры которые служат как датчики и меняют цвет

    float radius2 = 0.05f;
    int num_segments1 = 100;
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments1; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius2 * cosf(theta) -0.35 * size;
        float dy = radius2 * sinf(theta) -0.35 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    float radius3 = 0.05f;
    int num_segments2 = 100;
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments2; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius3 * cosf(theta) - 0.35 * size;
        float dy = radius3 * sinf(theta) + 0.125 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    float radius4 = 0.05f;
    int num_segments3 = 100;
    glColor3f(r2, g2, b2);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments3; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius4 * cosf(theta) + 0.075 * size;
        float dy = radius4 * sinf(theta) + 0.375 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    float radius5 = 0.05f;
    int num_segments4 = 100;
    glColor3f(r3, g3, b3);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments4; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius5 * cosf(theta) + 0.425 * size;
        float dy = radius5 * sinf(theta) + 0.125 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    float radius6 = 0.05f;
    int num_segments5 = 100;
    glColor3f(r4, g4, b4);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments5; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius6 * cosf(theta) + 0.425 * size;
        float dy = radius6 * sinf(theta) - 0.35 * size;
        glVertex2f(dx, dy);
    }
    glEnd();



    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments1; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius2 * cosf(theta) - 0.35 * size;
        float dy = radius2 * sinf(theta) - 0.35 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments2; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius3 * cosf(theta) - 0.35 * size;
        float dy = radius3 * sinf(theta) + 0.125 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments3; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius4 * cosf(theta) + 0.075 * size;
        float dy = radius4 * sinf(theta) + 0.375 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments4; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius5 * cosf(theta) + 0.425 * size;
        float dy = radius5 * sinf(theta) + 0.125 * size;
        glVertex2f(dx, dy);
    }
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments5; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments1);
        float dx = radius6 * cosf(theta) + 0.425 * size;
        float dy = radius6 * sinf(theta) - 0.35 * size;
        glVertex2f(dx, dy);
    }
    glEnd();
    glFlush();


    

    //


    // Не двигающиеся части (Круги + квадраты + контуры к ним)

    glColor3f(0.5f, 0.5f, 0.5f);
     
    glBegin(GL_QUADS);
    glVertex2f(-0.45 * size, -0.3 * size);
    glVertex2f(-0.325 * size, -0.3 * size);
    glVertex2f(-0.325 * size, -0.175 * size);
    glVertex2f(-0.45 * size, -0.175 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.45 * size, 0.175 * size);
    glVertex2f(-0.325 * size, 0.175 * size);
    glVertex2f(-0.325 * size, 0.3 * size);
    glVertex2f(-0.45 * size, 0.3 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.325 * size, -0.3 * size);
    glVertex2f(0.45 * size, -0.3 * size);
    glVertex2f(0.45 * size, -0.175* size);
    glVertex2f(0.325 * size, -0.175 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.325 * size, 0.175* size);
    glVertex2f(0.45 * size, 0.175 * size);
    glVertex2f(0.45 * size, 0.3 * size);
    glVertex2f(0.325 * size, 0.3 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.1 * size, 0.425 * size);
    glVertex2f(0.1 * size, 0.425 * size);
    glVertex2f(0.1 * size, 0.5 * size);
    glVertex2f(-0.1 * size, 0.5 * size);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.45 * size, -0.3 * size);
    glVertex2f(-0.325 * size, -0.3 * size);
    glVertex2f(-0.325 * size, -0.175 * size);
    glVertex2f(-0.45 * size, -0.175 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.45 * size, 0.175 * size);
    glVertex2f(-0.325 * size, 0.175 * size);
    glVertex2f(-0.325 * size, 0.3 * size);
    glVertex2f(-0.45 * size, 0.3 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.325 * size, -0.3 * size);
    glVertex2f(0.45 * size, -0.3 * size);
    glVertex2f(0.45 * size, -0.175 * size);
    glVertex2f(0.325 * size, -0.175 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.325 * size, 0.175 * size);
    glVertex2f(0.45 * size, 0.175 * size);
    glVertex2f(0.45 * size, 0.3 * size);
    glVertex2f(0.325 * size, 0.3 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.1 * size, 0.425 * size);
    glVertex2f(0.1 * size, 0.425 * size);
    glVertex2f(0.1 * size, 0.5 * size);
    glVertex2f(-0.1 * size, 0.5 * size);
    glEnd();

    glFlush();

    // Прямоуголькини которые двигаються + контур

    glPushMatrix();
    //glTranslatef(objectX, objectY, 0.0f);  
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
   

    glColor3f(0.0, 1.0, 0.3);
    
    glBegin(GL_QUADS);
    glVertex2f(-0.025 * size,0);
    glVertex2f(0.025 * size,0);
    glVertex2f(0.025 * size,0.175 * size);
    glVertex2f(-0.025 * size,0.175 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.025 * size, 0.125 * size);
    glVertex2f(0.075 * size, 0.125 * size);
    glVertex2f(0.075 * size, 0.3 * size);
    glVertex2f(0.025 * size, 0.3 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.075 * size, 0.125 * size);
    glVertex2f(-0.025 * size, 0.125 * size);
    glVertex2f(-0.025 * size, 0.3 * size);
    glVertex2f(-0.075 * size, 0.3 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.025 * size, 0.25 * size);
    glVertex2f(0.025 * size, 0.25 * size);
    glVertex2f(0.025 * size, 0.425 * size);
    glVertex2f(-0.025 * size, 0.425 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.0125 * size, 0.425 * size);
    glVertex2f(0.0125 * size, 0.425 * size);
    glVertex2f(0.0125 * size, 0.5 * size);
    glVertex2f(-0.0125 * size, 0.5 * size);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.05 * size, 0.45 * size);
    glVertex2f(0.05 * size, 0.45 * size);
    glVertex2f(0.05 * size, 0.475 * size);
    glVertex2f(-0.05 * size, 0.475 * size);
    glEnd();

    glLineWidth(2.0f); 
    glColor3f(0.0f, 0.0f, 0.0f); 

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.025 * size, 0);
    glVertex2f(0.025 * size, 0);
    glVertex2f(0.025 * size, 0.175 * size);
    glVertex2f(-0.025 * size, 0.175 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.025 * size, 0.125 * size);
    glVertex2f(0.075 * size, 0.125 * size);
    glVertex2f(0.075 * size, 0.3 * size);
    glVertex2f(0.025 * size, 0.3 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.075 * size, 0.125 * size);
    glVertex2f(-0.025 * size, 0.125 * size);
    glVertex2f(-0.025 * size, 0.3 * size);
    glVertex2f(-0.075 * size, 0.3 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.025 * size, 0.25 * size);
    glVertex2f(0.025 * size, 0.25 * size);
    glVertex2f(0.025 * size, 0.425 * size);
    glVertex2f(-0.025 * size, 0.425 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.0125 * size, 0.425 * size);
    glVertex2f(0.0125 * size, 0.425 * size);
    glVertex2f(0.0125 * size, 0.5 * size);
    glVertex2f(-0.0125 * size, 0.5 * size);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.05 * size, 0.45 * size);
    glVertex2f(0.05 * size, 0.45 * size);
    glVertex2f(0.05 * size, 0.475 * size);
    glVertex2f(-0.05 * size, 0.475 * size);
    glEnd();
    
    glFlush();
    
    glPopMatrix();

    glutSwapBuffers();

    //
}

void control(unsigned char key, int x, int y) {
  
    if (key == 'Z' || key == 'z') {
        rotationAngle += 5.0f; 
        glutPostRedisplay(); 
    }

    if (key == 'c' || key == 'C') {
        rotationAngle -= 5.0f;
        glutPostRedisplay();
    }

    if (key == 'q' || key == 'Q') {
        
        if (!isRed) {
            r = 0.0f;
            g = 0.5f;
            b = 0.0f;
            isRed = true;
        }

        else {
            r = 1.0f;
            g = 0.0f;
            b = 0.0f;
            isRed = false;
        }
    }
    glutPostRedisplay();

    if (key == 'w' || key == 'W') {
        
        if (!isRed) {
            r1 = 0.0f;
            g1 = 0.5f;
            b1 = 0.0f;
            isRed = true;
        }
        else {
            r1 = 1.0f;
            g1 = 0.0f;
            b1 = 0.0f;
            isRed = false;
        }
    }
    glutPostRedisplay();

    if (key == 'e' || key == 'E') {
        
        if (!isRed) {
            r2 = 0.0f;
            g2 = 0.5f;
            b2 = 0.0f;
            isRed = true;
        }
        else {
            r2 = 1.0f;
            g2 = 0.0f;
            b2 = 0.0f;
            isRed = false;
        }
    }
    glutPostRedisplay();

    if (key == 'r' || key == 'R') {
        
        if (!isRed) {
            r3 = 0.0f;
            g3 = 0.5f;
            b3 = 0.0f;
            isRed = true;
        }
        else {
            r3 = 1.0f;
            g3 = 0.0f;
            b3 = 0.0f;
            isRed = false;
        }
    }
    glutPostRedisplay();

    if (key == 't' || key == 'T') {
        
        if (!isRed) {
            r4 = 0.0f;
            g4 = 0.5f;
            b4 = 0.0f;
            isRed = true;
        }
        else {
            r4 = 1.0f;
            g4 = 0.0f;
            b4 = 0.0f;
            isRed = false;
        }
    }
    glutPostRedisplay();

    if (key == 'y' || key == 'Y')
    {
        r = 1.0f;
        g = 0.0f;
        b = 0.0f;
        r1 = 1.0f;
        g1 = 0.0f;
        b1 = 0.0f;
        r2 = 1.0f;
        g2 = 0.0f;
        b2 = 0.0f;
        r3 = 1.0f;
        g3 = 0.0f;
        b3 = 0.0f;
        r4 = 1.0f;
        g4 = 0.0f;
        b4 = 0.0f;
        
    }
    glutPostRedisplay();

    switch (key) {
    case 's': 
        value++;
        break;
    case 'a': 
        value--;
        break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutCreateWindow("Robot 2024");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutKeyboardFunc(control);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
