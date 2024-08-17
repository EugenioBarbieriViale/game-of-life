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
    /* printf("-----------\n"); */
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            /* printf("(%d, %d) ---- ", j, i); */
            if (cells[y + i][x + j] == 1 && (j != 0 || i != 0))
                nei++;
        }
    }

    return nei;
}

void update_cells(int x, int y, int nei, int l, int cells[l][l]) {
    if (nei < 2 && cells[y][x] == 1)
        cells[y][x] = 0;

    else if ((nei == 2 || nei == 3) && cells[y][x] == 1)
        cells[y][x] = 1;

    else if (nei > 3 && cells[y][x] == 1)
        cells[y][x] = 0;

    else if (nei == 3 && cells[y][x] == 0)
        cells[y][x]= 1;
}

void draw_cells(int x, int y, int size, int l, int cells[l][l]) {
    if (cells[y][x] == 1)
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

    /* cells[20][20] = 1; */
    /* cells[21][21] = 1; */
    /* cells[22][21] = 1; */
    /* cells[22][20] = 1; */
    /* cells[22][19] = 1; */

    /* cells[20][20] = 1; */
    /* cells[20][21] = 1; */
    /* cells[21][20] = 1; */
    /* cells[21][21] = 1; */

    cells[19][20] = 1;
    cells[20][20] = 1;
    cells[21][20] = 1;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        sleep(1);

        for (int i=0; i<l; i++) {
            for (int j=0; j<l; j++) {
                int nei = count_neighbours(j, i, l, cells);

                draw_cells(j, i, size, l, cells);
                update_cells(j, i, nei, l, cells);
            }
        }

        draw_grid(L, size);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
