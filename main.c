#include <stdio.h>
#include "helper.h"
int main()
{
    RegistroEstudiante *registroE1=registroEstudiante();
    RegistroCurso *registroC1=registroCurso();
    agregarEstudiante(registroE1,"AA1234","Francisco");
    agregarEstudiante(registroE1,"AA1235","Franco");
    agregarEstudiante(registroE1,"AA1236","Marcos");
    agregarEstudiante(registroE1,"AA1237","Juan");

    mostrarEstudiantes(registroE1,registroC1);


    printf("Registramos Estudiantes en cursos:\n");
    agregarCurso(registroC1,"BB223","Fisica");
    agregarCurso(registroC1,"BB224","Analisis");


    registrarCurso(registroC1,registroE1,"BB223","AA1234");
    registrarCurso(registroC1,registroE1,"BB223","AA1235");
    registrarCurso(registroC1,registroE1,"BB223","AA1236");
    registrarCurso(registroC1,registroE1,"BB223","AA1237");

    mostrarCursos(registroE1,registroC1);
    printf("Eliminamos Estudiante en cursos:\n");

    eliminarEstudiante(registroE1,"AA1237",registroC1);
    mostrarEstudiantes(registroE1,registroC1);

    return 0;
}
