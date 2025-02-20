#include <GL/glut.h>

void segilima();
void reshape(int width, int height);

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Project Membuat Segilima");

    init();
    glutDisplayFunc(segilima);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)width / (float)height;
    if (aspect >= 1.0) {
        glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
    } else {
        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
}

void segilima()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    
    glColor3ub(255, 255, 0); 
    glVertex2f(0.0, 0.5);
    glVertex2f(0.47, 0.15);
    glVertex2f(0.29, -0.4);
    glVertex2f(-0.29, -0.4);
    glVertex2f(-0.47, 0.15);
    
    glEnd();
    glFlush();
}

