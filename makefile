# ----------------------------
# Makefile Options
# ----------------------------

NAME = RICKROLL
ICON = astley.png
DESCRIPTION = "Rick roll your friends even on a calculator"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
