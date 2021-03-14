
#include <inc/lib.h>



void
exit(void) {
// lab 11
  close_all();
// lab 11 end
  sys_env_destroy(0);
}
