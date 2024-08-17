#include <stdio.h>
#include <raylib.h>
#include <unistd.h>

void draw_grid(int L, int size) {
    for (int i=0; i < L; i+=size) {
        DrawLine(i, 0, i, L, WHITE);
        DrawLine(0, i, L, i, WHITE);
    }
}

void alloc_cells(int l, int cells[l][l]) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            cells[i][j] = 0;
        }
    }
}

int count_neighbours(int x, int y, int l, int cells[l][l]) {
    int nei = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (y+i <= l && y+i >=0 && x+j <= l && x+j >=0)
                if (cells[y + i][x + j] == 1 && j != 0 && i != 0) {
                    nei++;
                }
        }
    }

    return nei;
}

void update_cells(int x, int y, int nei, int cell) {
    if (nei < 2 && cell == 1)
        cell = 0;

    else if ((nei == 2 || nei == 3) && cell == 1)
        cell = 1;

    else if (nei > 3 && cell == 1)
        cell = 0;

    else if (nei == 3 && cell == 0)
        cell = 1;
}

void draw_cell(int x, int y, int size, int cell) {
    if (cell == 1)
        DrawRectangle(x*size, y*size, size, size, YELLOW);
}

int main() {
    const int L = 800;
    const int size = 15;

    const int l = (int)L/size;

    int cells[l][l];

    alloc_cells(l, cells);

    InitWindow(L, L, "GoL");
    SetTargetFPS(30);

    cells[20][20] = 1;
    cells[21][21] = 1;
    cells[22][21] = 1;
    cells[22][20] = 1;
    cells[22][19] = 1;

    /* cells[20][20] = 1; */
    /* cells[20][21] = 1; */
    /* cells[21][20] = 1; */
    /* cells[21][21] = 1; */

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        sleep(1);

        for (int i=0; i<l; i++) {
            for (int j=0; j<l; j++) {
                int cell = cells[i][j];
                int nei = count_neighbours(j, i, l, cells);

                draw_cell(j, i, size, cell);
                update_cells(j, i, nei, cell);
            }
        }

        draw_grid(L, size);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
