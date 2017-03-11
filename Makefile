# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 05:08:22 by qloubier          #+#    #+#              #
#    Updated: 2017/03/11 20:09:41 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME		= rt
PROJECTNAME	= rt

# Project vars
LIBSMK		= lib/libft/libft.a lib/mathex/libmathex.a ../mglw/libmglw.a
LIBSFLAGS	= -lm
INCDIR		= -Iinclude
CFLAGS		= -Wall -Wextra -Werror #-Weverything
SRCS		= src/main.c

# Setup vars
SILENT		= @
BUILDDIR	= build
SRCDIR		= src
TARGETDIR	= .
ifndef FANCY
	FANCY	= on
endif

# Set compiler command name
ifndef CC
	CC		= clang
endif

# Set debug flag if config is in debug mode
ifndef config
	config	= release
endif
ifeq ($(config),debug)
  CFLAGS	+= -O1 -g -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif
ifeq ($(config),release)
  CFLAGS	+= -Ofast
endif

# Global vars
ROOTDIR		= $(CURDIR)
OPSYS		= $(shell uname -s)

# Intern vars
I_BD		= $(BUILDDIR)/$(config)
OBJS		= $(subst /,~,$(I_SRCS:$(SRCDIR)/%.c=%.o))
I_OBD		= $(I_BD)/$(config)
I_SRCS		= $(shell find $(SRCDIR) -name "*.c" -type f)
I_OBJS		= $(OBJS:%=$(I_BD)/%)
I_DEP		= $(I_OBJS:%.o=%.d)
I_MKTARGET	=
I_BUILDTIME	= no
LIBDIRS		= $(shell for lib in $(LIBSMK); do dirname "$$lib"; done)
INCDIR		+= $(LIBDIRS:%=-I%/include)#-Imglw/include -Imathex/include -Ilibft/include
LIBFLAGS	+= $(LIBDIRS:%=-L%) $(shell basename -as .a $(LIBSMK) | sed -e "s/lib/-l/g") -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

.PHONY: all clean fclean re libclean $(I_DEP)

all: $(TARGETDIR)/$(NAME)

$(LIBSMK):
	$(SILENT)$(MAKE) -C $(shell dirname $@) $(I_MKTARGET) BUILDDIR=$(CURDIR)/$(I_BD) PROJECTPATH=$(CURDIR) config=$(config)

$(I_BD):
	$(SILENT)mkdir -p $(I_BD)

$(TARGETDIR)/$(NAME): $(I_BD) $(LIBSMK) $(I_OBJS)
ifeq ($(I_BUILDTIME),yes)
	$(SILENT)$(CC) -MMD -MP $(CFLAGS) $(INCDIR) $(LIBFLAGS) -o $@ $(I_OBJS)
else
	$(SILENT)$(MAKE) -s I_BUILDTIME=yes SILENT=$(SILENT)
endif

$(I_OBJS):
ifeq ($(I_BUILDTIME),yes)
	@printf "\e[33mCompile $(notdir $(subst ~,/,$(@:$(I_BD)/%.o=%.c)))\e[31m\e[80D"
	$(SILENT)$(CC) -MMD -MP $(CFLAGS) $(INCDIR) -o $@ -c $(subst ~,/,$(@:$(I_BD)/%.o=$(SRCDIR)/%.c))
	@printf "\e[m[\e[32mok\e[m] \e[35m$(notdir $@)\e[m compiled !\e(B\e[m\n"
endif

-include $(I_DEP)

libclean:
	$(SILENT)$(MAKE) -Bs $(LIBSMK) I_MKTARGET=fclean

clean:
	@printf "\e[31mCleaning compile files ...\e(B\e[m\n"
	$(SILENT)rm -f $(I_OBJS) $(I_DEP)

fclean: clean
	@printf "\e[31mCleaning $(NAME) ...\e(B\e[m\n"
	$(SILENT)rm -f $(TARGETDIR)/$(NAME)

re: fclean all
