NAME		=	so_long
NAME_BONUS	=	so_long_bonus

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra

LIBFT		=	./current_lib
LIBMLX		=	./MLX42

LIBS		=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HEADERS		=	-I $(current_lib)/Includes -I $(LIBMLX)/build
HEADER_BONUS=	-I $(current_lib)/Includes -I $(LIBMLX)/build

SRCS		=	./src/so_long.c \
				./src/validate.c \
				./src/window_images.c \
				./src/player.c \
				./src/utils.c \
				./src/init.c \
				./src/handle_cases.c \
				./src/handle_decorations.c \
				./src/animations.c \
				./src/flood_fill.c \
				./src/clear_mlx.c \
				./src/errors.c

SRCS_BONUS	=	./bonus/animations_bonus.c \
				./bonus/clear_mlx_bonus.c \
				./bonus/enemie_bonus.c \
				./bonus/errors_bonus.c \
				./bonus/flood_fill_bonus.c \
				./bonus/handle_cases_bonus.c \
				./bonus/handle_decorations_bonus.c \
				./bonus/init_bonus.c \
				./bonus/player_bonus.c \
				./bonus/so_long_bonus.c \
				./bonus/utils_bonus.c \
				./bonus/validate_bonus.c \
				./bonus/window_images_bonus.c

OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

all: libmlx libft ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o:%.c
	${CC} ${FLAGS} ${HEADERS} -o $@ -c $<

bonus: libmlx libft ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	$(CC) $(OBJS_BONUS) $(LIBS) $(HEADER_BONUS) -o $(NAME_BONUS)

clean:
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_BONUS}
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf ${NAME} ${NAME_BONUS}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft bonus