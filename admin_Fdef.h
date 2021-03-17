int choice;

void welcome()
{   

    
    printf("%66s\n","Log in as:");
    printf("%64s\n","1. Admin");
    printf("%67s\n","2. Customer");
    printf("%71s\n\n","3. Exit Program");

    printf("%75s","Enter your choice: ");
    scanf("%d",&choice);
    // fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); adminLogin(); break;

        case 2: system("cls"); /*customer();*/ welcome(); break;

        case 3: system("cls"); ex(); break;

        default: system("cls"); printf("%80s\n%86s\n\n","Invalid choice !","Please, enter a correct choice"); welcome(); break;
    }
}


void adminLogin()
{
    char name[] = "admin";
    char pass[] = "admin123";
    char N[10],P[10];

    printf("%80s\n\n","Admin Login Portal");
    printf("%80s","Username: ");
    scanf("%s",N);
    printf("%80s","Password: ");
    scanf("%s",P);

    if(!(strcmp(name,N)))
    {
        // printf("N==name\n");
        if(!(strcmp(pass,P)))
        {
            system("cls");
            //printf("P==pass\n");
            admin();
        }
        else {
            system("cls");
            printf("%80s\n%80s\n","You have entered incorrect password","Enter username and password again");
            adminLogin();
        }
    }
    else
    {
        system("cls");
        printf("%80s\n%80s\n","You have entered incorrect username","Enter username and password again");
        adminLogin();
    }
}

void admin()
{

    printf("%80s\n\n","You are in ADMIN mode");
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