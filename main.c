#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
void password(void);
void menu(void);
void stdListfun(void);
void stdDetailfun(void);
void noticefun(void);
void backendfun(void);
void exitfun(void);
void addnewfun(void);
void modifyfun(void);
void deletefun(void);
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    system("cls");
    system("color B");
    password();
    getch();
}
// password fun. starts from here.
void password(void)
{
    char passwords[20] = {"f"};
    gotoxy(1, 2);
    int j, z;
    char head[40] = {" Authorized person only "};
    z = strlen(head);
    for (j = 0; j <= 10; j++)
    {

        printf("\xDB");
        Sleep(50);
    }

    for (j = 0; j <= z; j++)
    {
        printf("%c", head[j]);
        Sleep(50);
    }
    for (j = 0; j <= 10; j++)
    {
        printf("\xDB");
        Sleep(50);
    }
    gotoxy(12, 4);
    Sleep(500);
    printf("password : ");
    char ch, pass[20];
    int i = 0;
    while (ch != 13) // 13 refers to enter key.
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            printf("*");
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, passwords) == 0)
    {
        gotoxy(30, 6);
        printf("CORRECT PASSWORD.");
        Sleep(1000);
        menu();
    }
    else
    {
        gotoxy(30, 6);
        printf("You entered the wrong password.");
        Sleep(700);
        system("cls");
        password();
    }
}
// menu fun. starts from here.
void menu()
{
    system("cls");
    gotoxy(30, 1);

    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 NETAJI SUBHS UIVERSITY HOSTEL DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
    gotoxy(31, 4);
    Sleep(200);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1.Student List");
    gotoxy(31, 7);
    Sleep(200);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2.Student Details");
    gotoxy(31, 10);
    Sleep(200);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3.Notice");
    gotoxy(31, 13);
    Sleep(200);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4.Backend");
    gotoxy(31, 16);
    Sleep(200);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5.Exit");

    switch (getch())
    {
    case '1':
        stdListfun();
        break;
    case '2':
        stdDetailfun();
        break;
    case '3':
        noticefun();
        break;
    case '4':
        backendfun();
        break;
    case '5':
        exitfun();
        break;

    default:
        system("cls");
        printf("Invalid Enter.");
        Sleep(250);
        menu();
        getch();
    }
}
void stdListfun(void)
{
    system("cls");
    FILE *hDirectory;
    char Name[30];
    char Course[25];
    char Semester[15];
    double Phone;
    char Room_no[10];

    hDirectory = fopen("directory.txt", "r");
    system("cls");
    gotoxy(31, 2);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    printf("\n");
    char ch;
    //  int f=0;
    while (fscanf(hDirectory, "%s %s %s %s %lf", Name, Course, Semester, Room_no, &Phone) != EOF)
    {

        // printf("------------------------------------------\n");
        printf("Name:%s\n", Name);
        printf("course:%s\n", Course);
        printf("semester:%s\n", Semester);
        printf("Room no:%s\n", Room_no);
        printf("Phone no:%.0lf\n", Phone);
        // f = 1;
        printf("------------------------------------------");
        printf("\n\n");
    }
    // while (!feof(hDirectory))

    // {
    //     ch = fgetc(hDirectory);
    //     printf("%c", ch);
    // }
    Sleep(1000);
    printf("Enter y for menu section:");
    while (getch() == 'y')
    {
        menu();
    }
    fclose(hDirectory);
}
void stdDetailfun(void)
{
    FILE *fptr;
    int flag = 0;
    int res;
    char Name[100];
    char Course[100];
    char Semester[100];
    double Phone;
    char Room_no[8];
    char name1[100];
    system("cls");
    fflush(stdin);
    gotoxy(18, 2);
    printf("\xDB\xDB\xDB Enter the name of the person you want to see the detail:: ");
    gets(name1);
    fptr = fopen("directory.txt", "r");
    // fflush(stdin);
    while (fscanf(fptr, "%s %s %s %s %lf\n", Name, Course, Semester, Room_no, &Phone) != EOF)
    {
        res = strcmp(Name, name1);
        if (res == 0)
        {
            gotoxy(39, 4);
            printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
            gotoxy(28, 5);
            printf("----------------------------------------");
            gotoxy(31, 6.5);
            printf("\xB3\xB2\xB2\xB2 Name:\t%s", Name);
            gotoxy(31, 7);
            printf("\xB3\xB2\xB2\xB2 Course:\t%s", Course);
            gotoxy(31, 8);
            printf("\xB3\xB2\xB2\xB2 Semester:\t%s", Semester);
            gotoxy(31, 9);
            printf("\xB3\xB2\xB2\xB2 Room_no:\t%s", Room_no);
            gotoxy(31, 10);
            printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf", Phone);
            gotoxy(31, 11);
            printf("----------------------------------------");
            flag = 1;
            Sleep(100);
            gotoxy(18, 12);
            printf("Enter 1 for menu option or 2 for searching again.");
            if (getch() == '1')
            {
                menu();
            }
            else if (getch() == '2')
            {
                stdDetailfun();
            }
        }
    }

    if (flag == 0)
    {
        system("cls");
        gotoxy(39, 4);
        printf("No record found.");

        gotoxy(39, 6);
        printf("Enter a to enter file again or m key to open menu section:");
        if (getch() == 'a')
        {
            system("cls");
            stdDetailfun();
        }
        else if (getch() == 'm')
        {
            system("cls");
            menu();
        }

        fclose(fptr);
    }
}

void noticefun(void)
{
    system("cls");
    FILE *nptr;
    char c;
    nptr = fopen("notice.txt", "r");
    if (nptr == NULL)
    {
        printf("Cannot open file \n");
    }
    c = fgetc(nptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(nptr);
    }
    fclose(nptr);
    printf("\n Enter m for back to menu and any key to exit");
    if (getch() == 'm')

    {
        menu();
    }
    else
    {
        exitfun();
    }
}
void backendfun(void)
{
    system("cls");
    printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 EDIT SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
    gotoxy(31, 8);
    gotoxy(1, 2);
    printf("1. Add New Student Details");
    gotoxy(1, 4);
    printf("2. Modify");
    gotoxy(1, 6);
    printf("3. Delete");
    gotoxy(1, 8);
    printf("4. Back to Menu");
    switch (getch())
    {
    case '1':
        addnewfun();
        break;
    case '2':
        modifyfun();
        break;
    case '3':
        deletefun();
        break;
    case '4':
        menu();
        break;

    default:
        printf("Not a valid Input");
        backendfun();
        break;
    }
}
// fun. for exit
void exitfun(void)
{
    system("cls");
    printf("tusi jarey ho, tusi naa jaoooo\n");
    getch();
}
// fun. for adding new details
void addnewfun()
{
    system("cls");
    FILE *hDirectory;
    char Name[30];
    char Course[25];
    char Semester[15];
    double Phone;
    char Room_no[10];
    char Address[100];
    hDirectory = fopen("directory.txt", "ab+");
    if (hDirectory == NULL)
    {
        printf("failed to create the required directory");
    }
    else
    {
        gotoxy(52, 3);
        printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Hosteller Details \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
        gotoxy(31, 6);
        printf("Name:\t");
        gotoxy(52, 6);
        gets(Name);
        gotoxy(31, 7);
        printf("Course:\t");
        gotoxy(52, 7);
        gets(Course);
        gotoxy(31, 8);
        printf("Semester:\t");
        gotoxy(52, 8);
        gets(Semester);
        gotoxy(31, 9);
        printf("Room Number:\t");
        gotoxy(52, 9);
        gets(Room_no);
        gotoxy(31, 10);
        printf("Phone Number:\t");
        gotoxy(52, 10);
        scanf("%lf", &Phone);
        fprintf(hDirectory, "%s %s %s %s %.0lf\n", Name, Course, Semester, Room_no, Phone);
    }
    fclose(hDirectory);
    system("cls");
    char ch;
    gotoxy(31, 4);
    printf("Do you wanna add more datas.Press y for that:");
    Sleep(1000);
    fflush(stdin);
    ch = getch();
    if ((ch == 'y' || ch == 'Y'))
    {
        addnewfun();
    }
    else
    {
        menu();
    }
}
// fun. to modify details
void modifyfun()
{
    system("cls");
    FILE *hDirectory, *hDirectory1;
    char Name[100], Course[100], Semester[100], Room_no[100], name1[100], course1[100], semester1[100], room_no1[100];
    int res, f = 0;
    double Phone, Phone1;
    hDirectory = fopen("directory.txt", "r");
    hDirectory1 = fopen("temp.txt", "a");
    system("cls");
    gotoxy(31, 4);
    printf("Enter the name: ");
    gets(name1);
    system("cls");
    while (fscanf(hDirectory, "%s %s %s %s %lf\n", Name, Course, Semester, Room_no, &Phone) != EOF)
    {
        res = strcmp(Name, name1);
        if (res == 0)
        {
            f = 1;
            gotoxy(31, 4);
            printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
            gotoxy(31, 6);
            printf("Enter the new Course:");
            scanf("%s", course1);
            gotoxy(31, 7);
            printf("Enter the semester:");
            scanf("%s", semester1);
            gotoxy(31, 8);
            printf("Enter the new room no:");
            scanf("%s", room_no1);
            gotoxy(31, 9);
            printf("Enter the new phone number:");
            scanf("%lf", &Phone1);
            fprintf(hDirectory1, "%s %s %s %s %.0lf\n", Name, course1, semester1, room_no1, Phone1);
        }
        else
        {
            fprintf(hDirectory1, "%s %s %s %s %.0lf\n", Name, Course, Semester, Room_no, Phone);
        }
    }
    if (f == 0)
    {
        printf("Record Not found.");
    }
    fclose(hDirectory);
    fclose(hDirectory1);
    hDirectory = fopen("directory.txt", "w");
    fclose(hDirectory);
    hDirectory = fopen("directory.txt", "a");
    hDirectory1 = fopen("temp.txt", "r");
    while (fscanf(hDirectory1, "%s %s %s %s %lf\n", Name, Course, Semester, Room_no, &Phone) != EOF)
    {
        fprintf(hDirectory, "%s %s %s %s %.0lf\n", Name, Course, Semester, Room_no, Phone);
    }

    fclose(hDirectory);
    fclose(hDirectory1);
    hDirectory1 = fopen("temp.txt", "w");
    fclose(hDirectory1);
    printf("\n\nPress 1 to modify another student's detail and  any other key for menu option .");
    fflush(stdin);
    if (getch() == '1')
    {
        modifyfun();
    }
    else
    {
        menu();
    }
}
// fun. to delete entries
void deletefun()
{
    system("cls");
    FILE *hDirectory, *hDirectory1;
    char Name[100], Course[100], Semester[100], Room_no[100], name1[100], course1[100], semester1[100], room_no1[100];
    int res, f = 0;
    double Phone, Phone1;
    hDirectory = fopen("directory.txt", "r");
    hDirectory1 = fopen("temp.txt", "a");
    system("cls");
    gotoxy(31, 4);
    printf("Enter the hosteller name you want to delete: ");
    gets(name1);
    system("cls");
    while (fscanf(hDirectory, "%s %s %s %s %lf\n", Name, Course, Semester, Room_no, &Phone) != EOF)
    {
        res = strcmp(Name, name1);
        if (res == 0)
        {
            f = 1;
            printf("record deleted successfully.");
        }
        else
        {
            fprintf(hDirectory1, "%s %s %s %s %.0lf\n", Name, Course, Semester, Room_no, Phone);
        }
    }
    if (f == 0)
    {
        printf("Record Not found.");
    }
    fclose(hDirectory);
    fclose(hDirectory1);
    hDirectory = fopen("directory.txt", "w");
    fclose(hDirectory);
    hDirectory = fopen("directory.txt", "a");
    hDirectory1 = fopen("temp.txt", "r");
    while (fscanf(hDirectory1, "%s %s %s %s %lf\n", Name, Course, Semester, Room_no, &Phone) != EOF)
    {
        fprintf(hDirectory, "%s %s %s %s %.0lf\n", Name, Course, Semester, Room_no, Phone);
    }

    fclose(hDirectory);
    fclose(hDirectory1);
    hDirectory1 = fopen("temp.txt", "w");
    fclose(hDirectory1);
    printf("\n\nPress y for menu option.");
    fflush(stdin);
    if (getch() == 'y')
    {
        menu();
    }
}
