#ifndef _MAIN_H_
#define _MAIN_H

char *_getenv(const char *name);
char *locate(const char *name);
char *join_paths(const char sep, const char *path1, const char *path2);
int file_exists(const char *filepath);
char *_strdup(const char *str);

#endif
