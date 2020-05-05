##一、标题

###1.使用`#`表示标题，其中`#`必须在行首

#一号标题
##二号标题
###三号标题

###2.使用`===`或者`---`表示

一号标题
===

二号标题
---

##二、分割线

使用三个或以上的`-`或者`*`表示，且这一行只有符号，注意不要被识别为二级标题即可，例如中间或者前面可以加空格。

分割线
***

##三、斜体和粗体

使用`*`和`**`分别表示斜体和粗体，删除线使用两个`~`表示

**粗体**
*斜体*

##四、超链接和图片

链接和图片的写法类似，图片仅在超链接前多了一个`!`

[百度](http://wwww.baidu.com)
![小埋](./xiaomai.jpg)

##五、无序列表

使用`-`、`+`和`*`（符号和文字之间有空格）
表示无序列表，前后留一行空白，可嵌套，例如

+ 一层
    - 二层
    - 二层
        * 三层
            + 四层
+ 一层

##六、有序列表

使用`1.`（点号后面有个空格）表示有序列表，可嵌套。

1. 一层
    1. 二层
    2. 二层
2. 一层

##七、文字引用

使用`>`表示，可以有多个`>`，表示层级更深，例如

>第一层
>>第二层
>这样跳不出去
>>>还可以更深

>这样就跳出去了

##八、行内代码块

其实上面已经用过很多次了，即使用`表示，例如
`行内代码块`

扩展：很多字符是需要转义，使用反斜杠 \ 进行转义

##九、代码块

1. 使用四个空格缩进表示代码块
2. 一些 IDE 支持行数提示和着色，一般使用三个`表示，例如

```
int main {
    int a = 0;
    int b = 0;
    int c = a * b + 1;
    printf("%d\n", c);
    return 0;
}
```

##十、表格

直接看例子吧，第二行的`---:`表示了对齐方式，默认左对齐，还有 右对齐 和 居中

|商品|数量|单价|
|---|---:|:---:|
|苹果|10|\$1|
|电脑|1|\$1000|


##十一、流程图

主要的语法为`name=>type:describe`，其中type主要有以下几种：
1.开始和结束：`start` `end`
2.输入输出：`inputoutput`
3.操作：`operation`
4.条件：`condition`
5.子程序：`subroutine`

```flow
st=>start: Start:>http://www.baidu.com
io=>inputoutput: verification
op=>operation: Your operation
cond=>condition: Yes or No?
sub=>subroutine: Your Subroutine
e=>end

st->io->op->cond
cond(yes)->e
cond(no)->sub->io

```
[更多流程图语法](http://flowchart.js.org/)

##十二、数学公式

使用`$`表示，其中一个`$`表示在行内，两个`$`表示独占一行。

eg : $\sum_{i=1}^n a_i=0$

支持 LaTeX 编辑显示支持，访问[MathJax](https://math.meta.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference)参考更多使用方法。
[推荐一个常用的数学公式在线编译网站](https://private.codecogs.com/latex/eqneditor.php)

##十三、支持 HTML 标签

1. 例如想要段落的缩进，可以如下：

&nbsp;&nbsp;不断行的空白格&nbsp;或&#160;
&ensp;&ensp;半方大的空白&ensp;或&#8194;
&emsp;&emsp;全方大的空白&emsp;或&#8195;

2. 点我跳转的功能这里演示不了，写法如下：

    <h6 id='anchor'>我是一个锚点</h6>

    [点我跳转](#anchor)

##十四、其它

1. markdown 各个 IDE 的使用可能存在大同小异，一般可以参考各个 IDE 的介绍文档
2. 本文档介绍的内容基本适用于大部分的 IDE