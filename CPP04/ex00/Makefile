# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 20:45:51 by maaugust          #+#    #+#              #
#    Updated: 2026/08/04 04:39:30 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
NAME           = polymorphicAnimal

# ============================== COMPILER FLAGS ============================== #
CXX            = c++
CXXFLAGS       = -Wall -Wextra -Werror -std=c++98 -MMD -MP
INCLUDES       = -Iinc
RM             = rm -rf

# ================================== COLORS ================================== #
GREEN          := \033[32m
RED            := \033[31m
YELLOW         := \033[33m
CYAN           := \033[36m
RESET          := \033[0m
BOLD           := \033[1m

# =============================== SOURCE FILES =============================== #
SRC_PATH       = ./src/
SRC            = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
SRC            := $(addprefix $(SRC_PATH), $(SRC))

# =============================== OBJECT FILES =============================== #
OBJ_PATH       = ./obj/
OBJ            = $(patsubst $(SRC_PATH)%.cpp, $(OBJ_PATH)%.o, $(SRC))
DEP            = $(OBJ:.o=.d)

# ============================ COMPILATION RULES ============================= #
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)✔ ex00 objects built successfully.$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@printf "$(GREEN)$(BOLD)✔ Build complete → $(NAME)$(RESET)\n"

# =============================== CLEAN TARGETS ============================== #
clean:
	@$(RM) $(OBJ_PATH)
	@printf "$(YELLOW)• Cleaned object files.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)• Full clean complete.$(RESET)\n"

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all clean fclean re

# =============================== DEPENDENCIES =============================== #
-include $(DEP)
