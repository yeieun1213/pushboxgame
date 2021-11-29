#include <iostream>
#include <ncurses.h>                                                         
#include "startend.h"

Start::Start()
{
startx = 0;
starty = 0;
choices[0] = "Start";
choices[1] = "Exit";
n_choices = sizeof(choices) / sizeof(char *); 
}

int Start::print_start(WINDOW *win_start)
{
        int highlight = 1;
        int choice = 0;
        int key;
                                                                             
        print_menu(win_start, highlight);
        while(1)                     
        {       key = wgetch(win_start);
                switch(key)
                {       case KEY_UP: 
                                if(highlight == 1)
                                        highlight = n_choices;
                                else
                                        --highlight;  
                                break;
                        case KEY_DOWN:
                                if(highlight == n_choices)
                                        highlight = 1;
                                else
                                        ++highlight;
                                break;
                        case 10:
                                choice = highlight;
                                break;
                        default:
                                refresh();
                                break;
                }                                                                                                       
                print_menu(win_start, highlight);
                if(choice != 0)                                  
                        break;
        }                                                                                                               
 
        clrtoeol();
	endwin();
                                                                                                   
        return choice;
}                                                                                                                       
                                                                                                                        

void Start::print_menu(WINDOW *win_start, int highlight)
{                                                                                                                       
        int x, y, i;
                                                                                                                        
        x = 2;
        y = 2;
        box(win_start, 0, 0);
        for(i = 0; i < n_choices; ++i)
        {
		if(highlight == i + 1) /* High light the present choice */
                {       wattron(win_start, A_REVERSE);
                        mvwprintw(win_start, y, x, "%s", choices[i]);
                        wattroff(win_start, A_REVERSE);
                }                                                                                                       
                else
                        mvwprintw(win_start, y, x, "%s", choices[i]);
                ++y;
        }                                                                                                               
        wrefresh(win_start);
}     
    
