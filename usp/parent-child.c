#include <stdio.h>
#include <unistd.h>
void print_unbuffered(const char* str)
{
setbuf(stdout, NULL);
while(1)
{
char ch = *str;
if (ch == '\0') break;
printf("%c", ch); // alternatively, use putc
str++;
}
}i
nt main()
{
pid_t pid = fork();
if (pid < 0)
{
return -1;
}i
f (pid)
{
print_unbuffered("parent parent parent parent parent");
}e
lse
{
print_unbuffered("child child child child child");
}
printf("\n");
}