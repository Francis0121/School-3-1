#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>

void mydisplay();
void init();

float vertices[] = {
	// front
	1, 1, 1, -1, 1, 1, -1,-1, 1,
	-1,-1, 1, 1,-1, 1, 1, 1, 1,
	// back
	1,-1,-1, -1,-1,-1, -1, 1,-1,
	-1, 1,-1, 1, 1,-1, 1,-1,-1,
	// top
	1, 1, 1, 1, 1,-1, -1, 1,-1,
	-1, 1,-1, -1, 1, 1, 1, 1, 1,
	// bottom
	-1,-1,-1, 1,-1,-1, 1,-1, 1,
	1,-1, 1, -1,-1, 1, -1,-1,-1,
	// right
	1, 1, 1, 1,-1, 1, 1,-1,-1,
	1,-1,-1, 1, 1,-1, 1, 1, 1,
	// left
	-1, 1, 1, -1, 1,-1, -1,-1,-1,
	-1,-1,-1, -1,-1, 1, -1, 1, 1,
};

float colors[] = {
	// front, red
	1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,
	1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,
	// back, cyan
	0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
	0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
	// left, green
	0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
	0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
	// right, magenta
	1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1,
	// top, blue
	0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
	0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
	// bottom, yellow
	1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
	1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
};

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("simple");
	
	if( glewInit() != GLEW_OK ) {
		std::cout << "GLEW faild to init. :-(" << std::endl;
	}
	
	init();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}

void init(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
	glEnable(GL_DEPTH_TEST);
	
	// ~ Intrinsic
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, -5.0f, 5.0f);
	// ~ Extrinisic
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	gluLookAt(	0.0f, 0.0f, 3.0f,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);
}

#define BUFFER_OFFSET(i) ((void*)(i))

void mydisplay()
{
	// Trianlge Mesh ������ ���ӵ� 3���� ���� �ﰢ���� ǥ����.
	float vertice_2d[] = {
		1,1,0,		-1,1,0,		-1,-1,0,		
		-1,-1,0,		1,-1,0,		1,1,0
	};
	
	// �� ���� ���� ���� ǥ���Ѵ�. �� ���� ������.
	float color_2d[] = {
		1, 0, 0, 1,		0, 1, 0, 1,		0, 0, 1, 1, 
		1, 0, 0, 1,		1, 0, 0, 1,		1, 0, 0, 1
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glEnableClientState(GL_VERTEX_ARRAY); 
	glEnableClientState(GL_COLOR_ARRAY);
	
	// set our vertices 
	glVertexPointer(3, GL_FLOAT, 0, vertice_2d); 
	glColorPointer(4, GL_FLOAT, 0, color_2d); 
	
	// draw
	glDrawArrays(GL_TRIANGLES, 0, 6); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY); 

	glFlush();
}