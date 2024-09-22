all: todolist

todolist: todolist.c
	gcc todolist.c -g -o todolist

run: todolist
	./todolist
