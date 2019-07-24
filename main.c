#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_int_from_file(char const *file) {
  FILE *fp = fopen(file, "rt");
  fseek(fp, 0, SEEK_END);
  long const n = ftell(fp);
  rewind(fp);
  char *buf = malloc(n + 1);
  fread(buf, n, 1, fp);
  int const i = strtol(buf, NULL, 10);
  free(buf);
  return i;
}

int write_int_to_file(char const *file, int val) {
  FILE *fp = fopen(file, "wt");
  if (!fp) {
    return 1;
  }
  char buf[32];
  int const n = snprintf(buf, sizeof(buf), "%i", val);
  fwrite(buf, n, 1, fp);
  fclose(fp);
  return 0;
}

int main(int argc, char const *argv[]) {
  if (argc < 4) {
    printf("usage: add <file1> <file2> <output-file>\n");
    return 1;
  }
  int const x = load_int_from_file(argv[1]);
  int const y = load_int_from_file(argv[2]);
  return write_int_to_file(argv[3], x + y);
}
