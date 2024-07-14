#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool draw_cell(int x, int y, int cx, int cy) {
    if (x == cx && y == cy)
        return true;
    return false;
}

void display(int X, int Y, int cx, int cy) {
    for (int y=0; y<Y; y++) {
        for (int x=0; x<X; x++) {
            if (draw_cell(x, y, cx, cy))
                printf("@");
            else if ((y == 0 || y == Y-1) || (x == 0 || x == X-1))
                printf(".");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int X = 36;
    int Y = X / 3;

    int cell_x = 9;
    int cell_y = 4;

    int i = 0;
    while (i < 1000) {
        if (cell_x < X)
            cell_x++;
        else
            cell_x--;

        display(X, Y, cell_x, cell_y);

        system("clear");
        i++;
    }

    return 0;
}
