#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long long solution(unsigned long long a, unsigned long long b, unsigned long long c);

int main()
{
    long double a, b, c;
    scanf("%Lf", &a);
    scanf("%Lf", &b);
    scanf("%Lf", &c);
    unsigned long long x = solution(a, b, c);
    printf("%llu\n", x);
    return 0;
}

unsigned long long solution(unsigned long long a, unsigned long long b, unsigned long long c){
    unsigned long long total_grades = a + b + c;
    unsigned long long mark = 2*a + 3*b + 4*c;
    unsigned long long low = 0;
    unsigned long long high = 1e15;
    if (mark * 10 >= total_grades * 35)
        return 0;
    while (low <= high){
        unsigned long long mid = (low + high) / 2;
        unsigned long long new_sum = mark + 5 * mid;
        unsigned long long new_total_grades = total_grades + mid;

        if((new_sum * 10) >= (35 * new_total_grades)){ 
            high = mid - 1;
            /*printf("количество пятерок больше чем надо, уменьшаем high до %llu\n", high);*/
        }
        else if((new_sum * 10) < (35 * new_total_grades)){
            low = mid + 1;
            /*printf("количество пятерок меньше чем надо, увеличиваем low до %llu\n", low);*/
        }
    }
    return low;
} 