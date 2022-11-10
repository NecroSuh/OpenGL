#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

static int Day = 0, Day1 = 0, Day2 = 0,
Day3 = 0, Day4 = 0, Day5 = 0, Day6 = 0, Day7 = 0, Time = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(2.0, 0.3, 0.3);   // 태양
    glutWireSphere(0.2, 20, 16);

    glPushMatrix();
    glRotatef((GLfloat)Day1, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.0, 0.0);    // 간격
    glColor3f(0.9, 0.8, 1.2);   // 수성
    glutWireSphere(0.04, 10, 8);

    glPushMatrix();
    glRotatef((GLfloat)Day2, 0.0, 1.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);    // 간격
    glColor3f(1.5, 1.8, 0.2);   // 금성
    glutWireSphere(0.08, 10, 8);
    glLoadIdentity();

    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.8, 0.0, 0.0);    // 간격
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.6, 0.7);   // 지구
    glutWireSphere(0.1, 10, 8);

    glPushMatrix();
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);    // 간격
    glColor3f(0.9, 0.8, 0.2);   // 달
    glutWireSphere(0.04, 10, 8);
    glLoadIdentity();

    glPushMatrix();
    glRotatef((GLfloat)Day3, 0.0, 1.0, 0.0);
    glTranslatef(1.2, 0.0, 0.0);    // 간격
    glColor3f(1.5, 0.2, 0.2);   // 화성
    glutWireSphere(0.09, 10, 8);
    glLoadIdentity();

    glPushMatrix();
    glRotatef((GLfloat)Day4, 0.0, 1.0, 0.0);
    glTranslatef(1.6, 0.0, 0.0);    // 간격
    glColor3f(0.43, 0.3, 0.15);   // 목성
    glutWireSphere(0.15, 15, 10);
    glLoadIdentity();

    glPushMatrix();
    glRotatef((GLfloat)Day5, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);    // 간격
    glColor3f(0.7, 0.51, 0.57);   // 토성
    glutWireSphere(0.14, 15, 10);
    glLoadIdentity();

    glPushMatrix();
    glRotatef((GLfloat)Day6, 0.0, 1.0, 0.0);
    glTranslatef(2.4, 0.0, 0.0);    // 간격
    glColor3f(0.3, 0.7, 0.8);   // 천왕성
    glutWireSphere(0.1, 10, 8);
    glLoadIdentity();

    glPushMatrix();
    glRotatef((GLfloat)Day7, 0.0, 1.0, 0.0);
    glTranslatef(2.7, 0.0, 0.0);    // 간격
    glColor3f(0.2, 0.2, 0.9);   // 해왕성
    glutWireSphere(0.1, 10, 8);
    glLoadIdentity();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)500;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)500;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
        -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 10) % 360;
        glutPostRedisplay();
        Day1 = (Day + 5) % 360;
        glutPostRedisplay();
        Day3 = (Day + 12) % 360;
        glutPostRedisplay();
        Day4 = (Day + 12) % 360;
        glutPostRedisplay();
        Day5 = (Day + 14) % 360;
        glutPostRedisplay();
        Day6 = (Day + 16) % 360;
        glutPostRedisplay();
        Day7 = (Day + 18) % 360;
        glutPostRedisplay();
        break;
    case 't':
        Time = (Time + 20) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
