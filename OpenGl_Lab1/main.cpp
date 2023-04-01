#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO; // глобальна€ переменна€ дл€ хранени€ указател€ на буфер вершин

// функци€ рендера
static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); // очистка буфера кадра

    glEnableVertexAttribArray(0); // разрешение использовани€ каждого атрибута вершины
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // прив€зываем наш буфер, приготавлива€ его дл€ отрисовки
    // этот вызов говорит конвейеру как воспринимать данные внутри буфера
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // индекс атрибута, кол-во компонентов в атрибуте,
    // тип данных, нужно ли нормализовать, число байт между 2 экземпл€рами

    // отрисовка
    glDrawArrays(GL_TRIANGLES, 0, 3); // тип, индекс, кол-во элементов

    glDisableVertexAttribArray(0); // отключение атрибута вершины

    glutSwapBuffers(); // обмен фонового буфера и буфера кадра местами
}

static void CreateVertexBuffer()
{
    // создаем массив из трЄх экземпл€ров структуры Vector3f
    Vector3f Vertices[3];
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f); //l 
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f); //r
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f); //u

    // создание буфера
    glGenBuffers(1, &VBO); // создание буфера
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // св€зывание буфера с целью
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // наполнение буфера данными
}

int main(int argc, char** argv)
{
    // инициализаци€ и настройка GLUT
    glutInit(&argc, argv); // инициализаци€ GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // двойна€ буферизаци€ и буфер цвета

    // настройка и создание окна
    glutInitWindowSize(550, 550); // размер окна
    glutInitWindowPosition(100, 100); // позици€ окна
    glutCreateWindow("Lesson 03"); // создание окна

    glutDisplayFunc(RenderSceneCB); // задаЄт обратный вызов отображени€ дл€ текущего окна

    // инициализируем GLEW и провер€ем на ошибки
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливает цвет, который будет использован во врем€ очистки буфера кадра

    CreateVertexBuffer(); // создание буффера вершин

    glutMainLoop(); // передаЄт контроль GLUT'у

    return 0;
}
