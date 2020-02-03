Implementation of general (N shares, K threshold) [Shamir Secret Sharing Scheme](https://en.wikipedia.org/wiki/Shamir%27s_Secret_Sharing). *(Implemented over GF(2^8).)*

#To Run

    clear && gcc -c shamir_wrapper.c && gcc test.c shamir_wrapper.o && ./a.out 
