#include <stdio.h>
#include <raylib.h>

#define X 1000
#define Y 800

int main() {
    InitWindow(X, Y, "GoL");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }
}
