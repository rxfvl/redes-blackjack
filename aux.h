#ifndef AUX_H
#define AUX_H

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

struct Cliente
{
    char usuario[50];
    int puntuacion;
    int esperando; // 0 = esperando, 1 = jugando
    int sd;
    int posicionTurno;
    int pierde;
    int plantado;
};

struct Partida
{
    struct Cliente jugador1;
    struct Cliente jugador2;
    int turno; // 1 = jugador1, 2 = jugador2
    int numJugadores;
};

void registro(char buffer[250], int new_sd);
char* buscarUsuario(char usuario[250]);
char* generarCarta(int* corazones, int* diamantes, int* treboles, int *picas, int i, struct Partida* partidaVector, int ordenPartida);
int buscarCliente(struct Cliente *clientVector, int new_sd);
#endif