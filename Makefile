
COMPIL = -gcc -Wall -Wextra -Werror
OBJDIR = ftptfobj
LIBFTDIR = libft

SRC = ft_printf.c ptfstr.c extract_data.c data_process_char.c \
	  data_process_nbr.c process_utils.c return_functions.c \

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
NAME = libftprintf.a

all :libft_all $(NAME)

libft_all :
	@echo "Checking Libft."
	@make -C $(LIBFTDIR)/

$(NAME) : $(OBJ) ft_printf.h
	@echo "\n\033[1;36mlibftprintf objects are just built.\033[0m"
	@cp $(LIBFTDIR)/libft.a $@
	@ar rcs $@ $(OBJ)
	@echo "\033[1;36m$@ is built !\033[0m"

$(OBJDIR)/%.o : %.c
	@$(COMPIL) -I $(LIBFTDIR)/ -c $< -o $@


.PHONY : clean fclean re

clean : libft_clean
	@rm -rf $(OBJ)
	@echo "\n\033[1;33mlibftprintf objects removed.\033[0m"

fclean : clean libft_fclean
	@rm -f $(NAME)
	@echo "\033[1;33m$(NAME) removed.\033[0m"

re : fclean all

libft_clean :
	@make clean -C $(LIBFTDIR)/

libft_fclean :
	@make fclean -C $(LIBFTDIR)/
