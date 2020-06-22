#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Record
{
    char name[25];
    int month, day, hour, minute;
    bool status;
} records[2000], temp;

int toll[24];   // tolls of different hours in a day

bool cmp(Record a, Record b);
void getAns (int on, int off, int& time, int& money);

int main ()
{
    // input toll
    for(int i = 0; i < 24; i++)
    {
        scanf("%d", &toll[i]);
    }

    // input number of calls
    int num;
    scanf("%d", &num);

    // input calls
    char statusTemp[10];    // temp variable storing on/off-line
    for(int i = 0; i < num; i++)
    {
        scanf("%s", records[i].name);
        scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
        scanf("%s", statusTemp);
        if(statusTemp == "on-line")
        {
            records[i].status = true;
        }
        else
        {
            records[i].status = false;
        }
    }

    sort(records, records + num, cmp);  // sort
    int on, off, next;                  // on and off are paired records, next is the next user
    on = 0;

    while(on < num)
    // in each loop, deal with all records of single user
    {
        int needPrint = 0;      // whether this user needs output
        next = on;              // find the next user from current position
        while(next < num && strcmp(records[next].name, records[on].name) == 0)
        {
            if(needPrint == 0 && records[next].status == true)
            {
                needPrint = 1;  // find on, set needPrint to 1
            }
            else if(needPrint == 1 && records[next].status == false)
            {
                needPrint = 2;  // if off is found after an on, set needPrint to 2
            }
            next++;             // increase "next" until next user
        }
        if(needPrint < 2)       // no on-off pair found
        {
            on = next;
            continue;
        }
        int allMoney = 0;       // total cost
        printf("%s %02d\n", records[on].name, records[on].month);

        while(on < next)
        // find all the on-off pairs of the user
        {
            while(on < next - 1
                  && !(records[on].status == true && records[on+1].status == false))
            // until a pair of continuous on-off pair is found
            {
                on++;
            }
            off = on + 1;   // off must be the next one of on
            if(off == next)
            // on-off pair search of current user is finished
            {
                on = next;
                break;
            }

            printf("%02d:%02d:%02d ", records[on].day, records[on].hour, records[on].minute);
            printf("%02d:%02d:%02d ", records[off].day, records[off].hour, records[off].minute);
            int time = 0;   // time
            int money = 0;  // cost of one call
            getAns(on, off, time, money);
            allMoney += money;  // total money plus cost of current call
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1;   // find next call record
        }

        printf("Total amount: $%.2f\n", allMoney / 100.0);
    }

    return 0;
}

bool cmp(Record a, Record b)
{
    int s = strcmp(a.name, b.name);
    if(s != 0)
    {
        return s < 0;
    }
    else if(a.month != b.month)
    {
        return a.month < b.month;
    }
    else if(a.day != b.day)
    {
        return a.day < b.day;
    }
    else
    {
        return a.minute < b.minute;
    }
}

void getAns (int on, int off, int& time, int& money)
{
    temp = records[on];
    while(temp.day < records[off].day
          || temp.hour < records[off].hour
          || temp.minute < records[off].minute)
    {
        time++;                     // total time of this record ++
        money += toll[temp.hour];   // fee increases by toll[temp.hour]
        temp.hour++;                // current time increases by 1min
        if(temp.minute >= 60)
        // enter next hour
        {
            temp.minute = 0;
            temp.hour++;
        }
        if(temp.hour >= 24)
        // enter next day
        {
            temp.hour = 0;
            temp.day++;
        }
    }
}


