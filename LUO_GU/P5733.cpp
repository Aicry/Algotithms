#include <iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        if (islower(a[i]))
            a[i] = toupper(a[i]);
    }
    cout << a;
    return 0;

}
/*��Ŀ����
��Ҷ�֪��һЩ�칫������Զ�����ĸת��Ϊ��д�Ĺ��ܡ�����һ�����Ȳ����� 100 �Ҳ������ո���ַ�����Ҫ�󽫸��ַ����е�����Сд��ĸ��ɴ�д��ĸ�������

�����ʽ
��

�����ʽ
��

�����������
���� #1����
Luogu4!
��� #1����
LUOGU4!*/