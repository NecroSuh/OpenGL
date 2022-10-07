#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>

void mydisplay(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	// R: »¡°­ G: ÃÊ·Ï B: ÆÄ¶û A: alpha Åõ¸íµµ
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0.4f, -0.4f);
	glVertex2f(0.4f, 0.4f);
	glVertex2f(-0.2f, 0.2f);
	glEnd();
	glFinish();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
