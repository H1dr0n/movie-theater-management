int choice;

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
    printf("\t\t\t\t2. Set Show Time\n");
    printf("\t\t\t\t3. Delete Movie\n");
    printf("\t\t\t\t4. Logout\n");

    printf("\n\t\t\t\tEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        // case 1: system("cls"); add_movie(); break;

        // case 2: system("cls"); set_show_time(); break;

        // case 3: system("cls"); delete_movie(); break;

        case 4: system("cls"); welcome(); break;

        default: system("cls"); admin(); break;
    }

}

int ex()
{
    return 0;
}