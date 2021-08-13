#include<stdio.h>
#include<stdlib.h>

int get_1st_weekday(int year)
{
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7; /// Algorithm to find the first week day of a year
    return d;
}

int main()
{
    system("Color 3F"); /// Changes background and word colors

    int year, month, day, daysInMonth, weekDay=0, startingDay;   /// startingDay = 1st day of the year, day = to print from 1 to 28 or 29 or 30 or 31
    char ch;
    printf("\n\t\t\t\tCALENDAR(YYYY)\n\n");

  do{
    printf("\nEnter your desired year: ");
    scanf("%d",&year);

    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if((year%4 == 0 && year%100 != 0) || year%400 == 0)  // leap year statement
        {
            monthDay[1] = 29;
        }

    startingDay = get_1st_weekday(year);   /// storing function algorithm in a variable

    for(month=0; month<12; month++)        /// print month from 0 = Jan to 11 = Dec
    {
        daysInMonth = monthDay[month];   ///  monthDay[3] = 30
        printf("\n\n-----------------%s-----------------\n",months[month]); /// months[0] = Jan
        printf("\n  Sun  Mon  Tue  Wed  Thur  Fri  Sat\n");

        for(weekDay=0; weekDay<startingDay; weekDay++){ /// this will start printing space until the startingDay
            printf("     ");
        }

        for(day=1;day<=daysInMonth;day++){
            printf("%5d",day); /// %5d means it reserves 5 spaces for 1 day starting from left

            if(++weekDay > 6){  /// when week became greater than 6 its time to repeat from 0
                printf("\n");
                weekDay = 0;    /// starts from 0 = Sunday again
            }
            startingDay = weekDay; /// this will point the first week day of the year
        }
    }
    printf ("\n\nDo you want to repeat the operation Y/N: ");
    scanf (" %c", &ch);
  }while (ch == 'y' || ch == 'Y');

    return 0;
}
