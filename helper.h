//
// Created by Fran on 21/08/2024.
//

#ifndef UNTITLED18_HELPER_H
#define UNTITLED18_HELPER_H

typedef struct nodo
{
    struct nodo *sig;
    struct nodo *ant;
    char id[12];
}Nodo;
typedef struct estudiante
{
    char id[12];
    char nombre[25];
    struct estudiante*sig;
    struct estudiante*ant;
    Nodo *cursos;
}Estudiante;
typedef struct registroEstudiante
{
    Estudiante *cabEst;
}RegistroEstudiante;
typedef struct curso
{
    char id[12];
    char nombre[25];
    struct curso*sig;
    struct curso*ant;
    Nodo *estudiantes;
}Curso;
typedef struct registroCurso
{
    Curso *cabCurso;
}RegistroCurso;

Nodo *newNodo(char id[12]);
Estudiante *newEstudiante(char id[12],char nombre[25]);
RegistroEstudiante *registroEstudiante();
Curso *newCurso(char id[12],char nombre[25]);
RegistroCurso *registroCurso();

void agregarEstudiante(RegistroEstudiante *registroEstudiante,char *id,char *nombre);
Estudiante *buscarEstudiante(char *id,RegistroEstudiante *registroEstudiante);
Curso *buscarCurso(char *id,RegistroCurso *registroCurso);
void eliminarEstudiante(RegistroEstudiante*registroEstudiante,char *id,RegistroCurso *registroCurso);
void agregarCurso(RegistroCurso *registroCurso,char *idCurso,char *nombre);
void registrarCurso(RegistroCurso *registroCurso,RegistroEstudiante *registroEstudiante,char *idCurso,char *idEstudiante);
void mostrarEstudiante(Estudiante *estudiante,RegistroCurso *registroCurso);
void mostrarEstudiantes(RegistroEstudiante*registroEstudiante,RegistroCurso*registroCurso);
void mostrarCurso(Curso *curso,RegistroEstudiante*registroEstudiante);
void mostrarCursos(RegistroEstudiante*registroEstudiante,RegistroCurso*registroCurso);

#endif //UNTITLED18_HELPER_H
