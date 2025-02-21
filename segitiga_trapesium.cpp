#include <glut.h>

int window1, window2;

void displayTriangle() {
    // Membersihkan buffer warna
    glClear(GL_COLOR_BUFFER_BIT);

    // Menentukan warna segitiga menjadi merah
    glColor3f(1.0f, 0.0f, 0.0f); // Merah

    // Menggambar segitiga
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, -0.5f); // Titik pertama
        glVertex2f( 0.6f, -0.5f); // Titik kedua
        glVertex2f( 0.0f,  0.4f); // Titik ketiga
    glEnd();

    // Menampilkan hasil gambar ke layar
    glFlush();
}

void displayTrapezoid() {
    // Membersihkan buffer warna
    glClear(GL_COLOR_BUFFER_BIT);

    // Menentukan warna trapesium menjadi biru
    glColor3f(0.0f, 0.0f, 1.0f); // Biru

    // Menggambar trapesium
    glBegin(GL_QUADS);
        glVertex2f(-0.7f, -0.4f); // Titik pertama
        glVertex2f( 0.7f, -0.4f); // Titik kedua
        glVertex2f( 0.3f,  0.4f); // Titik ketiga
        glVertex2f(-0.3f,  0.4f); // Titik keempat
    glEnd();

    // Menampilkan hasil gambar ke layar
    glFlush();
}

void init() {
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Proyeksi ortografik 2D
}

void setupWindow(int window_id, const char* title, void (*displayFunc)()) {
    glutSetWindow(window_id);
    glutDisplayFunc(displayFunc); // Menentukan fungsi tampilan
    glutReshapeWindow(500, 500);  // Ukuran jendela
    glutSetWindowTitle(title);    // Judul jendela
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // Membuat window pertama untuk segitiga (tidak tampilkan dulu)
    window1 = glutCreateWindow("Segitiga Merah");
    init();
    
    // Membuat window kedua untuk trapesium (tidak tampilkan dulu)
    window2 = glutCreateWindow("Trapesium Biru");
    init();

    // Setup window 1 dan 2 agar jendela menunggu tampilan setelah menu dipilih
    setupWindow(window1, "Segitiga Merah", displayTriangle);
    setupWindow(window2, "Trapesium Biru", displayTrapezoid);
    
    // Menampilkan menu dan menunggu pilihan
    glutMainLoop();

    return 0;
}

