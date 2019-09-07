#include <u.h>
#include <libc.h>
#include <bio.h>

/*
	http://rosalind.info/problems/rna/

	Implementation notes:
	
	DNA is explicitly validated. 
*/

// Determine if input rune is valid rna
int
validdna(Rune r)
{
	#define NDNA 4
	const Rune dna[NDNA] = {L'A', L'C', L'G', L'T'};
	uint i;
	
	for(i = 0; i < NDNA; i++)
		if(r == dna[i])
			return 1;
	
	return 0;
}


void
main(int, char*[])
{
	Biobuf *in, *out;
	long r;
	uvlong n;
	
	in	= Bfdopen(0, OREAD);
	out	= Bfdopen(1, OWRITE);

	for(n = 0; (r = Bgetrune(in)) >= 0; n++){
		if(!validdna(r))
			sysfatal("err: rune #%ulld is invalid DNA rune", n);
		
		switch(r){
		case L'T':
			Bputrune(out, L'U');
			break;
			
		default:
			Bputrune(out, r);
		}
	}

	Bflush(out);
	
	// Clean up
	Bterm(in);
	Bterm(out);

	exits(nil);
}
