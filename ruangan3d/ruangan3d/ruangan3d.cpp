#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <glut.h>

GLint slices = 35;
GLint stacks = 35;

using namespace std;
static float ypos = 0, zpos = 0, xpos = 0, a = -9, b = -5, c = -30,  pintu = 0;
int z = 0;

void init(void)
{
    glClearColor(0.8, 0.8, 0.8, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glShadeModel(GL_FLAT);
}


//fungsi kotak kosong, belum diisi koordinat. diisi di display()
void kotak(float x1, float y1, float z1, float x2, float y2, float z2)
{
    //depan
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1, y1, z1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2, y1, z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2, y2, z1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1, y2, z1);
    //atas
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1, y2, z1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2, y2, z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2, y2, z2);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1, y2, z2);
    //belakang
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1, y2, z2);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2, y2, z2);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2, y1, z2);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1, y1, z2);
    //bawah
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1, y1, z2);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x2, y1, z2);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2, y1, z1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x1, y1, z1);
    //samping kiri
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1, y1, z1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1, y2, z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x1, y2, z2);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x1, y1, z2);
    //samping kanan
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x2, y1, z1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x2, y2, z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2, y2, z2);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2, y1, z2);
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        //putar arah jarum jam (menambah derajat putaran)
    case 'z':
        ypos = ypos + 5;
        if (ypos > 360) ypos = 0;
        glutPostRedisplay();
        break;
        //putar berlawanan arah jarum jam (mengurangi derajat putaran)
    case 'x':
        ypos = ypos - 5;
        if (ypos > 360) ypos = 0;
        glutPostRedisplay();
        break;
        //vertikal bawah (menambah koordinat y)
    case 's':
        b = b + 1;
        glutPostRedisplay();
        break;
        //vertikal atas (mengurangi koordinat y)
    case 'w':
        b = b - 1;
        glutPostRedisplay();
        break;
        //horisontal kiri (mengurangi koordinat x)
    case 'a':
        a = a + 1;
        glutPostRedisplay();
        break;
        //horisontal kanan (menambah koordinat x)
    case 'd':
        a = a - 1;
        glutPostRedisplay();
        break;
        //memperbesar objek (menambah koordinat z)
    case 'q':
        c = c + 1;
        glutPostRedisplay();
        break;
        //memperkecil abjek(mengurangi koordinat z)
    case 'e':
        c = c - 1;
        glutPostRedisplay();
        break;

        //putar arah jarum jam (menambah derajat putaran)
    case '[':
        xpos = xpos + 5;
        if (xpos > 360) xpos = 0;
        glutPostRedisplay();
        break;
        //putar berlawanan arah jarum jam (mengurangi derajat putaran)
    case ']':
        xpos = xpos - 5;
        if (xpos > 360) xpos = 0;
        glutPostRedisplay();

    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    //perpindahan
    glTranslatef(a, b, c);
    //putaran
    glRotatef(xpos, 1, 0, 0);
    glRotatef(ypos, 0, 1, 0);
    glRotatef(zpos, 0, 0, 1);

        //lantai
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    kotak(0, 0, 18, 25, 0.5, 0);
    glEnd();
    glPopMatrix();

    //dinding kiri
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.8f);
    kotak(0, 0.5, 18, 0.5, 10, 0);
    glEnd();
    glPopMatrix();

    //dinding belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.8f);
    kotak(6, 0.5, 0.5, 25, 10, 0.0);
    glEnd();
    glPopMatrix();

    //pintu
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.0f, 0.0f);
    kotak(0.5, 0.5, 0.5, 6, 10, 0);
    glEnd();
    glPopMatrix();
    //gagang pintu
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    kotak(5.2, 5.8, 0.7, 5.5, 6, 0.5);
    kotak(4.5, 5.8, 0.9, 5.6, 6, 0.7);
    //alas gagang
    kotak(5.1, 6.5, 0.55, 5.7, 5, 0.5);
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(5.35, 5.2, 0.56, 5.45, 5.5, 0.55);
    glEnd();
    glPopMatrix();
    //gagang pintu belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    kotak(5.2, 5.8, 0, 5.5, 6, -0.2);
    kotak(4.5, 5.8, -0.2, 5.6, 6, -0.4);
    //alas gagang
    kotak(5.1, 6.5, 0, 5.7, 5, -0.05);
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(5.35, 5.2, -0.05, 5.45, 5.5, -0.06);
    glEnd();
    glPopMatrix();
    //meja
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.3f);
    kotak(21, 3.5, 16, 24.8, 3.8, 9.5);
    //kaki kanan belakang
    kotak(24.3, 0.5, 15.9, 24.6, 3.6, 15.6);
    //kaki kiri belakang
    kotak(24.3, 0.5, 9.9, 24.6, 3.6, 9.6);
    //kaki kiri depan
    kotak(21.1, 0.5, 9.9, 21.4, 3.6, 9.6);
    //kaki kanan depan
    kotak(21.1, 0.5, 15.9, 21.4, 3.6, 15.6);
    //belakang bawah
    kotak(24.4, 1, 15.6, 24.6, 1.6, 9.9);
    //kanan bawah
    kotak(21.4, 1, 15.9, 24.3, 1.6, 15.7);
    //kiri bawah
    kotak(21.4, 1, 9.8, 24.3, 1.6, 9.9);
    glEnd();
    glPopMatrix();

   

    //kursi
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.0f, 0.0f);
    kotak(18, 2.2, 15.5, 20.3, 2.5, 12.8);
    //kiri depan
    kotak(20, 0.5, 15.5, 20.3, 2.5, 15.2);
    //kanan depan
    kotak(20, 0.5, 13.1, 20.3, 2.5, 12.8);
    //kanan belakang
    kotak(18, 0.5, 13.1, 18.3, 5.2, 12.8);
    //kiri belakang
    kotak(18, 0.5, 15.5, 18.3, 5.2, 15.2);
    //senderan
    kotak(18, 3.8, 15.5, 18.2, 4.9, 12.8);
    glEnd();
    glPopMatrix();
    
    //lukisan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.3f, 1.0f);
    kotak(0.6, 6.6, 15.5, 0.61, 8.8, 8.9);
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(0.5, 6.4, 15.7, 0.6, 9, 8.7);
    glEnd();
    glPopMatrix();
    //kasur
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.3f);
    kotak(1.1, 1.4, 15.5, 13.4, 3, 8.7);
    //kaki 1
    kotak(0.5, 0.5, 15.6, 1.2, 5.5, 14.9);
    //kaki 2
    kotak(0.5, 0.5, 9.4, 1.1, 5.5, 8.7);
    //kaki 3
    kotak(12.9, 0.5, 9.4, 13.6, 5, 8.7);
    //kaki 4
    kotak(12.9, 0.5, 15.6, 13.6, 5, 14.9);
    //penyangga depan
    kotak(0.6, 3, 15.4, 1, 5.1, 8.9);
    //penyangga belakang
    kotak(12.9, 1.4, 15.4, 13.6, 4.5, 8.9);
    glEnd();
    glPopMatrix();
    //kasur
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.9f, 0.8f);
    kotak(1.1, 2.5, 15.4, 13.4, 3.5, 9);
    //bantal
    glColor3f(0.9f, 0.8f, 0.7f);
    kotak(1.3, 3.5, 14.4, 4, 4, 10);
    //selimut
    glColor3f(0.6f, 0.6f, 0.6f);
    kotak(5, 3.5, 15.4, 13.4, 3.7, 9);
    //kanan
    kotak(5, 3, 9, 13.4, 3.6, 8.9);
    //kiri
    kotak(5, 3, 15.5, 13.4, 3.6, 15.4);
    glEnd();
    glPopMatrix();

    //lemari kecil
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.2f);
    kotak(0.5, 0.8, 8.5, 4, 4.5, 4.7);
    //kaki kiri
    kotak(0.5, 0.5, 8.5, 4.3, 4.9, 8.3);
    //kaki kanan
    kotak(0.5, 0.5, 4.5, 4.3, 4.9, 4.7);
    //pegangan
    glColor3f(0.5f, 0.5f, 0.5f);
    kotak(4.2, 2.1, 6.9, 4.3, 2.3, 6.2);
    kotak(4.2, 3.9, 6.9, 4.3, 4.1, 6.2);
    glEnd();
    glPopMatrix();
    //lacinya
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.1f, 0.1f);
    kotak(4, 1, 8.2, 4.2, 2.5, 4.9);
    kotak(4, 2.7, 8.2, 4.2, 4.3, 4.9);
    glEnd();
    glPopMatrix();

    //tong sampah
    GLUquadricObj* pobj;
    pobj = gluNewQuadric();
    gluQuadricNormals(pobj, GLU_SMOOTH);
    glPushMatrix();
    //glColor3f(8, 0.5, 0);
    glColor3f(0.8, 0.8, 0.8);
    glRotatef(90, 1, 0, 0);
    glTranslatef(8.5, 2.5, -3);
    gluCylinder(pobj, 1, 1, 3, 20, 3);
    glPopMatrix();
    //lampu tidur
    glPushMatrix();
    glColor3f(1, 0.2, 0);
    glRotatef(90, 1, 0, 0);
    glTranslatef(2, 6.5, -6);
    gluCylinder(pobj, 0.3, 0.3, 2, 10, 2);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.5, 0);
    glRotatef(90, 1, 0, 0);
    glTranslatef(2, 6.5, -6);
    gluCylinder(pobj, 0.3, 0.7, 0.8, 20, 2);
    glPopMatrix();
    //sofa
    /*glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    kotak(1.1, 1.4, 15.5, 4.4, 2.5, 8.7);
    //kaki 1
    kotak(0.5, 0.5, 15.6, 1, 5, 14.9);
    //kaki 2
    kotak(0.5, 0.5, 9.4, 1, 5, 8.7);
    //kaki 3
    kotak(4, 0.5, 9.4, 4.5, 2.5, 8.7);
    //kaki 4
    //     a   c    b     a   c    b //a=depan b=samping c=atas
    kotak(4, 0.5, 15.6, 4.5, 2.5, 14.9);
    //senderan
    kotak(0.6, 3, 15.4, 1, 5, 8.7);
    glEnd();
    glPopMatrix();
    //meja
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.5f);
    kotak(6, 2, 15.5, 10.5, 3, 8.7);
    //kaki 1
    kotak(6, 0.5, 15.6, 6.5, 2.5, 14.9);
    //kaki 2
    kotak(6, 0.5, 9.4, 6.5, 2.5, 8.7);
    //kaki 3
    kotak(10, 0.5, 9.4, 10.5, 2.5, 8.7);
    //kaki 4
    kotak(10, 0.5, 15.6, 10.5, 2.5, 14.9);
    glEnd();
    glPopMatrix();*/
    //lemari
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.2f);
    kotak(16, 0.6, 3.5, 23.8, 8.5, 0.5);
    //kanan
    kotak(23.8, 0.5, 3.7, 24, 8.7, 0.5);
    //kiri
    kotak(15.8, 0.5, 3.7, 16, 8.7, 0.5);
    //gagang pintu kiri
    glColor3f(0.5f, 0.5f, 0.5f);
    kotak(19.3, 4.5, 3.9, 19.5, 5.7, 3.7);
    //gagang pintu kanan
    kotak(20.3, 4.5, 3.9, 20.5, 5.7, 3.7);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.1f, 0.1f);
    //pintu kiri
    kotak(16.2, 0.9, 3.7, 19.7, 8.3, 3.5);
    //pintu kanan
    kotak(20.1, 0.9, 3.7, 23.6, 8.3, 3.5);
    glEnd();
    glPopMatrix();

    //cermin 
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(9.2, 2.8, 0.55, 13.2, 8.2, 0.5);
    glColor3f(1.1f, 1.0f, 1.0f);
    kotak(9.4, 3, 0.6, 13, 8, 0.55);
    glEnd();
    glPopMatrix();

    //ac
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.1f, 1.1f, 1.1f);
    kotak(0.55, 8.45, 8.2, 1.2, 9.7, 4.5);
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(1.2, 8.5, 8.2, 1.25, 8.45, 4.5);
    kotak(1.2, 8.6, 8.1, 1.25, 8.62, 4.6);
    kotak(1.2, 9.58, 8.1, 1.25, 9.6, 7);
    kotak(1.2, 9.52, 8.2, 1.25, 9.54, 6.5);
    kotak(0.55, 8.39, 8.1, 1.15, 8.4, 4.6);
    glEnd();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();

}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0 * (GLfloat)w / (GLfloat)h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, 0.0);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 600);
    glutInitWindowPosition(20, 75);
    glutCreateWindow("Ruangan 3d");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}