#include <mdk.h>
#include "sha.h"

static int TRIGGER = 1;

int my_read(char * buf, int len) {
  int i;
  for(i = 0; i < len; i++) {
    do {
      buf[i] = ((char (*)( void ))0x40000074)(); // getchar()
    }while(buf[i] == 0x3F);

    if (buf[i] == '\n') {
      if (i != 0){
        buf[i] = '\0';
        return i+1;
      } else {
        i--;
      }
    }
  }
  buf[len - 1] = '\0';

  return i+ 1;
}

int main(void) {
  wdt_disable(); // Disable watchdog

  gpio_output(TRIGGER);
  gpio_write(TRIGGER, 0);
  
  char pass[32];
  char correct_pass[] = {0xd9,0x7e,0x56,0x83,0xed,0x78,0xa,0x9f,0x13,0x4e,0xf2,0x7b,0x5a,0x66,0x17,0xa3,0x61,0xbf,0x63,0x9a,0x69,0x2a,0xe6,0x1f,0x78,0xaa,0x8a,0x72};
  printf("Password: ");
  
  int l = my_read(pass, 16);
  
  gpio_write(TRIGGER, 1);
  
  spin(256);
  
  SHA_CTX ctx;

  ets_sha_enable();
  ets_sha_init(&ctx, SHA2_256);

  char output[128];

  ets_sha_update(&ctx, (unsigned char *)pass, (unsigned int)l, 0);

  ets_sha_finish(&ctx, (unsigned char *) output);

  unsigned int i;

  for(i = 0; i< sizeof(correct_pass); i++)
  {
    if (output[i] != correct_pass[i]) {
      printf("Incorrect password!\n");
      return 0;
    }
  }
 
  gpio_write(TRIGGER, 0);

  printf("Correct password!\n");
  printf("Administration console!\n");

  /*
  
  This part would have have critical fucntion that only technicians should have access.

  */

 
  return 0;
}
