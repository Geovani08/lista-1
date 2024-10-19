#include <GL/glut.h>
#include <math.h>

void drawSpiral(float centerX, float centerY, float radius, int numTurns) {
    glBegin(GL_LINE_STRIP); 
    glColor3f(1.0, 0.0, 0.0); 

    
    for (float angle = 0; angle < numTurns * 2 * M_PI; angle += 0.1) {
        float currentRadius = radius * (angle / (numTurns * 2 * M_PI));
        float x = centerX + cos(angle) * currentRadius;
        float y = centerY + sin(angle) * currentRadius;

        glVertex2f(x, y); 
    }

    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    drawSpiral(0.0, 0.0, 1.0, 5);
    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Espiral");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
