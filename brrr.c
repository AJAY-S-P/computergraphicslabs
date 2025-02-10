
#include <GL/glut.h>
#include <stdio.h>

int x1 = 200, y_start = 100, x2 = 300, y_end = 180;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenhamLine(int x1, int y_start, int x2, int y_end) {
    int dx = x2 - x1;
    int dy = y_end - y_start;
    int p = 2 * dy - dx;
    int x = x1;
    int y = y_start;

    plot(x, y);

    while (x < x2) {
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        plot(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhamLine(x1, y_start, x2, y_end);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Brrrrrrrzzzzzz....");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
