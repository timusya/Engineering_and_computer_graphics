#include <GL/freeglut.h> // ���������� ��� ���������� ������� �������� � �.�.

static void RenderSceneCB() // ������� �������
{
    glClear(GL_COLOR_BUFFER_BIT); // ������� ������ �����
    glutSwapBuffers(); // ����� �������� ������ � ������ ����� �������
}

int main(int argc, char** argv)
{
    // ������������� � ��������� GLUT
    glutInit(&argc, argv); // ������������� GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // ������� ����������� � ����� �����

    // ��������� � �������� ����
    glutInitWindowSize(550, 550); // ������ ����
    glutInitWindowPosition(100, 100); // ������� ����
    glutCreateWindow("Lesson 01"); // �������� ����

    glutDisplayFunc(RenderSceneCB); // ����� �������� ����� ����������� ��� �������� ����

    glClearColor(0.1f, 0.2f, 0.7f, 0.9f); // ������������� ����, ������� ����� ����������� �� ����� ������� ������ �����

    glutMainLoop(); // ������� �������� GLUT'�

    return 0;
}