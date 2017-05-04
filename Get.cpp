#include "ccstream.h"

#include <stdio.h>

#include <conio.h>

#include "struct.h"

#include <windows.h>


void Get::str(char *s, int dim)
{
	int key = 0, i = 0;

	while (key != 13)
	{
		key = getch();

		if (i == 0)key -= 32;
		if (key == ARROW)
			key = getch();
		else if (key == 8 && i > 0)
		{
			printf("\b \b");
			s[i] = 0;
			i--;
		}
		if ((IsIncluded(key, 'A', 'Z', 0) || IsIncluded(key, 'a', 'z', 0) || IsIncluded(key, '0', '9', 0) || key == 32) && i <= dim)
		{
			printf("%c", key);
			s[i] = key;
			i++;
		}
	}
	s[i] = '\0';
}


 int Get::num(int dim) {
	char s[dim];
	int key = 0, i = 0;

	while (key != 13)
	{
		key = getch();

		if (key == ARROW)
			key = getch();
		else
			if (key == 8 && i > 0)
			{
				printf("\b \b");
				s[i] = 0;
				i--;
			}
			else
				if (IsIncluded(key, '0', '9', 0) && i <= dim)
				{
					printf("%c", key);
					s[i] = key;
					i++;
				}
	}

	s[i] = '\0';
	return atoi(s);

 }


 void  time(mtime t){
        int time [2]={0,0} ,pos=0;
        short c;
        do{
            system ("color 9f");
            printf("\rInsrire ora :");

        if (pos==0)
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 176);
			printf("%.2d",time[0]);
			SetConsoleTextAttribute(h, 15);
            printf(":%.2d",time[1]);
        }
        else
            {
             HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			 SetConsoleTextAttribute(h, 15);
             printf("%.2d:",time[0]);
			 SetConsoleTextAttribute(h, 176);
             printf("%.2d",time[1]);
            }

        c=getch();
        if (c==224)
        {
            switch(getch())
            {

                case KEY_UP :{
                    time[pos]++;
                    break;
                }
                case KEY_DOWN:{
                    time[pos]--;
                    break;
                }
                case KEY_LEFT:{
                    pos--;
                    break;
                }
                case KEY_RIGHT:{
                    pos++;
                    break;
                }
            }
        }

        if (pos==2) pos=0;
        if (pos==-1)pos=1;
        if(time[1]==60)
        {
            time[0]++;
            time[1]=0;
        }
        if(time[1]==-1)
            {
                time[0]--;
                time[1]=59;
            }
        if(time [0]==24) time[0]=0;
        if(time [0]==-1) time[0]=23;
			Sleep(100);
             }while(c!=13);

        t.h=time[0];
        t.m=time[1];

     }
