INCDIR=-I../Common
LIBS=-lGLESv2 -lEGL -lm -lX11

COMMONSRC=../Common/esShader.c    \
          ../Common/esTransform.c \
          ../Common/esShapes.c    \
          ../Common/esUtil.c
COMMONHRD=esUtil.h

SRC=TriangleFan.c

default: all

all: GLES_TriangleFan 


clean:
	find . -name "GLES_*" | xargs rm -f

GLES_TriangleFan: ${COMMONSRC} ${COMMONHDR} ${SRC}
	gcc ${COMMONSRC} ${SRC} -o $@ ${INCDIR} ${LIBS}

