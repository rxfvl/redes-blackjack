#include "aux.h"
#include <stdlib.h>


void registro(char buffer[250], int new_sd){
    char usuario[50];
    char password[50];
    char *token;
    int correcto = 0;
    char msg[250];
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
                if (buscarUsuario(token) != NULL)
                {
                    strcpy(msg, "-Err. Usuario ya registrado\n");
                    send(new_sd, msg, sizeof(msg), 0);
                    return;
                }
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
        printf("fichero\n");
        FILE *fichero = fopen("usuarios.txt", "a");
        if(fichero == NULL)
        {
            printf("Error al abrir el fichero\n");
            exit(-1);
        }
        fprintf(fichero, "%s %s", usuario, password);

        fclose(fichero);
    }
    else 
    {
        strcpy(msg, "-Err. Comando incorrecto\n");
        send(new_sd, msg, sizeof(msg), 0);
    }
}

char* buscarUsuario(char* usuario)
{
    char usuarioF[50];
    char* password;  

    size_t len = strlen(usuario);
    if (usuario[len - 1] == '\n') {usuario[len - 1] = '\0';}

    FILE* ficheroAux = fopen("usuarios.txt", "a");
    if (ficheroAux == NULL)
    {
        printf("Fichero usuarios.txt no existe\n");
        exit(-1);
    }
    fclose(ficheroAux);

    FILE* fichero = fopen("usuarios.txt", "r");
    if (fichero == NULL)
    {
        printf("Fichero usuarios.txt no existe\n");
        exit(-1);
    }
    else
    {
        while (fscanf(fichero, "%s", usuarioF) != EOF)
        {
            password = malloc(50 * sizeof(char));
            fscanf(fichero, "%s", password);
            if (strcmp(usuario, usuarioF) == 0)
            {
                fclose(fichero);
                
                return password;
            }
            free(password);
        }
        fclose(fichero);

        return NULL;
    }
}