#include <stdint.h>
/***
*
method: convert_to_shares
memory to be allocated by client
size of shares_OUT must be shares_OUT[total_number_of_shares][secret_len]
shares_OUT's ith index will have shares corresponding to x = (i+1)
secret is considered to be corresponding to x = 0
*
***/
void convert_to_shares(
		uint8_t secret_len, uint8_t secret[secret_len],
		uint8_t total_number_of_shares,
		uint8_t threshold_number_of_shares,
		uint8_t shares_OUT[total_number_of_shares][secret_len]
); 
/***
*
method: recover_secret_from_shares
memory to be allocated by client
size of secret_OUT must be equal to number_of_bytes
secret is considered to be corresponding to x = 0
*
***/
void recover_secret_from_shares(
		uint8_t number_of_bytes, // visualise this as horizontal length
		uint8_t num_shares, //threshold. shares is a 2D array. visualise this as vertical height
		uint8_t shares[num_shares][number_of_bytes],
		uint8_t x_coords[num_shares],
		uint8_t secret_OUT[number_of_bytes]
);
//TODO:
// void verify_shares(shares, secret); //to verify by all nCr combinations