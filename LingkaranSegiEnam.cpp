#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Menggambar lingkaran hijau di sebelah kiri dengan jarak lebih jauh dan ukuran lebih besar
    glColor3f(0.0, 1.0, 0.0);
    float x, y;
    int num_segments = 100;
    float radius = 0.5f; // Perbesar ukuran lingkaran
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * i / num_segments;
        x = -0.7 + radius * cos(theta); // Geser lebih jauh ke kiri
        y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    
    // Menggambar segi enam berwarna biru tua di sebelah kanan dengan jarak lebih jauh
    glColor3f(0.0, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f(0.75, 0.4);
        glVertex2f(1.2, 0.0);
        glVertex2f(1.0, -0.45);
        glVertex2f(0.4, -0.7);
        glVertex2f(-0.05, -0.45);
        glVertex2f(-0.1, 0.0);
    glEnd();
    
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        gluOrtho2D(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w);
    } else {
        gluOrtho2D(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Segi Enam dan Lingkaran");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

