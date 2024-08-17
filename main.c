#include <stdio.h>
#include <raylib.h>
#include <unistd.h>

#define L 800
#define size 15

#define l (int)(L/size)

void draw_grid() {
    for (int i=0; i < L; i+=size) {
        DrawLine(i, 0, i, L, WHITE);
        DrawLine(0, i, L, i, WHITE);
    }
}

void alloc_cells(int cells[l][l]) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            cells[i][j] = 0;
        }
    }
}

void alloc_gen(int cells[l][l], int gen[l][l]) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            cells[i][j] = gen[i][j];
        }
    }
}

int count_neighbours(int x, int y, int cells[l][l]) {
    int nei = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (cells[y + i][x + j] == 1 && (j != 0 || i != 0))
                nei++;
        }
    }

    return nei;
}

void update_cells(int x, int y, int nei, int cells[l][l], int gen[l][l]) {
    if (nei < 2 && cells[y][x] == 1)
        gen[y][x] = 0;

    if ((nei == 2 || nei == 3) && cells[y][x] == 1)
        gen[y][x] = 1;

    if (nei > 3 && cells[y][x] == 1)
        gen[y][x] = 0;

    if (nei == 3 && cells[y][x] == 0)
        gen[y][x]= 1;
}

void draw_cells(int x, int y, int cells[l][l]) {
    if (cells[y][x] == 1) // or gen
        DrawRectangle(x*size, y*size, size, size, YELLOW);
}

int main() {
    int cells[l][l];
    int next_gen[l][l];

    alloc_cells(cells);
    alloc_cells(next_gen);

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

    /* cells[19][20] = 1; */
    /* cells[20][20] = 1; */
    /* cells[21][20] = 1; */

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        sleep(1);

        for (int i=0; i<l; i++) {
            for (int j=0; j<l; j++) {
                int nei = count_neighbours(j, i, cells);

                draw_cells(j, i, cells);
                update_cells(j, i, nei, cells, next_gen);
            }
        }

        alloc_gen(cells, next_gen);

        draw_grid();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
