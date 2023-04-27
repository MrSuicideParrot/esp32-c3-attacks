#include <mdk.h>

static int TRIGGER = 1;

void my_read(char * buf, int len) {
  for(int i = 0; i < len; i++) {
    do {
      buf[i] = ((char (*)( void ))0x40000074)(); // getchar()
    }while(buf[i] == 0x3F);

    if (buf[i] == '\n') {
      if (i != 0){
        buf[i] = '\0';
        return;
      } else {
        i--;
      }
    }
  }
  buf[len - 1] = '\0';
}

int main(void) {
  wdt_disable(); // Disable watchdog

  gpio_output(TRIGGER);
  gpio_write(TRIGGER, 0);
  
  char pass[32];
  char correct_pass[] = "SecretPassword";
  
  
  printf("Password: ");
  
  my_read(pass, 16);

  gpio_write(TRIGGER, 1);
  
  spin(256);
  
  int incorrect = 0;
  for(unsigned int i = 0; i < sizeof(correct_pass); i++){
      if (correct_pass[i] != pass[i]){
          incorrect = 1;
          break;
      }
  }

  
  gpio_write(TRIGGER, 0);

  if (incorrect) {
      printf("Incorrect password!\n");
      return 0;
  }   
  
  if(strcmp(correct_pass, pass) != 0){
     printf("Incorrect password!\n");
    return 0;
  }

  
  printf("Correct password!\n");
  printf("Administration console!\n");

  /*
  
  This part would have have critical fucntion that only technicians should have access.

  */

 
  return 0;
}
