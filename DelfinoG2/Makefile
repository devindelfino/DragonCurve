CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2014
#CPATHS=	-L/usr/X11R6/lib -I/usr/X11R6/include # 2011
CPATHS=		-I/usr/include -L/usr/lib # 2014
CFLAGS=		$(CPATHS)$(CLIBS)

OBJECTS = dragonCurve.o DelfinoG2Main.o

#targets-----------------------------
DelfinoG2:	$(OBJECTS)
		g++ $(OBJECTS) -o DelfinoG2 $(CFLAGS)
clean:
	rm *.o

#dependencies
DelfinoG2Main.o:	dragonCurve.h
dragonCurves.o:		dragonCurve.h

