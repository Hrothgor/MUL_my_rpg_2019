/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void poll_event(global_t *g, sfEvent event)
{
    for (int i = 0; i < sfKeyCount; i++)
        g->event.key[i] = 0;
    g->event.mouseLup = 0;
    g->event.mouseRup = 0;
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        g->mouse = sfMouse_getPositionRenderWindow(g->window);
        for (int i = 0; i < sfKeyCount; i++) {
            g->event.key[i] = event.type == sfEvtKeyPressed \
            && event.key.code == i ? 1 : g->event.key[i];
        }
        g->event.mouseLdown = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
        g->event.mouseLup = event.type == sfEvtMouseButtonReleased \
        && event.mouseButton.button == sfMouseLeft ? 1 : 0;
        g->event.mouseRdown = sfMouse_isButtonPressed(sfMouseRight) ? 1 : 0;
        g->event.mouseRup = event.type == sfEvtMouseButtonReleased \
        && event.mouseButton.button == sfMouseRight ? 1 : 0;
    }
}

void description(void)
{
    write(1, "My Defender\n\n", 13);
    write(1, "USAGE:\n", 7);
    write(1, "    ./my_defender\n", 18);
    write(1, "    Launch the game.\n\n", 22);
    write(1, "HOW TO PLAY:\n", 13);
    write(1, "    Click with your mouse on the top left corner of the \
game menu to know how to play the game.\n", 96);
    write(1, "CREDITS:\n", 9);
    write(1, "    Developement : Jules MINGUET and Florian CHANSON\n", 53);
    write(1, "    All graphics : Florian CHANSON\n", 35);

}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            description();
            return (0);
        }
    }
    char *seed = malloc(sizeof(char));
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;

    srand((unsigned int) seed);
    window = sfRenderWindow_create(mode, "The RPG", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    update(window, event);
    return (0);
}
