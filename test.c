/*
To experiment, change TOTAL and/or THRESHOLD. 
If you change THRESHOLD, 
make sure that you initialise uint8_t x[THRESHOLD] properly.
(size should be THRESHOLD and elements should be 1...THRESHOLD)
*/

#include <stdio.h>
#include <stdlib.h>
#include "shamir_wrapper.h"
#include <string.h>
#include <time.h>
#include <assert.h>


#define TOTAL 6
#define THRESHOLD 3


int main() {
	
	srand(time(NULL));

	uint8_t secret[] = " The answer!\
to the ultimate question(?)...\
of life, \
the #1v3rse \
& everything \
is > \n\
{!@{}@!}{{{...``~~~`}.\
";
	for(int k = 0; k < 1000; k++) {
		uint8_t len = strlen(secret);
		uint8_t shares[TOTAL][len];
		
		convert_to_shares(
			len, secret,
			TOTAL,
			THRESHOLD,
			shares
		);
	
		for (int i = 0; i < TOTAL; i++) {
			for (int j = 0; j < strlen(secret); j++) {
				printf("%d ", (int)shares[i][j]);
			}
			printf("\n");
		}
		
		uint8_t x[THRESHOLD] = {3, 4, 6}; //1...THRESHOLD
		uint8_t shares_[THRESHOLD][len];
		for(int i = 0; i < THRESHOLD; i++) {
			for(int j = 0; j < len; j++)
				shares_[i][j] = shares[x[i]-1][j];
		}
	
		uint8_t recovered_secret[len+1];
		recovered_secret[len] = '\0';
		recover_secret_from_shares(
			len,
			THRESHOLD,
			shares_,
			x,
			recovered_secret
		);
		
		// printf("\n\n%s\n", recovered_secret);
		assert(!strcmp(secret, recovered_secret));
		printf("Test #%d passed\n", k);
	}
	// for (int i =0 ; i  < len; i++ ) {
	// 	printf("%d ", secret[i]);
	// }
	return 0;
}