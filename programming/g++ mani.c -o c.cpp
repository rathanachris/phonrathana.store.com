#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main() {
    float t = 0;
    // Clear screen and hide cursor
    printf("\033[2J\033[?25l");

    while(1) {
        // Reset cursor to top and print header
        printf("\033[H\033[1;35m\n [ STEREO AUDIO WAVEFORM ]\n\n");

        for(int i = 0; i < 15; i++) {
            printf("\033[1;36m");
            
            // Calculate wave logic (using i to create a vertical spread)
            int left  = 10 + 8 * sin(t + i * 0.5) * cos(t * 1.5);
            int right = 10 + 8 * sin(t + i * 0.5) * cos(t * 1.5);

            // Print Left Channel
            printf("\033[1;32m/▊\n");
            for(int j = 0; j < 20; j++) printf(j < left ? "▊" : "•");
            
            // Divider
            printf("\033[1;32m/▊\033[1;37m ▊ \033[1;36m ▊ ");

            // Print Right Channel
            for(int j = 0; j < 20; j++) printf(j < right ? "▊" : "_");
            printf("\033[1;36m/▊\033");
        }

        printf("\n \033[1;33m> CH-1 (L): ACTIVE | CH-2 (R): ACTIVE\n");
        
        t += 0.1;       // Speed of animation
        usleep(50000);  // Delay (50ms)
    }
    return 0;
}
