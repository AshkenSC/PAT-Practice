// PAT B1004

/*
��ѭ���������ѧ����Ϣ
��maxGrade maxName maxId��¼��������Ϣ�е���߷ֵķ��� ���� ѧ��
��minGrade minName minId��¼��������Ϣ�е���ͷֵķ��� ���� ѧ��
����ǰ��Ŀ��������maxGrade���������߷�����������Ϣ
����ǰ��Ŀ��������minGrade���������ͷ�����������Ϣ

ע�⣺maxGrade��ʼ��Ϊ-1��minGrade��ʼ��Ϊ101
���򣬵�����ĳЩ�������ʱ����Ϣ���޷�������¼�����磬�����˶���0�֣��������˶���100�֣�
*/

#include <iostream>
using namespace std;

int main()
{
    int num, grade;
    int maxGrade = -1, minGrade = 101;
    string maxName, maxId, minName, minId;
    string name, id;

    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> name >> id >> grade;
        if(grade > maxGrade) {
            maxGrade = grade;
            maxName = name;
            maxId = id;
        }
        if(grade < minGrade) {
            minGrade = grade;
            minName = name;
            minId = id;
        }
    }

    cout << maxName << " " << maxId << endl;
    cout << minName << " " << minId << endl;

    return 0;
}
