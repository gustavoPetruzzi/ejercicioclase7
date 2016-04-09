#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 5
char mostrarMenu( char textomenu[], char min, char max);
int main()
{
    int i;
    int legajo[MAX] ={1,2,3,4,5};
    char opcion = 'a';
    char apellidos[MAX][25]= {"Perez","Gonzalez","Petruzzi","Carajo","RECARAJO"};
    char auxApellido[25];
    int auxLegajo;
    int flagIgual;
    char modificar;
    int j;

    /*for(i = 0; i<MAX; i++)
    {
        printf("Ingrese su legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese su apellido: ");
        fflush(stdin);
        scanf("%s", apellidos[i]);

    }*/
    do
    {
        opcion = mostrarMenu("1-Modificar\n2-Borrar\n3-Mostrar\n4-Ordenar por apellido\n5-Salir\n", '1', '5');

        switch(opcion)
        {
            case '1':
                system("cls");
                flagIgual = 1;
                printf("Ingrese legajo:");
                fflush(stdin);
                scanf("%d", & auxLegajo);
                for(i= 0; i<MAX; i++)
                {
                    if(legajo[i] == auxLegajo)
                    {
                        printf("Desea modificarlo? s/n\n");
                        fflush(stdin);
                        scanf("%c", &modificar);
                        modificar =tolower(modificar);
                        if(modificar == 's')
                        {
                            printf("Ingrese el Nuevo apellido:\n");
                            scanf("%s", auxApellido);
                            printf("Apellido borrado: %s\n",apellidos[i]);
                            strcpy(apellidos[i], auxApellido);
                            printf("Apellido Nuevo: %s\n",apellidos[i]);

                        }
                        flagIgual = 0;
                        break;
                    }
                }
                if(flagIgual == 1)
                {
                    printf("NO HAY NINGUN LEGAJO IGUAL \n");
                }
                system("pause");
                system("cls");
                break;
            case '2':
                system("cls");
                flagIgual = 1;
                printf("Ingrese n° legajo");
                fflush(stdin);
                scanf("%d", & auxLegajo);
                for(i= 0; i<MAX; i++)
                {
                    if(legajo[i] == auxLegajo)
                    {
                        printf("Desea Borrarlo? s/n\n");
                        fflush(stdin);
                        scanf("%c", &modificar);
                        if(modificar == 's')
                        {
                            legajo[i]= -1;
                            strcpy(apellidos[i], "-1");

                        }
                        flagIgual = 0;
                        break;
                    }
                }
                if(flagIgual == 1)
                {
                    printf("NO HAY NINGUNO IGUAL");
                }
                system("pause");
                system("cls");
                break;

            case '3':
                system("cls");
                printf("Legajo\tApellido\n\n");
                for(i=0;i<MAX;i++)
                {
                    if(legajo[i]>0)
                        {
                            printf("%d\t%s\n",legajo[i],apellidos[i]);
                        }
                }
                system("pause");
                system("cls");
                break;

                system("cls");
            case '4':
                system("cls");
                for(i = 0; i< MAX-1; i++)
                {
                    for(j = i + 1; j<MAX; j++)
                    {
                        if(strcmp(apellidos[i], apellidos[j])>0)
                        {

                            strcpy(auxApellido, apellidos[i]);
                            strcpy(apellidos[i], apellidos[j]);
                            strcpy(apellidos[j], auxApellido);

                            auxLegajo = legajo[i];
                            legajo[i] = legajo[j];
                            legajo[j] = auxLegajo;
                        }
                        else if(strcmp(apellidos[i], apellidos[j])== 0)
                        {
                            auxLegajo = legajo[i];
                            legajo[i] = legajo[j];
                            legajo[j] = auxLegajo;
                        }

                    }
                }
                system("pause");
                system("cls");
                break;

            case '5':
                break;
        }

    }while(opcion != '5');
    return 0;
}

char mostrarMenu( char textomenu[], char min, char max )
{
    char opcion ='|';
    int flagPrimera = 1;


    do
    {
        if(opcion !='|' && flagPrimera != 1)
        {
            printf("ERROR: reingrese\n");
        }
        printf("%s", textomenu);
        fflush(stdin);
        scanf("%c",&opcion);
        flagPrimera = 0;
    }while(opcion < min || opcion > max);
    return opcion;



}
