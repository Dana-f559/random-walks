all:
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a main.c -o game
clean:
	rm my_app