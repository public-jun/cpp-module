NAME := ex02
CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow

INCLUDE := -I./includes
srcs := ./srcs/main.cpp \
		./srcs/ClapTrap.cpp \
		./srcs/ScavTrap.cpp \
		./srcs/FragTrap.cpp \
		./srcs/DiamondTrap.cpp
objs := $(srcs:.cpp=.o)
depends := $(srcs:%.cpp=%.d)

.PHONY: all
all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(NAME) $(objs)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.cpp=.d) -o $@ $<

-include $(depends)
.PHONY: clean
clean:
	$(RM) -rf *.dSYM
	$(RM) -rf $(objs) $(depends)

.PHONY: fclean
fclean: clean
	$(RM) -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re
