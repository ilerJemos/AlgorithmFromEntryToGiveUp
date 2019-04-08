# Marddown 语法

## 字体
*斜体* 
**粗体**
***斜体加粗***
~~删除线~~
> 引用
>> 二级引用
>>> 三级引用

---
分割线

![显示在图片下方的文字](/Resource/img/tenYuan.jpg/ "十元里美")

---
超链接
[名称-百度](http://baidu.com "title-baidu")

## 列表

### 无序列表

- 列表内容
  - 二级列表
  - 两个空格  
  
### 有序列表

1. 列表内容
   1. 列表内容
2. 列表内容

## 表格

居左============表头|居中=============表头|居=========右表头|
:-|:-:|-:
内容|内容|内容  

## 缩进

&#8195;你好 &emsp;你好

## 代码

`hello world`  

```
    //代码块
    printf("hello world")

```
    //直接tab缩进
    cout>>hello
markdown 代码块里的html会显示内容  

## 流程图

```flow
st=>start: Start
op=>operation: My Operation
cond=>condition: Yes or No?
e=>end: End
st->op->cond
cond(yes)->e
cond(no)->op
```

## 表情

:worried:
:smile: