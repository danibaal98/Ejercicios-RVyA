#include <GL/glut.h>

static GLint rotateX = 0;
static GLint rotateY = 0;
static GLint rotateZ = 0;

static GLint direction = 1;

typedef enum {
  ROTATE_X,
  ROTATE_Y,
  ROTATE_Z
} rotate_t;

static rotate_t rotation;

void render () { 
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Posición de la cámara virtual (position, look, up) */
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glRotatef(rotateX, 1, 0, 0);
  glRotatef(rotateY, 0, 1, 0);
  glRotatef(rotateZ, 0, 0, 1);

  
  /* En color blanco */
  glColor3f( 1.0, 1.0, 1.0 );  
  /* Renderiza la tetera */
  glutWireTeapot(1.5);
  /* Intercambio de buffers... Representation ---> Window */
  glutSwapBuffers();      
} 

void changeAngle (int *rotate) {
  *rotate = (*rotate + direction) % 360;
  glutPostRedisplay();
}

void resize (int w, int h) { 
  /* Definición del viewport */
  glViewport(0, 0, w, h);

  /* Cambio a transform. vista */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* Actualiza el ratio ancho/alto */
  gluPerspective(50., w/(double)h, 1., 10.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW);
}

void rotate () {
  switch (rotation) {
    case ROTATE_X:
      changeAngle(&rotateX);
      break;
    case ROTATE_Y:
      changeAngle(&rotateY);
      break;
    case ROTATE_Z:
      changeAngle(&rotateZ);
      break;
  }
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'x':
      rotation = ROTATE_X;
      glutIdleFunc(rotate);
      break;
    case 'y':
      rotation = ROTATE_Y;
      glutIdleFunc(rotate);
      break;
    case 'z':
      rotation = ROTATE_Z;
      glutIdleFunc(rotate);
      break;
    case 's':
      glutIdleFunc(NULL);
  }
}

void directionFuncion (int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_RIGHT:
      direction = 1;
      break;
    case GLUT_KEY_LEFT:
      direction = -1;
      break;
  }
}

int main (int argc, char* argv[]) { 
  glutInit( &argc, argv ); 
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE ); 
  glutInitWindowSize(640, 480); 
  glutCreateWindow( "IVI - Sesion 2" ); 
  glEnable (GL_DEPTH_TEST);
  
  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render); 
  glutReshapeFunc(resize); 
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(directionFuncion);

  /* Bucle de renderizado */
  glutMainLoop();  
  
  return 0; 
} 
