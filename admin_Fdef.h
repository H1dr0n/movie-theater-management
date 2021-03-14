int choice;

void welcome()
{
    printf("\t\t\t\tWelcome to Movie Theatre\n\n");
    printf("\t\t\t\tLog in as:\n");
    printf("\t\t\t\t1. Admin\n");
    printf("\t\t\t\t2. Customer\n");
    printf("\t\t\t\t3. Exit Program\n\n");

    printf("\t\t\t\tEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("cls"); admin(); break;

        case 2: system("cls"); /*customer();*/ welcome(); break;

        case 3: system("cls"); ex(); break;

        default: system("cls"); welcome(); break;
    }
}



void admin()
{
    printf("\t\t\t\t*-*Admin Login Portal*-*\n\n");
    printf("\t\t\t\tUsername: ");
    scanf("%*s");
    printf("\t\t\t\tPassword: ");
    scanf("%*s");

    printf("\n\n\t\t\t\tYou\'ve logged in successfully\n\n");

    system("cls");

    printf("\t\t\t\t*-*Admin Login Portal*-*\n\n");
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