typedef struct {
    int month;
    int date;
    int year;
} date;


typedef struct {
    enum tagfield{female, male} sex;
    union {
        int children;
        int beard;
    } u;
}sexType;


typedef struct {
    enum tagfield{single,married,widowed,divorced} status;
    union {
        date marriage;
        date deathOfSpouse;
        date divorced;
        int numOfDivorced;
    }u;
}martialStatus;

typedef struct {
    char name[10];
    int age;
    float salary;
    date dob;
    sexType sexInfo;
    martialStatus mastialInfo;
}humanbeing;




int main()
{
    humanbeing person1;
    strcpy(person1.name,"Harris");
    person1.age = 20;
    person1.salary = 100;
    person1.dob.date = 19;
    person1.dob.year = 2000;
    person1.dob.month = 3;
    person1.mastialInfo.status = married;
    person1.mastialInfo.u.marriage.year = 2021;
    person1.mastialInfo.u.marriage.month = 2;
    person1.mastialInfo.u.marriage.date = 19;
}
