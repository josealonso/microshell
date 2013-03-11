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
#define  NUM 60

#ifndef __PARSER__H
#define __PARSER__H

char **separaParametros (
          char *linea,             /* <=  line to be processed          */
          char **ficheroEntrada,   /* =>  file name that will be used
                                      for the input redirection.
                                      Returns NULL if there is no redirection */
          char **ficheroSalida,    /* =>  file name that will be used
                                      for the output redirection.
                                      Returns NULL if there is no redirection */
          int  *ejecucionSumergida /* =>  background execution mode
                                      1 ON, 0 OFF */
     );

/*   DESCRIPCION:
       Devuelve la direccion a una array estatico de punteros a cadenas de
       caracteres. 
       Cada puntero apuntara a cada una de las cadenas delimitadas por espacios
       en blanco que aparezcan en el parametro linea. 
       En el array no se almacenan los simbolos de redireccion ni los nombres de
       los ficheros a emplear en las redirecciones ni el simbolo &. 
       El primer elemento del array no utilizado apunta a NULL
*/

#endif
