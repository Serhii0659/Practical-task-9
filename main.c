#include <stdio.h>
#include <limits.h>
#include <conio.h>

// Сума чисел від 1 до n
int sum (int n) {
    int result = 0;
    for (; n >= 1; n--) {
        result += n;
    }
    return result;
}

int minSteps(int x, int y) {
    int current_position = x; // Поточна позиція
    int distance = y - current_position; // Відстань від поточної точки до кінця
    int step = 1;
    int total_steps = 0; // Підрахунок кроків

    printf("Starting at %d, ending at %d\n", x, y);

    while (distance >= 1) {
        total_steps++;
        current_position += step;
        distance = y - current_position;
        printf("Step %d: Move to %d\n", total_steps, current_position);
        if ((sum(step)+step) < distance) {
            step++;
        } else if ((sum(step)) > distance) {
            if (step > 1) {
            step--;
            }
        }
    }
    return total_steps;
}

int main() {
    int x, y;
    do {
    printf("Enter value for x (0 <= x < 2^31): ");
    scanf("%d", &x);
    if (x <= 0)
        printf ("x must be greater than 0\n");
    } while (x <= 0);
    do {
    printf("Enter value for y (x <= y < 2^31): ");
    scanf("%d", &y);
    if (y <= x)
        printf ("y must be greater than x (%d), and less than 2^31\n", x);
    } while (y <= x);

    printf("Minimum number of steps from %d to %d: %d\n", x, y, minSteps(x, y));

    printf ("Press any key to exit the program.");
    getch();
    return 0;
}