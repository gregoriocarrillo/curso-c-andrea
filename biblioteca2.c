#include <stdio.h>
#include <time.h>

int main()
{
    system("cls");
    //Mostrar la fecha y hora actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Fecha y hora actual: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        
    // Variables que usaremos más adelante
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    int numero_paginas;
    char editorial[50];
    int esta_prestado;
    char isbn[14];

    //Variables para el menu
    int opcion = 0;
    int libros_disponibles = 100;

    //Inicializar libro ejemplo
    sprintf(titulo, "El principito");
    sprintf(autor, "Antoine de Saint-Exupery");
    anio_publicacion = 1943;
    numero_paginas = 96;
    sprintf(editorial, "Reynal & Hitchcock");
    esta_prestado = 0;
    sprintf(isbn, "9780156012195");

    // Mensaje de bienvenida
    printf("========================================\n");
    printf("    Biblioteca - Sistema de Gestion\n");
    printf("========================================\n");
    printf("Libros disponibles: %d\n\n", libros_disponibles);


    do {
        // Menú principal
        printf("\033[0;31m");
        printf("1. Ver catalogo de libros\n");
        printf("1.1. Ordenar catalogo por autor\n");
        printf("2. Buscar libro\n");
        printf("3. Prestar libro\n");
        printf("4. Devolver libro\n");
        printf("5. Salir\n\n");
        printf("\033[0m");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        //Mostrar informacion del libro de ejemplo
        if (opcion == 1) {
            printf("\nInformacion del libro:\n");
            printf("Titulo: %s\n", titulo);
            printf("Autor: %s\n", autor);
            printf("Año: %d\n", anio_publicacion);
            printf("Paginas: %d\n", numero_paginas);
            printf("Editorial: %s\n", editorial);
            printf("ISBN: %s\n", isbn);
            printf("Estado: %s\n", esta_prestado ? "Prestado" : "Disponible");
        }
        
    } while (opcion != 5);

    return 0;
    
}
