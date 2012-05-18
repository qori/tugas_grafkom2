/**********************************/
/*    Qori Nurqolbi - 10108424    */
/* Idham Herawan Putra - 10108450 */
/*      Nur Mufmin - 10108447     */
/*     Vian Arwanda - 10108467    */
/**********************************/
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\OpenGL\GL\glut.h>

using namespace std;
static int elbow = 20, up = 0, look_right = 0;

void init(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position2[] = { -2.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);*/
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
	glScalef(-2.0, 0.15, 0.2);
	glutSolidCube(1.2);
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
	glScalef(0.15, -2.0, 0.2);
	glutSolidCube(1.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.3, 0.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.9, 0.0);
	glScalef(0.1, -2.0, 0.2);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glutSolidSphere(0.15, 30.0, 20.0);
	glPopMatrix();

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat) h / (GLfloat) w, 1.5 * (GLfloat) h
				/ (GLfloat) w, -10.0, 10.0);
	} else {
		glOrtho(-1.5 * (GLfloat) w / (GLfloat) h, 1.5 * (GLfloat) w
				/ (GLfloat) h, -1.5, 1.5, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 's':
			elbow = (elbow + 5) % 360;
			//up = (up + 3) % 360;
			//look_right = (look_right + 5) % 360;
			glutPostRedisplay();

			break;
		case 'e':
			elbow = (elbow - 5) % 360;
			//up = (up - 3) % 360;
			//look_right = (look_right - 5) % 360;

			glutPostRedisplay();
			break;
		default:
			break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	cout << "Keterangan :" << endl;
	cout << "------------------------------" << endl;
	cout << "Tekan s untuk Putar kincir angin ke arah kiri" << endl;
	cout << "Tekan e untuk Putar kincir angin ke arah kanan" << endl;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Kincir Angin");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}