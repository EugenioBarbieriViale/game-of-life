#include <stdio.h>
#include <raylib.h>

#define L 1000
#define dist 15

#define len (int)(L/dist+2)

typedef struct {
    int x;
    int y;
    bool alive;
} Cell;

Cell cells[(int)(L/dist)];

void init_cells() {
    int c = 0;
    for (int i=0; i<L; i+=dist) {
        cells[c].x = i;
        cells[c].y = i;

        if (c % 2 == 0)
            cells[c].alive = true;

        c++;
    }
}

void draw_grid() {
    for (int i=0; i < len; i++) {
        DrawLine(cells[i].x, 0, cells[i].x, L, WHITE);
        DrawLine(0, cells[i].y, L, cells[i].y, WHITE);
    }
}

void live() {
    for (int y=0; y < len; y++) {
        for (int x=0; x < len; x++) {
            if (cells[x].alive)
                DrawRectangle(cells[x].x, cells[y].y, dist, dist, YELLOW);
        }
    }
}

int main() {
    InitWindow(L, L, "GoL");
    SetTargetFPS(30);

    init_cells(dist);

    int n_cells = (int)((L*L)/(dist*dist));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);


        live();
        draw_grid();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
