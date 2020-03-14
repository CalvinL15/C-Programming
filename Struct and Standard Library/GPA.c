#include <stdlib.h>
#include "GPA_calculation.h"

void GPA_calculation(struct Student all_student[], int N){
	int cmp(const void *a, const void *b){
		struct Student *x = (struct Student *)a;
		struct Student *y = (struct Student *)b;
		if(x->GPA > y->GPA)
			return -1;
		else if(x->GPA < y->GPA)
			return 1;
		return 0;		
	}
	for(int i = 0; i<N; i++){
		double total = 0.0;
		all_student[i].N_credit = 0;
		for(int j = 0; j<all_student[i].N_class; j++){
			if(strcmp(all_student[i].all_class[j].score, "A+") == 0)
				total += (4.3 * all_student[i].all_class[j].academic_credit);
			else if(strcmp(all_student[i].all_class[j].score, "A") == 0)
				total += (4.0 * all_student[i].all_class[j].academic_credit);
			else if(strcmp(all_student[i].all_class[j].score, "A-") == 0)
				total += (3.7 * all_student[i].all_class[j].academic_credit);
			else if(strcmp(all_student[i].all_class[j].score, "B+") == 0)
				total += (3.3 * all_student[i].all_class[j].academic_credit);
			else if(strcmp(all_student[i].all_class[j].score, "B") == 0)
				total += (3.0 * all_student[i].all_class[j].academic_credit);	
			else if(strcmp(all_student[i].all_class[j].score, "B-") == 0)
				total += (2.7 * all_student[i].all_class[j].academic_credit);
			else if(strcmp(all_student[i].all_class[j].score, "C+") == 0)
				total += (2.3 * all_student[i].all_class[j].academic_credit);
			else if(strcmp(all_student[i].all_class[j].score, "C") == 0)
				total += (2.0 * all_student[i].all_class[j].academic_credit);	
			else if(strcmp(all_student[i].all_class[j].score, "C-") == 0)
				total += (1.7 * all_student[i].all_class[j].academic_credit);
			all_student[i].N_credit += all_student[i].all_class[j].academic_credit; 							
		}
		all_student[i].GPA = (total/all_student[i].N_credit);
	}
	qsort(all_student, N, sizeof(struct Student), cmp);
	int presawards = N/20 + 1;
	if(N%20 == 0) presawards--;
	int idx = 0;
	int flag = 0;
	while(idx+1 <= presawards){
		if(all_student[idx].GPA >= 3.38 && all_student[idx].N_credit >= 15){
			if(flag == 1)
				printf("\n");
			printf("%d %s %f", idx+1, all_student[idx].name, all_student[idx].GPA);
			flag = 1;
		//	presawards--;	
		}
		else if(all_student[idx].GPA < 3.38)
			break;
		idx++;	
	}
	return 0;
}

