# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 17:05:58 by sanan             #+#    #+#              #
#    Updated: 2023/10/05 22:25:08 by sanan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vector

SRC_FILES =\
main.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC_DIR = include/

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)
	@$(ECHO) $(PURPLE) "🐶 : $(NAME) is Ready!" $(RESET)

$(NAME) : $(OBJS)
	@$(ECHO) $(CYAN) 🐶 assembling $(GREEN) $@
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(ECHO) $(BLUE) 🐶 compiling $(GREEN) $<
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

clean :
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo $(RED) "	   🐶 cleaned object files!" $(RESET)

fclean : clean
	@rm -rf $(NAME)
	@echo $(RED) "	   🐶 cleaned archive, target files!" $(RESET)

re :
	@make fclean
	@make all

RESET	=	"\x1b[0m"
GREY	=	"\x1b[30m"
RED		=	"\x1b[31m"
GREEN	=	"\x1b[32m"
YELLOW	=	"\x1b[33m"
BLUE	=	"\x1b[34m"
PURPLE	=	"\x1b[35m"
CYAN	=	"\x1b[36m"
WHITE	=	"\x1b[37m"

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo $(YELLOW) "`expr " [ \`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`% ]" $(RESET)
endif

.PHONY : all clean fclean re