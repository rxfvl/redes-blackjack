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
                        strcpy(msg, "+OK. Usuario registrado correctamente\n");
                        send(new_sd, msg, sizeof(msg), 0);  
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

int generarCarta(int* corazones, int* diamantes, int* treboles, int *picas, int new_sd)
{
    int disponible = 0;
    int puntos = 0;
    char* carta;
    int palo;
    int numero;
    char msg[250];
    while(disponible == 0)
    {
        carta = malloc(250 * sizeof(char));
        palo = rand() % 4;
        numero = rand() % 13;
        switch(palo)
        {
            case 0:
                if(corazones[numero] == 0)
                {
                    corazones[numero] = 1;
                    disponible = 1;
                    sprintf(carta, "+OK, [CORAZONES, %d]\n", numero + 1);
                    strcpy(msg, carta);
                    send(new_sd, msg, sizeof(msg), 0);
                    free(carta);
                }
            break;
            case 1:
                if(diamantes[numero] == 0)
                {
                    diamantes[numero] = 1;
                    disponible = 1;
                    sprintf(carta, "+OK, [DIAMANTES, %d]\n", numero + 1);
                    strcpy(msg, carta);
                    send(new_sd, msg, sizeof(msg), 0);
                    free(carta);
                }
            break;
            case 2:
                if(treboles[numero] == 0)
                {
                    treboles[numero] = 1;
                    disponible = 1;
                    sprintf(carta, "+OK, [TREBOLES, %d]\n", numero + 1);
                    strcpy(msg, carta);
                    send(new_sd, msg, sizeof(msg), 0);
                    free(carta);
                }
            break;
            case 3:
                if(picas[numero] == 0)
                {
                    picas[numero] = 1;
                    disponible = 1;
                    sprintf(carta, "+OK, [PICAS, %d]\n", numero + 1);
                    strcpy(msg, carta);
                    send(new_sd, msg, sizeof(msg), 0);
                    free(carta);
                }
            break;
        }                      
    }
    puntos = numero + 1;
    return puntos;
}