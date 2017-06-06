#define chunk 30

typedef struct enrollment{
        int eID, cID, nGrades;
        int grades[20];
}enrollment;

typedef struct student{
	int sID, classes, cNum;
	char name[30];
	enrollment* enroll;
}student;

typedef struct course{
	char title[30];
	int students, cID, nGrades;
}course;

