CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2014
#CPATHS=	-L/usr/X11R6/lib -I/usr/X11R6/include # 2011
CPATHS=		-I/usr/include -L/usr/lib # 2014
CFLAGS=		$(CPATHS)$(CLIBS)


helloclass:	helloclass.cpp
		g++ helloclass.cpp -o helloclass $(CFLAGS)

menu:		menu.cpp
		g++ menu.cpp -o menu $(CFLAGS)

square:		square.cpp
		g++ square.cpp -o square $(CFLAGS)

text:		text.cpp
		g++ text.cpp -o text $(CFLAGS)

wheatonMap:		wheatonMap.cpp
			g++ wheatonMap.cpp -o wheatonMap $(CFLAGS)

clean:
		rm *.o
