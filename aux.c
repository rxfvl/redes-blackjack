#include "aux.h"

void registro(char buffer[250]){
    char usuario[50];
    char password[50];
    char *token;

    printf("fichero creado\n");

    // Separar el buffer por espacios
    token = strtok(buffer, " ");
    
    // Recorrer el comando
    while (token != NULL) {
        if(strcmp(token, "-u") == 0) {
            // El siguiente token será el nombre de usuario
            token = strtok(NULL, " ");
            if(token != NULL) {
                strcpy(usuario, token);
            }
            if(buscarUsuario(usuario) != NULL)
            {
                printf("-Err. Nombre de usuario en uso\n");
                return;
            }
        }
        else if(strcmp(token, "-p") == 0) {
            // El siguiente token será la contraseña
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(password, token);
            }
        }
        token = strtok(NULL, " ");
    }

    FILE *fichero = fopen("usuarios.txt", "a");
    if(fichero == NULL){
        printf("Error al abrir el fichero\n");
        return;
    }

    fprintf(fichero, " %s %s\n", usuario, password);

    fclose(fichero);
}

char* buscarUsuario(char* usuario)
{
    char linea [100];
    char usuarioF[50];

    FILE* fichero = fopen("usuarios.txt", "r");
    if (fichero == NULL)
    {
        printf("Fichero usuarios.txt no existe\n");
    }
    else
    {
        while(fgets(linea, sizeof(linea), fichero))
        {
            linea[strcspn(linea, "\n")] = 0;
            char *aux = strtok(linea, " ");
            if(strcmp(usuario, aux) == 0){
                aux = strtok(NULL, " ");
                fclose(fichero);
                return aux;
            }
        }
        fclose(fichero);
        return NULL;
    }
}