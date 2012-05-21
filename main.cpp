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

#define CAMERA_RELEASE 0
#define CAMERA_ROTATE 1
#define CAMERA_ZOOM 2

using namespace std;

static int elbow = 20, up = 0, look_right = 0;
static float cloud1, cloud2, cloud3, cloud4, cloud5, cloud6, cloud7 = 0;   // awan cloud

const double PI = 3.141592653589793;
int i, radius, jumlah_titik, x_tengah, y_tengah;

int cameraSetting;
float viewAngleX, viewAngleY, scaleFactor = 1.0;
int clickX, clickY;

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

void renderLingkaran() {
	glBegin(GL_POLYGON);
		radius = 15;
		jumlah_titik = 20;
		x_tengah = 50;
		y_tengah = 50;
		
		for (i = 0; i <= 360; i++){
		    float sudut = i * (2 * PI / jumlah_titik);
			float x = x_tengah + radius * cos(sudut);
			float y = y_tengah + radius * sin(sudut);
			glVertex2f(x / 100,y / 100);
		}
	glEnd();
}

void display(void) {
	// Clear the screen
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Set world window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);

    // Setup 3D environment
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(1,0,5,
            0,0,0,
            0,1,0);

    // Rotate and scale 3D environment to current user settings
    glRotatef(viewAngleX, 0, 1, 0);
    glRotatef(viewAngleY, 1, 0, 0);
    glScalef(scaleFactor, scaleFactor, scaleFactor);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.3, 0.6, 0.7); /* warna awan */

	/* -- begin awan 1 -- */
	glPushMatrix();

	glTranslatef((GLfloat) (-1.09 + cloud1), 0.0, -1.2);

	glPushMatrix();
	glTranslatef(-1.09, 0.0, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.19, -0.14, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.04, -0.19, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.94, -0.12, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPopMatrix();
	/* -- end awan 1 -- */

	/* -- begin awan 2 -- */
	glPushMatrix();
	glTranslatef((GLfloat) (-0.02 + cloud2), 0.0, -1.2);

	glPushMatrix();
	glTranslatef(-0.02, 0.5, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.12, 0.46, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.21, 0.36, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.09, 0.36, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.02, 0.32, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, 0.34, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.09, 0.44, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPopMatrix();
	/* -- end awan 2 -- */


	/* -- begin awan 3 -- */
	glPushMatrix();

	glTranslatef((GLfloat) (-1.45 + cloud3), 0.60, -1.2);

	glPushMatrix();
	glTranslatef(-1.45, 0.60, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.62, 0.60, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.72, 0.60, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.62, 0.68, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPopMatrix();
	/* -- end awan 3 -- */


	
	/* -- begin awan 4 -- */
	glPushMatrix();

	glTranslatef((GLfloat) (-1.45 + cloud4), 0.60, -1.2);

	glPushMatrix();
	glTranslatef(-0.30, 0.10, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.50, 0.10, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.10, 0.10, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.10, 0.10, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.33, 0.20, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.23, 0.20, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.11, 0.20, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPopMatrix();
	/* -- end awan 4 -- */

	
	
	/* -- begin awan 5 -- */
	glPushMatrix();

	glTranslatef((GLfloat) (-0.30 + cloud5), 1.20, -1.2);

	glPushMatrix();
	glTranslatef(-0.30, 1.20, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.50, 1.20, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.70, 1.20, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.90, 1.20, -1.2);
	renderLingkaran();
	glPopMatrix();





	glPushMatrix();
	glTranslatef(-0.30, 1.05, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.50, 1.05, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.70, 1.05, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.90, 1.05, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.01, 1.13, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.21, 1.13, -1.2);
	renderLingkaran();
	glPopMatrix();
	

	glPopMatrix();
	/* -- end awan 5 -- */


	
	/* -- begin awan 6 -- */
	glPushMatrix();

	glTranslatef((GLfloat) (1.00 + cloud6), 0.50, -1.2);

	glPushMatrix();
	glTranslatef(1.00, 0.50, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.20, 0.50, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.40, 0.50, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.40, 0.50, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.03, 0.60, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.93, 0.60, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.81, 0.60, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPopMatrix();
	/* -- end awan 6 -- */
	
	
	/* -- begin awan 7 -- */
	glPushMatrix();
	glTranslatef((GLfloat) (-2.02 + cloud7), 0.5, -1.2);

	glPushMatrix();
	glTranslatef(-2.02, 0.5, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.12, 0.46, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.21, 0.36, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.09, 0.36, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.02, 0.32, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.1, 0.34, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.09, 0.44, -1.2);
	renderLingkaran();
	glPopMatrix();

	glPopMatrix();
	/* -- end awan 7 -- */




	glPushMatrix();
	glColor3f(0.5, 0.27, 0.07);
	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.9);
	glScalef(-2.0, 0.15, 0.2);
	glutSolidCube(1.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.27, 0.07);
	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.9);
	glScalef(0.15, -2.0, 0.2);
	glutSolidCube(1.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, -1.4, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, -0.9, 0.0);
	glScalef(0.1, -2.0, 0.2);
	glutWireCube(1.0);
	glPopMatrix();

	/*glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, -0.09);
	glScalef(0.02, 0.13, 1.3);
	glutSolidCube(1.2);
	glPopMatrix();*/

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glutWireSphere(0.15, 30.0, 20.0);
	glScalef(1.0,1.0,4.0);
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
			
			if (cloud1 <= -4.12) {
				cloud1 = 5.42003;
			} else {
				cloud1 -= 0.01;
			}
			
			if (cloud2 <= -6.22005) {
				cloud2 = 3.37;
			} else {
				cloud2 -= 0.01;
			}

			if (cloud3 <= -3.24) {
				cloud3 = 6.30001;
			} else {
				cloud3 -= 0.03;
			}
			
			if (cloud4 <= -3.892) {//ini masuk ke e
				cloud4 = 5.09599; //copy kesini hasil hitung tadi
			} else {
				cloud4 -= 0.015;
			}

			
			if (cloud5 >= 4.54501) {
				cloud5 = -3.34501;
			} else {
				cloud5 -= 0.015;
			}

			if (cloud6 <= -7.64998) {
				cloud6 = -0.45;
			} else {
				cloud6 -= 0.015;
			}

			if (cloud7 <= -1.62) {
				cloud7 = 6.88499;
			} else {
				cloud7 -= 0.015;
			}
		            

			glutPostRedisplay();

			break;
		case 'e':
			elbow = (elbow - 5) % 360;

			if (cloud1 >= 5.42003) {
				cloud1 = -4.12;
			} else {
				cloud1 += 0.01;
			}

			if (cloud2 >= 3.37) {
				cloud2 = -6.22005;
			} else {
				cloud2 += 0.01;
			}

			if (cloud3 >= 6.30001) {
				cloud3 = -3.24;
			} else {
				cloud3 += 0.03;
			}

			if (cloud4 >= 5.09599) { // hasil perhitungan ini masukin di cloud 4 s juga
				cloud4 = -3.892; // ini hasil dari perhitungan di cloud4 s
			} else {
				cloud4 += 0.015;
			}

			if (cloud5 >= 3.34501) {
				cloud5 = -4.54501;
			} else {
				cloud5 += 0.015;
			}
			
			if (cloud6 >= -0.45) {
				cloud6 = -7.64998;
			} else {
				cloud6 += 0.015;
			}

			if (cloud7 >= 6.88499) {
				cloud7 = -1.62;
			} else {
				cloud7 += 0.015;
			}

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
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Kincir Angin");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}