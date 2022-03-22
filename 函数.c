#include <stdio.h>
#include <stdlib.h>
//相关头文件
#include <sys/types.h>
#include <regex.h>
/*主要是三个函数，详情看txt中的内容
int regcomp (regex_t *compiled, const char *pattern, int cflags)
int regexec (regex_t *compiled, char *string, size_t nmatch, regmatch_t matchptr [], int eflags)
void regfree (regex_t *compiled)
size_t regerror (int errcode, regex_t *compiled, char *buffer, size_t length)
*/

char *emails[] = {"12345679@qq.com", "##fnsdkdfn215@163.com", "123@sina.com"};

int main(){
    int status = 0, i = 0, j;
    int flag = REG_EXTENDED;
    //获取长度
    size_t nmatch = sizeof(emails) / sizeof(emails[0]);
    regmatch_t match[nmatch];
    regex_t reg;

    //正则式,这里匹配的是邮箱
    const char *pattern = "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$";

    //编译正则表达式
    if (regcomp(&reg, pattern, flag) != 0) {
        printf("编译失败\n");
        exit(0);
    }

    
    for (j = 0; j < nmatch; j++){
        //匹配正则表达式
        status = regexec(&reg, emails[j], nmatch, match + j, 0);

        if (status == REG_NOMATCH){
            printf("it can't match\t");
            puts(emails[j]);
        } else if (status == 0){
            printf("match is right\t");
            for (i = match[j].rm_so; i < match[j].rm_eo; i++){
                putchar(emails[j][i]);
            }
            putchar('\n');
        }
    }

    //释放正则表达式
    regfree(&reg);
    return 0;
}