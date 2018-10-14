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

		

OBJ = $(SRC:.cpp=.o)

#INC = -I ./inc/ -I ./SDL/SDL2.framework/Headers\
-I ./SDL/SDL2_image.framework/Headers\
-I ./SDL/SDL2_ttf.framework/Headers

#FRM = -F ./SDL/ -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework OpenCL

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


		

		
#		UserDisplay.cpp \
		UserModule.cpp \
			InfoDisplay.cpp \
		InfoModule.cpp \

