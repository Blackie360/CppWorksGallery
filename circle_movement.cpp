#include "splashkit.h"

int main()
{
    open_window("Move the Circle", 800, 600);

    double circle_x = 400;
    double circle_y = 300;
    double circle_radius = 30;
    double move_speed = 5;

    while (not quit_requested())
    {
        process_events();

        // Check keyboard input and move the circle
        if (key_down(LEFT_KEY) && circle_x - move_speed >= circle_radius)
        {
            circle_x -= move_speed;
        }
        if (key_down(RIGHT_KEY) && circle_x + move_speed <= screen_width() - circle_radius)
        {
            circle_x += move_speed;
        }
        if (key_down(UP_KEY) && circle_y - move_speed >= circle_radius)
        {
            circle_y -= move_speed;
        }
        if (key_down(DOWN_KEY) && circle_y + move_speed <= screen_height() - circle_radius)
        {
            circle_y += move_speed;
        }

        // Clear the screen
        clear_screen(COLOR_WHITE);

        // Change color randomly
        color circle_color = COLOR(rand() % 256, rand() % 256, rand() % 256);
        
        // Draw the circle at the updated position with the new color
        fill_circle(circle_color, circle_x, circle_y, circle_radius);

        refresh_screen(60); // Refresh the screen at 60 frames per second
    }

    return 0;
}
