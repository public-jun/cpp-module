NAME     :=  replace
CXX      := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

srcs     := ./main.cpp

objs     := $(srcs:.cpp=.o)
-include $(depends)
depends  := $(srcs:%.cpp=%.d)

.PHONY: all
all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(objs)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -MMD -MP -MF $(<:.cpp=.d) -o $@ $<

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
