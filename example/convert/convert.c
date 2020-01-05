// Author (Created): Roger "Equah" Hürzeler
// Date (Created): 12020.01.05 HE
// License: apache-2.0

#include "equah/sblint.h"

// [>] Main
int main() {
  
  // [i] Declare convert variables.
  int start_int = 420;
  size_t sblint_len = 10;
  char sblint[sblint_len];
  int end_int;
  
  // [i] Convert integer.
  size_t req_len = equah_sblint__required_bytes(start_int);
  size_t its = equah_sblint__int_to_bytes(start_int, sblint, sblint_len);
  size_t sti = equah_sblint__bytes_to_int(sblint, sblint_len, &end_int);
  
  // [i] Print result.
  printf("\nRequired byte array size for %i: %li\n\n", start_int, req_len);
  printf("\n%i -> [", start_int);
  size_t pos = 1;
  printf("0x%x", (unsigned char) sblint[0]);
  while (sblint_len > pos) {
    printf(", 0x%x", (unsigned char) sblint[pos]);
    pos++;
  }
  printf("] -> %i\n\n", end_int);
  
  return 0;
}
