#include <mdk.h>

static int TRIGGER = 10;

int main(void) {
  REG(0x60008108)[0] = BIT(0); // Disable brownout detector
  wdt_disable(); // disable watchdog

  gpio_output(TRIGGER);
  gpio_write(TRIGGER, 0);
  
  volatile int count = 0;
  const int MAX = 100000;
  const int factor = 7;
  int i;

  printf("Starting for\n");
  char op;
  op = ((char (*)( void ))0x40000074)(); // getchar()
  while (op != 'c')
  {
      op = ((char (*)( void ))0x40000074)(); // getchar()
  }
  
  gpio_write(TRIGGER, 1);
  for (i = 0; i < MAX; ++i) {
      count += factor;
  }
  gpio_write(TRIGGER, 0);
  if (i != MAX || count != MAX * factor) {
      printf("Glitch! %d %d %d\n", i, count , MAX);
  } else {
      printf("Normal!\n");
  }

  return 0;
}
