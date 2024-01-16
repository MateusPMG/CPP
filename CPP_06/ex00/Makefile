NAME = a.out
SRC = main.cpp ScalarConverter.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 #-fsanitize=address,undefined

all:	$(NAME)

$(NAME): $(SRC)
		 $(CC) $(CFLAGS) $(^) -o $(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

test: 	all
		./$(NAME) 0
		./$(NAME) 42
		./$(NAME) 42.0f
		./$(NAME) 42.0
		./$(NAME) nan
		./$(NAME) nanf
		./$(NAME) inf
		./$(NAME) inff
		./$(NAME) -inf
		./$(NAME) -inff
		./$(NAME) -0
		./$(NAME) -0.0
		./$(NAME) -0.0f
		./$(NAME) 0.0
		./$(NAME) 0.0f
		./$(NAME) 0.f
		./$(NAME) 33.4321d
		./$(NAME) 33.4321f
		./$(NAME) 33.4321
		./$(NAME) 21212121
		./$(NAME) 2147483647
		./$(NAME) 2147483648
		./$(NAME) 2147483648.0
		./$(NAME) 2147483648.0f


valgrind: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42.0f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nan
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nanf
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) inf
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) inff
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -inf
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -inff
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -0.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -0.0f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.0f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 33.4321d
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 33.4321f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 33.4321
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 21212121
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483647
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648.0f

re:			fclean all

.PHONY:		all clean re fclean