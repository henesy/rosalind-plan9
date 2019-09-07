</$objtype/mkfile

TARG=#unused
OFILES=#unused

BIN = /$objtype/bin

DIRS = \
	dna \

all:V:	all-dirs

install:V:	install-dirs

clean:V:	clean-dirs

nuke:V:		nuke-dirs

installall:V:	installall-dirs

%-dirs:V:
	for(i in $DIRS) @{
		cd $i
		mk $MKFLAGS $stem
	}
