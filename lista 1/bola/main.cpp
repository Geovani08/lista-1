#include <GL/glut.h>
#include <math.h>

float angle = 0.0; 

void drawCircle(float x, float y, float radius) {
    
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); 
    for(int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawPacman(float x, float y, float radius) {
       glColor3f(0.0, 0.0, 0.0);
    drawCircle(x, y, radius);

    glBegin(GL_TRIANGLE_FAN); 
    glColor3f(1.0, 1.0, 0.0); 
    glVertex2f(x, y); 
    for(int i = angle; i <= 360 - angle; i++) {
        float angleRad = i * M_PI / 180.0;
        glVertex2f(x + cos(angleRad) * radius, y + sin(angleRad) * radius);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    drawPacman(0.0, 0.0, 0.5); 
    glFlush();
}

void timer(int value) {
    angle += 5; 
    if (angle >= 45) { 
        angle = 0;
    }
    glutPostRedisplay(); 
    glutTimerFunc(100, timer, 0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pac-Man");
    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0); 
    glutMainLoop();
    return 0;
}
