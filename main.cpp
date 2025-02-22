#include <GL/glut.h>
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

int menuOption = 0;
bool isMenu5Active = false;

void drawText(float x, float y, const std::string& text) {
    glRasterPos2f(x, y);
    for (size_t i = 0; i < text.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (menuOption == 0) { // Tampilkan menu hanya jika tidak ada menu yang dipilih
        glColor3f(0.0, 0.0, 0.0);
        drawText(-0.9, 0.9, "===============================");
        drawText(-0.9, 0.85, "Menu yang tersedia:");
        drawText(-0.9, 0.8, "1. Segitiga Merah");
        drawText(-0.9, 0.75, "2. Trapesium Biru");
        drawText(-0.9, 0.7, "3. Logo UPN Kuning");
        drawText(-0.9, 0.65, "4. Lingkaran Hijau");
        drawText(-0.9, 0.6, "5. Menu 5:");
        drawText(-0.85, 0.55, "   a. Hourglass Merah Terang");
        drawText(-0.85, 0.5, "   b. Segienam Biru");
        drawText(-0.9, 0.45, "6. Abstract Olive");
        drawText(-0.9, 0.4, "===============================");
        drawText(-0.9, 0.35, "Tekan tombol angka (1-6) untuk memilih menu.");
    } else {
        switch (menuOption) {
            case 1: // Segitiga merah
                glColor3f(1.0f, 0.0f, 0.0f);
                glBegin(GL_TRIANGLES);
                    glVertex2f(-0.6f, -0.5f);
                    glVertex2f(0.6f, -0.5f);
                    glVertex2f(0.0f, 0.4f);
                glEnd();
                break;
            case 2: // Trapesium biru
                glColor3f(0.0f, 0.0f, 1.0f);
                glBegin(GL_QUADS);
                    glVertex2f(-0.7f, -0.4f);
                    glVertex2f(0.7f, -0.4f);
                    glVertex2f(0.3f, 0.4f);
                    glVertex2f(-0.3f, 0.4f);
                glEnd();
                break;
            case 3: // Logo UPN kuning
                glColor3ub(255, 255, 0);
                glBegin(GL_POLYGON);
                    glVertex2f(0.0, 0.5);
                    glVertex2f(0.47, 0.15);
                    glVertex2f(0.29, -0.4);
                    glVertex2f(-0.29, -0.4);
                    glVertex2f(-0.47, 0.15);
                glEnd();
                break;
            case 4: // Lingkaran hijau
                glColor3f(0.0, 1.0, 0.0);
                glBegin(GL_POLYGON);
                for (int i = 0; i < 100; i++) {
                    float theta = 2.0f * PI * i / 100;
                    glVertex2f(0.5 * cos(theta), 0.5 * sin(theta));
                }
                glEnd();
                break;
            case 5: // Hourglass merah terang
                glColor3ub(220, 20, 60);
                glBegin(GL_TRIANGLES);
                    glVertex2f(-0.5, 0.5);
                    glVertex2f(0.5, 0.5);
                    glVertex2f(0.0, 0.0);
                glEnd();
                glBegin(GL_TRIANGLES);
                    glVertex2f(-0.5, -0.5);
                    glVertex2f(0.5, -0.5);
                    glVertex2f(0.0, 0.0);
                glEnd();
                break;
            case 6: // Segienam biru (5b)
			    glPushMatrix();
			    glLoadIdentity(); // Reset transformasi agar tidak terkena skala dari reshape
			    glColor3f(0.0, 0.0, 0.5);
			    glBegin(GL_POLYGON);
			        glVertex2f(0.0f, 0.5f);
			        glVertex2f(0.43f, 0.25f);
			        glVertex2f(0.43f, -0.25f);
			        glVertex2f(0.0f, -0.5f);
			        glVertex2f(-0.43f, -0.25f);
			        glVertex2f(-0.43f, 0.25f);
			    glEnd();
			    glPopMatrix();
			    break;

            case 7: // Abstract olive
                glClear(GL_COLOR_BUFFER_BIT);
                glLoadIdentity();
                glColor3f(0.5f, 0.5f, 0.0f); // Hijau zaitun
                glBegin(GL_POLYGON);
                    glVertex2f(-0.6f, 0.8f); // Kiri atas
                    glVertex2f(0.6f, 0.9f);  // Kanan atas
                    glVertex2f(0.4f, 0.5f);  // Kanan bawah
                    glVertex2f(-0.4f, 0.4f); // Kiri bawah
                glEnd();
                glBegin(GL_POLYGON);
                    glVertex2f(-0.4f, 0.4f);
                    glVertex2f(0.4f, 0.5f);
                    glVertex2f(0.3f, 0.0f);
                    glVertex2f(-0.5f, 0.1f);
                glEnd();
                glBegin(GL_POLYGON);
                    glVertex2f(-0.5f, 0.1f);
                    glVertex2f(0.3f, 0.0f);
                    glVertex2f(0.55f, -0.3f);
                    glVertex2f(-0.2f, -0.6f);
                glEnd();
                glColor3f(1.0f, 1.0f, 1.0f); // Putih
                glLineWidth(3.0f); // Atur ketebalan garis
                glBegin(GL_LINES);
                    glVertex2f(-0.6f, 0.4f); // Kiri
                    glVertex2f(0.4f, 0.5f);  // Kanan
                glEnd();
                glBegin(GL_LINES);
                    glVertex2f(-0.5f, 0.1f);
                    glVertex2f(0.3f, 0.0f);
                glEnd();
                break;
        }

        // Tampilkan instruksi untuk kembali ke menu utama
        glColor3f(0.0, 0.0, 0.0);
        drawText(-0.9, -0.9, "Tekan 'b' untuk kembali ke menu utama.");
    }
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (isMenu5Active) {
        // Jika menu 5 aktif, tangani input 'a' atau 'b'
        switch (key) {
            case 'a':
                menuOption = 5; // Hourglass merah terang
                isMenu5Active = false; // Nonaktifkan menu 5
                break;
            case 'b':
                menuOption = 6; // Segienam biru
                isMenu5Active = false; // Nonaktifkan menu 5
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan tekan 'a' atau 'b'." << std::endl;
                break;
        }
    } else {
        // Jika menu 5 tidak aktif, tangani input biasa
        switch (key) {
            case '1':
                menuOption = 1;
                break;
            case '2':
                menuOption = 2;
                break;
            case '3':
                menuOption = 3;
                break;
            case '4':
                menuOption = 4;
                break;
            case '5': // Menu 5
                isMenu5Active = true; // Aktifkan menu 5
                std::cout << "Pilih submenu 5: a. Hourglass Merah Terang, b. Segienam Biru" << std::endl;
                break;
            case '6':
                menuOption = 7; // Abstract olive
                break;
            case 'b': // Tombol 'b' untuk kembali ke menu utama
                menuOption = 0;
                break;
            default:
                break;
        }
    }
    glutPostRedisplay();
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

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Menu Shapes");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
