#include <gl/glut.h>

void practice1();
void practice2();
void practice3();

void init();

// glut를 이용해서 opengl을 사용하기위한 밑작업을 한 것. 
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // ' GLUT_DEPTH ' 부분을 practice 2 추가시 사용
	glutCreateWindow("simple");

	init();
	// Callback 함수를 계속 바꿈
	glutDisplayFunc(practice3); // callback 함수를 등록한다. 실행하는 것 X 
	glutMainLoop(); 

	return 0;
}

void init()
{
	// RGB Color를 RGB로 변경 http://www.opengl.org/discussion_boards/showthread.php/139274-How-to-Convert-from-RGB-255-to-OpenGL-Float-Color 
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // RGBA
	glEnable(GL_DEPTH_TEST); // practice 2 부분에서 추가
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	// 카메라를 기준으로 얼만큼의 volume을 볼것인가?에대한 정의를 할 수 있는 함수
	glOrtho(-2.0, 2.0, 
			-2.0, 2.0, 
			-2.0, 2.0);
}


void practice1()
{
	/** Practice 02. 추가사항 */
	// glClear : 화면을 깨끗하게 지워라 
	// monitor clear XXXXX --- Frame buffer (그림을 그릴 수 있는 canvas) 삭제 
	glClear(GL_COLOR_BUFFER_BIT ); 

	// 내가 넣은 정보는 각 vertex에 대한 정보만 넣었고 그에 대한 색상만 줬는데
	// 각각에 대한 정보를 이용하여 polygon을 만들고 그것들을 pixcels로 구성해준다.
	// vertex에 대한 순서는 화면으로 볼때 시계방향으로가 아닌 반시계방향으로 그려야 한다.
	
	// Practice 1. 2차원 평면에 다양한 색상으로 그림
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

	// GL Commander buffer에 쌓여있던 명령어들을 모두 비우고, 즉시 실행되도록 하는 역할이다.
	// glFlush는 gl Command가 완전히 실행되기전에 return이 가능하고
	// glFinish는 gl Command가 완전히 실행되고 return이 된다. (이것에 대한 의미는 찾아야함)
	glFlush();
}

void practice2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// 'GL_DEPTH_BUFFER_BIT' practice 2 에서 추가

	// Practice 2. 3차원에 두가지를 그림

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

	glMatrixMode(GL_MODELVIEW);// MODEL(사각형) VIEW(Camera) 를 지정할 것이다라고 말해주는 역할
	glLoadIdentity();
	gluLookAt(	0.5f, 0.5f, 0.0f, // Position 위치
				0.0f, 0.0f, -0.25f, // Orientation 방향 : 그 지점을 바라보고 있다.
				0.0f, 1.0f, 0.0f); // 카메라의 위 방향을 선택

	// 2개의 사각형
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