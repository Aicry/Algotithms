#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
fstream fout("out.txt");
ifstream fin("expr.txt");

map<string, string> KEYWORDS = {
    pair<string, string>{"int", "关键字"},
    pair<string, string>{"for", "关键字"},
    pair<string, string>{"+", "加法运算符"},
    pair<string, string>{"-", "加法运算符"},
    pair<string, string>{"*", "乘法运算符"},
    pair<string, string>{"/", "乘法运算符"},
    pair<string, string>{"=", "赋值符"},
    pair<string, string>{"&&", "关系运算符"},
    pair<string, string>{"||", "关系运算符"},
    pair<string, string>{"!=", "关系运算符"},
    pair<string, string>{"<", "关系运算符"},
    pair<string, string>{">", "关系运算符"},
    pair<string, string>{"<=", "关系运算符"},
    pair<string, string>{">=", "关系运算符"},
    pair<string, string>{"==", "关系运算符"},
    pair<string, string>{"(", "左小括号"},
    pair<string, string>{")", "右小括号"},
    pair<string, string>{",", "逗号"},
    pair<string, string>{";", "分号"},
    pair<string, string>{"{", "左大括号"},
    pair<string, string>{"}", "右大括号"},
};
map<string, string>::iterator it;
vector<pair<string, string>> Sym;

bool _IsLegal_ID(string c)
{ ///判断标识符是否合法
    if (isdigit(c[0]))
        return false;
    if (isalpha(c[0]) || c[0] == '_')
    {
        for (auto i = 1; i < c.size(); ++i)
        {
            if (!(isalnum(c[i]) || c[i] == '_'))
                return false;
        }
    }
    return true;
}
bool _IsLegal_Num(string num)
{ ///判断常数是否合法
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] > '9' || num[i] < '0')
            return false;
    }
    return true;
}
void LexicalAnalysis()
{ ///词法分析
    char ch;
    string word_temp; ///缓存区
    int i = 0, j = 0, k = 0, flag = 0;
    int mark = 0;
    //如果mark=1；说明有预读的字符，回退这个字符
    while (mark || fin.get(ch))
    { //每次只读取一个单词，直至文件末尾
        mark = 0;
        if (isalnum(ch) || ch == '_')
        {                          ///判断字母、数字
            word_temp.push_back(ch); ///添加字母、数字序列
            fin.get(ch);
            mark = 1;
            continue;
        }
        else
        {
            if (word_temp != "")
            {
                it = KEYWORDS.find(word_temp);
                if (it != KEYWORDS.end())
                {
                    Sym.push_back(*it);
                }
                else if (_IsLegal_ID(word_temp))
                    Sym.push_back(pair<string, string>(word_temp, "id"));
                else if (_IsLegal_Num(word_temp))
                    Sym.push_back(pair<string, string>(word_temp, "num"));
                else
                    Sym.push_back(pair<string, string>(word_temp, "error"));
                word_temp = "";
            }
            if (ch == ' ' || ch == 10 || ch == 13 || ch == '	') ///去掉空格、回车、换行和制表符
                continue;
            if (ch == '#')break;
            else
            {

                word_temp.push_back(ch), flag = 0;
                if (word_temp[0] == '=' || word_temp[0] == '>' || word_temp[0] == '<' || word_temp[0] == '!')
                    fin.get(ch), mark = 1, flag = 1;

                if (word_temp[0] == '&')
                    fin.get(ch), mark = 1, flag = 2; //预读 mark=1；

                if (ch == '=' && flag == 1)
                    word_temp.push_back(ch), mark = 0; //预读的可行，mark=0；

                else if (ch == '&' && flag == 2)
                    word_temp.push_back(ch), mark = 0;

                it = KEYWORDS.find(word_temp);
                if (it != KEYWORDS.end())
                {
                    Sym.push_back(*it);
                }
                else
                    Sym.push_back(pair<string, string>(word_temp, "error"));
                word_temp = "";
            }
        }
    }
}


#define ADVANCE() (idx<CNT-1? ++idx : threshold=1)
int threshold = 0;
int ERROR = 0, CNT = 0;
int idx = 0;
void G(vector<pair<string, string>>& Sym);
void E(vector<pair<string, string>>& Sym);
void E1(vector<pair<string, string>>& Sym);
void T(vector<pair<string, string>>& Sym);
void T1(vector<pair<string, string>>& Sym);
void F(vector<pair<string, string>>& Sym);

void F(vector<pair<string, string>>& Sym) { //F→(E)|id|num
    if (ERROR == -1)return;
    if (Sym[idx].second == "id" || Sym[idx].second == "num") { // 当前Sym为标识符, 常数
        ADVANCE();
    }
    else if (Sym[idx].first == "(") {
        ADVANCE();
        E(Sym);
        if (Sym[idx].first == ")")ADVANCE();
        else { ERROR = -1; return; }
    }
    else {
        ERROR = -1; return;
    }
}
void E1(vector<pair<string, string>>& Sym) { //E'→+TE'|-TE'|ε
    if (ERROR == -1)return;
    if (Sym[idx].second == "加法运算符") { // 当前Sym为"+ -"
        ADVANCE();
        T(Sym); E1(Sym);
    }
    else if (Sym[idx].first != ")" && threshold != 1) { //Sym不为")"或idx超过表达式长度
        ERROR = -1; return;
    }
}
void T(vector<pair<string, string>>& Sym) { //T→FT'
    if (ERROR == -1)return;

    F(Sym);
    T1(Sym);
}
void E(vector<pair<string, string>>& Sym) { //E→TE'
    T(Sym); E1(Sym);
}
void G(vector<pair<string, string>>& Sym) {
    if (Sym[idx].second != "id") { ERROR = -1; return; }
    else {
        ADVANCE();
        if (Sym[idx].first != "=") { ERROR = -1; return; }
        else {
            ADVANCE();
            E(Sym);
        }
    }
}
void T1(vector<pair<string, string>>& Sym) { //T'→*FT'|/FT'|ε
    if (ERROR == -1)return;
    if (Sym[idx].second == "乘法运算符") { // 当前Sym为"* /"
        ADVANCE();
        F(Sym);
        T1(Sym);
    }
    else if (Sym[idx].first != ")" && Sym[idx].second != "加法运算符" && threshold != 1) {
        //Sym不为")"或"+"或"-"或idx超过表达式长度
        ERROR = -1; return;
    }

}
void SyntaxAnalysis(vector<pair<string, string>>& Sym) {
    CNT = Sym.size();
    G(Sym);
    if (ERROR == -1 || !threshold)
        cout << " wrong";
    else
        cout << "correct";
}

int main()
{
    LexicalAnalysis();
    for (int i = 0; i < Sym.size(); ++i)
    {
        cout << "<" << Sym[i].first << "," << Sym[i].second << ">" << endl;
    }
    SyntaxAnalysis(Sym);
    return 0;
}