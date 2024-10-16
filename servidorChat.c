#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#include "aux.h"

#define MSG_SIZE 250
#define MAX_CLIENTS 30

/*
 * El servidor ofrece el servicio de un chat
 */

void manejador(int signum);
void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]);

struct Cliente
{
    char usuario[50];
    int inicioSesion;
    int listo;
};

struct Partida
{
    struct sockaddr_in socket1;
    struct sockaddr_in socket2;
    char usuario1[50];
    char usuario2[50];
    int puntos1;
    int puntos2;
};

int main(){
	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int sd_servidor, new_sd;
	struct sockaddr_in servidor, from;
	char buffer[MSG_SIZE];
	socklen_t from_len;
    fd_set readfds, auxfds;
   	int salida;
   	int arrayClientes[MAX_CLIENTS];
    int numClientes = 0;
    char* user = malloc(50 * sizeof(char));
    

   	//contadores
    int i, j, k;
	int recibidos;
   	char identificador[MSG_SIZE];
    int on, ret;

    //Vector de Struct Cliente
    struct Cliente clientVector[30];
    int ordenCliente = 0;

    //Vector de Struct Partida
    struct Partida partidaVector[30];
    int ordenPartida = 0;

    //inicio de sesion
    int inicioSesion = 0;
    
    //baraja de cartas
    int *corazones = (int *)calloc(13, sizeof(int));
    int *diamantes = (int *)calloc(13, sizeof(int));
    int *treboles = (int *)calloc(13, sizeof(int));
    int *picas = (int *)calloc(13, sizeof(int));
    srand(time(NULL));

    if(corazones == NULL || diamantes == NULL || treboles == NULL || picas == NULL) 
    {
        perror("Error al asignar memoria para los vectores de la baraja");
        exit(1);
    }
	/* --------------------------------------------------
		Se abre el socket 
	---------------------------------------------------*/
  	sd_servidor = socket(AF_INET, SOCK_STREAM, 0);
	if(sd_servidor == -1){
		perror("No se puede abrir el socket cliente\n");
    	exit (1);	
	}
    
    // Activaremos una propiedad del socket para permitir· que otros
    // sockets puedan reutilizar cualquier puerto al que nos enlacemos.
    // Esto permite· en protocolos como el TCP, poder ejecutar un
    // mismo programa varias veces seguidas y enlazarlo siempre al
   	// mismo puerto. De lo contrario habrÌa que esperar a que el puerto
    // quedase disponible (TIME_WAIT en el caso de TCP)
    on=1;
    ret = setsockopt( sd_servidor, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(2000);
	servidor.sin_addr.s_addr =  INADDR_ANY;

	if(bind (sd_servidor, (struct sockaddr *) &servidor, sizeof (servidor)) == -1){
		perror("Error en la operación bind");
		exit(1);
	}
	
   	/*---------------------------------------------------------------------
		Del las peticiones que vamos a aceptar sólo necesitamos el 
		tamaño de su estructura, el resto de información (familia, puerto, 
		ip), nos la proporcionará el método que recibe las peticiones.
   	----------------------------------------------------------------------*/
	from_len = sizeof (from);

	if(listen(sd_servidor, 1) == -1){
		perror("Error en la operación de listen");
		exit(1);
	}

	//Inicializar los conjuntos fd_set
    printf("El servidor está esperando conexiones...\n");	
    	
	FD_ZERO(&readfds);
    FD_ZERO(&auxfds);
    FD_SET(sd_servidor,&readfds);
    FD_SET(0,&readfds);
    
    //Capturamos la señal SIGINT (Ctrl+c)
    signal(SIGINT, manejador);
    
	/*-----------------------------------------------------------------------
		El servidor acepta una petición
	------------------------------------------------------------------------ */
	while(1){
        //Esperamos recibir mensajes de los clientes (nuevas conexiones o mensajes de los clientes ya conectados)
            
        auxfds = readfds;
            
        salida = select(FD_SETSIZE,&auxfds,NULL,NULL,NULL);
            
        if(salida > 0){
                for(i=0; i < FD_SETSIZE; i++){
                    //Buscamos el socket por el que se ha establecido la comunicación
                    if(FD_ISSET(i, &auxfds)){
                        if(i == sd_servidor){
                            if((new_sd = accept(sd_servidor, (struct sockaddr *)&from, &from_len)) == -1){
                                perror("Error aceptando peticiones");
                            }
                            else{
                                if(numClientes < MAX_CLIENTS){
                                    arrayClientes[numClientes] = new_sd;
                                    numClientes++;
                                    FD_SET(new_sd, &readfds);
                                
                                    strcpy(buffer, "+Ok. Usuario conectado\n");
                                
                                    send(new_sd, buffer, sizeof(buffer), 0);
                                
                                    for(j=0; j<(numClientes-1);j++){
                                        bzero(buffer,sizeof(buffer));
                                        sprintf(buffer, "Nuevo Cliente conectado en <%d>", new_sd);
                                        send(arrayClientes[j], buffer, sizeof(buffer), 0);
                                    }
                                }
                                else{
                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer, "Demasiados clientes conectados\n");
                                    send(new_sd, buffer, sizeof(buffer), 0);
                                    close(new_sd);
                                }
                            }
                        }
                        else if(i == 0){
                            //Se ha introducido información de teclado
                            bzero(buffer, sizeof(buffer));
                            fgets(buffer, sizeof(buffer), stdin);

                            //Controlar si se ha introducido "SALIR", cerrando todos los sockets y finalmente saliendo del servidor. (implementar)
                            if(strcmp(buffer,"SALIR\n") == 0){
                                for (j = 0; j < numClientes; j++){
                                    bzero(buffer, sizeof(buffer));
                                    strcpy(buffer,"Desconexión servidor\n"); 
                                    send(arrayClientes[j],buffer , sizeof(buffer),0);
                                    close(arrayClientes[j]);
                                    FD_CLR(arrayClientes[j],&readfds);
                                }

                                close(sd_servidor);
                                exit(-1);
                            }
                            //Mensajes que se quieran mandar a los clientes (implementar)
                            
                        } 
                        else{
                            bzero(buffer,sizeof(buffer));
                            
                            recibidos = recv(i, buffer, sizeof(buffer), 0);
                            
                            if(recibidos > 0)
                            {

                                if(strstr(buffer,"REGISTRO") != NULL)
                                {
                                    printf("registro\n");
                                    registro(buffer, new_sd);
                                }

                                if(strstr(buffer,"USUARIO") != NULL)
                                {
                                    char* usuario = strtok(buffer, " ");
                                    usuario = strtok(NULL, " ");

                                    if(usuario != NULL)
                                    {
                                        char* contraseña = buscarUsuario(usuario);
                                        strcpy(user, usuario);
                                        printf("user: %s\n", user);
                                        
                                        if(contraseña != NULL)
                                        {  
                                            strcpy(buffer, "+OK. Usuario correcto\n");
                                            send(new_sd, buffer, sizeof(buffer), 0);
                                            inicioSesion = 1;
                                        }
                                        else
                                        {
                                            strcpy(buffer, "-Err. Usuario incorrecto\n");
                                            send(new_sd, buffer, sizeof(buffer), 0);
                                        }
                                    }
                                }

                                if(strstr(buffer,"PASSWORD") != NULL)
                                {
                                    if(inicioSesion == 0)
                                    {
                                        strcpy(buffer, "-Err. Introduce usuario antes\n");
                                        send(new_sd, buffer, sizeof(buffer), 0); 
                                    }
                                    else
                                    {
                                        printf("user2: %s\n", user);
                                        char* password = strtok(buffer, " ");
                                        password = strtok(NULL, " ");
                                        printf("%s\n",user);
                                        char *pass = buscarUsuario(user);
                                        printf("passwd antigua: %sb\n", pass);
                                        printf("passwd nueva: %sb\n", password);

                                        size_t len = strlen(password);
                                        if (password[len - 1] == '\n') {password[len - 1] = '\0';}                                    

                                        if((strcmp(pass, password)) == 0)
                                        {
                                            inicioSesion = 2;

                                            struct Cliente cliente;
                                            strcpy(cliente.usuario, user);
                                            cliente.inicioSesion = 1;
                                            clientVector[ordenCliente] = cliente;

                                            strcpy(buffer, "+OK. Usuario validado\n");
                                            send(new_sd, buffer, sizeof(buffer), 0);

                                            ordenCliente++;
                                        }
                                        else
                                        {
                                            strcpy(buffer, "-Err. Error en la validación\n");
                                            send(new_sd, buffer, sizeof(buffer), 0);
                                        }

                                    }
                                }

                                if(strstr(buffer,"INICIAR-PARTIDA") != NULL)
                                {
                                    if(inicioSesion != 2)
                                    {
                                        strcpy(buffer, "-Err. Necesitas iniciar sesion antes\n");
                                        send(new_sd, buffer, sizeof(buffer), 0); 
                                    }
                                    else{
                                        for(int i = 0; i < 30; i++)
                                        {
                                            if(strcmp(clientVector[i].usuario, user) == 0)
                                            {
                                                clientVector[i].listo = 1;
                                            }
                                        }

                                        for(int i = 0; i < 30; i++)
                                        {
                                            if(clientVector[i].listo == 1)
                                            {
                                                
                                            }
                                        }
                                    }
                                }

                                if(strstr(buffer,"PEDIR-CARTA") != NULL)
                                {
                                    int disponible = 0;
                                    while(disponible == 0)
                                    {
                                        char* carta = malloc(20 * sizeof(char));
                                        int palo = rand() % 4;
                                        int numero = rand() % 13;
                                        switch(palo)
                                        {
                                            case 0:
                                                if(corazones[numero] == 0)
                                                {
                                                    corazones[numero] = 1;
                                                    disponible = 1;
                                                    sprintf(carta, "+Ok, [CORAZONES, %d]", numero + 1);
                                                    strcpy(buffer, carta);
                                                    send(new_sd, buffer, sizeof(buffer), 0);
                                                    free(carta);
                                                }
                                            break;
                                            case 1:
                                                if(diamantes[numero] == 0)
                                                {
                                                    diamantes[numero] = 1;
                                                    disponible = 1;
                                                    sprintf(carta, "+Ok, [DIAMANTES, %d]", numero + 1);
                                                    strcpy(buffer, carta);
                                                    send(new_sd, buffer, sizeof(buffer), 0);
                                                    free(carta);
                                                }
                                            break;
                                            case 2:
                                                if(treboles[numero] == 0)
                                                {
                                                    treboles[numero] = 1;
                                                    disponible = 1;
                                                    sprintf(carta, "+Ok, [TREBOLES, %d]", numero + 1);
                                                    strcpy(buffer, carta);
                                                    send(new_sd, buffer, sizeof(buffer), 0);
                                                    free(carta);
                                                }
                                            break;
                                            case 3:
                                                if(picas[numero] == 0)
                                                {
                                                    picas[numero] = 1;
                                                    disponible = 1;
                                                    sprintf(carta, "+Ok, [PICAS, %d]", numero + 1);
                                                    strcpy(buffer, carta);
                                                    send(new_sd, buffer, sizeof(buffer), 0);
                                                    free(carta);
                                                }
                                            break;
                                        }                          
                                    }

                                }

                                //if(strstr(buffer,"PLANTARME") != NULL){
                                    
                                // }
                                
                                if(strcmp(buffer, "SALIR\n") == 0)
                                {
                                    salirCliente(i, &readfds, &numClientes, arrayClientes);
                                }
                                else
                                {
                                    sprintf(identificador, "<%d>: %s", i, buffer);
                                    bzero(buffer, sizeof(buffer));

                                    strcpy(buffer,identificador);

                                    printf("%s\n", buffer);

                                    for(j=0; j<numClientes; j++)
                                    {
                                        if(arrayClientes[j] != i)
                                        {
                                            send(arrayClientes[j], buffer, sizeof(buffer), 0);
                                        }
                                    }
                                }    
                            }

                            //Si el cliente introdujo ctrl+c
                            if(recibidos== 0){
                                printf("El socket %d, ha introducido ctrl+c\n", i);
                                //Eliminar ese socket
                                salirCliente(i, &readfds, &numClientes, arrayClientes);
                            }
                        }
                    }
                }
            }
		}

	close(sd_servidor);
	return 0;
	
}

void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]){
  
    char buffer[250];
    int j;
    
    close(socket);
    FD_CLR(socket, readfds);
    
    //Re-estructurar el array de clientes
    for (j = 0; j < (*numClientes)-1; j++)
        if (arrayClientes[j] == socket)
            break;

    for (; j < (*numClientes) - 1; j++)
        (arrayClientes[j] = arrayClientes[j+1]);
    
    (*numClientes)--;
    
    bzero(buffer,sizeof(buffer));
    sprintf(buffer,"Desconexión del cliente <%d>",socket);
    
    for(j=0; j<(*numClientes); j++)
        if(arrayClientes[j] != socket)
            send(arrayClientes[j],buffer,sizeof(buffer),0);


}

void manejador (int signum){
    printf("\nSe ha recibido la señal sigint\n");
    signal(SIGINT, manejador);
    
    //Implementar lo que se desee realizar cuando ocurra la excepción de ctrl+c en el servidor
}