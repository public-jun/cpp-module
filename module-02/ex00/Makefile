NAME := ex00
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDE := ./includes
srcs := ./srcs/main.cpp \
		./srcs/Fixed.cpp
objs := $(srcs:.cpp=.o)
depends := $(srcs:%.cpp=%.d)
-include $(depends)

.PHONY: all
all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(NAME) $(objs)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.cpp=.d) -o $@ $<

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
