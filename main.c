#include <stdio.h>
#include <raylib.h>
#include <unistd.h>

#define L 800
#define size 30

#define l (int)(L/size)

void draw_grid() {
    for (int i=0; i < L; i+=size) {
        DrawLine(i, 0, i, L, WHITE);
        DrawLine(0, i, L, i, WHITE);
    }
}

void alloc_zeroes(int cells[l][l]) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            cells[i][j] = 0;
        }
    }
}

void next_generation(int cells[l][l], int gen[l][l]) {
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
    if (cells[y][x] == 1)
        DrawRectangle(x*size, y*size, size, size, YELLOW);
}

void play(int cells[l][l], int next_gen[l][l]) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            int nei = count_neighbours(j, i, cells);
            update_cells(j, i, nei, cells, next_gen);
        }
    }

    next_generation(cells, next_gen);
}

int main() {
    int cells[l][l];
    int next_gen[l][l];

    alloc_zeroes(cells);
    alloc_zeroes(next_gen);

    InitWindow(L, L, "GoL");
    SetTargetFPS(30);

    cells[10][10] = 1;
    cells[10][11] = 1;
    cells[10][12] = 1;
    cells[11][9]  = 1;
    cells[11][10] = 1;
    cells[11][11] = 1;

    int count = 0;
    bool mode = true;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        /* sleep(1); */
        WaitTime(1);

        if (IsKeyPressed(KEY_SPACE)) {
            count++;
            if (count % 2 == 1)
                mode = false;
            else
                mode = true;
        }

        if (mode)
            play(cells, next_gen);

        for (int i=0; i<l; i++) {
            for (int j=0; j<l; j++) {
                draw_cells(j, i, cells);
            }
        }

        draw_grid();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
