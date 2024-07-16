#include <stdio.h>
#include <raylib.h>

#define L 1000

int pos[L][2];

typedef struct {
    int x;
    int y;
    bool alive;
} Cell;

int init_grid(int dist) {
    int len = 0;
    for (int i=0; i<L; i+=dist) {
        pos[len][0] = i;
        pos[len][1] = i;
        len++;
    }
    return len;
}

void draw_grid(int dist) {
    for (int i=0; i < init_grid(dist); i++) {
        DrawLine(pos[i][0], 0, pos[i][0], L, WHITE);
        DrawLine(0, pos[i][1], L, pos[i][1], WHITE);
    }
}

void print_grid(int dist) {
    for (int i=0; i<init_grid(dist); i++) {
        printf("%d\n", pos[i][0]);
    }
}

int main() {
    InitWindow(L, L, "GoL");
    SetTargetFPS(30);

    int dist = 15;

    init_grid(dist);

    Cell c;
    c.x = pos[10][0];
    c.y = pos[10][1];
    c.alive = true;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(c.x, c.y, dist, dist, YELLOW);

        draw_grid(dist);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
