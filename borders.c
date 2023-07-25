#include <curses.h>
#include <stdio.h>
WINDOW* create_window(int x, int y, int width, int height);
void pager(WINDOW*, char[], int);

int main(int argc, char** argv)
{
    printf("Make Sure to set your terminal on fullscreen Mode and Press Enter ;)");
    getchar();
    int margin =1;

    int MAX_ROW, MAX_COL;
    int ch;
    WINDOW* msg_win;
    WINDOW* credits_win;
    WINDOW* ascii_win;
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr,true);
    getmaxyx(stdscr,MAX_ROW, MAX_COL);

    int msg_win_startX = 0;
    int msg_win_startY = 0;
    int msg_win_width = (int)(0.40*MAX_COL);
    int msg_win_height = MAX_ROW;
    int credits_win_startX = msg_win_startX+msg_win_width+margin;
    int credits_win_startY = msg_win_startY;
    int credits_win_width = msg_win_width;
    int credits_win_height = msg_win_height/2;

    int ascii_win_startX = msg_win_startX+msg_win_width+margin;
    int ascii_win_startY = credits_win_startY+credits_win_height;
    int ascii_win_width = msg_win_width;
    int ascii_win_height = msg_win_height/2;

    refresh();
    msg_win = create_window(msg_win_startX,msg_win_startY,msg_win_width,msg_win_height);
    credits_win = create_window(credits_win_startX,credits_win_startY,credits_win_width,credits_win_height);
    ascii_win = create_window(ascii_win_startX,ascii_win_startY,ascii_win_width,ascii_win_height);
    mvwprintw(credits_win,1,1,"I am Making a notedsdasdsdasdasd here dasdsd sadsa dsa das das das das d as");
    wrefresh(credits_win);
    while(true)
    {




    }



    return 0;
}
WINDOW* create_window(int x, int y, int width, int height)
{
    WINDOW* win =  newwin(height,width,y,x);
   if(win)
   {
     box(win,0,0);
    // wborder(win,'|','|','-','-','+','+','+','+');

    wrefresh(win);
    return win;
   }
   else
   {
    printw("Cannot Create New WIndow \n");
    return NULL;
   }

}
void destroy_window(WINDOW* win)
{
    wborder(win,' ',' ',' ',' ',' ',' ',' ',' ');
    wrefresh(win);
    delwin(win);
}
void pager(WINDOW* win,char filename[], int effect)
{
    
}