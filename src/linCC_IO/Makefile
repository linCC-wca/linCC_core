CC=gcc
CFLAGS=-std=gnu99 -pthread
INCLUDEDIR=-I./lib/libSQL/ \
	-I./lib/ \
	-I./error/ \
	-I./lib/threads \
	-I./lib/s7Comm/ \
	-I./lib/libLog/
SOURCES=main.c \
	lib/libSQL/dbAccess.c \
	lib/varTag.c \
	lib/s7Comm/libPLC.c \
	lib/snap7.c \
	lib/commInfo.c \
	lib/db_tagsPack.c \
	lib/PLCComm.c \
	lib/threads/threads.c \
	lib/libLog/libLog.c \
	lib/db_tagsWrite.c
OUTFILE=linCC_IO
MYSQLLIBS=`mysql_config --include --libs`

all:
	$(CC) $(SOURCES) -o $(OUTFILE) $(MYSQLLIBS) -lsnap7 $(INCLUDEDIR) $(CFLAGS)
clean:
	@rm -f $OUTFILE
	@echo 'cleaned!'
