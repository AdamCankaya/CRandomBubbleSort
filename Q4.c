/* CS261- Assignment 1 - Q.4*/
/* Name: Adam Cankaya
 * Date: October 7, 2013
 * Solution description: Generates random ID and scores for 5 students, passes the array into a bubble
                            sort function which arranges the array in ascending order of scores.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i, j, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j =0;j < n-1-i; j++)
        {
            if(students[j].score > students[j+1].score)
            {
                // move the score entry
                temp = students[j+1].score;
                students[j+1].score = students[j].score;
                students[j].score = temp;
                // move the ID entry
                temp = students[j+1].id;
                students[j+1].id = students[j].id;
                students[j].id = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
        int n = 5;

    /*Allocate memory for n students using malloc.*/
        struct student *students = malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
        int i;
        for(i = 0; i < n; i++)
        {
            students[i].id = rand() % 10 + 1;
            students[i].score = rand() % 100;
        }

    /*Print the contents of the array of n students.*/
        for(i = 0; i < n; i++)
        {
            printf("ID #%d, Score: %d\n", students[i].id, students[i].score);
        }
        printf("\n");

    /*Pass this array along with n to the sort() function*/
        sort(students, n);

    /*Print the contents of the array of n students.*/
        for(i = 0; i < n; i++)
        {
            printf("ID #%d, Score: %d\n", students[i].id, students[i].score);
        }

    return 0;
}
