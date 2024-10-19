#include <GL/glut.h>
void displaytri1(void);
void displaytri2(void);
void displaytri3(void);
void display() {
glClear(GL_COLOR_BUFFER_BIT);
  	displaytri1();
  	displaytri2();
  	displaytri3();

    glFlush(); 
}
void displaytri1() {
     

    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
  	glVertex3f(-0.6, -0.75, 0.5);
    glVertex3f(0.6, -0.75, 0);
    glVertex3f(0, 0.75, 0);
	
	glEnd();
 
}
void displaytri2(){
	glLineWidth(2.0);

    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 0.0);
  	glVertex3f(-0.6, -0.75, 0.5);
    glVertex3f(0.6, -0.75, 0);
    glVertex3f(0, 0.75, 0);

 	glEnd();
}

void displaytri3(){
	glPointSize(10.0);

    
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0);
  	glVertex3f(-0.6, -0.75, 0.5);
    glVertex3f(0.6, -0.75, 0);
    glVertex3f(0, 0.75, 0);

 	glEnd();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(80, 80);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Triangulo");
	
	glutDisplayFunc(display);
	glutMainLoop();
}
