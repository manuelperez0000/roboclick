#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <stdlib.h>
#include <unistd.h>
#define _WIN32_WINNT 0x0500
#include <strings.h>
#define d 1

int main(){
    int n = 1;
    int x,y,c,d,seg;
    
    printf("Intrduzca: 1 = inicio ; 0 = salir: ");
    scanf("%i", &c);
    
    if(c == 1){
    	FILE* fichero;
		fichero = fopen("robot.txt", "wt");
    	puts("1 guardar posicion\n2 left-click\n3 right-click\n4 esperar\n5 para guardar\n0 para terminar");
    	do{
    		scanf("%i", &d);
    		if(d == 1){
    			POINT cursor;
				GetCursorPos(&cursor);
				x = cursor.x;
				y = cursor.y;
				printf("posicion %i:X %i Y %i\n",n,x,y);
				n++;
	
			    fprintf(fichero, "SetCursorPos(%i,%i);\nSleep(1000);\n", x,y);
			    
			}else if(d==2){
				puts("Hizo left-click");
				fprintf(fichero, "LeftClick();\nSleep(1000);\n");
			}else if(d==3){
				fprintf(fichero, "RightClick();\nSleep(1000);\n");
			}else if(d==4){
				puts("Cuantos milisegundos desea esperar");
				scanf("%i", &seg);
				fprintf(fichero, "Sleep(%i);\n",seg);
			}else if(d==0){
				c=0;
			}
			
		}while(c != 0);
		fclose(fichero);
	}else{
		printf("Programa terminado");
		
	}
    return 0;
}
