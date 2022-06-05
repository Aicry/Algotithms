#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
struct Word {
    int num; ///词所属种类
    string w; ///词的属性值
};
ofstream fout("c_out.txt");
map<string, int> KEYWORDS = {
    pair<string, int>{"int", 0}, pair<string, int>{"return", 1}, pair<string, int>{"if", 2},
    pair<string, int>{"else", 3}, pair<string, int>{"while", 4}, pair<string, int>{"do", 5},
    pair<string, int>{"const", 6}, pair<string, int>{"string", 7}, pair<string, int>{"for", 8},
    pair<string, int>{"continue", 9},

    pair<string, int>{"+", 10}, pair<string, int>{"-", 11},
    pair<string, int>{"*", 12}, pair<string, int>{"/", 13},
    pair<string, int>{"=", 14},

    pair<string, int>{"&&", 15}, pair<string, int>{"||", 16}, pair<string, int>{"!=", 17},
    pair<string, int>{"<", 18}, pair<string, int>{">", 19},pair<string, int>{"<=", 20}, 
    pair<string, int>{">=", 21}, pair<string, int>{"==", 22},

    pair<string, int>{"(", 23}, pair<string, int>{")", 24}, pair<string, int>{",", 25},
    pair<string, int>{";", 26}, pair<string, int>{"{", 27},pair<string, int>{"}", 28},
    pair<string, int>{"!", 29}
};
map<string, int>::iterator it;
bool _IsLegal_ID(string c) { ///判断标识符是否合法
    if(isdigit(c[0]))
        return false;
    if(isalpha(c[0])||c[0]=='_')
        {
            for (auto i = 1; i < c.size();++i)
            {
                if(!(isalnum(c[i])||c[i]=='_'))
                    return false;
            }
        }
    return true;
}

bool _IsLegal_Num(string num) { ///判断常数是否合法
    for(int i=0; i<num.size(); i++) {
        if(!isdigit(num[i]))
            return false;
    }
    return true;
}

void SampleCodeShow(const char *FILENAME) { ///读取并显示示例程序文件
    FILE *fp;
    char ch;
    fp=fopen(FILENAME, "r");
    if(!fp) {
        printf("无法打开文件: %s !\n", FILENAME);
        exit(1);
    }
    fout<<"------------示例程序如下------------"<<endl;
    while((ch=fgetc(fp))!=EOF) {
        fout << ch;
    }
    fclose(fp);
    fout << endl;
}

void LexicalAnalysis(const char* FILENAME, vector<int>& Sym) { ///词法分析
    char ch;
    string word_temp;  ///缓存区
    int i = 0, j = 0, k = 0, flag = 0;
    FILE* fp; ///创建文件
    Word word[100];
    SampleCodeShow(FILENAME); ///示例程序展示
    fout << "------------词法分析----------------" << endl;
    fp = fopen(FILENAME, "r"); ///打开文件
    int mark = 0;

    //如果mark=1；说明有预读的字符，回退这个字符
    while (mark || (ch = fgetc(fp)) != '#') { //每次只读取一个单词，直至文件末尾
        mark = 0;
        if (isalnum(ch) || ch == '_') { ///判断字母、数字
            word_temp.push_back(ch); ///添加字母、数字序列   
            ch = fgetc(fp);
            mark = 1;
            continue;
        }
        else {
            if (word_temp != "") {
                word[i].w = word_temp; ///将字母、数字序列拷贝到结构数组中
                word_temp = ""; ///临时数组置空
                i++; ///结构数组的下标加1
            }
            if (ch == '#')break;//预读#就终止循环
            if (ch == ' ' || ch == 10 || ch == 13 || ch == '	') ///去掉空格、回车、换行和制表符
                continue;

            else {

                word_temp.push_back(ch), flag = 0;
                if (word_temp[0] == '=' || word_temp[0] == '>' || word_temp[0] == '<' || word_temp[0] == '!')
                    ch = fgetc(fp), mark = 1, flag = 1;

                if (word_temp[0] == '&')
                    ch = fgetc(fp), mark = 1, flag = 2;     //预读 mark=1；

                if (ch == '=' && flag == 1)
                    word_temp.push_back(ch), mark = 0;  //预读的可行，mark=0；

                else if (ch == '&' && flag == 2)
                    word_temp.push_back(ch), mark = 0;

                word[i].w = word_temp; ///将非字母、数字符号序列拷贝到结构数组中
                word_temp = "";
                i++;
            }

        }
    }
    ///分类别

    for (j = 0; j < i; j++) {
        it = KEYWORDS.find(word[j].w);
        if (it != KEYWORDS.end()) {
            k = it->second;
            if (k >= 0 && k <= 9)

                word[j].num = 1; ///关键字

            else if (k >= 10 && k <= 11)

                word[j].num = 2; //加法运算符

            else if (k >= 12 && k <= 13)

                word[j].num = 3; //乘法运算符

            else if (k == 14)

                word[j].num = 4; //赋值符

            else if (k >= 15 && k <= 22)

                word[j].num = 5; //关系运算符

            else if (k == 23)

                word[j].num = 23; //左小括号 

            else if (k == 24)

                word[j].num = 24; //右小括号

            else if (k >= 25 && k <= 30)

                word[j].num = 6; //其他

        }
        else if (_IsLegal_ID(word[j].w))

            word[j].num = 7; ///标识符

        else if (_IsLegal_Num(word[j].w))

            word[j].num = 8; ///常数

        else

            word[j].num = 0; ///无法识别
    }

    for (j = 0; j < i; j++) { ///格式化打印输出, 即(种类, 属性值)

        Sym.push_back(word[j].num);
        if (word[j].num == 1)
            fout << "< " << word[j].w << " , " << "关键字 >" << endl;

        else if (word[j].num == 2)
            fout << "< " << word[j].w << " , " << "加法运算符 >" << endl;

        else if (word[j].num == 3)
            fout << "< " << word[j].w << " , " << "乘法运算符 >" << endl;

        else if (word[j].num == 4)
            fout << "< " << word[j].w << " , " << "赋值运算符 >" << endl;

        else if (word[j].num == 5)
            fout << "< " << word[j].w << " , " << "关系运算符 >" << endl;

        else if (word[j].num == 23)
            fout << "< " << word[j].w << " , " << "左小括号 >" << endl;

        else if (word[j].num == 24)
            fout << "< " << word[j].w << " , " << "右小括号 >" << endl;

        else if (word[j].num == 6)
            fout << "< " << word[j].w << " , " << "其他运算符 >" << endl;

        else if (word[j].num == 7)
            fout << "< " << word[j].w << " , " << "标识符 >" << endl;

        else if (word[j].num == 8)
            fout << "< " << word[j].w << " , " << "常数 >" << endl;

        else if (word[j].num == 0)
            fout << "< " << word[j].w << " , " << "ERROR >" << endl;
    }
    fclose(fp); ///关闭文件

}
