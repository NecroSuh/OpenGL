#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

static int Day = 0, Day1 = 0, Day2 = 0, Day3 = 0, 
Day4 = 0, Day5 = 0, Day6 = 0, Day7 = 0, Time = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
    glColor3f(1.0, 0.3, 0.3);
    glutSolidSphere(0.2, 20, 16);  //태양    

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.03, 0.0);
    glRotatef((GLfloat)Day1, 0.0, 1.0, 0.0);
    glTranslatef(0.37, 0.0, 0.0);
    glColor3f(0.75, 0.75, 0.75);
    glutSolidSphere(0.03, 10, 8); // 수성
    glLoadIdentity();
    
    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.03, 0.0);
    glRotatef((GLfloat)Day2, 0.0, 1.0, 0.0);
    glTranslatef(0.6, 0.0, 0.0);
    glColor3f(1.0, 0.84, 0.0);
    glutSolidSphere(0.06, 10, 8); // 금성
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.03, 0.0);
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.8, 0.0, 0.0);    // 간격
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.6, 0.7);
    glutSolidSphere(0.06, 10, 8);  //지구    

    glPushMatrix();
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.9, 0.8, 0.2);
    glutSolidSphere(0.03, 10, 8);  //달    
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.01, 0.0);
    glRotatef((GLfloat)Day3, 0.0, 1.0, 0.0);
    glTranslatef(1.2, 0.0, 0.0);
    glColor3f(0.9, 0.1, 0.1);
    glutSolidSphere(0.06, 10, 8); //화성
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.01, 0.0);
    glRotatef((GLfloat)Day4, 0.0, 1.0, 0.0);
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(0.95, 0.81, 0.59);
    glutSolidSphere(0.12, 10, 8); //목성
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.01, 0.0);
    glRotatef((GLfloat)Day5, 0.0, 1.0, 0.0);
    glTranslatef(1.9, 0.0, 0.0);
    glColor3f(0.77, 0.54, 0.07);
    glutSolidSphere(0.11, 10, 8); //토성
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.01, 0.0);
    glRotatef((GLfloat)Day6, 0.0, 1.0, 0.0);
    glTranslatef(2.2, 0.0, 0.0);
    glColor3f(0.16, 0.43, 0.53);
    glutSolidSphere(0.08, 10, 8); //천왕성
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.01, 0.0);
    glRotatef((GLfloat)Day7, 0.0, 1.0, 0.0);
    glTranslatef(2.5, 0.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidSphere(0.08, 10, 8); //해왕성
    glLoadIdentity();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();
    glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)1000;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)1000;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0 * WidthFactor, 5.0 * WidthFactor,
        -5.0 * HeightFactor, 5.0 * HeightFactor, -5.0, 5.0);
}


void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void MyTimer(int Value) {
    Day = (Day + 10) % 360;
    glutPostRedisplay();
    Day1 = (Day1 + 15) % 360;
    glutPostRedisplay();
    Day2 = (Day2 + 12) % 360;
    glutPostRedisplay();
    Day3 = (Day3 + 9) % 360;
    glutPostRedisplay();
    Day4 = (Day4 + 6) % 360;
    glutPostRedisplay();
    Day5 = (Day5 + 3) % 360;
    glutPostRedisplay();
    Day6 = (Day6 + 2) % 360;
    glutPostRedisplay();
    Day7 = (Day7 + 1) % 360;
    glutPostRedisplay();
    glutTimerFunc(50, MyTimer, 1);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("태양계 모델링");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutTimerFunc(50, MyTimer, 1);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}