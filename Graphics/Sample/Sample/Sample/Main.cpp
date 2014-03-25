#include <gl/freeglut.h> // Zoom-In, Zoom-Out [Step 4]. glut.h -> freeglut.h�� ����

void practice1();
void practice2();
void practice3();
void reshape(int w, int h);
void mousewheel(int wheel, int direction, int x, int y);

void init();

double fovy = 60.0;
double aspect = 1.0; // Zoom-In, Zoom-Out [Step 2] aspect ���� ������ ���߰�

// glut�� �̿��ؼ� opengl�� ����ϱ����� ���۾��� �� ��. 
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // ' GLUT_DEPTH ' �κ��� practice 2 �߰��� ���
	glutCreateWindow("simple");

	init();
	// Callback �Լ��� ��� �ٲ�
	glutDisplayFunc(practice3); // callback �Լ��� ����Ѵ�. �����ϴ� �� X 
	glutReshapeFunc(reshape); // Window ����� ����Ǿ����� �θ��� �Լ�. Callback �Լ� ����
	glutMouseWheelFunc(mousewheel);// Zoom-In, Zoom-Out [Step 5] glutMouseWheelFunc�� ���� �̺�Ʈ �߰�
	glutMainLoop();	//	��[13.03.25]-���� �߿��� �κ��̴�.
					//	���⼭ Message Procedure�� ����ؼ� ���ư��鼭
					//	switch ���� ���ؼ� Display �ϰԵǸ� practice �� �ض�
					//	Window Resize�� �Ǿ������� reshape �Լ��� �����϶�� ��ɾ ����Ǵ� ���̴�.
					//	���� reshape�Լ����� glutPostRedisplay() �� ���ٸ� ȭ���� �ٽ� �θ� ���� ����.
					//	glutPostRedisplay(); �̰��� �ؾ� �޽��� �������� �Ǿ� reshape�� ������ �Լ��� �����ϰ� �Ǵ� ���̴�.
	return 0;
}

void init()
{
	// RGB Color�� RGB�� ���� http://www.opengl.org/discussion_boards/showthread.php/139274-How-to-Convert-from-RGB-255-to-OpenGL-Float-Color 
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // RGBA
	glEnable(GL_DEPTH_TEST); // practice 2 �κп��� �߰�
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	// ī�޶� �������� ��ŭ�� volume�� �����ΰ�?������ ���Ǹ� �� �� �ִ� �Լ�
	glOrtho(-2.0, 2.0, 
			-2.0, 2.0, 
			-2.0, 2.0);
}


void practice1()
{
	/** Practice 02. �߰����� */
	// glClear : ȭ���� �����ϰ� ������ 
	// monitor clear XXXXX --- Frame buffer (�׸��� �׸� �� �ִ� canvas) ���� 
	glClear(GL_COLOR_BUFFER_BIT ); 

	// ���� ���� ������ �� vertex�� ���� ������ �־��� �׿� ���� ���� ��µ�
	// ������ ���� ������ �̿��Ͽ� polygon�� ����� �װ͵��� pixcels�� �������ش�.
	// vertex�� ���� ������ ȭ������ ���� �ð�������ΰ� �ƴ� �ݽð�������� �׷��� �Ѵ�.
	
	// Practice 1. 2���� ��鿡 �پ��� �������� �׸�
	glBegin(GL_POLYGON); 

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, 0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.5f, 0.5f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.5f, -0.5f);
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.5f, -0.5f);

	glEnd();

	// GL Commander buffer�� �׿��ִ� ��ɾ���� ��� ����, ��� ����ǵ��� �ϴ� �����̴�.
	// glFlush�� gl Command�� ������ ����Ǳ����� return�� �����ϰ�
	// glFinish�� gl Command�� ������ ����ǰ� return�� �ȴ�. (�̰Ϳ� ���� �ǹ̴� ã�ƾ���)
	glFlush();
}

void practice2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// 'GL_DEPTH_BUFFER_BIT' practice 2 ���� �߰�

	// Practice 2. 3������ �ΰ����� �׸�

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f( 0.25f, 0.25f, -0.25f);
	glVertex3f(-0.25f, 0.25f, -0.25f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glVertex3f( 0.25f, -0.25f, -0.25f);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glEnd();

	glFlush();
}

// Extrinsic parameter Pdf 40.page
void practice3(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);// MODEL(�簢��) VIEW(Camera) �� ������ ���̴ٶ�� �����ִ� ����
	glLoadIdentity();
	gluLookAt(	0.5f, 0.5f, 0.0f, // Position ��ġ
				0.0f, 0.0f, -0.25f, // Orientation ���� : �� ������ �ٶ󺸰� �ִ�.
				0.0f, 1.0f, 0.0f); // ī�޶��� �� ������ ����

	// 2���� �簢��
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f( 0.25f, 0.25f, -0.25f);
	glVertex3f(-0.25f, 0.25f, -0.25f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glVertex3f( 0.25f, -0.25f, -0.25f);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glEnd();

	glFlush();
}

// [14.03.25]
// Step 1. ī�޶���  Viewport�� �ٲ��ְ�, Perspective ������ �������ش�.
// Step 2. �������� ���׿� ���ؼ� �ٽ� �׸���� �޽����� ������ �־�� �Ѵ�. glutPostRedisplay() �Լ� �̿�
void reshape(int w, int h){
	// setting viewport
	int width = w;
	int height = h;
	
	glViewport(0, 0, width, height);

	// ���� Window ����� ���� �����ٰ� ����� �����Ѵ�.
	double aspect = (GLdouble) width / (GLdouble) height; 

	// setting intrinsic parameters of camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// gluPerspective(60.0, aspect, 0.01, 10000.0);
	// Step. 2
	gluPerspective(fovy, aspect, 0.01, 10000.0);
	// glOrtho(left, right, bootom, top, zNea, zFar

	// force to redisplay
	// ...

	// practice3() �� �ϸ� �ȵȴ�. (���� : �����쿡 �޽����� ������ �� ��������)
	glutPostRedisplay(); 
}


// [14.03.25]
// Zoom-In, Zoom-Out [Step 1]. fovy �� ���������� 60.0���� �����ϰ� Zoom_in Zoom_out�� ���� �� �Լ� �ۼ�
// Zoom-In, Zoom-Out [Step 3]. glutPostRedisplay(); �߰�
void mousewheel(int wheel, int direction, int x, int y){

	if(direction < 0)	// Zoom in
		fovy *= 0.8;
	else if(direction > 0)	// Zoom out
		fovy *=1.2;

	// force to redisplay
	// ...
	
	glutPostRedisplay();
}