INCDIR=-I../Common
LIBS=-lGLESv2 -lEGL -lm -lX11

COMMONSRC=../Common/esShader.c    \
          ../Common/esTransform.c \
          ../Common/esShapes.c    \
          ../Common/esUtil.c
COMMONHRD=esUtil.h

SRC1=Triangle.c
SRC2=MultiTriangles.c
SRC3=MultiTriangles_Avicci.c
SRC4=Sierpinski_Gasket.c

default: all

all: GLES_Triangle \
     GLES_MultiTriangles \
     GLES_MultiTriangles_Avicci \
     GLES_Sierpinski_Gasket \

clean:
	find . -name "GLES_*" | xargs rm -f

GLES_Triangle: ${COMMONSRC} ${COMMONHDR} ${SRC1}
	gcc ${COMMONSRC} ${SRC1} -o $@ ${INCDIR} ${LIBS}

GLES_MultiTriangles: ${COMMONSRC} ${COMMONHDR} ${SRC2}
	gcc ${COMMONSRC} ${SRC2} -o $@ ${INCDIR} ${LIBS}

GLES_MultiTriangles_Avicci: ${COMMONSRC} ${COMMONHDR} ${SRC3}
	gcc ${COMMONSRC} ${SRC3} -o $@ ${INCDIR} ${LIBS}

GLES_Sierpinski_Gasket: ${COMMONSRC} ${COMMONHDR} ${SRC4}
	gcc ${COMMONSRC} ${SRC4} -o $@ ${INCDIR} ${LIBS}
