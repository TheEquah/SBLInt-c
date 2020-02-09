// Author (Created): Roger "Equah" Hürzeler
// Date (Created): 12020.02.09 HE
// License: apache-2.0

#include "equah/sblint.h"

// [>] Stream
// [i] Buffer which simulates a stream of bytes.
char stream[100];

// [>] Stream Read
// [i] Reads a single byte from the "stream".
unsigned char stream_read() {
	static size_t pos = 0;
	unsigned char c = stream[pos];
	pos++;
	printf("0x%x; ", c);
	return c;
}

// [>] Stream Write
// [i] writes a single byte to the "stream".
void stream_write(unsigned char c) {
	static size_t pos = 0;
	stream[pos] = c;
	printf("0x%x; ", (unsigned char) c);
	pos++;
}

// [>] Main
int main() {
  
  // [i] Declare convert variables.
  int start_int = 420;
  size_t sblint_len = 10;
  int end_int;
  
  // [i] Convert integer.
	printf("\nStart integer: %i", start_int);
  printf("\nSBSInt required lengt: %li", equah_sblint__required_bytes(start_int));
	printf("\nWriting: ");
	size_t itl = equah_sblint__int_to_sbytes(start_int, &stream_write);
	printf("(Written amount: %li)\nReading: ", itl);
  size_t lti = equah_sblint__sbytes_to_int(&stream_read, &end_int);
  printf("(Read amount: %li)\nResult integer: %i\n", lti, end_int);
	
  return 0;
}
