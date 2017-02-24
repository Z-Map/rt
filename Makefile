# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 05:08:22 by qloubier          #+#    #+#              #
#    Updated: 2017/02/24 15:05:47 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME		= rt
PROJECTNAME	= rt

# Vars
LIBS		= libft/libft.a mathex/libmathex.a mglw/libmglw.a
LIBFLAGS	= -lm
INCDIR		= -Iinclude
CFLAGS		= -Wall -Wextra -Werror

OPSYS		= $(shell uname -s)

ifndef CC
  CC=clang
endif

ifndef config
  config=release
endif

ifeq ($(config),debug)
  CFLAGS+=-O1 -g -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif
ifeq ($(config),release)
  CFLAGS+=-Ofast
endif

SILENT		= @
BUILDDIR	= build
SRCDIR		= src

all:
