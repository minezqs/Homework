//动态学生成绩管理

#include <stdio.h>
#include <stdlib.h>

//Student结构体
struct Student
{
    char id[20];
    char name[20];
    float Chinese;
    float Math;
    float English;
    float total;
    float average;
};

//输入板块
void inputStudent(struct Student *s,int n){
    for(int i=0;i<n;i++){
        printf("第%d个学生(学号，姓名，语文，数学，英语):",i+1);
        scanf("%19s %19s %f %f %f",
            (s+i)->id,(s+i)->name,
            &(s+i)->Chinese,
            &(s+i)->Math,
            &(s+i)->English);
    }
}

//计算总分,平均分
void Calculatenum(struct Student *s,int n){
    for(int i=0;i<n;i++){
        s[i].total = s[i].Chinese+s[i].Math+s[i].English;
        s[i].average = s[i].total/3.0;
    }
}

// 升序排序
// void sort(struct Student *s,int n){
//     for(int i=0;i<n;i++){
//         if(s[i].Chinese > s[i].Math){
//             float num = s[i].Chinese;
//             s[i].Chinese = s[i].Math;
//             s[i].Math = num;
//         }

//         if(s[i].Chinese > s[i].English){
//             float num = s[i].Chinese;
//             s[i].Chinese = s[i].English;
//             s[i].English = num;
//         }

//         if(s[i].Math > s[i].English){
//             float num = s[i].Math;
//             s[i].Math = s[i].English;
//             s[i].English = num;
//         }
//     }
// }

//总分排序
//(结构体之间可以直接用 = 整体复制）
void sortStudent(struct Student *s,int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n-1-i; j++){
            if (s[j].total > s[j+1].total){
                struct Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }      
        }       
    }
}

//统计及格人数
int statistics(struct Student *s,int n){
    int st = 0;
    for (int i = 0; i < n; i++){
        if (s[i].Chinese >=60.0 &&
            s[i].Math >=60.0 &&
            s[i].English >=60.0){        
            st++;
        }
    }
    return st;
}

//统计至少一门及格人数
int statistics_1(struct Student *s,int n){
    int st_1=0;
    for (int i = 0; i < n; i++){
        if (s[i].Chinese>=60.0 ||
            s[i].Math>=60.0 ||
            s[i].English>=60.0){
            st_1++;
        }
    }
    return st_1;
}

//输出
void printStudent(struct Student *s,int n){
    printf("\n%s %s %s %s %s %s %s\n",
           "学号","姓名","语文","数学","英语","总分","平均分");
    for (int i = 0; i < n; i++){
        printf("%s %s %.2f %.2f %.2f %.2f %.2f\n",
               s[i].id,s[i].name,
               s[i].Chinese,s[i].Math,s[i].English,
               s[i].total,s[i].average); 
    }
}

//主函数
int main(void){
    int n;
    printf("请输入学生人数:");
    if(scanf("%d",&n)!=1 || n <= 0){
        printf("人数不合规！\n");
        return 1;
    }

    struct Student *s = malloc((size_t)n * sizeof(struct Student));
    if (s==NULL){
        printf("内存分配失败！");
        return 1;
    }

    inputStudent(s,n);
    Calculatenum(s,n);
    sortStudent(s,n);
    printStudent(s,n);

    int pass = statistics(s,n);
    int pass_1 = statistics_1(s,n);
    printf("\n三门全部及格人数:%d",pass);
    printf("\n至少一门及格人数:%d",pass_1);

    free(s);
    s=NULL;
    return 0; 
}
