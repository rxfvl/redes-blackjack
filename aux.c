#include "aux.h"

void registro(char buffer[250]){
    char usuario[50];
    char usuarioF[50];
    char password[50];
    char linea [100];
    char *token;
    
    FILE *fichero = fopen("usuarios.txt", "a");
    if(fichero == NULL){
        printf("Error al abrir el fichero\n");
        return;
    }

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
            while(fgets(linea, sizeof(linea), fichero)){
                linea[strcspn(linea, "\n")] = 0;
                char *aux = strtok(linea, ",");
                strcpy(usuarioF, aux);
                if(strcmp(usuario, usuarioF) == 0){
                    printf("-Err. Nombre de usuario en uso\n");
                    return;
                }
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

    fprintf(fichero, "%s,%s\n", usuario, password);

    fclose(fichero);
}