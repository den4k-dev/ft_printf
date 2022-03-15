NAME = libftprintf.a
CC = cc
CFLAGS = -c -Wall -Werror -Wextra

SRC_FOLDER = src/
SRC_FILES = ft_printf_utils.c ft_printf.c ft_printf_parser.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))
OBJ_M = $(SRC:.c=.o)
HEADER_NAME = ft_printf.h

SRC_FOLDER_BONUS = src_bonus/
SRC_FILES_BONUS = ft_printf_utils_bonus.c ft_printf_format_settings_bonus.c ft_printf_bonus.c ft_printf_parser_bonus.c ft_printf_printer_bonus.c
SRC_BONUS = $(addprefix $(SRC_FOLDER_BONUS), $(SRC_FILES_BONUS))
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER_NAME_BONUS = ft_printf_bonus.h

LIB_NAME = libft.a
LIB_FOLDER = libft/
LIB = $(LIB_FOLDER)$(LIB_NAME)

ifdef BONUS
	OBJ = $(OBJ_BONUS)
	FOLDER = $(SRC_FOLDER_BONUS)
	HEADER = $(HEADER_NAME_BONUS)
else
	OBJ = $(OBJ_M)
	FOLDER = $(SRC_FOLDER)
	HEADER = $(HEADER_NAME)
endif

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)

$(LIB): libft_ ;

libft_:
	make -C $(LIB_FOLDER) all

$(FOLDER)%.o: $(FOLDER)%.c $(FOLDER)$(HEADER)
	$(CC) $(CFLAGS) $< -o $@

bonus:
	make BONUS=1 all

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIB_FOLDER) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_FOLDER) fclean

re: fclean all

.PHONY: all clean fclean re bonus
