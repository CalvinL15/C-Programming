#include <stdio.h>
#include <stdbool.h>
#define MAX 4
 
bool light[MAX][MAX] = {0};
int min_pressed_n = MAX * MAX;
int min_pressed[MAX * MAX] = {0};
 
bool AllOff(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (light[i][j])
                return false;
    return true;
}
void Flip(int n, int r, int c)
{
    if (r - 1 >= 0)
        light[r - 1][c] = !light[r - 1][c];
    if (r + 1 < n)
        light[r + 1][c] = !light[r + 1][c];
    if (c - 1 >= 0)
        light[r][c - 1] = !light[r][c - 1];
    if (c + 1 < n)
        light[r][c + 1] = !light[r][c + 1];
    light[r][c] = !light[r][c];
    return;
}
void LightsOut(int n, int iter, int pressed[], int pressed_n)
{
    if (pressed_n >= min_pressed_n)
        return;
    if (iter == n * n) {
        if (AllOff(n) && pressed_n < min_pressed_n) {
            min_pressed_n = pressed_n;
            for (int i = 0; i < pressed_n; i++)
                min_pressed[i] = pressed[i];
        }
        return;
    }
    int r = iter / n, c = iter % n;
    Flip(n, r, c);
    pressed[pressed_n] = iter;
    LightsOut(n, iter + 1, pressed, pressed_n + 1);
    Flip(n, r, c);
    LightsOut(n, iter + 1, pressed, pressed_n);
    return;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int pos;
    while (scanf("%d", &pos) != EOF)
        light[pos / n][pos % n] = true;
 
    int pressed[MAX * MAX] = {0};
    LightsOut(n, 0, pressed, 0);
    for (int i = 0; i < min_pressed_n; i++)
        printf((i == min_pressed_n - 1 ? "%d\n" : "%d "), min_pressed[i]);
    return 0;
}
