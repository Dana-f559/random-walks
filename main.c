#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Point {
    size_t x;
    size_t y;
} Point;

Point *random_walk(int number_of_steps){
    Point *pts = malloc(sizeof(Point) * number_of_steps);
    pts[0] = (Point) {0, 0};
    for (int i = 1; i < number_of_steps; i++){
        Point p = pts[i-1];
        int r = GetRandomValue(0,3);
        switch (r)
        {
            case 0:
                p.x += 1;
                break;
            case 1:
                p.x -= 1;
                break;
            case 2:
                p.y += 1;
                break;
            case 3:
                p.y -= 1;
                break;
            default:
                break;
        }
        pts[i] = p;
    }

    return pts;
}

int main(void){
    const int Window_Height = 800;
    const int Window_Width = 600;

    size_t n_steps = 10000;
    Point *pts = random_walk(n_steps);
    // create the window
    InitWindow(Window_Height, Window_Width, "basic window");


    size_t step_size = 5;
    while (!WindowShouldClose()){
        
        BeginDrawing();
            ClearBackground(RAYWHITE); 

            for (int i = 0; i < n_steps - 1; i++){
                Point p1 = pts[i];
                Point p2 = pts[i+1];
                DrawLine(Window_Width/2 + step_size * p1.x, 
                        Window_Height/2 + step_size * p1.y,
                        Window_Width/2 + step_size * p2.x, 
                        Window_Height/2 + step_size * p2.y, BLUE);
            }
        EndDrawing();
    }

    CloseWindow();
    free(pts);

    return 0;
}