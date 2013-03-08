/*************************************************
** PARSER.C: separa la línea en palabras
**************************************************

   DESCRIPCION:
       Devuelve la direccion a una array estatico de punteros a cadenas de
       caracteres. 
       Cada puntero apuntara a cada una de las cadenas delimitadas por espacios
       en blanco que aparezcan en el parametro linea. 
       En el array no se almacenan los simbolos de redireccion ni los nombres de
       los ficheros a emplear en las redirecciones ni el simbolo &. 
       El primer elemento del array no utilizado apunta a NULL
*/

#include "parser.h"

char **separaParametros (
          char *linea,             /* <=  cadena a procesar */
          char **ficheroEntrada,   /* =>  nombre del fichero a utilizar
                                      en la redireccion de entrada.
                                      devuelve NULL si no hay redireccion */
          char **ficheroSalida,    /* =>  nombre del fichero a utilizar
                                      en la redireccion de salida.
                                      devuelve NULL si no hay redireccion */
          int  *ejecucionSumergida /* =>  1 ON, 0 OFF */
     )

{
static char *param[255];
//char *tok;
int ntok=0;

*ficheroEntrada      = NULL;
*ficheroSalida       = NULL;
*ejecucionSumergida = 0;

if ((param[ntok] = strtok (linea, DELIMITADOR)) != NULL) {
   ntok++;
   while ((param[ntok]=strtok ((char *)NULL, DELIMITADOR)) != NULL) {
      if (strcmp (param[ntok], "&") == 0) 
         *ejecucionSumergida = 1;
      else
         if (strcmp (param[ntok], "<") == 0)
            *ficheroEntrada = strtok ((char *)NULL, DELIMITADOR);
         else
            if (strcmp (param[ntok], ">") == 0)
               *ficheroSalida = strtok ((char *)NULL, DELIMITADOR);
            else
               ntok++;
     } /* while */
  } /* if */ 
  return (param);
} /* separaParametros */
