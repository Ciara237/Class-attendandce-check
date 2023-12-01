#include<stdio.h>
#define MAX_STUDENTS 50
int validitycheckint(int numread, int x){//To check if the input vaiable is actually a integer number
            if(numread!=1){
                printf("The value entered is not valid.\n");
                printf("Enter a valid value.\n");
                scanf("%*[^\n]");//Discards the input if condition holds .
            }

}
int main(){
    char student_names[MAX_STUDENTS][50];//Array to store student names
    int attendance[MAX_STUDENTS]={0};//Array to store attendance (0 for absent, 1 present)
    int present=0, absent=0;

    //Input number of Students
    int num_students, numread;
        do{
    printf("Enter the number of Students\n");
    scanf("%d", &num_students);
    validitycheckint(numread, num_students);
    }while(numread==0);
    //Input Student Names
    printf("Enter the names of students\n");
    for(int i=0; i < num_students;i++){
        printf("Student %d:", i+1);
        scanf("%s", student_names[i]);
        printf("\n");
    }

    //Roll Call
    printf("\nRoll Call:\n");
    for(int i=0; i<num_students; i++){
            s:
        printf("Is %s present? (1 for Yes, 0 for No):", student_names[i]);
        scanf("%d", &attendance[i]);
        if(attendance>1 || attendance<0){
            printf("Invalid input.\n");
            goto s;
        }
        printf("\n");
        if(attendance[i]==0){
            absent= absent +1;
        }
        else{
            present+=1;
        }
    }

    //Display Attendance
    printf("Attendance Report:\n");
    for(int i=0; i<num_students ; i++){
        printf("%s: %s\n", student_names[i], attendance[i]? "Present" : "Absent");
    }
    printf("Number of students Present: %d\nNumber of Students Absent: %d", present, absent);
    return 0;
}
