#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>

int main() {  
    setlocale(LC_ALL, "");
    initscr();
    wchar_t wstr[] = { 9632, L'\0' };
    wchar_t astr[] = { 2588, L'\0' };
    mvaddwstr(0, 0, wstr);
    // mvaddws(1,1,astr);
    refresh();
    getch();
    endwin();
    return 0;
}