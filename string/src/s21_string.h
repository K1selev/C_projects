#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#define BUFF_SIZE 4096
#define S21_NULL (void*)0
typedef unsigned long s21_size_t;

typedef struct flags {
  int minus;
  int plus;
  int hash;
  int space;
  int zero;
  int width;
  int accuracy;
  int is_accuracy;
  int length;
  int specificator;
  int for_prerounding;
} flags;

// sprintf
int s21_sprintf(char* str, const char* format, ...);
const char* parse_param(const char* fstring, flags* f);
const char* get_spec(const char* fstring, flags* f);
char* get_type(char** result, flags f);
char* int_arg(char** str, flags f, va_list* args, unsigned int* count);
char* double_arg(char** str, flags f, va_list* args, unsigned int* count);
void e_arg(long double x, flags f, int accuracy, char** nu1, int og);
char* intptr_arg(char** str, va_list* args, unsigned int count);
char* uints_arg(char** str, flags f, va_list* args, unsigned int* count);
char* char_arg(char** str, flags f, va_list* args, const char** format,
               unsigned int* count);
char* work_with_arg(va_list* args, flags f, char** str, const char** format,
                    unsigned int* count);
char* string_arg(char** str, flags f, va_list* args, const char** format,
                 unsigned int* count);
char* wstring_arg(char** str, flags f, va_list* args, const char** format,
                  unsigned int* count);
char* ptr_arg(char** str, flags f, va_list* args, unsigned int* count);
char* wide_char(char** str, flags f, va_list* args, unsigned int* count);
char* itoa(int64_t value, char* result, int base);
char* uitoa(long long unsigned value, char* result, int base);
void to_upper(char* x);
size_t s21_wcslen(const wchar_t* a);
void clean_flags(flags* f);
void dtos(long double x, long double x1, char* nu, int* length);
void rounding_double(int length, int accuracy, char* nu, flags f);
void recursive_long_int(long double d_arg, int symbols, char** str);
void itoa_helper(int new_num, char** str);
void filling(char* result, flags f, int* i, int strlength);
void print_base(flags f, unsigned long x, char* result, int* i, int* accuracy);
void g_treatment(int* specificator, int* accuracy, char* nu, int* og,
                 long double x);
int value_to_str(long double x, char* nu, long double x1, int* length);
void cut_zeros(char* nu, flags f, int og);
void e_to_str(long double x, char* nu, char* nunu, flags a, int* i,
              int accuracy);
void put_sign(int minus, flags f, char* result, int i);

// small funcs
void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* restrict dest, const void* restrict src, s21_size_t n);
void* s21_memmove(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strcat(char* dest, const char* src);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strlen(const char* str);
int s21_strcmp(const char* str1, const char* str2);
char* s21_strcpy(char* dest, const char* src);
char* s21_strchr(const char* str, int c);
char* s21_strstr(const char* haystack, const char* needle);
s21_size_t s21_strspn(const char* s, const char* accept);
char* s21_strpbrk(const char* s, const char* accept);
char* s21_strtok(char* str, const char* delim);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
char* s21_strrchr(const char* str, int c);
char* s21_strerror(int errnum);
char* s21_itoa_er(long int num, char* str);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
// sharp
void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);

#ifdef __APPLE__
#define E_FLAG 0
#define ERR_MAX 107
#define STRERR_MAX 70
#define ERROR "Unknown error: "
#define ERROR_LIST                                                            \
  char errlist[107][70] = {"Undefined error: 0",                              \
                           "Operation not permitted",                         \
                           "No such file or directory",                       \
                           "No such process",                                 \
                           "Interrupted system call",                         \
                           "Input/output error",                              \
                           "Device not configured",                           \
                           "Argument list too long",                          \
                           "Exec format error",                               \
                           "Bad file descriptor",                             \
                           "No child processes",                              \
                           "Resource deadlock avoided",                       \
                           "Cannot allocate memory",                          \
                           "Permission denied",                               \
                           "Bad address",                                     \
                           "Block device required",                           \
                           "Resource busy",                                   \
                           "File exists",                                     \
                           "Cross-device link",                               \
                           "Operation not supported by device",               \
                           "Not a directory",                                 \
                           "Is a directory",                                  \
                           "Invalid argument",                                \
                           "Too many open files in system",                   \
                           "Too many open files",                             \
                           "Inappropriate ioctl for device",                  \
                           "Text file busy",                                  \
                           "File too large",                                  \
                           "No space left on device",                         \
                           "Illegal seek",                                    \
                           "Read-only file system",                           \
                           "Too many links",                                  \
                           "Broken pipe",                                     \
                           "Numerical argument out of domain",                \
                           "Result too large",                                \
                           "Resource temporarily unavailable",                \
                           "Operation now in progress",                       \
                           "Operation already in progress",                   \
                           "Socket operation on non-socket",                  \
                           "Destination address required",                    \
                           "Message too long",                                \
                           "Protocol wrong type for socket",                  \
                           "Protocol not available",                          \
                           "Protocol not supported",                          \
                           "Socket type not supported",                       \
                           "Operation not supported",                         \
                           "Protocol family not supported",                   \
                           "Address family not supported by protocol family", \
                           "Address already in use",                          \
                           "Can't assign requested address",                  \
                           "Network is down",                                 \
                           "Network is unreachable",                          \
                           "Network dropped connection on reset",             \
                           "Software caused connection abort",                \
                           "Connection reset by peer",                        \
                           "No buffer space available",                       \
                           "Socket is already connected",                     \
                           "Socket is not connected",                         \
                           "Can't send after socket shutdown",                \
                           "Too many references: can't splice",               \
                           "Operation timed out",                             \
                           "Connection refused",                              \
                           "Too many levels of symbolic links",               \
                           "File name too long",                              \
                           "Host is down",                                    \
                           "No route to host",                                \
                           "Directory not empty",                             \
                           "Too many processes",                              \
                           "Too many users",                                  \
                           "Disc quota exceeded",                             \
                           "Stale NFS file handle",                           \
                           "Too many levels of remote in path",               \
                           "RPC struct is bad",                               \
                           "RPC version wrong",                               \
                           "RPC prog. not avail",                             \
                           "Program version wrong",                           \
                           "Bad procedure for program",                       \
                           "No locks available",                              \
                           "Function not implemented",                        \
                           "Inappropriate file type or format",               \
                           "Authentication error",                            \
                           "Need authenticator",                              \
                           "Device power is off",                             \
                           "Device error",                                    \
                           "Value too large to be stored in data type",       \
                           "Bad executable (or shared library)",              \
                           "Bad CPU type in executable",                      \
                           "Shared library version mismatch",                 \
                           "Malformed Mach-o file",                           \
                           "Operation canceled",                              \
                           "Identifier removed",                              \
                           "No message of desired type",                      \
                           "Illegal byte sequence",                           \
                           "Attribute not found",                             \
                           "Bad message",                                     \
                           "EMULTIHOP (Reserved)",                            \
                           "No message available on STREAM",                  \
                           "ENOLINK (Reserved)",                              \
                           "No STREAM resources",                             \
                           "Not a STREAM",                                    \
                           "Protocol error",                                  \
                           "STREAM ioctl timeout",                            \
                           "Operation not supported on socket",               \
                           "Policy not found",                                \
                           "State not recoverable",                           \
                           "Previous owner died",                             \
                           "Interface output queue is full"}
#elif __linux__
#define E_FLAG 1
#define ERR_MAX 133
#define STRERR_MAX 70
#define ERROR "Unknown error "
#define ERROR_LIST                                         \
  char errlist[134][70] = {                                \
      "Success",                                           \
      "Operation not permitted",                           \
      "No such file or directory",                         \
      "No such process",                                   \
      "Interrupted system call",                           \
      "Input/output error",                                \
      "No such device or address",                         \
      "Argument list too long",                            \
      "Exec format error",                                 \
      "Bad file descriptor",                               \
      "No child processes",                                \
      "Resource temporarily unavailable",                  \
      "Cannot allocate memory",                            \
      "Permission denied",                                 \
      "Bad address",                                       \
      "Block device required",                             \
      "Device or resource busy",                           \
      "File exists",                                       \
      "Invalid cross-device link",                         \
      "No such device",                                    \
      "Not a directory",                                   \
      "Is a directory",                                    \
      "Invalid argument",                                  \
      "Too many open files in system",                     \
      "Too many open files",                               \
      "Inappropriate ioctl for device",                    \
      "Text file busy",                                    \
      "File too large",                                    \
      "No space left on device",                           \
      "Illegal seek",                                      \
      "Read-only file system",                             \
      "Too many links",                                    \
      "Broken pipe",                                       \
      "Numerical argument out of domain",                  \
      "Numerical result out of range",                     \
      "Resource deadlock avoided",                         \
      "File name too long",                                \
      "No locks available",                                \
      "Function not implemented",                          \
      "Directory not empty",                               \
      "Too many levels of symbolic links",                 \
      "Unknown error 41",                                  \
      "No message of desired type",                        \
      "Identifier removed",                                \
      "Channel number out of range",                       \
      "Level 2 not synchronized",                          \
      "Level 3 halted",                                    \
      "Level 3 reset",                                     \
      "Link number out of range",                          \
      "Protocol driver not attached",                      \
      "No CSI structure available",                        \
      "Level 2 halted",                                    \
      "Invalid exchange",                                  \
      "Invalid request descriptor",                        \
      "Exchange full",                                     \
      "No anode",                                          \
      "Invalid request code",                              \
      "Invalid slot",                                      \
      "Unknown error 58",                                  \
      "Bad font file format",                              \
      "Device not a stream",                               \
      "No data available",                                 \
      "Timer expired",                                     \
      "Out of streams resources",                          \
      "Machine is not on the network",                     \
      "Package not installed",                             \
      "Object is remote",                                  \
      "Link has been severed",                             \
      "Advertise error",                                   \
      "Srmount error",                                     \
      "Communication error on send",                       \
      "Protocol error",                                    \
      "Multihop attempted",                                \
      "RFS specific error",                                \
      "Bad message",                                       \
      "Value too large for defined data type",             \
      "Name not unique on network",                        \
      "File descriptor in bad state",                      \
      "Remote address changed",                            \
      "Can not access a needed shared library",            \
      "Accessing a corrupted shared library",              \
      ".lib section in a.out corrupted",                   \
      "Attempting to link in too many shared libraries",   \
      "Cannot exec a shared library directly",             \
      "Invalid or incomplete multibyte or wide character", \
      "Interrupted system call should be restarted",       \
      "Streams pipe error",                                \
      "Too many users",                                    \
      "Socket operation on non-socket",                    \
      "Destination address required",                      \
      "Message too long",                                  \
      "Protocol wrong type for socket",                    \
      "Protocol not available",                            \
      "Protocol not supported",                            \
      "Socket type not supported",                         \
      "Operation not supported",                           \
      "Protocol family not supported",                     \
      "Address family not supported by protocol",          \
      "Address already in use",                            \
      "Cannot assign requested address",                   \
      "Network is down",                                   \
      "Network is unreachable",                            \
      "Network dropped connection on reset",               \
      "Software caused connection abort",                  \
      "Connection reset by peer",                          \
      "No buffer space available",                         \
      "Transport endpoint is already connected",           \
      "Transport endpoint is not connected",               \
      "Cannot send after transport endpoint shutdown",     \
      "Too many references: cannot splice",                \
      "Connection timed out",                              \
      "Connection refused",                                \
      "Host is down",                                      \
      "No route to host",                                  \
      "Operation already in progress",                     \
      "Operation now in progress",                         \
      "Stale file handle",                                 \
      "Structure needs cleaning",                          \
      "Not a XENIX named type file",                       \
      "No XENIX semaphores available",                     \
      "Is a named type file",                              \
      "Remote I/O error",                                  \
      "Disk quota exceeded",                               \
      "No medium found",                                   \
      "Wrong medium type",                                 \
      "Operation canceled",                                \
      "Required key not available",                        \
      "Key has expired",                                   \
      "Key has been revoked",                              \
      "Key was rejected by service",                       \
      "Owner died",                                        \
      "State not recoverable",                             \
      "Operation not possible due to RF-kill",             \
      "Memory page has hardware error"}
#endif

#endif  // SRC_S21_STRING_H
