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
    int opcion = 0;

    // Mensaje de bienvenida
    printf("========================================\n");
    printf("    Biblioteca - Sistema de Gestion\n");
    printf("========================================\n\n");

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
    return 0;
}
