#include <stdio.h>
#include <raylib.h>

#define L 1000
#define dist 15

#define len (int)(L/dist+1)
#define n_cells len*len

typedef struct {
    int x;
    int y;
    bool alive;
} Cell;

Cell cells[n_cells];

void init_cells() {
    for (int y=0; y<L; y+=dist) {
        for (int x=0; x<L; x+=dist) {
            cells[x/dist].x = x;
            cells[y/dist].y = y;
        }
    }
}

void draw_grid() {
    for (int i=0; i < len; i++) {
        DrawLine(cells[i].x, 0, cells[i].x, L, WHITE);
        DrawLine(0, cells[i].y, L, cells[i].y, WHITE);
    }
}

void draw_cell(int pos_x, int pos_y) {
    for (int y=0; y < len; y++) {
        for (int x=0; x < len; x++) {

            /* if (cells[x].alive) */
            if (cells[x].x == pos_x && cells[y].y == pos_y)
                DrawRectangle(cells[x].x, cells[y].y, dist, dist, YELLOW);
        }
    }
}

bool state(int x, int y) {
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            DrawRectangle(x + j*dist, y + i*dist, dist, dist, RED);
        }
    }
}

int main() {
    InitWindow(L, L, "GoL");
    SetTargetFPS(30);

    init_cells(dist);


    int x = 5*dist;
    int y = 5*dist;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);


        state(x, y);
        draw_cell(x, y);
        draw_grid();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
