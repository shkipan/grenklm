CXX = clang++
CXXFLAGS = -g -Wall -Werror -Wextra
NAME = ft_gkrellm

SRC = 	main.cpp \
		Display.cpp \
		Module.cpp \
		Window.cpp \
		TimeDisplay.cpp \
		TimeModule.cpp \
		NetDisplay.cpp \
		NetModule.cpp \
		UserDisplay.cpp \
		UserModule.cpp \
		InfoDisplay.cpp \
		InfoModule.cpp \
		CPUUsageDisplay.cpp \
		CPUUsageModule.cpp \
		PhysMemoryModule.cpp \
		PhysMemoryDisplay.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


