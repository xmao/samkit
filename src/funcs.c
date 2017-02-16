#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <htslib/sam.h>

void sam_ids(char *infile, int is_unique)
{
    samFile *in = sam_open(infile, "r");
    bam_hdr_t *header = sam_hdr_read(in);
    
    bam1_t *aln = bam_init1();
    char *qname = NULL;

    GHashTable * reads =  g_hash_table_new_full(
	g_str_hash, g_str_equal, NULL, NULL);
    char *copied_qname = NULL;
    
    while (sam_read1(in, header, aln) >= 0) {
	/* TODO: split qname with :, get lane and tile number */
	qname = bam_get_qname(aln);
	if (is_unique) {
	    /* printf("qname: %s\n", qname); */
	    if (!g_hash_table_contains(reads, qname)) {		
		/* Save reads for later usage */
		copied_qname = (char *) malloc(strlen(qname) * sizeof(char) + 1);
		strcpy(copied_qname, qname);
		g_hash_table_insert(reads, copied_qname, copied_qname);
		printf("copied_qname: %s\n", copied_qname);
	    }
	} else {
	    printf("%s\n", qname);
	}
	
    }

    if (is_unique) {
	/* g_hash_table_foreach(free); */
	g_hash_table_destroy(reads);
    }

    bam_destroy1(aln);
    bam_hdr_destroy(header);
    sam_close(in);
}

void sam_loc(char *infile)
{
    samFile *in = sam_open(infile, "r");
    bam_hdr_t *header = sam_hdr_read(in);
    
    bam1_t *aln = bam_init1();
    
    while (sam_read1(in, header, aln) >= 0) {
	printf("%s\n", bam_get_qname(aln));
    }

    bam_destroy1(aln);
    bam_hdr_destroy(header);
    sam_close(in);
}
