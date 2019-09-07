#include <u.h>
#include <libc.h>
#include <bio.h>

/*
	http://rosalind.info/problems/dna/

	Implementation notes:
	
	This prints counts of runes out in the order they occur alphabetically.
	
	I didn't want to write a hashmap-like, which would be more correct, probably.
	
	#define'd constants in Plan9 are ints and arrays must be positive constants.
*/


// Rune is unsigned, so this works - adjust as needed
const ulong RUNEMAX = (ulong)(-1) / 100;

uvlong *counts;


void
main(int, char*[])
{
	Biobuf *in, *out;
	Rune i;
	long r;
	
	in	= Bfdopen(0, OREAD);
	out	= Bfdopen(1, OWRITE);

	// Did you know calloc(2) checks for overflows?
	counts = calloc(RUNEMAX, sizeof(uvlong));
	if(counts == nil)
		sysfatal("err: calloc failed, probably an overflow");
	
	while((r = Bgetrune(in)) >= 0)
		counts[r]++;
	
	// Print counts
	for(i = 0; i < RUNEMAX; i++)
		if(counts[i] > 0)
			Bprint(out, "%ulld ", counts[i]);
			
	Bprint(out, "\n");
	Bflush(out);
	
	// Clean up
	free(counts);
	Bterm(in);
	Bterm(out);

	exits(nil);
}
