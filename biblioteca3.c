#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_LIBROS 100
#define MAX_TITULO 100
#define MAX_AUTOR 50

int main()
{
    //Mostrar la fecha y hora actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Fecha y hora actual: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    //Estructura basica de nuestros datos
    char titulos[MAX_LIBROS][MAX_TITULO] = {"El principito", "Don Quijote de la Mancha", "1984"};
    char autores[MAX_LIBROS][MAX_AUTOR] = {"Antoine de Saint-Exupery", "Miguel de Cervantes", "George Orwell"};
    int disponible[MAX_LIBROS] = {1, 1, 1}; // 1 = Disponible, 0 = Prestado
    int num_libros = 3;

    int opcion;
    char busqueda[MAX_TITULO];
    int encontrado;

    do
    {
        printf("==== Biblioteca - Sistema de Gestion ====\n");
        
        printf("1.   |Ver todos los libros\n");
        printf("2.   |Buscar libro\n");
        printf("3.   |Prestar libro\n");
        printf("4.   |Devolver libro\n");
        printf("5.   |Agregar nuevo libro\n");
        printf("6.   |Salir\n");
        

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        switch (opcion)
        {
        case 1: // Ver todos los libros
            printf("==== Catalogo de libros ====\n");
            printf("%-30s | %-20s | %s\n", "Titulo", "Autor", "Disponible");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < num_libros; i++)
            {
                printf("%-30s | %-20s | %s\n", 
                        titulos[i],
                        autores[i],
                        disponible[i] ? "Disponible" : "Prestado");
            }
            break;
        case 2: // Buscar libro
            printf("Introduce el titulo del libro a buscar: ");
            fgets(busqueda, MAX_TITULO, stdin);
            busqueda[strcspn(busqueda, "\n")] = 0; // Eliminar salto de linea

            encontrado = 0;
            for (int i = 0; i < num_libros; i++)
            {
                if (strstr(titulos[i], busqueda) != NULL)
                {
                    printf("Libro encontrado:\n");
                    printf("Titulo: %s\n", titulos[i]);
                    printf("Autor: %s\n", autores[i]);
                    printf("Estado: %s\n", disponible[i] ? "Disponible" : "Prestado");
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("Libro no encontrado\n");
            }
            break;

        case 3: // Prestar libro
            printf("Introduce el titulo del libro a prestar: ");
            fgets(busqueda, MAX_TITULO, stdin);
            busqueda[strcspn(busqueda, "\n")] = 0; // Eliminar salto de linea

            encontrado = 0;
            for (int i = 0; i < num_libros; i++)
            {
                if (strstr(titulos[i], busqueda) != NULL)
                {
                    if (disponible[i])
                    {
                        disponible[i] = 0;
                        printf("Libro prestado\n");
                    }
                    else
                    {
                        printf("El libro no esta disponible\n");
                    }
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("Libro no encontrado\n");
            }
            break;

        case 4: // Devolver libro  
            printf("Introduce el titulo del libro a devolver: ");
            fgets(busqueda, MAX_TITULO, stdin);
            busqueda[strcspn(busqueda, "\n")] = 0; // Eliminar salto de linea

            encontrado = 0;
            for (int i = 0; i < num_libros; i++)
            {
                if (strstr(titulos[i], busqueda) != NULL)
                {
                    if (!disponible[i])
                    {
                        disponible[i] = 1;
                        printf("Libro devuelto\n");
                    }
                    else
                    {
                        printf("El libro ya esta disponible\n");
                    }
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("Libro no encontrado\n");
            }
            break;

        case 5: // Agregar nuevo libro
            printf("Introduce el titulo del libro: ");
            fgets(titulos[num_libros], MAX_TITULO, stdin);
            titulos[num_libros][strcspn(titulos[num_libros], "\n")] = 0; // Eliminar salto de linea

            printf("Introduce el autor del libro: ");
            fgets(autores[num_libros], MAX_AUTOR, stdin);
            autores[num_libros][strcspn(autores[num_libros], "\n")] = 0; // Eliminar salto de linea

            disponible[num_libros] = 1;
            num_libros++;
            printf("Libro agregado\n");
            break;

        case 6: // Salir
            printf("Saliendo del programa...\n");
            break;

        default:
            break;
        }

    } while (opcion != 6);

    return 0;
    

}