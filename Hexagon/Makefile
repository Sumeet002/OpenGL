INCDIR=-I../Common
LIBS=-lGLESv2 -lEGL -lm -lX11

COMMONSRC=../Common/esShader.c    \
          ../Common/esTransform.c \
          ../Common/esShapes.c    \
          ../Common/esUtil.c
COMMONHRD=esUtil.h

SRC1=Hexagon_TriangleFan.c
SRC2=Hexagon_LineLoop.c
SRC3=Hexagon_Lines.c
SRC4=Hexagon_Triangles.c

default: all

all: GLES_Hexagon_TriangleFan \
     GLES_Hexagon_LineLoop \
     GLES_Hexagon_Lines \
     GLES_Hexagon_Triangles

clean:
	find . -name "GLES_*" | xargs rm -f

GLES_Hexagon_TriangleFan: ${COMMONSRC} ${COMMONHDR} ${SRC1}
	gcc ${COMMONSRC} ${SRC1} -o $@ ${INCDIR} ${LIBS}

GLES_Hexagon_LineLoop: ${COMMONSRC} ${COMMONHDR} ${SRC2}
	gcc ${COMMONSRC} ${SRC2} -o $@ ${INCDIR} ${LIBS}

GLES_Hexagon_Lines: ${COMMONSRC} ${COMMONHDR} ${SRC3}
	gcc ${COMMONSRC} ${SRC3} -o $@ ${INCDIR} ${LIBS}

GLES_Hexagon_Triangles: ${COMMONSRC} ${COMMONHDR} ${SRC4}
	gcc ${COMMONSRC} ${SRC4} -o $@ ${INCDIR} ${LIBS}
