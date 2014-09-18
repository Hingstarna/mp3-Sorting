#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(void){

  int cr8 = mkdir(" ~/home/test", S_IRWXU | S_IRWXG| S_IROTH| S_IXOTH);

  mode_t process_mask = umask(0);
  int result_code = mkdir(" ~/home/test", s_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

























// int mkdir(const char *pathname, mode_t mode);























