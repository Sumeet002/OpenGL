INCDIR=-I../Common
LIBS=-lGLESv2 -lEGL -lm -lX11

COMMONSRC=../Common/esShader.c    \
          ../Common/esTransform.c \
          ../Common/esShapes.c    \
          ../Common/esUtil.c
COMMONHRD=esUtil.h

SRC=TriangleStrip.c

default: all

all: GLES_TriangleStrip 


clean:
	find . -name "GLES_*" | xargs rm -f

GLES_TriangleStrip: ${COMMONSRC} ${COMMONHDR} ${SRC}
	gcc ${COMMONSRC} ${SRC} -o $@ ${INCDIR} ${LIBS}

