INCDIR=-I../Common
LIBS=-lGLESv2 -lEGL -lm -lX11

COMMONSRC=../Common/esShader.c    \
          ../Common/esTransform.c \
          ../Common/esShapes.c    \
          ../Common/esUtil.c
COMMONHRD=esUtil.h

SRC1=Rectangle_TriangleFan.c
SRC2=Rectangle_LineLoop.c
SRC3=Rectangle_Triangles.c

default: all

all: GLES_Rectangle_TriangleFan \
     GLES_Rectangle_LineLoop \
     GLES_Rectangle_Triangles

clean:
	find . -name "GLES_*" | xargs rm -f

GLES_Rectangle_TriangleFan: ${COMMONSRC} ${COMMONHDR} ${SRC1}
	gcc ${COMMONSRC} ${SRC1} -o $@ ${INCDIR} ${LIBS}

GLES_Rectangle_LineLoop: ${COMMONSRC} ${COMMONHDR} ${SRC2}
	gcc ${COMMONSRC} ${SRC2} -o $@ ${INCDIR} ${LIBS}

GLES_Rectangle_Triangles: ${COMMONSRC} ${COMMONHDR} ${SRC3}
	gcc ${COMMONSRC} ${SRC3} -o $@ ${INCDIR} ${LIBS}
