#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

int main(){
	int inicio,rep,proc,opc,mx,my,x,y,h,e,seg,scanSeg;
	POINT cursor;
	do{
		puts("1 comenzar 0 salir");
		scanf("%i",&inicio);
		if(inicio == 1){
			puts("Ingrese el numero de repeticiones");
			scanf("%i",&rep);
			puts("Ingrese el numero de procesos");
			scanf("%i",&proc);
			puts("inicio del programa: 1-clcik 2-right-click 3-wait 4-save");
			int arreglo[proc][3];
			for(int i=1;i<=proc;i++){
				printf("Evento: %i de %i\n",i,proc);
				opc=0;
				scanf("%i",&opc);
				
				switch(opc){
					case 1:
						GetCursorPos(&cursor);
						mx = cursor.x;
						my = cursor.y;
						arreglo[i][0] = 1;
						arreglo[i][1] = mx;
						arreglo[i][2] = my;
						printf("Click %i,%i\n",arreglo[i][1],arreglo[i][2]);
					break;
					case 2:
						GetCursorPos(&cursor);
						mx = cursor.x;
						my = cursor.y;
						arreglo[i][0] = 2;
						arreglo[i][1] = mx;
						arreglo[i][2] = my;
						printf("R-click %i,%i\n",arreglo[i][1],arreglo[i][2]);
					break;
					case 3:
						arreglo[i][0] = 3;
						puts("Cuantos milisegundos desea esperar");
						scanf("%i",&scanSeg);
						arreglo[i][1] = scanSeg;
						printf("Wait %is\n",arreglo[i][1]);
					break;
				}
			}
			//se ejecuta el programa
			do{
				puts("Ingrese 1 para ejecutar el programa 0 para salir\n");
				scanf("%i",&h);
				if(h == 1){
					puts("Inicio de ejecucion del programa:\n");
					for(int j = 0;j<rep;j++){
						printf("Repeticion: %i\n",j+1);
						for(int i = 1;i<=proc;i++){
							if(arreglo[i][0]==1){
								x=arreglo[i][1];
								y=arreglo[i][2];
								printf("Evento: %i: click en x: %i, y: %i\n",i,x,y);
								SetCursorPos(x,y);
								Sleep(250);
								INPUT Input = {0};												
							    Input.type = INPUT_MOUSE;
							    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
							    SendInput( 1, &Input, sizeof(INPUT) );
							    ZeroMemory(&Input,sizeof(INPUT));
							    Input.type        = INPUT_MOUSE;
							    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;			
							    SendInput( 1, &Input, sizeof(INPUT) );
								Sleep(250);
							}else if(arreglo[i][0]==2){
								x=arreglo[i][1];
								y=arreglo[i][2];
								printf("Evento: %i: right-click en x: %i, y: %i\n",i,x,y);
								SetCursorPos(x,y);
								Sleep(250);
								INPUT Input = {0};												
							    Input.type = INPUT_MOUSE;
							    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
							    SendInput( 1, &Input, sizeof(INPUT) );
							    ZeroMemory(&Input,sizeof(INPUT));
							    Input.type        = INPUT_MOUSE;
							    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;			
							    SendInput( 1, &Input, sizeof(INPUT) );
								Sleep(1000);
							}else if(arreglo[i][0]==3){
								seg = arreglo[i][1];
								printf("Evento: %i es un wait %i segundos\n",i,seg);
								Sleep(seg);
							}
						}
						puts("\n");
					}	
				}
			}while(h==1);
		}
	}while(inicio == 1);
		return 0;
}
