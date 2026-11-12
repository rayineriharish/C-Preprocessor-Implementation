
exe: comment.o inclusion.o macro.o main.o
        cc comment.o inclusion.o macro.o main.o -o exe

inclusion.o:inclusion.c
        cc -c inclusion.c
macro.o:macro.c
        cc -c macro.c
comment.o:comment.c
        cc -c comment.c
main.o:main.c
        cc -c main.c
clear:
        @echo "cleaning up..."
        @rm -r *.o

