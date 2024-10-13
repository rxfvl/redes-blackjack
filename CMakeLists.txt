cmake_minimum_required(VERSION 3.0)
project(Blackjack)

add_executable(server aux.c servidorChat.c)
add_executable(cliente aux.c clienteChat.c)