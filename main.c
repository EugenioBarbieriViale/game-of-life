#include <stdio.h>
#include <raylib.h>

#define L 1000
#define dist 15

#define len (int)(L/dist+1)

typedef struct {
    int x;
    int y;
    bool alive;
} Cell;

Cell cells[len];

void init_cells() {
    int c = 0;
    for (int i=0; i<L; i+=dist) {
        cells[c].x = i;
        cells[c].y = i;

        c++;
    }
}

void draw_grid() {
    for (int i=0; i < len; i++) {
        DrawLine(cells[i].x, 0, cells[i].x, L, WHITE);
        DrawLine(0, cells[i].y, L, cells[i].y, WHITE);
    }
}

void live(int pos_x, int pos_y) {
    for (int y=0; y < len; y++) {
        for (int x=0; x < len; x++) {

            /* if (cells[x].alive) */
            if (cells[x].x == pos_x && cells[y].y == pos_y)
                DrawRectangle(cells[x].x, cells[y].y, dist, dist, YELLOW);
        }
    }
}

int main() {
    InitWindow(L, L, "GoL");
    SetTargetFPS(30);

    init_cells(dist);

    int n_cells = (int)((L*L)/(dist*dist));

    int x = 0;
    int y = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);


        live(x, y);
        draw_grid();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
