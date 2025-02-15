
NAME = so_long

BNAME = so_long_bonus

MSC = MDR/main.c MDR/get_next_line.c MDR/get_next_line_utils.c MDR/map.c MDR/ft_printf.c MDR/ft_putchar_fd.c MDR/ft_puthex.c \
		MDR/ft_putnbr_fd.c MDR/ft_putstr_fd.c MDR/ft_putu.c MDR/control.c MDR/check_direction.c MDR/hoop.c MDR/image.c MDR/ft_strncmp.c \
		MDR/reod.c MDR/ft_allocate.c

BNS = BNS/main_bonus.c BNS/get_next_line_bonus.c BNS/get_next_line_utils_bonus.c BNS/map_bonus.c BNS/ft_printf_bonus.c BNS/ft_putchar_fd_bonus.c BNS/ft_puthex_bonus.c \
		BNS/ft_putnbr_fd_bonus.c BNS/ft_putstr_fd_bonus.c BNS/ft_putu_bonus.c BNS/control_bonus.c BNS/check_direction_bonus.c BNS/hoop_bonus.c BNS/image_bonus.c BNS/ft_strncmp_bonus.c \
		BNS/reod_bonus.c BNS/enemy_bonus.c BNS/help_fun_bonus.c BNS/ft_allocate.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(MSC:%.c=%.o)

BNS_OBJ = $(BNS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

MDR/%.o: MDR/%.c so_long.h get_next_line.h ft_printf.h mlx/mlx.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNAME)

$(BNAME): $(BNS_OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(BNS_OBJ) -o $(BNAME)

BNS/%.o: BNS/%.c BNS/so_long_bonus.h BNS/get_next_line_bonus.h BNS/ft_printf_bonus.h mlx/mlx.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(BNS_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf so_long so_long_bonus

re: fclean all
