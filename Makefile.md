```
$0 脚本本身的名字
$@ 所有参数的列表
$# 传入脚本的参数个数
$$ 脚本运行的当前进程ID号
$? 显示最后命令的退出状态，0表示没有错误，其他表示有错误

shift(shift 1) 命令每执行一次，变量的个数($#)减一（之前的$1变量被销毁,之后的$2就变成了$1），而变量值提前一位。

同理，shift n后，前n位参数都会被销

make -f xxx #指定xxx文件 -f(file)

wildcard 用来明确表示通配符

Makefile里的subst,字符串处理函数

用法是$(subst FROM,TO,TEXT),即将TEXT中的东西从FROM变为TO

MAKEFILE_LIST:列表变量, 在每次make读入一个make文件时, 都把它添加到最后一项

name被认为是一个以空格分隔是字符串，比如test abc ddd

lastword：返回name中的最后一个字符串 $(lastword test abc ddd) 返回ddd

firstword：返回name中的第一个字符串 $(firstword test abc ddd) 返回test

dirname命令去除文件名中的非目录部分，仅显示与目录有关的内容
```