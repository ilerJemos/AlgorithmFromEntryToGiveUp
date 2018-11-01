# 回显
echo

name = "qinjx"
echo ${name}

str = 'this is a string'
str2 = "hello  i know you are \" ${name}\"! \n"
#length
echo ${#name}

echo ${str:1:4}
#search
echo `expr index "$str" is`

array_name = (v0,v1,v2,v3)
array_name[0]=1
array_name[1]=2
array_name[2]=4
array_name[3]=8

echo ${array_name[@]}

#向shell 传递参数
echo "执行的文件名：$0";
echo "第一个参数为：$1";
echo "第二个参数为：$2";
echo "第三个参数为：$3";

#参数类型
# $n
# $# 传递到脚本的参数个数
# $*
# $@
# $$ 	脚本运行的当前进程ID号
# $! 后台运行的最后一个进程的ID号
# $- 显示Shell使用的当前选项，与set命令功能相同
# $? 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。

#运算
a=1
b=2
# 算术运算
`expr $a + $b`
# 关系运算
# -eq -nq -gt -lt -ge -le
[$a -eq $b]
#布尔运算
# ！ -a -o
#逻辑运算
# && ||
# = ！= -z -n str
#文本测试运算

#显示换行
  echo -e "OK!\n" # -e 开启转义
  echo "It it a test"
#重定向
  echo "It is a test" > myfile

  echo `date`

printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg  
printf "%-10s %-8s %-4.2f\n" 郭靖 男 66.1234 

#流程控制

#function
[ function ] funname [()]

{

    action;

    [return int;]

}


#使用 . 号来引用test1.sh 文件
. ./test1.sh

# 或者使用以下包含文件代码
# source ./test1.sh