# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 05:08:22 by qloubier          #+#    #+#              #
#    Updated: 2017/05/15 19:13:08 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME			= rt
PROJECTNAME		= rt

# Project vars
RT_DEBUG		= on
ifeq ($(RT_NATIVEMKLIB),on)
	LIBSMK		= ../libft/libft.a ../mathex/libmathex.a ../mglw/libmglw.a
else
	LIBSMK		= lib/libft/libft.a lib/mathex/libmathex.a lib/mglw/libmglw.a
endif
LIBSFLAGS		= -lm
INCDIR			= -Iinclude -Ilib/mglw/lib/glload/include
SRCS			= src/main.c

ifndef CFLAGS
	CFLAGS		= -Wall -Wextra -Werror -Wpadded
endif

# Setup vars
SILENT			= @
BUILDDIR		= build
SRCDIR			= src
TARGETDIR		= .
ifndef FANCY
	FANCY		= on
endif

# Set compiler command name
ifndef CC
	CC			= clang
endif

# Set debug flag if config is in debug mode
ifndef config
	config		= release
endif
ifeq ($(config),debug)
  RT_DEBUG		= on
  CFLAGS		+= -O1 -g -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif
ifeq ($(config),release)
  CFLAGS		+= -Ofast
endif

ifeq ($(RT_DEBUG),on)
	CFLAGS		+= -DRT_DEBUG
endif

# Global vars
ROOTDIR			= $(CURDIR)
OPSYS			= $(shell uname -s)

# Intern vars
I_BD			= $(BUILDDIR)/$(config)
I_LASTCFG		= $(shell if [ -e $(BUILDDIR)/cfg ]; then cat $(BUILDDIR)/cfg; fi;)
I_PHONY			=
ifneq ($(I_LASTCFG),$(config))
  I_PHONY		=  $(TARGETDIR)/$(NAME)
endif
OBJS			= $(subst /,~,$(I_SRCS:$(SRCDIR)/%.c=%.o))
I_OBD			= $(I_BD)/$(config)
I_SRCS			= $(shell find $(SRCDIR) -name "*.c" -type f)
I_HEADERS		= $(shell find ./include -name "*.h" -type f)
I_OBJS			= $(OBJS:%=$(I_BD)/%)
I_DEP			= $(I_OBJS:%.o=%.d)
I_MKTARGET		=
I_MKLIB			= $(addprefix $(I_BD)/,$(notdir $(LIBSMK)))
I_BUILDTIME		= $(shell if [ -d $(I_BD) ]; then printf "yes"; else printf "no"; fi)
I_GITINITED		= $(shell if [ -e lib/libft/Makefile ] && [ -e lib/mathex/Makefile ] && [ -e lib/mglw/Makefile ]; then printf "yes"; else printf "no"; fi)
LIBDIRS			= $(shell for lib in $(LIBSMK); do dirname "$$lib"; done)
INCDIR			+= $(LIBDIRS:%=-I%/include) #-Imglw/include -Imglw/lib/glload/include -Imathex/include -Ilibft/include

LIBFLAGS		+= -L$(I_BD) $(addprefix -l,$(I_MKLIB:$(I_BD)/lib%.a=%))

I_CFLAGS		= $(CFLAGS) $(INCDIR) #-Weverything

ifeq ($(OPSYS),Linux)
  LIBFLAGS		+= -lrt -lm -ldl -lXrandr -lXinerama -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lXdmcp -lGL
else
  LIBFLAGS		+= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif

.PHONY: all clean fclean re libclean $(I_DEP) unicorn gitinit gitpull pull gitreinit $(I_PHONY)

all: $(TARGETDIR)/$(NAME)

gitreinit:
	git submodule deinit -f lib/libft lib/mathex lib/mglw
	$(SILENT)$(MAKE) -s gitinit

gitinit:
ifneq ($(I_GITINITED),yes)
	$(SILENT)git submodule update --init lib
	$(SILENT)echo "Submodule inited"
	$(SILENT)cd lib/libft && git checkout master && git pull origin master
	$(SILENT)cd lib/mathex && git checkout master && git pull origin master
	$(SILENT)cd lib/mglw && git checkout mglw42 && git pull origin mglw42
endif

gitpull: gitinit
	$(SILENT)printf "Libft : "
	$(SILENT)cd lib/libft && git pull
	$(SILENT)printf "Mathex : "
	$(SILENT)cd lib/mathex && git pull
	$(SILENT)printf "mGLw : "
	$(SILENT)cd lib/mglw && git pull
	$(SILENT)printf "RT : "
	$(SILENT)git pull

pull: gitpull

$(I_MKLIB):
	$(SILENT)$(MAKE) --no-print-directory -C $(dir $(filter %/$(notdir $@),$(LIBSMK))) $(I_MKTARGET)\
		TARGETDIR=$(CURDIR)/$(I_BD) BUILDDIR=$(I_BD) PROJECTPATH=$(CURDIR)\
		config=$(config) SILENT=$(SILENT)

$(I_BD):
	$(SILENT)mkdir -p $(I_BD)

include/object_factory/objects.py:

include/generated/%.h: include/object_factory/objects.py
	$(SILENT)cd include && python3 obf_test.py > /dev/null

$(I_OBJS):
ifeq ($(I_BUILDTIME),yes)
	@printf "\e[33mCompile $(notdir $@)\e[31m\e[80D"
	$(SILENT)$(CC) -MMD -MP $(I_CFLAGS) -o $@ -c $(subst ~,/,$(@:$(I_BD)/%.o=$(SRCDIR)/%.c))
	@printf "\e[80D%-79.79b \e[m[\e[32mok\e[m]\n" "\e[35m$(notdir $@)\e[m compiled !\e(B\e[m"
endif

-include $(I_DEP)

ifeq ($(I_BUILDTIME),yes)
$(TARGETDIR)/$(NAME): $(I_BD) $(I_MKLIB) $(I_OBJS)
	$(SILENT)$(CC) $(I_CFLAGS) -o $@ $(I_OBJS) $(LIBFLAGS)
	$(SILENT)printf "$(config)" > $(BUILDDIR)/cfg
	@printf "\e[80D%-79.79b \e[m[\e[32mok\e[m]\n" "\e[35m$(NAME)\e[m compiled !\e(B\e[m"
	@$(MAKE) -s unicorn
else
$(TARGETDIR)/$(NAME): $(I_BD)
	$(SILENT)$(MAKE) -s $@ I_BUILDTIME=yes SILENT=$(SILENT)
endif

norme:
ifeq ($(OPSYS),Darwin)
	@printf "\e[33mChecking 42 Norme :\e[m\e[20D"
	@norminette $(I_HEADERS) $(I_SRCS) | awk 'BEGIN { FS=":"; filename="" }\
	 	$$1 == "Norme" { filename=$$2; }\
		$$1 ~ /Error .+/ { \
			if (filename != "") {\
				print "\n\033[1;31mErrors on :\033[0;36m"filename;\
				filename=""\
			} \
			sub("Error ","",$$1);\
			if ($$2 == " C++ comment") { print "\033[0;33m"$$1"\033[32m"$$2 }\
			else { print "\033[0;33m"$$1"\033[0m"$$2 }\
		}' > tmp_norme.txt
	@if [[ -s tmp_norme.txt ]]; then cat tmp_norme.txt; else printf "\\e[1;32mNo norme error on rt sources\\e[m\\n"; fi;
	@rm tmp_norme.txt
else
	@printf "\e[33mNo Norminette here\e[m\n"
endif

unicorn:
	@printf " ______________________________________________________________\n\
|\e[48;5;235m                                 \e[91m     \\                       \e[m|\n\
|\e[48;5;235m                                 \e[31m      \\                      \e[m|\n\
|\e[48;5;235m     ____          _______       \e[92m       \\\\                     \e[m|\n\
|\e[48;5;235m   🦄|      \\      |___ ___|      \e[32m        \\\\                    \e[m|\n\
|\e[48;5;235m    |  D   |         | |         \e[93m         >\\/7                \e[m|\n\
|\e[48;5;235m    |    _/          | |         \e[33m     _.-(6'  \\               \e[m|\n\
|\e[48;5;235m    | |\\ \\           | |         \e[94m    (=___._/\` \\              \e[m|\n\
|\e[48;5;235m    | | \\ \\          | |         \e[34m         )  \\ |              \e[m|\n\
|\e[48;5;235m    | |  \\ \\         | |         \e[95m        /   / |              \e[m|\n\
|\e[48;5;235m    |_|   \\_\\        |_|         \e[35m       /    > /              \e[m|\n\
|\e[48;5;235m                                 \e[91m      j    < _\\              \e[m|\n\
|\e[48;5;235m                                 \e[31m  _.-' :      \`\`.            \e[m|\n\
|\e[48;5;235m                                 \e[95m  \\ r=._\\        \`.          \e[m|\n\
|\e[48;5;235m                                 \e[35m <\`\\\\_  \\         .\`-.        \e[m|\n\
|\e[48;5;235m                                 \e[92m  \\ r-7  \`-. ._  ' .  \`\\     \e[m|\n\
|\e[48;5;235m                                 \e[32m   \\\`,      \`-.\`7  7)   )    \e[m|\n\
|\e[48;5;235m                                 \e[94m    \\/         \\|  \\'  / \`-._ \e[m|\n\
|\e[48;5;235m                                 \e[34m               ||    .'      \e[m|\n\
|\e[48;5;235m                                 \e[91m                \\\\  (         \e[m|\n\
|\e[48;5;235m                                 \e[31m                 >\\  >       \e[m|\n\
|\e[48;5;235m                                 \e[95m             ,.-' >.'        \e[m|\n\
|\e[48;5;235m                                 \e[35m            <.'_.''          \e[m|\n\
|\e[48;5;235m                                 \e[95m              <'             \e[m|\n\
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n"

flib:
	$(SILENT)$(MAKE) -Bs $(I_MKLIB) I_MKTARGET=all

libclean:
	$(SILENT)$(MAKE) -Bs $(I_MKLIB) I_MKTARGET=fclean

clean:
	@printf "\e[31mCleaning compile files ...\e(B\e[m\n"
	$(SILENT)rm -f $(I_OBJS) $(I_DEP)

fclean: clean
	@printf "\e[31mCleaning $(NAME) ...\e(B\e[m\n"
	$(SILENT)rm -f $(TARGETDIR)/$(NAME)

re: fclean all
