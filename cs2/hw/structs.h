typedef struct enrollment{
        int eID, cID, nGrades;
        int grades[10];
}enrollment;

typedef struct student{
	int sID, classes;
	char name[30];
	enrollment enroll[4];
}student;

typedef struct course{
	char title[30];
	int students, cID, nGrades;
}course;

