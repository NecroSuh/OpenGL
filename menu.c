#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

GLboolean IsSphere = 1;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.0, 0.5);
    if (IsSphere)
        glutWireSphere(0.2, 15, 15);
    else
        glutWireTorus(0.1, 0.3, 40, 20);
    glFlush();
}

void MyMainMenu(int entryID) {
    if (entryID == 1)
        IsSphere = 1;
    else if (entryID == 2)
        IsSphere = 0;
    else if (entryID == 3)
        exit(0);
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
    glLoadIdentity( );
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
