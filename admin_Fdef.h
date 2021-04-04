int choice;
FILE *fp;
void welcome()
{   

    
    printf("\t\t\t\tLog in as:\n");
    printf("\t\t\t\t1. Admin\n");
    printf("\t\t\t\t2. Customer\n");
    printf("\t\t\t\t3. Exit Program\n\n");

    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    // fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); adminLogin(); break;

        case 2: system("cls"); /*customer();*/ welcome(); break;

        case 3: system("cls"); ex(); break;

        default: system("cls"); printf("\t\t\t\tInvalid choice !\n\t\t\tPlease, enter a correct choice\n\n"); welcome(); break;
    }
}


void adminLogin()
{
    char name[] = "admin";
    char pass[] = "admin123";
    char N[10],P[10];

    printf("\t\t\t\tAdmin Login Portal\n\n");
    printf("\t\t\t\tUsername: ");
    scanf("%s",N);
    //printf("\n");


    if(!(strcmp(name,N)))
    {
        printf("\t\t\t\tPassword: ");
        scanf("%s",P);
        if(!(strcmp(pass,P)))
        {
            system("cls");
            admin();
        }
        else {
            system("cls");
            printf("\t\t\t\tYou have entered incorrect password.\n\t\t\t\tEnter username and password again.\n\n");
            adminLogin();
        }
    }
    else
    {
        system("cls");
        printf("\t\t\t\tYou have entered incorrect username.\n\t\t\t\tEnter username and password again.\n\n");
        adminLogin();
    }
}

void admin()
{

    printf("\t\t\t\tYou are in ADMIN mode\n\n");
    printf("\t\t\t\t1. Add Movie\n");
    printf("\t\t\t\t2. Delete Movie\n");
    printf("\t\t\t\t3. Browse Movies\n");
    printf("\t\t\t\t4. Logout\n");

    printf("\n\t\t\t\tEnter your choice:");
    scanf("%d",&choice); fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); add_movie(); break;

        // case 2: system("cls"); set_show_time(); admin(); break;

        case 3: system("cls"); browse_movies(); break;

        case 4: system("cls"); welcome(); break;

        default: system("cls"); admin(); break;
    }

}

void add_movie()
{   
    char m_n[200], d_t[50], t_p[20] ;
    fp = fopen("movies.txt","a+");

    printf("\t\t\t\tEnter Movie name: ");
    gets(m_n); fputs(m_n, fp); putc(' ',fp);
    printf("\t\t\t\tEnter date and time (dd/mm/yy): ");
    gets(d_t); fputs(d_t,fp); putc(' ',fp);
    printf("\t\t\t\tEnter ticket price in TAKA: ");
    gets(t_p); fputs(t_p,fp); putc(' ',fp);
    putc('\n',fp);
    fflush(stdin);
    printf("\n\n\t\t\t\tAdd another movie? (Y/N): ");
    if(getch()=='n')
    {
        fclose(fp);
        system("cls");
        admin();

    }
    else 
    {
        system("cls");
        add_movie();
    }
    
}


void browse_movies()
{
    fp = fopen("movies.txt","r");

    char ch = fgetc(fp);
    printf("\t\t\t\t");
    while(ch!=EOF)
    {   
        putchar(ch);
        ch = fgetc(fp);
    }

    printf("\n\n\t\t\t\tEnter any key to return to admin mode... ");
    getch();
    system("cls");
    admin();
}

int ex()
{
    return 0;
}