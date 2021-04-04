void customer()
{
    printf("\t\t\t\tYou are in Customer Mode.\n\n");
    printf("\t\t\t\t1. Sign up\n");
    printf("\t\t\t\t2. Log in\n");
    printf("\t\t\t\t3. Browse movies\n");
    printf("\t\t\t\t4. Logout\n");

    switch(choice)
    {
        case 1: system("cls"); signup(); break;

        case 2: system("cls"); login(); break;

        case 3: system("cls"); browse_movies(); break;

        case 4: system("cls"); welcome(); break;
    }
}