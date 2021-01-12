#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <stdlib.h>
#include<strings.h>
#include <windows.h>
#define d 1
void LeftClick();
void RightClick();
int main(){
	Sleep(5000);
	int g=0;
	for(g=0;g<500;g++){
		/*codigo i abajo*/
SetCursorPos(385,160);
Sleep(1000);
LeftClick();
Sleep(1000);
SetCursorPos(940,359);
Sleep(1000);
LeftClick();
Sleep(1000);
Sleep(9000);
SetCursorPos(219,223);
Sleep(1000);
LeftClick();
Sleep(1000);
Sleep(49000);
SetCursorPos(102,378);
Sleep(1000);
LeftClick();
Sleep(1000);
Sleep(9000);
SetCursorPos(887,487);
Sleep(1000);
LeftClick();
Sleep(1000);

    }
	return 0;
}
void LeftClick(){
    puts("LEFT CLICK");
    
    INPUT Input = {0};												
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    SendInput( 1, &Input, sizeof(INPUT) );
    ZeroMemory(&Input,sizeof(INPUT));
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;			
    SendInput( 1, &Input, sizeof(INPUT) );
}
void RightClick(){
    puts("right CLICK");
    INPUT Input = {0};												

    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
    SendInput( 1, &Input, sizeof(INPUT) );

    ZeroMemory(&Input,sizeof(INPUT));
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;			
    SendInput( 1, &Input, sizeof(INPUT) );
}
