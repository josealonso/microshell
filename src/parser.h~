/*************************************************
******************* PARSER.H *********************
*************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define  DELIMITADOR (char *)" "
#define  NUM 20

#ifndef __PARSER__H
#define __PARSER__H

char **separaParametros (
          char *linea,             /* <=  cadena a procesar */
          char **ficheroEntrada,   /* =>  nombre del fichero a utilizar
                                      en la redireccion de entrada.
                                      devuelve NULL si no hay redireccion */
          char **ficheroSalida,    /* =>  nombre del fichero a utilizar
                                      en la redireccion de salida.
                                      devuelve NULL si no hay redireccion */
          int  *ejecucionSumergida /* =>  1 ON, 0 OFF */
     );

#endif
