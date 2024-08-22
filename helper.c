//
// Created by Fran on 21/08/2024.
//

#include "helper.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

Nodo *newNodo(char id[12])
{
    Nodo *aux= malloc(sizeof(Nodo));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->sig=NULL;
    strcpy(aux->id,id);
    return aux;
}
Estudiante *newEstudiante(char id[12],char nombre[25])
{
    Estudiante *aux= malloc(sizeof(Estudiante));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->ant=NULL;
    aux->sig=NULL;
    strcpy(aux->id,id);
    strcpy(aux->nombre,nombre);
    aux->cursos=NULL;
    return aux;
}
RegistroEstudiante *registroEstudiante()
{
    RegistroEstudiante *aux= malloc(sizeof(RegistroEstudiante));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->cabEst=NULL;
    return aux;
}
Curso *newCurso(char id[12],char nombre[25])
{
    Curso *aux= malloc(sizeof(Curso));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->sig=NULL;
    aux->ant=NULL;
    strcpy(aux->id,id);
    strcpy(aux->nombre,nombre);
    aux->estudiantes=NULL;
    return aux;
}
RegistroCurso *registroCurso()
{
    RegistroCurso *aux= malloc(sizeof(RegistroCurso));
    if(aux==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->cabCurso=NULL;
    return aux;
}

void agregarEstudiante(RegistroEstudiante *registroEstudiante,char *id,char *nombre)
{
    Estudiante *nuevo= newEstudiante(id,nombre);
    if(registroEstudiante->cabEst==NULL)
    {
        registroEstudiante->cabEst=nuevo;
    }else
    {
        Estudiante *aux=registroEstudiante->cabEst;
        while (aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->ant=aux;
    }
}
Estudiante *buscarEstudiante(char *id,RegistroEstudiante *registroEstudiante)
{
    Estudiante *aux=registroEstudiante->cabEst;
    while (aux!=NULL)
    {
        if(strcmp(aux->id,id)==0)
        {
            return aux;
        }
        aux=aux->sig;
    }
    return NULL;
}
Curso *buscarCurso(char *id,RegistroCurso *registroCurso)
{
    Curso *aux=registroCurso->cabCurso;
    while (aux!=NULL)
    {
        if(strcmp(aux->id,id)==0)
        {
            return aux;
        }
        aux=aux->sig;
    }
    return NULL;
}
void eliminarEstudiante(RegistroEstudiante*registroEstudiante,char *id,RegistroCurso *registroCurso)
{
    Estudiante *estudiante=buscarEstudiante(id,registroEstudiante);
    if(estudiante==NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    Nodo *aux=estudiante->cursos;
    while (aux!=NULL)
    {
        Curso *curso=buscarCurso(id,registroCurso);
        if(curso!=NULL)
        {
            Nodo *act=curso->estudiantes;
            Nodo *ant=NULL;
            while(act!=NULL)
            {
                if(strcmp(act->id,id)==0)
                {
                    if(ant==NULL)
                    {
                        curso->estudiantes=act->sig;
                        if(act->sig!=NULL)
                        {
                            act->ant->sig=NULL;
                        }
                    }else
                    {
                        ant->sig=act->sig;
                        if(act->sig!=NULL)
                        {
                            act->sig->ant=ant;
                        }
                    }
                    free(act);
                    break;
                }
                ant=act;
                act=act->sig;
            }
        }
        aux=aux->sig;
    }
    if(estudiante->ant==NULL)
    {
        registroEstudiante->cabEst=estudiante->sig;
        if(estudiante->sig!=NULL)
        {
            estudiante->sig->ant=NULL;
        }
    }else
    {
        estudiante->ant->sig=estudiante->sig;
        if(estudiante->sig!=NULL)
        {
            estudiante->ant->sig=NULL;
        }
    }
    if(estudiante->sig!=NULL)
    {
        estudiante->sig->ant=estudiante->ant;
    }
    free(estudiante);
}
void agregarCurso(RegistroCurso *registroCurso,char *idCurso,char *nombre)
{
    Curso *nuevo= newCurso(idCurso,nombre);
    if(registroCurso->cabCurso==NULL)
    {
        registroCurso->cabCurso=nuevo;
    }else
    {
        Curso *aux=registroCurso->cabCurso;
        while (aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
}
void registrarCurso(RegistroCurso *registroCurso,RegistroEstudiante *registroEstudiante,char *idCurso,char *idEstudiante)
{
    Estudiante *estudiante= buscarEstudiante(idEstudiante,registroEstudiante);
    if(estudiante==NULL)
    {
        printf("No existe estudiante\n");
        exit(-1);
    }
    Curso *curso= buscarCurso(idCurso,registroCurso);
    if(curso==NULL)
    {
        agregarCurso(registroCurso,idCurso,"Curso nuevo");
        curso= buscarCurso(idCurso,registroCurso);
    }
    Nodo *nuevo= newNodo(idEstudiante);
    if(curso->estudiantes==NULL)
    {
        curso->estudiantes=nuevo;
    }else
    {
        Nodo *aux=curso->estudiantes;
        while(aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->ant=aux;
    }
    Nodo *nuevo1= newNodo(idCurso);
    if(estudiante->cursos==NULL)
    {
        estudiante->cursos=nuevo1;
    }else
    {
        Nodo *aux=estudiante->cursos;
        while(aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo1;
        nuevo1->ant=aux;
    }

}
void mostrarEstudiante(Estudiante *estudiante,RegistroCurso *registroCurso)
{
    printf("Nombre:%s\n",estudiante->nombre);
    printf("ID:%s\n",estudiante->id);
    Nodo *aux = estudiante->cursos;
    while(aux!=NULL)
    {
        printf("Materia:%s\n", buscarCurso(aux->id,registroCurso)->nombre);
        aux=aux->sig;
    }
}
void mostrarEstudiantes(RegistroEstudiante*registroEstudiante,RegistroCurso*registroCurso)
{
    Estudiante *aux=registroEstudiante->cabEst;
    while (aux!=NULL)
    {
        mostrarEstudiante(aux,registroCurso);
        aux=aux->sig;
    }
}
void mostrarCurso(Curso *curso,RegistroEstudiante*registroEstudiante)
{
    printf("Nombre:%s\n",curso->nombre);
    printf("ID:%s\n",curso->id);
    Nodo *aux = curso->estudiantes;
    while(aux!=NULL)
    {
        printf("Estudiante:%s\n", buscarEstudiante(aux->id,registroEstudiante)->nombre);
        aux=aux->sig;
    }
}
void mostrarCursos(RegistroEstudiante*registroEstudiante,RegistroCurso*registroCurso)
{
    Curso *aux=registroCurso->cabCurso;
    while (aux!=NULL)
    {
        mostrarCurso(aux,registroEstudiante);
        aux=aux->sig;
    }
}
