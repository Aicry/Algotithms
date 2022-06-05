#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
struct Word {
    int num; ///����������
    string w; ///�ʵ�����ֵ
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
bool _IsLegal_ID(string c) { ///�жϱ�ʶ���Ƿ�Ϸ�
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

bool _IsLegal_Num(string num) { ///�жϳ����Ƿ�Ϸ�
    for(int i=0; i<num.size(); i++) {
        if(!isdigit(num[i]))
            return false;
    }
    return true;
}

void SampleCodeShow(const char *FILENAME) { ///��ȡ����ʾʾ�������ļ�
    FILE *fp;
    char ch;
    fp=fopen(FILENAME, "r");
    if(!fp) {
        printf("�޷����ļ�: %s !\n", FILENAME);
        exit(1);
    }
    fout<<"------------ʾ����������------------"<<endl;
    while((ch=fgetc(fp))!=EOF) {
        fout << ch;
    }
    fclose(fp);
    fout << endl;
}

void LexicalAnalysis(const char* FILENAME, vector<int>& Sym) { ///�ʷ�����
    char ch;
    string word_temp;  ///������
    int i = 0, j = 0, k = 0, flag = 0;
    FILE* fp; ///�����ļ�
    Word word[100];
    SampleCodeShow(FILENAME); ///ʾ������չʾ
    fout << "------------�ʷ�����----------------" << endl;
    fp = fopen(FILENAME, "r"); ///���ļ�
    int mark = 0;

    //���mark=1��˵����Ԥ�����ַ�����������ַ�
    while (mark || (ch = fgetc(fp)) != '#') { //ÿ��ֻ��ȡһ�����ʣ�ֱ���ļ�ĩβ
        mark = 0;
        if (isalnum(ch) || ch == '_') { ///�ж���ĸ������
            word_temp.push_back(ch); ///�����ĸ����������   
            ch = fgetc(fp);
            mark = 1;
            continue;
        }
        else {
            if (word_temp != "") {
                word[i].w = word_temp; ///����ĸ���������п������ṹ������
                word_temp = ""; ///��ʱ�����ÿ�
                i++; ///�ṹ������±��1
            }
            if (ch == '#')break;//Ԥ��#����ֹѭ��
            if (ch == ' ' || ch == 10 || ch == 13 || ch == '	') ///ȥ���ո񡢻س������к��Ʊ��
                continue;

            else {

                word_temp.push_back(ch), flag = 0;
                if (word_temp[0] == '=' || word_temp[0] == '>' || word_temp[0] == '<' || word_temp[0] == '!')
                    ch = fgetc(fp), mark = 1, flag = 1;

                if (word_temp[0] == '&')
                    ch = fgetc(fp), mark = 1, flag = 2;     //Ԥ�� mark=1��

                if (ch == '=' && flag == 1)
                    word_temp.push_back(ch), mark = 0;  //Ԥ���Ŀ��У�mark=0��

                else if (ch == '&' && flag == 2)
                    word_temp.push_back(ch), mark = 0;

                word[i].w = word_temp; ///������ĸ�����ַ������п������ṹ������
                word_temp = "";
                i++;
            }

        }
    }
    ///�����

    for (j = 0; j < i; j++) {
        it = KEYWORDS.find(word[j].w);
        if (it != KEYWORDS.end()) {
            k = it->second;
            if (k >= 0 && k <= 9)

                word[j].num = 1; ///�ؼ���

            else if (k >= 10 && k <= 11)

                word[j].num = 2; //�ӷ������

            else if (k >= 12 && k <= 13)

                word[j].num = 3; //�˷������

            else if (k == 14)

                word[j].num = 4; //��ֵ��

            else if (k >= 15 && k <= 22)

                word[j].num = 5; //��ϵ�����

            else if (k == 23)

                word[j].num = 23; //��С���� 

            else if (k == 24)

                word[j].num = 24; //��С����

            else if (k >= 25 && k <= 30)

                word[j].num = 6; //����

        }
        else if (_IsLegal_ID(word[j].w))

            word[j].num = 7; ///��ʶ��

        else if (_IsLegal_Num(word[j].w))

            word[j].num = 8; ///����

        else

            word[j].num = 0; ///�޷�ʶ��
    }

    for (j = 0; j < i; j++) { ///��ʽ����ӡ���, ��(����, ����ֵ)

        Sym.push_back(word[j].num);
        if (word[j].num == 1)
            fout << "< " << word[j].w << " , " << "�ؼ��� >" << endl;

        else if (word[j].num == 2)
            fout << "< " << word[j].w << " , " << "�ӷ������ >" << endl;

        else if (word[j].num == 3)
            fout << "< " << word[j].w << " , " << "�˷������ >" << endl;

        else if (word[j].num == 4)
            fout << "< " << word[j].w << " , " << "��ֵ����� >" << endl;

        else if (word[j].num == 5)
            fout << "< " << word[j].w << " , " << "��ϵ����� >" << endl;

        else if (word[j].num == 23)
            fout << "< " << word[j].w << " , " << "��С���� >" << endl;

        else if (word[j].num == 24)
            fout << "< " << word[j].w << " , " << "��С���� >" << endl;

        else if (word[j].num == 6)
            fout << "< " << word[j].w << " , " << "��������� >" << endl;

        else if (word[j].num == 7)
            fout << "< " << word[j].w << " , " << "��ʶ�� >" << endl;

        else if (word[j].num == 8)
            fout << "< " << word[j].w << " , " << "���� >" << endl;

        else if (word[j].num == 0)
            fout << "< " << word[j].w << " , " << "ERROR >" << endl;
    }
    fclose(fp); ///�ر��ļ�

}
