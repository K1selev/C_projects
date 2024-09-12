
typedef struct options {  //  объявление структуры
  int b;
  int e;
  int E;
  int n;
  int s;
  int t;
  int T;
  int v;
} opt;  //  у нас теперь есть место для запоминания значений после парсера

void parser(int argc, char *argv[], opt *options);
void reader(int argc, char *argv[], opt *options);