NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
OBJ = $(SRC:.cpp=.o)
SRC = Fixed.cpp main.cpp

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ):$(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all

debug:fclean
	$(CXX) $(CXXFLAGS) -fsanitize=address -g3 -c $(SRC)
	$(CXX) $(CXXFLAGS) $(OBJ) -fsanitize=address -g -o $(NAME)