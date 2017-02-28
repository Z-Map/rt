# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 05:08:22 by qloubier          #+#    #+#              #
#    Updated: 2017/02/28 19:11:28 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME		= rt
PROJECTNAME	= rt

# Project vars
LIBSMK		= libft/libft.a mathex/libmathex.a mglw/libmglw.a
LIBSFLAGS	= -lm
INCDIR		= -Iinclude
CFLAGS		= -Wall -Wextra -Werror
SRCS		= src/main.c

# Setup vars
SILENT		= @
BUILDDIR	= build
SRCDIR		= src
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

# Intern vars
OPSYS		= $(shell uname -s)
I_SRCS		= $(shell find src -name "*.c" -type f)
I_OBJS		= $(I_SRCS:src/%.c=$(BUILDDIR)/%.o)

all: $(NAME)

src/%.c: $(BUILDDIR)/%.o
	

$(NAME): $(I_SRCS)
