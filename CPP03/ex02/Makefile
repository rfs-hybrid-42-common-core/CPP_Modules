# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 20:45:51 by maaugust          #+#    #+#              #
#    Updated: 2026/07/31 01:35:25 by maaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ PROJECT FILE NAMES ============================ #
NAME           = fragTrap

# ============================== COMPILER FLAGS ============================== #
CXX            = c++
CXXFLAGS       = -Wall -Wextra -Werror -std=c++98 -MMD -MP
RM             = rm -rf

# ================================== COLORS ================================== #
GREEN          := \033[32m
RED            := \033[31m
YELLOW         := \033[33m
CYAN           := \033[36m
RESET          := \033[0m
BOLD           := \033[1m

# =============================== SOURCE FILES =============================== #
SRC            = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

# =============================== OBJECT FILES =============================== #
OBJ            = $(SRC:.cpp=.o)
DEP            = $(OBJ:.o=.d)

# ============================ COMPILATION RULES ============================= #
%.o: %.cpp
	@printf "$(CYAN)Compiling:$(RESET) $(YELLOW)$<$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# =============================== BUILD TARGETS ============================== #
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)✔ ex02 objects built successfully.$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@printf "$(GREEN)$(BOLD)✔ Build complete → $(NAME)$(RESET)\n"

# =============================== CLEAN TARGETS ============================== #
clean:
	@$(RM) $(OBJ) $(DEP)
	@printf "$(YELLOW)• Cleaned object files.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)• Full clean complete.$(RESET)\n"

# ============================== REBUILD TARGETS ============================= #
re: fclean all

.PHONY: all clean fclean re

# =============================== DEPENDENCIES =============================== #
-include $(DEP)
