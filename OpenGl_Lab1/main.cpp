#include <GL/freeglut.h> // библиотека для управления оконной системой и т.д.

static void RenderSceneCB() // функция рендера
{
    glClear(GL_COLOR_BUFFER_BIT); // очистка буфера кадра
    glutSwapBuffers(); // обмен фонового буфера и буфера кадра местами
}

int main(int argc, char** argv)
{
    // инициализация и настройка GLUT
    glutInit(&argc, argv); // инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // двойная буферизация и буфер цвета

    // настройка и создание окна
    glutInitWindowSize(550, 550); // размер окна
    glutInitWindowPosition(100, 100); // позиция окна
    glutCreateWindow("Lesson 01"); // создание окна

    glutDisplayFunc(RenderSceneCB); // задаёт обратный вызов отображения для текущего окна

    glClearColor(0.1f, 0.2f, 0.7f, 0.9f); // устанавливает цвет, который будет использован во время очистки буфера кадра

    glutMainLoop(); // передаёт контроль GLUT'у

    return 0;
}