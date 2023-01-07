#include <curses.h>

#include "list.h"
#include "cell.h"

int main(void) {
    WINDOW *canvas, *info;
    MEVENT mort;
    int maxy, maxx, ch, maxyCanv, maxxCanv;
    Cell blankCell = {.x = -1, .y = -1};
    

    initscr();
    getmaxyx(stdscr, maxy, maxx);

    mousemask(ALL_MOUSE_EVENTS, NULL);
    curs_set(0);
    noecho();

    canvas = subwin(stdscr, maxy, maxx-(maxx/4), 0 ,0);
    info = subwin(stdscr, maxy, (maxx/4)-1, 0 ,maxx-(maxx/4));

    getmaxyx(canvas, maxyCanv, maxxCanv);
    Cell board[maxxCanv][maxyCanv];
    for (size_t i = 0; i < maxxCanv; i++)
        for (size_t j = 0; j < maxyCanv; j++)
            board[i][j] = blankCell;

    if (canvas == NULL || info == NULL) {
        addstr("Unable to create subwindow\n");
        endwin();
        return 1;
    }
    box(canvas, 0, 0);
    box(info, 0, 0);

    mvwaddstr(canvas, 1, 1, "Canvas Window");
    mvwaddstr(info, 1, 1, "Info Window");

    do {
        ch = getch();
        refresh();
        
        if (ch == KEY_MOUSE) {
            getmouse(&mort);
            mvwprintw(info, 1, 2, "%d\t%d", mort.y, mort.x);
            touchwin(info);
        } else {
            addch(ch);
        }
        
    } while (ch != '~');

    endwin();
    return 0;
}