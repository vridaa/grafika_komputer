#include <GL/glut.h>  // Untuk Windows/Linux
#include <GL/gl.h>
#include <GL/glu.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Warna hijau zaitun untuk bentuk utama
    glColor3f(0.5f, 0.5f, 0.0f);

    // Trapesium atas
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, 0.8f); //kiri atas
        glVertex2f(0.6f, 0.9f); // kanan atas
        glVertex2f(0.4f, 0.5f); // kanan bawah
        glVertex2f(-0.4f, 0.4f); // kiri bawah
    glEnd();

    // Jajar genjang tengah
    glBegin(GL_POLYGON);
       glVertex2f(-0.4f, 0.4f);
        glVertex2f(0.4f, 0.5f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(-0.5f, 0.1f);
    glEnd();

    // Trapesium bawah
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f, 0.1f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(0.55f, -0.3f);
        glVertex2f(-0.2f, -0.6f);
    glEnd();

    
    glColor3f(1.0f, 1.0f, 1.0f);  // Putih

    
    glLineWidth(3.0f); // Atur ketebalan garis

    // Garis antara trapesium atas dan jajar genjang tengah
    glBegin(GL_LINES);
        glVertex2f(-0.6f, 0.4f); //kiri
        glVertex2f(0.4f, 0.5f); // kanan
    glEnd();

    // Garis antara jajar genjang tengah dan trapesium bawah
    glBegin(GL_LINES);
        glVertex2f(-0.5f, 0.1f);
        glVertex2f(0.3f, 0.0f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Shape with Lines");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

