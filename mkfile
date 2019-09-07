</$objtype/mkfile

TARG=#unused
OFILES=#unused

BIN = /$objtype/bin/rosalind

DIRS = \
	dna \
	rna \

all:V:	all-dirs

install:V:	install-dirs

clean:V:	clean-dirs

nuke:V:		nuke-dirs

installall:V:	installall-dirs

demo:V:	demo-dirs

%-dirs:V:
	for(i in $DIRS) @{
		echo
		cd $i
		mk $MKFLAGS $stem
		echo
	}
