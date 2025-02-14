NAME		=	so_long
#NAME_BONUS	=	so_long_bonus

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra

LIBFT		=	./current_lib
LIBMLX		=	./MLX42

LIBS		=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HEADERS		=	-I $(current_lib)/Includes -I $(LIBMLX)/build -I Includes

SRCS		=	./src/so_long.c \
				./src/validate.c \
				./src/window_images.c \
				./src/player.c \
				./src/utils.c \
				./src/init.c \
				./src/handle_cases.c \
				./src/handle_decorations.c \
				./src/animations.c \
				./src/enemie.c \
				./src/flood_fill.c \
				./src/clear_mlx.c \
				./src/errors.c

OBJS		=	${SRCS:.c=.o}

all: libmlx libft ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o:%.c
	${CC} ${FLAGS} ${HEADERS} -o $@ -c $<

# bonus: libft ${NAME_BONUS}

#${NAME_BONUS}: ${OBJS_BONUS}
#	$(CC) $(OBJS_BONUS) $(LIB) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf ${OBJS}
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf ${NAME} ${NAME_BONUS}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft bonus