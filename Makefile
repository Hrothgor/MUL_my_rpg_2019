##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make build
##

SRC	=	*.c\
		lib/my/*.c\
		button/*.c\
		spells/*.c\
		ennemi/*.c\
		boss/*.c

NAME	=	my_rpg

ERROR = -W -Wall -Wextra

SFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-network

all:
	gcc -o $(NAME) -I./include $(SRC) $(SFML) $(ERROR) -lm -Wno-unused-value -Wno-unused-parameter -Wno-pointer-to-int-cast
clean:
	rm -f $(CRITO) $(CRITA) unit-tests

fclean:
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit-tests ./lib/my/*.c ./tests/*.c $(SRC) -lcriterion --coverage
	./unit-tests
