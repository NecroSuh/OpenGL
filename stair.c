#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLboolean IsSphere = 1;
GLboolean IsSmall = 1;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.0, 0.5);
    if ((IsSphere) && (IsSmall))
        glutWireSphere(0.2, 15, 15);        //작은 원구
    else if ((IsSphere) && (!IsSmall))
        glutWireSphere(0.4, 15, 15);        //큰 원구
    else if ((!IsSphere) && (IsSmall))
        glutWireTorus(0.1, 0.3, 40, 20);    //작은 원환체
    else
        glutWireTorus(0.2, 0.5, 40, 20);    //큰 원환체
    glFlush();
}

void MyMainMenu(int entryID) {
    if (entryID == 1)
        IsSphere = 1;                //원구 그리기
    else if (entryID == 2)
        IsSphere = 0;               //원환체 그리기
    else if (entryID == 3)
        exit(0);                        //프로그램 종료
    glutPostRedisplay();
}

void MySubMenu(int entryID) {
    if (entryID == 1)
        IsSmall = 1;                 //작은 크기로 그리기
    else if (entryID == 2)
        IsSmall = 0;                //큰 크기로 그리기
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Example Drawing");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MySubMenuID = glutCreateMenu(MySubMenu);
    glutAddMenuEntry("Small One", 1);
    glutAddMenuEntry("Big One", 2);
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddSubMenu("Change Size", MySubMenuID);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
