#include <stdio.h>
struct student {
  char name[20];
  int age;
  char course[20];
  int roll;
  float marks;
};

int main()
{
FILE *fp1;
FILE *fp2;
int n;
printf("Enter the number of students: ");
scanf("%d",&n);

fp1 = fopen("Student_Info.txt","w");
struct student s[n];
int i;
for(i=0;i<n;i++)
{
  printf("\nstudent %d details\n",i+1);
  printf("Name = ");
  scanf(" %s",s[i].name);
  printf("age = ");
  scanf("%d",&s[i].age);
  printf("Course = ");
  scanf(" %s",s[i].course);
  printf("roll = ");
  scanf("%d",&s[i].roll);
  printf("marks = ");
  scanf("%f",&s[i].marks);
}
for(i=0;i<n;i++)
{
	fprintf(fp1,"\nStudent %d Details\n",i+1);
	fprintf(fp1,"Name = %s\n",s[i].name);
	fprintf(fp1,"Age = %d\n",s[i].age);
	fprintf(fp1,"Course = %s\n",s[i].course);
	fprintf(fp1,"Roll = %d\n",s[i].roll);
	fprintf(fp1,"Marks = %.2f\n",s[i].marks);
}
fclose(fp1);

fp1 = fopen("Student_Info.txt","r");
char ch;
while ((ch = fgetc(fp1)) != EOF) {
        putchar(ch);
}
fclose(fp1);

int sum = 0;
for(i=0;i<n;i++){
	sum = sum + s[i].marks;
}
//printf("\nSum = %d\n",sum);

fp2 = fopen("AverageMarks.txt","w");
int avg;
avg = sum/n;
fprintf(fp2,"Average = %d",avg);

}
