CC=gcc
CFLAGS=-std=gnu99 -pthread
INCLUDEDIR=-I./lib/libSQL/ \
	-I./lib/ \
	-I./error/ \
	-I./lib/libLog/
SOURCES=main.c \
	lib/libSQL/dbAccess.c \
	lib/libLog/libLog.c \
	lib/getTrend.c \
	lib/getTriggers.c
OUTFILE=linCC_trend
MYSQLLIBS=`mysql_config --include --libs`

all:
	$(CC) $(SOURCES) -o $(OUTFILE) $(MYSQLLIBS) -lsnap7 $(INCLUDEDIR) $(CFLAGS)
clean:
	@rm -f $(OUTFILE)
	@echo 'cleaned!'
