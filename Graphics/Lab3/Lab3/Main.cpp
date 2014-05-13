#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>

void init();
void mydisplay();
void reshape(int w, int h);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH );
	glutCreateWindow("Shading");
	
	init();

	glutDisplayFunc(mydisplay);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

void init(){
	GLfloat La[4] = { 0.1f, 0.1f, 0.1f, 1.0f }; // Ambient (r, g, b, a)
	GLfloat Ld[4] = { 1.0f, 1.0f, 0.0f, 1.0f }; // Diffuse (r, g, b, a)
	GLfloat Ls[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular (r, g, b, a)
	GLfloat Lp[4] = { 0.0f, 0.0f, 1.0f, 1.0f }; // Position (x, y, z, w) homogenous Point ������ w =1

	GLfloat ka[4] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Ambient 50% �ݻ�
	GLfloat kd[4] = { 0.9f, 0.9f, 0.9f, 0.9f }; // Diffuse 90% �ݻ�
	GLfloat ks[4] = { 0.8f, 0.8f, 0.8f, 0.8f }; // Specular 80% �ݻ�
	GLfloat shininess = 50.0f;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	// ������ ���ؼ� Setting
	glLightfv(GL_LIGHT0, GL_POSITION, Ld); // Light Position�� ���ָ� Default�� ���� ���� �ٶ󺸰��Ѵ�.
	glLightfv(GL_LIGHT0, GL_AMBIENT, ka); // La, Ld, Ls �� ka, kd, ks �� �ٲ� �׷��� ��
	glLightfv(GL_LIGHT0, GL_DIFFUSE, kd);
	glLightfv(GL_LIGHT0, GL_SPECULAR, ks);
		
	// ������ ���ؼ� Setting
	// GL_FRONT_AND_BACK �յڿ� �ش��ϴ� ������ ���� �����Ҽ��� �̷��� ���� ������ ���� �ִ�.
	// glMaterialf = ���� ���� �� glMaterialfv �迭
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, La); // ka, kd, ks �� La, Ld, Ls �� �ٲ� �׷��� ��
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Ld);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Ls);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);// ���� �� ��¦�Ÿ��� ȿ�� shininess ũ�Ⱑ ũ�� Ŭ���� ���� ���̰� �Ѵ�.
															// 1�� �������� ũ��. ���� 8/10 �� �¼� ������ ���� ������ ũ��.\

	glEnable(GL_LIGHTING); // ���� ȿ���� '�����'���� �����Ѵ�.
	glEnable(GL_LIGHT0); // Light�� ������ �����ִµ� 0���� Ų��.
}

void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(	0, 0, 5, 
				0, 0, 0,
				0, 1, 0 );

	glutSolidTeapot(1.0f); // x_obj
	glFinish();
}

void reshape(int w, int h){
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLdouble) w/(GLdouble) h, 0.001f, 10000.0f);

	glViewport(0, 0, w, h);
}