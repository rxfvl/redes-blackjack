#include "aux.h"
#include <stdlib.h>


void registro(char buffer[250]){
    char usuario[50];
    char password[50];
    char *token;
    int correcto = 0;

    // format: REGISTRO -u <usuario> -p <password>
    token = strtok(buffer, " ");
    token = strtok(NULL, " ");
    if (token != NULL)
    {
        if (strcmp(token, "-u") == 0)
        {
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                // if (buscarUsuario(token) != NULL)
                // {
                //     printf("-Err. Usuario ya registrado\n");
                //     return;
                // }
                strcpy(usuario, token);
            }
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                if (strcmp(token, "-p") == 0)
                {
                    token = strtok(NULL, " ");
                    if (token != NULL)
                    {
                        strcpy(password, token);
                        correcto = 1;
                    }
                }
            }
        }
    }
 
    if (correcto == 1)
    {
        FILE *fichero = fopen("usuarios.txt", "a");
        if(fichero == NULL){
            printf("Error al abrir el fichero\n");
            return;
        }
        fprintf(fichero, "%s %s", usuario, password);

        fclose(fichero);
    }
    else {
        printf("-Err. Comando incorrecto\n");
    }
}

char* buscarUsuario(char* usuario)
{
    // char linea [100];
    char usuarioF[50];
    char* password;

    FILE* fichero = fopen("usuarios.txt", "r");
    if (fichero == NULL)
    {
        printf("Fichero usuarios.txt no existe\n");
    }
    else
    {
        // while(fgets(linea, sizeof(linea), fichero))
        // {
        //     linea[strcspn(linea, "\n")] = 0;
        //     char *aux = strtok(linea, " ");
        //     if(strcmp(usuario, aux) == 0){
        //         aux = strtok(NULL, " ");
        //         fclose(fichero);
        //         return aux;
        //     }
        // }

        while(fscanf(fichero, "%s", usuarioF) != EOF)
        {
            fscanf(fichero, "%s", password);
            if(strcmp(usuario, usuarioF) == 0){                
                fclose(fichero);
                return password;
            }
        }
        fclose(fichero);
        return NULL;
    }
}